#ifndef __IMTOOL_UI_HPP_
#define __IMTOOL_UI_HPP_

#include <QMainWindow> 
#include <QLabel>
#include <QSpinBox>
#include <QTabWidget>
#include <QTabWidget>

#include "drop_area.hpp"

namespace imtool 
{

class UI : public QMainWindow {
  
  Q_OBJECT

  public:
   UI();

  public slots:
    void update_formats_table(const QMimeData *mime_data);

  private:
    void create_actions();
    void create_menus();   

  private:
    QWidget     *central_widget;
    QTabWidget  *tab_widget;
    QLabel      *image_preview;
    QSpinBox    *preview_selector;
    DropArea    *drop_area;
    
    
}; 

}

#endif
