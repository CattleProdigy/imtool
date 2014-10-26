#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

#include "ui.hpp"

int
main(int argc, char **argv)
{
  QApplication app(argc, argv);

  imtool::UI imtool_ui;
  imtool_ui.show();
  
  return app.exec();
}
