#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSplitter>
#include <QLabel>
#include <QProgressBar>

MainWindow::MainWindow(QWidget* parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow) {
  ui->setupUi(this);
  // QSplitter 水平分割窗口
  // QSplitter* splitter = new QSplitter(Qt::Horizontal, this);
  // splitter->addWidget(new QLabel("Left Widget"));
  // splitter->addWidget(new QLabel("Right Widget"));

  //splitter->show();
}

MainWindow::~MainWindow() {
  delete ui;
}

