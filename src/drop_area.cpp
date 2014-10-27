#include "drop_area.hpp"

#include <iostream>

#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDragLeaveEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QUrl>

imtool::DropArea::DropArea(QWidget *parent) : QLabel(parent) {

  setMinimumSize(200,200);
  setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
  setAlignment(Qt::AlignCenter);
  setAcceptDrops(true);
  setAutoFillBackground(true); 
  clear();
}

void 
imtool::DropArea::clear() {

  setText(tr("<drop content>"));
  setBackgroundRole(QPalette::Dark);
}

void 
imtool::DropArea::dragEnterEvent(QDragEnterEvent *event) {
  
  setText(tr("<drop content>"));
  setBackgroundRole(QPalette::Highlight);
  
  event->acceptProposedAction();
}

void 
imtool::DropArea::dragMoveEvent (QDragMoveEvent  *event) {

  event->acceptProposedAction();
}    

void 
imtool::DropArea::dragLeaveEvent(QDragLeaveEvent *event) {

  clear();
  event->accept();
}

void 
imtool::DropArea::dropEvent(QDropEvent *event) {

  const QMimeData *mime_data = event->mimeData();

  if (mime_data->hasImage()) {
    setPixmap(qvariant_cast<QPixmap>(mime_data->imageData()));
  } else if (mime_data->hasHtml()) {
    std::cout << "html" << std::endl;
    setText(mime_data->html());
    setTextFormat(Qt::RichText);
  } else if (mime_data->hasText()) {
    std::cout << "text" << std::endl;
    setText(mime_data->text());
    setTextFormat(Qt::PlainText);
  } else if (mime_data->hasUrls()) {
    std::cout << "url" << std::endl;
    QList<QUrl> urlList = mime_data->urls();
    QString text;
    for (int i = 0; i < urlList.size() && i < 32; ++i) {
      QString url = urlList.at(i).path();
      text += url + QString("\n");
    }
    setText(text);
  } else {
    setText(tr("Cannot display data"));
  }

  setBackgroundRole(QPalette::Dark);
  event->acceptProposedAction();
  emit changed(event->mimeData());
}
