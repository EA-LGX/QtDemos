#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSplitter>
#include <QTextEdit>
#include <QProgressBar>
#include <QMainWindow>

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();
};
#endif // MAINWINDOW_H
