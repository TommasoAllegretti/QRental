#include "myrents.h"

MyRents::MyRents(){
    setSceneRect(0, 0, 1900, 1080);
    loadBG();
    loadHomeBtn();
    loadMyRentsPage();
}

void MyRents::loadHomeBtn() {
    QPushButton* homeBtn = new QPushButton("Home");
    homeBtn->setGeometry(0, 0, 100, 50);
    homeBtn->setStyleSheet("QPushButton {color: white;"
                           "font-size: 24px;"
                           "font-weight: bold;"
                           "background-color: rgba(0, 0, 0, 100);"
                           "opacity: 1;}"
                           "QPushButton:hover {"
                           "background-color: rgba(150, 150, 150, 50);}");
    addWidget(homeBtn);

    connect(homeBtn, &QPushButton::clicked, this, &MyRents::openHome);
}

void MyRents::loadBG() {
    QBrush brush(QColor(66, 103, 178));
    setBackgroundBrush(brush);
}

void MyRents::loadMyRentsPage() {
    unsigned int row = 0;
    unsigned int index = 0;

    if(myLst->size() == 0){
        QLabel* emptyListLabel = new QLabel("Oops, you still haven't rented any vehicle...");
        emptyListLabel->setGeometry(100, 160*row + 100, 1700, 125);
        emptyListLabel->setStyleSheet("QLabel {color: white;"
                               "font-size: 20px;"
                             "border: 2px solid black;"
                               "font-weight: bold;"
                               "background-color: rgba(0, 0, 0, 100);"
                               "opacity: 1;}");
        addWidget(emptyListLabel);
    }

    else{
        double totCost = 0;
        double totRefund = 0;
        for(auto i = myLst->begin(); i != myLst->end(); i++){

            ORMotorcycle* ormv = dynamic_cast<ORMotorcycle*>(i->get());
            ShowroomVehicle* srv = dynamic_cast<ShowroomVehicle*>(i->get());

            QLabel* prodL = new QLabel();
            if(ormv && ormv->getRaceName() != "")
                //QLabel* prodL = new QLabel(ormv->getRaceName() + " - " + ormv->getName());
                prodL->setText("Race: " + ormv->getRaceName() + " \n\n " + ormv->getName());
            else if(srv && srv->getShowName() != "")
                //QLabel* prodL = new QLabel(srv->getShowName() + " - " + srv->getName());
                prodL->setText("Show: " + srv->getShowName() + " \n\n " + srv->getName());
            else
                //QLabel* prodL = new QLabel((*i)->getName());
                prodL->setText((*i)->getName());

            prodL->setGeometry(100, 160*row + 100, 270, 125);
            prodL->setStyleSheet("QLabel {color: white;"
                                   "font-size: 20px;"
                                 "border: 2px solid black;"
                                   "font-weight: bold;"
                                   "background-color: rgba(0, 0, 0, 100);"
                                   "opacity: 1;}");
            addWidget(prodL);


            QImage image(QDir::currentPath() + (*i)->getImgPath());
            QImage sImage = image.scaled(200, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation);

            QLabel* img = new QLabel();
            img->setScaledContents(true);
            img->setPixmap(QPixmap::fromImage(sImage));
            img->setGeometry(370, 160*row + 100, 170, 125);
            img->setStyleSheet("border: 2px solid black;"
                               "background-color: rgba(66, 103, 178, 0);");
            addWidget(img);

            QLabel* ratingLabel = new QLabel("Rating: " + QString::number((*i)->getRating()) + "/5");
            ratingLabel->setGeometry(540, 160*row + 100, 215, 125);
            ratingLabel->setStyleSheet("QLabel {color: white;"
                                   "font-size: 20px;"
                                       "border: 2px solid black;"
                                   "font-weight: bold;"
                                   "text-align:center;"
                                   "background-color: rgba(0, 0, 0, 100);"
                                   "opacity: 1;}");
            addWidget(ratingLabel);

            QLabel* kmLabel = new QLabel("Km: " + QString::number((*i)->getKm()));
            kmLabel->setGeometry(755, 160*row + 100, 215, 125);
            kmLabel->setStyleSheet("QLabel {color: white;"
                                   "font-size: 20px;"
                                   "border: 2px solid black;"
                                   "font-weight: bold;"
                                   "text-align:center;"
                                   "background-color: rgba(0, 0, 0, 100);"
                                   "opacity: 1;}");
            addWidget(kmLabel);

            QLabel* rentTimeLabel = new QLabel("Rent time: " + QString::number((*i)->getRentTime()) + " days");
            rentTimeLabel->setGeometry(970, 160*row + 100, 215, 125);
            rentTimeLabel->setStyleSheet("QLabel {color: white;"
                                   "font-size: 20px;"
                                         "border: 2px solid black;"
                                   "font-weight: bold;"
                                   "text-align:center;"
                                   "background-color: rgba(0, 0, 0, 100);"
                                   "opacity: 1;}");
            addWidget(rentTimeLabel);

            QLabel* costLabel = new QLabel("Cost: " + QString::number((*i)->getRentAmount()) + " €");
            costLabel->setGeometry(1185, 160*row + 100, 215, 125);
            costLabel->setStyleSheet("QLabel {color: white;"
                                   "font-size: 20px;"
                                     "border: 2px solid black;"
                                   "font-weight: bold;"
                                   "text-align:center;"
                                   "background-color: rgba(0, 0, 0, 100);"
                                   "opacity: 1;}");
            addWidget(costLabel);


            QLabel* refundLabel = new QLabel("Refund: " + QString::number((*i)->getRefundAmount()) + " €");
            refundLabel->setGeometry(1400, 160*row + 100, 215, 125);
            refundLabel->setStyleSheet("QLabel {color: white;"
                                   "font-size: 20px;"
                                     "border: 2px solid black;"
                                   "font-weight: bold;"
                                   "text-align:center;"
                                   "background-color: rgba(0, 0, 0, 100);"
                                   "opacity: 1;}");
            addWidget(refundLabel);


            QPushButton* delBtn = new QPushButton("Delete");
            delBtn->setGeometry(1650, 160*row + 100, 150, 125);
            delBtn->setStyleSheet("QPushButton {color: white;"
                                   "font-size: 24px;"
                                   "font-weight: bold;"
                                   "background-color: rgba(0, 0, 0, 100);"
                                   "opacity: 1;}"
                                   "QPushButton:hover {"
                                   "background-color: rgba(150, 150, 150, 50);}");
            addWidget(delBtn);

            connect(delBtn, &QPushButton::clicked, this, [=]{emit myLst->erase(index); MyRents::restorePage();});

            row++;
            index++;
            totCost += (*i)->getRentAmount();
            totRefund += (*i)->getRefundAmount();
        }


        QLabel* costTLabel = new QLabel("Total rentals cost: -" + QString::number(totCost) + " €");
        costTLabel->setGeometry(100, 900, 850, 150);
        costTLabel->setStyleSheet("QLabel {color: white;"
                               "font-size: 30px;"
                               "border: 2px solid black;"
                               "font-weight: bold;"
                               "background-color: rgba(0, 0, 0, 100);"
                               "opacity: 1;}");
        addWidget(costTLabel);

        QLabel* refundTLabel = new QLabel("Total expected refund: +" + QString::number(totRefund) + " €");
        refundTLabel->setGeometry(950, 900, 850, 150);
        refundTLabel->setStyleSheet("QLabel {color: white;"
                               "font-size: 30px;"
                               "border: 2px solid black;"
                               "font-weight: bold;"
                               "background-color: rgba(0, 0, 0, 100);"
                               "opacity: 1;}");
        addWidget(refundTLabel);

    }

}
