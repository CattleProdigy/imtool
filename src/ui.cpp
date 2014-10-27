#include "ui.hpp"

#include <iostream>

#include <QHBoxLayout>
#include <QImageReader>
#include <QImage> 
#include <QPicture>
#include <QSize>
#include <opencv2/opencv.hpp>

namespace imtool {

UI::UI() {

  // Initialize Drop Area
  drop_area = new DropArea;
  connect(drop_area, SIGNAL(changed(const QMimeData*)), this,
          SLOT(update_formats_table(const QMimeData*)));

  // Setup Tab View
  tab_widget = new QTabWidget;
  tab_widget->addTab(drop_area, QString("Input"));
  
  // Setup Image Preview
  image_preview = new QLabel;
  image_preview->setText(
    QString("Drop an image onto the drop area and it will show up here.")
  );
  image_preview->setAlignment(Qt::AlignCenter);

  // Setup Image Counter;
  preview_selector = new QSpinBox;
  preview_selector->setMinimumWidth(50);
  preview_selector->setMaximumWidth(50);

  // Setup the preview area
  QVBoxLayout *preview_layout = new QVBoxLayout;
  preview_layout->addWidget(image_preview);
  preview_layout->addWidget(preview_selector);
  preview_layout->setAlignment(preview_selector, Qt::AlignRight);
  
  create_actions();
  create_menus();

  // Initialize Central Widget
  central_widget = new QWidget(this);

  // Set Layout
  QHBoxLayout *central_layout = new QHBoxLayout;
  central_layout->addWidget(tab_widget);
  central_layout->addLayout(preview_layout);
  central_widget->setLayout(central_layout);

  setCentralWidget(central_widget);
  
  setWindowTitle(tr("imtool")); 
}

void
UI::update_formats_table(const QMimeData *mime_data) {

  std::cout << mime_data->text().toStdString() << std::endl;
  drop_area->update();

  if (mime_data->hasText()) {
  
    // Strip 'file://' from filename
    QString file_name = mime_data->text().trimmed();
    file_name.remove(0,7);

    // Load image TODO: load into image manager
    QImageReader qir; 
    qir.setFileName(file_name);
    if (qir.canRead()) {
      QImage image;
      image = qir.read();
      image_preview->setPixmap(QPixmap::fromImage(image));
    } else {
      std::cout << "fail" << std::endl;
    }
  }
}

void
UI::create_actions() {

}

void
UI::create_menus() {

}

}
