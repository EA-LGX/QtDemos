#include "mainwindow.h"

#include <QSplitter>
#include <QLabel>
#include <QProgressBar>
#include <QTextEdit>
#include <QWidget>
#include <QPushButton>


#include <QApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QMessageBox>

// 网络请求
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QEventLoop>

void getData();

int main(int argc, char* argv[]) {
    // 对高分屏的支持
#if (QT_VERSION >= QT_VERSION_CHECK(5,6,0))
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication a(argc, argv);

    // 水平分割窗口
    QSplitter* splitter = new QSplitter(Qt::Horizontal, 0);
    QSplitter* splitter2 = new QSplitter(Qt::Vertical);
    splitter->addWidget(splitter2);
    QTextEdit* label = new QTextEdit("top Widget");
    label->setAlignment(Qt::AlignCenter);
    splitter2->addWidget(label);
    QTextEdit* label2 = new QTextEdit("center Widget");
    label2->setAlignment(Qt::AlignCenter);
    splitter2->addWidget(label2);
    QPushButton* btn = new QPushButton("发送请求");
    splitter2->addWidget(btn);

    QObject::connect(btn, &QPushButton::clicked, [=]() {
        getData();
        });

    QTextEdit* label3 = new QTextEdit("right Widget");
    label3->setAlignment(Qt::AlignCenter);
    splitter->addWidget(label3);

    splitter->setWindowTitle("QSplitter");
    splitter->setGeometry(100, 100, 500, 300);
    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 2);
    splitter->show();

    QString jsonData = "{\"name\":\"John\",\"age\":18}";
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();
    QString name = jsonObj.value("name").toString();
    int age = jsonObj.value("age").toInt();

    // 弹出对话框
    QMessageBox::information(nullptr, "提示", QString("姓名：%1，年龄：%2").arg(name).arg(age));

    //MainWindow w;
    //w.show();
    return a.exec();
}

void getData() {
    // 通过Get请求获取数据
    QNetworkAccessManager* manager = new QNetworkAccessManager();
    QNetworkRequest request;
    request.setUrl(QUrl("https://tenapi.cn/v2/color"));

    QByteArray postData;
    postData.append("key1=value1");
    postData.append("&key2=value2");

    // QNetworkReply* reply = manager->post(request,postData);
    QNetworkReply* reply = manager->get(request);

    QObject::connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QString responseData = reply->readAll();
            QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData.toUtf8());
            QJsonObject jsonObj = jsonDoc.object();
            QString name = jsonObj.value("msg").toString();
            QMessageBox::information(nullptr, "提示", name);
        }
        else {
            QMessageBox::information(nullptr, "提示", "请求失败");
        }
        reply->deleteLater();
        });
}

