#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {

  qRegisterMetaType<vector<TrackingBox>>("vector<TrackingBox>");

  QApplication a(argc, argv);
  MainWindow m;
  m.setWindowTitle("AntiPirateGUI");
  m.show();
  return a.exec();
}
