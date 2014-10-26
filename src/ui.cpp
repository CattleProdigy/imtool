#include "ui.hpp"

#include <iostream>

#include <QVBoxLayout>

namespace imtool {

UI::UI() {

  // Initialize Drop Area
  drop_area = new DropArea;
  connect(drop_area, SIGNAL(changed(const QMimeData*)), this,
          SLOT(update_formats_table(const QMimeData*)));
  
  create_actions();
  create_menus();

  // Initialize Central Widget
  central_widget = new QWidget(this);

  // Set Layout
  QVBoxLayout *central_layout = new QVBoxLayout;
  central_layout->addWidget(drop_area);
  central_widget->setLayout(central_layout);

  setCentralWidget(central_widget);
  
  setWindowTitle(tr("imtool")); 
  resize(1280, 720);
}

void
UI::update_formats_table(const QMimeData *mime_data) {

  std::cerr << "got a thing" << std::endl;
  std::cout << mime_data->text().toStdString() << std::endl;

}

void
UI::create_actions() {

}

void
UI::create_menus() {

}

}
