#include "home.h"

Home::Home() {
    Rental* rentLst = new Rental();
    setSceneRect(0, 0, 1900, 1080);
    loadBG();
    loadMenuBar();
    loadProducts(rentLst);
}

void Home::updateId(unsigned int i) {
    targetId = i;
}

void Home::loadBG() {
    QBrush brush(QColor(66, 103, 178));
    setBackgroundBrush(brush);
}

void Home::loadMenuBar(){

    QPushButton* myRentsBtn = new QPushButton("My Rents");
    myRentsBtn->setGeometry(0, 0, 100, 50);
    myRentsBtn->setStyleSheet("QPushButton {color: white;"
                           "font-size: 20px;"
                           "font-weight: bold;"
                           "background-color: rgba(0, 0, 0, 100);"
                           "opacity: 1;}"
                           "QPushButton:hover {"
                           "background-color: rgba(150, 150, 150, 50);}");
    addWidget(myRentsBtn);

    connect(myRentsBtn, &QPushButton::clicked, this, &Home::openMyRents);

}

void Home::loadProducts(Rental* rtl) {
    int line = 0;
    int row = 0;

    QLabel* title = new QLabel("QRental");
    title->setGeometry(235, 0, 1440, 150);
    title->setStyleSheet("QLabel {color: white;"
                           "font-size: 40px;"
                           "font-weight: bold;"
                           "border: 5px solid black;"
                           "background-color: rgba(0, 0, 0, 100);"
                           "opacity: 1;}");
    addWidget(title);

    for(auto i = rtl->getBegin(); i != rtl->getEnd(); i++){
        bool rented = false;

        // check if product is already rented
        for(auto j = myLst->begin(); j != myLst->end(); j++){
            if((*i)->getId() == (*j)->getId())
                rented = true;
        }

            QLabel* prodL = new QLabel((*i)->getName());
            prodL->setGeometry(290*row + 235, 290*line + 200, 280, 50);
            prodL->setStyleSheet("QLabel {color: white;"
                                   "font-size: 20px;"
                                   "font-weight: bold;"
                                 "border: 2px solid black;"
                                   "background-color: rgba(0, 0, 0, 100);"
                                   "opacity: 1;}");
            addWidget(prodL);


            QImage image(QDir::currentPath() + (*i)->getImgPath());
            QImage sImage = image.scaled(280, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation);

            QLabel* img = new QLabel();
            img->setScaledContents(true);
            img->setPixmap(QPixmap::fromImage(sImage));
            img->setGeometry(290*row + 235, 290*line+250, 280, 170);
            addWidget(img);


        if(!rented){
            QPushButton* rentBtn = new QPushButton("Rent");
            rentBtn->setGeometry(290*row + 235, 290*line + 420, 280, 50);
            rentBtn->setStyleSheet("QPushButton {color: white;"
                                   "font-size: 20px;"
                                   "font-weight: bold;"
                                   "background-color: rgba(0, 0, 0, 100);"
                                   "opacity: 1;}"
                                   "QPushButton:hover {"
                                   "background-color: rgba(150, 150, 150, 50);}");
            addWidget(rentBtn);

            connect(rentBtn, &QPushButton::clicked, this, [=](){emit Home::updateId((*i)->getId()); Home::openProduct();});
        }

        else{

            QLabel* rentedLabel = new QLabel("Already rented!");
            rentedLabel->setGeometry(290*row + 235, 290*line + 420, 280, 50);
            rentedLabel->setStyleSheet("QLabel {color: rgba(255, 17, 0, 100);"
                                   "font-size: 20px;"
                                       "border: 2px solid black;"
                                   "font-weight: bold;"
                                   "background-color: rgba(0, 0, 0, 100);"
                                   "opacity: 1;}");
            addWidget(rentedLabel);

        }



            row++;
            if(((*i)->getId() + 1) % 5 == 0){
                line++;
                row = 0;
            }
        }

}


