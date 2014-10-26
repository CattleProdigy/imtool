#ifndef __IMTOOL_DROP_AREA_HPP_
#define __IMTOOL_DROP_AREA_HPP_

#include <QLabel>
#include <QMimeData>
#include <QWidget>

namespace imtool
{

class DropArea : public QLabel
{

  Q_OBJECT
 
  public:
    DropArea(QWidget *parent = 0);

  public slots:
    void clear();

  signals:
    void changed(const QMimeData *mime_data = 0);

  protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent (QDragMoveEvent  *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dropEvent      (QDropEvent     *event);

};

} // namespace imtool

#endif
