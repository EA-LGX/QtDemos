#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent) {
    QSplitter* spm = new QSplitter(Qt::Horizontal, 0);
    QTextEdit* te1 = new QTextEdit("Left Widget");
    te1->setAlignment(Qt::AlignCenter);
    spm->addWidget(te1);
    QTextEdit* te4 = new QTextEdit("Center");
    te4->setAlignment(Qt::AlignCenter);
    spm->addWidget(te4);

    QSplitter* spm2 = new QSplitter(Qt::Vertical, spm);

    QProgressBar* m_progressBar = new QProgressBar();
    m_progressBar->setRange(0, 100);
    m_progressBar->setValue(70);

    spm2->addWidget(m_progressBar);
    QTextEdit* te3 = new QTextEdit("Center Widget");
    te3->setAlignment(Qt::AlignCenter);
    spm2->addWidget(te3);
    QTextEdit* te5 = new QTextEdit("Bottom Widget");
    te5->setAlignment(Qt::AlignCenter);
    spm2->addWidget(te5);

    spm->setStretchFactor(0, 1);  // 索引, 比例
    spm->setStretchFactor(1, 2);
    spm->setStretchFactor(2, 1);
    spm->setWindowTitle("Splitter");
    spm->setFixedSize(800, 450);
    spm->show();

}

MainWindow::~MainWindow() {
}

