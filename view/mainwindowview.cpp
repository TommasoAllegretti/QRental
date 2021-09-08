#include "mainwindowview.h"

MainWindowView::MainWindowView() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void MainWindowView::resizeEvent(QResizeEvent* e){
    QGraphicsView::resizeEvent(e);
    fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
}
