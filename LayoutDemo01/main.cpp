#include "mainwindow.h"

#include <QApplication>
#include <QSplitter>
#include <QTextEdit>
#include <QProgressBar>

int main(int argc, char* argv[]) {
  // 对高分屏的支持
#if (QT_VERSION >= QT_VERSION_CHECK(5,6,0))
  QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
  QApplication a(argc, argv);

  MainWindow w;
  // w.show();

  return a.exec();
}