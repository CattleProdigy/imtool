#include <QApplication>
#include <QDebug>
#include <QImageReader>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QWidget>

#include <opencv2/opencv.hpp>

#include "ui.hpp"

int
main(int argc, char **argv)
{
  QApplication app(argc, argv);


  imtool::UI imtool_ui;
  imtool_ui.show();
  
  return app.exec();
}
