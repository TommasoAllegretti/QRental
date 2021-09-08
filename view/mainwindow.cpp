#include "mainwindow.h"
#include "mainwindowview.h"

#include "controller/controller.h"
#include "controller/homecontroller.h"
#include "controller/productcontroller.h"
#include "controller/myrentscontroller.h"
#include "controller/editcontroller.h"

#include <QGraphicsScene>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), view(new MainWindowView()), controller(new HomeController()) {
    setWindowTitle("QRental");
    setMinimumSize(QSize(1200, 600));
    setCentralWidget(view);
    setScreen(Routes::HomeScreen);
}

MainWindow::~MainWindow()
{
    delete view;
}

void MainWindow::setScreen(Routes r){
    if(controller)
        delete controller;
    switch(r) {
        default:
    case Routes::HomeScreen:
        controller = new HomeController;
    break;
    case Routes::ProductScreen:
        controller = new ProductController;
    break;
    case Routes::MyRentsScreen:
        controller = new MyRentsController;
    break;
    case Routes::EditScreen:
        controller = new EditController;
    break;

    }

    connect(controller, &Controller::goToScene, this, &MainWindow::setScreen);

    view->setScene(controller->getScene());

}











