#include "mainwindow.h"

#include <QApplication>
#include <QSplitter>
#include <QTextEdit>

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  int b  = 14 ;

  QSplitter *spm = new QSplitter(Qt::Horizontal, 0);
  QString str = "我在左边";
  // 将b转换为字符串
  str = str + QString::number(b);
  QTextEdit *te1 = new QTextEdit(str, spm);
  te1->setAlignment(Qt::AlignCenter);

  QSplitter *spr = new QSplitter(Qt::Vertical, spm);
  spr->setOpaqueResize(false);
  QTextEdit *te2 = new QTextEdit(QObject::tr("我在右上边"), spr);
  te2->setAlignment(Qt::AlignCenter);
  QTextEdit *te3 = new QTextEdit(QObject::tr("我在右下边"), spr);
  te3->setAlignment(Qt::AlignCenter);

  spm->setStretchFactor(1, 1);
  spm->setWindowTitle(QObject::tr("分割窗口"));
  spm->show();

  // MainWindow w;
  // w.show();
  return a.exec();
}