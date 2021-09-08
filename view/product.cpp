#include "product.h"

Product::Product() {
    setSceneRect(0, 0, 1900, 1080);
    Rental* rentLst = new Rental();
    loadBG();
    loadHomeBtn();
    loadProdPage(rentLst);
}

void Product::loadBG() {
    QBrush brush(QColor(66, 103, 178));
    setBackgroundBrush(brush);
}

void Product::loadHomeBtn() {
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

    connect(homeBtn, &QPushButton::clicked, this, &Product::openHome);
}

void Product::limitMessage() {
    QMessageBox* limit = new QMessageBox;
    limit->setText("You can only rent 5 vehicles at the same time.");
    limit->exec();
}

void Product::loadProdPage(Rental* rtl) {
    unsigned int fieldWidth = 250;
    unsigned int fieldHeight = 80;



    for(auto i = rtl->getBegin(); i != rtl->getEnd(); i++){
        if((*i)->getId() == targetId){
            QLabel* prodTitle = new QLabel((*i)->getName());
            prodTitle->setGeometry(100, 100, 500, 100);
            prodTitle->setStyleSheet("color: white;"
                                   "font-size: 40px;"
                                   "font-weight: bold;"
                                   "border: 5px solid black;"
                                   "background-color: rgba(0, 0, 0, 100);"
                                   "opacity: 1;");
            addWidget(prodTitle);


            QImage image(QDir::currentPath() + (*i)->getImgPath());
            QImage sImage = image.scaled(500, 375, Qt::KeepAspectRatio, Qt::SmoothTransformation);

            QLabel* img = new QLabel();
            img->setScaledContents(true);
            img->setPixmap(QPixmap::fromImage(sImage));
            img->setGeometry(100, 250, 500, 375);
            addWidget(img);


            QLabel* kmLabel = new QLabel("Km: " + QString::number((*i)->getKm()));
            kmLabel->setGeometry(450 + fieldWidth, 250, fieldWidth, fieldHeight);
            kmLabel->setStyleSheet("color: white;"
                                   "font-size: 20px;"
                                   "font-weight: bold;"
                                   "border: 2px solid black;"
                                   "background-color: rgba(0, 0, 0, 100);"
                                   "opacity: 1;");
            addWidget(kmLabel);

            QLabel* ratingLabel = new QLabel("Rating: " + QString::number((*i)->getRating()) + "/5");
            ratingLabel->setGeometry(450 + fieldWidth, 350, fieldWidth, fieldHeight);
            ratingLabel->setStyleSheet("color: white;"
                                   "font-size: 20px;"
                                   "font-weight: bold;"
                                   "border: 2px solid black;"
                                   "background-color: rgba(0, 0, 0, 100);"
                                   "opacity: 1;");
            addWidget(ratingLabel);

            QLabel* priceLabel = new QLabel("Daily Price: " + QString::number((*i)->getDailyPrice()) + " €/day");
            priceLabel->setGeometry(450 + fieldWidth, 450, fieldWidth, fieldHeight);
            priceLabel->setStyleSheet("color: white;"
                                   "font-size: 20px;"
                                   "font-weight: bold;"
                                   "border: 2px solid black;"
                                   "background-color: rgba(0, 0, 0, 100);"
                                   "opacity: 1;");
            addWidget(priceLabel);


            QCheckBox* extraInsuranceCB = new QCheckBox("Extra Insurance");
            extraInsuranceCB->setGeometry(500 + fieldWidth*2, 250, fieldWidth*2, fieldHeight);
            extraInsuranceCB->setStyleSheet("color: white;"
                                   "font-size: 20px;"
                                   "font-weight: bold;"
                                   "border: 2px solid black;"
                                   "background-color: rgba(0, 0, 0, 100);"
                                   "opacity: 1;");
            addWidget(extraInsuranceCB);


            QLabel* rentTimeLabel = new QLabel("Rent days: ");
                    rentTimeLabel->setGeometry(500 + fieldWidth*2, 350, fieldWidth, fieldHeight);
                    rentTimeLabel->setStyleSheet("color: white;"
                                               "font-size: 20px;"
                                               "font-weight: bold;"
                                               "border: 2px solid black;"
                                               "background-color: rgba(0, 0, 0, 100);"
                                               "opacity: 1;");
            addWidget(rentTimeLabel);


            QSpinBox* rentTimeSB = new QSpinBox();
            rentTimeSB->setGeometry(500 + fieldWidth*3, 350, fieldWidth, fieldHeight);
            rentTimeSB->setStyleSheet("font-size: 20px;"
                                   "border: 2px solid black;"
                                   "opacity: 1;");
            rentTimeSB->setMinimum(1);
            rentTimeSB->setMaximum(15);
            addWidget(rentTimeSB);


            // IF SHOWROOM VEHICLE
            ShowroomVehicle* srv = dynamic_cast<ShowroomVehicle*>(i->get());

            if(srv){
                QLabel* showNameLabel = new QLabel("Show Name: ");
                        showNameLabel->setGeometry(500 + fieldWidth*2, 450, fieldWidth, fieldHeight);
                        showNameLabel->setStyleSheet("color: white;"
                                                   "font-size: 20px;"
                                                   "font-weight: bold;"
                                                   "border: 2px solid black;"
                                                   "background-color: rgba(0, 0, 0, 100);"
                                                   "opacity: 1;");
                addWidget(showNameLabel);


                QLineEdit* showNameLE = new QLineEdit();
                showNameLE->setGeometry(500 + fieldWidth*3, 450, fieldWidth, fieldHeight);
                showNameLE->setStyleSheet( "font-size: 20px;"
                                           "border: 2px solid black;"
                                           "opacity: 1;");
                showNameLE->setMaxLength(10);
                addWidget(showNameLE);


                QCheckBox* rentRoomCB = new QCheckBox("Rent a Room");
                rentRoomCB->setGeometry(500 + fieldWidth*2, 550, fieldWidth*2, fieldHeight);
                rentRoomCB->setStyleSheet("color: white;"
                                       "font-size: 20px;"
                                       "font-weight: bold;"
                                       "border: 2px solid black;"
                                       "background-color: rgba(0, 0, 0, 100);"
                                       "opacity: 1;");
                addWidget(rentRoomCB);


                QLabel* specNLabel = new QLabel("Number of Spectators: ");
                        specNLabel->setGeometry(500 + fieldWidth*2, 650, fieldWidth, fieldHeight);
                        specNLabel->setStyleSheet("color: white;"
                                                   "font-size: 20px;"
                                                   "font-weight: bold;"
                                                   "border: 2px solid black;"
                                                   "background-color: rgba(0, 0, 0, 100);"
                                                   "opacity: 1;");
                addWidget(specNLabel);


                QSpinBox* specNSB = new QSpinBox();
                specNSB->setGeometry(500 + fieldWidth*3, 650, fieldWidth, fieldHeight);
                specNSB->setStyleSheet("font-size: 20px;"
                                       "border: 2px solid black;"
                                       "opacity: 1;");
                addWidget(specNSB);

                QCheckBox* securityCB = new QCheckBox("Hire security");
                securityCB->setGeometry(500 + fieldWidth*2, 750, fieldWidth*2, fieldHeight);
                securityCB->setStyleSheet("color: white;"
                                           "font-size: 20px;"
                                           "font-weight: bold;"
                                           "border: 2px solid black;"
                                           "background-color: rgba(0, 0, 0, 100);"
                                           "opacity: 1;");
                addWidget(securityCB);



                QPushButton* rentBtn = new QPushButton("Rent");
                rentBtn->setGeometry(720 + fieldWidth*2, 850, 280, 50);
                rentBtn->setStyleSheet("QPushButton {color: white;"
                                       "font-size: 16px;"
                                       "font-weight: bold;"
                                       "background-color: rgba(0, 0, 0, 100);"
                                       "opacity: 1;}"
                                       "QPushButton:hover {"
                                       "background-color: rgba(150, 150, 150, 50);}");
                addWidget(rentBtn);

                if(myLst->size() < 5){
                    ShowroomVehicle* objClone = srv->clone();
                    connect(rentBtn, &QPushButton::clicked, this, [=](){emit
                        objClone->setExtraInsurance(extraInsuranceCB->isChecked());
                        objClone->setShowName(showNameLE->text());
                        objClone->setRentRoom(rentRoomCB->isChecked());
                        objClone->setSpecN(specNSB->value());
                        objClone->setShowSec(securityCB->isChecked());
                        objClone->setRentTime(rentTimeSB->value());
                        myLst->push_back(objClone);
                        Product::openHome();
                    });
                }

                else{
                    connect(rentBtn, &QPushButton::clicked, this, [=](){emit limitMessage();});
                }

            }

            //IF CAR
            Car* cv = dynamic_cast<Car*>(i->get());

            if(cv){

                QLabel* roadFeeLabel = new QLabel("Road Fee: " + QString::number(cv->getRoadFee()) + " €");
                roadFeeLabel->setGeometry(450 + fieldWidth, 550, fieldWidth, fieldHeight);
                roadFeeLabel->setStyleSheet("color: white;"
                                       "font-size: 20px;"
                                       "font-weight: bold;"
                                       "border: 2px solid black;"
                                       "background-color: rgba(0, 0, 0, 100);"
                                       "opacity: 1;");
                addWidget(roadFeeLabel);

                QLabel* passengerNLabel = new QLabel("No. of passengers: ");
                        passengerNLabel->setGeometry(500 + fieldWidth*2, 450, fieldWidth, fieldHeight);
                        passengerNLabel->setStyleSheet("color: white;"
                                                   "font-size: 20px;"
                                                   "font-weight: bold;"
                                                   "border: 2px solid black;"
                                                   "background-color: rgba(0, 0, 0, 100);"
                                                   "opacity: 1;");
                addWidget(passengerNLabel);


                QSpinBox* passengerNSB = new QSpinBox();
                passengerNSB->setGeometry(500 + fieldWidth*3, 450, fieldWidth, fieldHeight);
                passengerNSB->setStyleSheet("font-size: 20px;"
                                       "border: 2px solid black;"
                                       "opacity: 1;");
                passengerNSB->setMinimum(1);
                passengerNSB->setMaximum(2);
                addWidget(passengerNSB);


                QCheckBox* highwayPassCB = new QCheckBox("Highway Pass");
                highwayPassCB->setGeometry(500 + fieldWidth*2, 550, fieldWidth*2, fieldHeight);
                highwayPassCB->setStyleSheet("color: white;"
                                       "font-size: 20px;"
                                       "font-weight: bold;"
                                       "border: 2px solid black;"
                                       "background-color: rgba(0, 0, 0, 100);"
                                       "opacity: 1;");
                addWidget(highwayPassCB);


                QCheckBox* acCB = new QCheckBox("Air Conditioning");
                acCB->setGeometry(500 + fieldWidth*2, 650, fieldWidth*2, fieldHeight);
                acCB->setStyleSheet("color: white;"
                                       "font-size: 20px;"
                                       "font-weight: bold;"
                                       "border: 2px solid black;"
                                       "background-color: rgba(0, 0, 0, 100);"
                                       "opacity: 1;");
                addWidget(acCB);

                QCheckBox* autoWindCB = new QCheckBox("Automatic Windows");
                autoWindCB->setGeometry(500 + fieldWidth*2, 750, fieldWidth*2, fieldHeight);
                autoWindCB->setStyleSheet("color: white;"
                                       "font-size: 20px;"
                                       "font-weight: bold;"
                                       "border: 2px solid black;"
                                       "background-color: rgba(0, 0, 0, 100);"
                                       "opacity: 1;");
                addWidget(autoWindCB);

                QCheckBox* gpsCB = new QCheckBox("GPS");
                gpsCB->setGeometry(500 + fieldWidth*2, 850, fieldWidth*2, fieldHeight);
                gpsCB->setStyleSheet("color: white;"
                                       "font-size: 20px;"
                                       "font-weight: bold;"
                                       "border: 2px solid black;"
                                       "background-color: rgba(0, 0, 0, 100);"
                                       "opacity: 1;");
                addWidget(gpsCB);

                QPushButton* rentBtn = new QPushButton("Rent");
                rentBtn->setGeometry(720 + fieldWidth*2, 950, 280, 50);
                rentBtn->setStyleSheet("QPushButton {color: white;"
                                       "font-size: 16px;"
                                       "font-weight: bold;"
                                       "background-color: rgba(0, 0, 0, 100);"
                                       "opacity: 1;}"
                                       "QPushButton:hover {"
                                       "background-color: rgba(150, 150, 150, 50);}");
                addWidget(rentBtn);

                if(myLst->size() < 5){
                    Car* objClone = cv->clone();
                    connect(rentBtn, &QPushButton::clicked, this, [=](){emit
                        objClone->setExtraInsurance(extraInsuranceCB->isChecked());
                        objClone->setPassengerN(passengerNSB->value());
                        objClone->setHighwayPass(highwayPassCB->isChecked());
                        objClone->setAc(acCB->isChecked());
                        objClone->setAutoWind(autoWindCB->isChecked());
                        objClone->setGps(gpsCB->isChecked());
                        objClone->setRentTime(rentTimeSB->value());
                        myLst->push_back(objClone);
                        Product::openHome();
                    });
                }
                else{
                    connect(rentBtn, &QPushButton::clicked, this, [=](){emit limitMessage();});
                }
            }


            //IF RMOTORCYCLE
            RMotorcycle* rmv = dynamic_cast<RMotorcycle*>(i->get());

            if(rmv){

                QLabel* roadFeeLabel = new QLabel("Road Fee: " + QString::number(rmv->getRoadFee()) + " €");
                roadFeeLabel->setGeometry(450 + fieldWidth, 550, fieldWidth, fieldHeight);
                roadFeeLabel->setStyleSheet("color: white;"
                                       "font-size: 20px;"
                                       "font-weight: bold;"
                                       "border: 2px solid black;"
                                       "background-color: rgba(0, 0, 0, 100);"
                                       "opacity: 1;");
                addWidget(roadFeeLabel);

                QLabel* passengerNLabel = new QLabel("No. of passengers: ");
                        passengerNLabel->setGeometry(500 + fieldWidth*2, 450, fieldWidth, fieldHeight);
                        passengerNLabel->setStyleSheet("color: white;"
                                                   "font-size: 20px;"
                                                   "font-weight: bold;"
                                                   "border: 2px solid black;"
                                                   "background-color: rgba(0, 0, 0, 100);"
                                                   "opacity: 1;");
                addWidget(passengerNLabel);


                QSpinBox* passengerNSB = new QSpinBox();
                passengerNSB->setGeometry(500 + fieldWidth*3, 450, fieldWidth, fieldHeight);
                passengerNSB->setStyleSheet("font-size: 20px;"
                                       "border: 2px solid black;"
                                       "opacity: 1;");
                passengerNSB->setMinimum(1);
                passengerNSB->setMaximum(4);
                addWidget(passengerNSB);


                QCheckBox* highwayPassCB = new QCheckBox("Highway Pass");
                highwayPassCB->setGeometry(500 + fieldWidth*2, 550, fieldWidth*2, fieldHeight);
                highwayPassCB->setStyleSheet("color: white;"
                                       "font-size: 20px;"
                                       "font-weight: bold;"
                                       "border: 2px solid black;"
                                       "background-color: rgba(0, 0, 0, 100);"
                                       "opacity: 1;");
                addWidget(highwayPassCB);


                QLabel* nStatesLabel = new QLabel("States to travel: ");
                        nStatesLabel->setGeometry(500 + fieldWidth*2, 650, fieldWidth, fieldHeight);
                        nStatesLabel->setStyleSheet("color: white;"
                                                   "font-size: 20px;"
                                                   "font-weight: bold;"
                                                   "border: 2px solid black;"
                                                   "background-color: rgba(0, 0, 0, 100);"
                                                   "opacity: 1;");
                addWidget(nStatesLabel);


                QSpinBox* nStatesSB = new QSpinBox();
                nStatesSB->setGeometry(500 + fieldWidth*3, 650, fieldWidth, fieldHeight);
                nStatesSB->setStyleSheet("font-size: 20px;"
                                       "border: 2px solid black;"
                                       "opacity: 1;");
                nStatesSB->setMaximum(10);
                addWidget(nStatesSB);

                QPushButton* rentBtn = new QPushButton("Rent");
                rentBtn->setGeometry(720 + fieldWidth*2, 750, 280, 50);
                rentBtn->setStyleSheet("QPushButton {color: white;"
                                       "font-size: 16px;"
                                       "font-weight: bold;"
                                       "background-color: rgba(0, 0, 0, 100);"
                                       "opacity: 1;}"
                                       "QPushButton:hover {"
                                       "background-color: rgba(150, 150, 150, 50);}");
                addWidget(rentBtn);

                if(myLst->size() < 5){
                    RMotorcycle* objClone = rmv->clone();
                    connect(rentBtn, &QPushButton::clicked, this, [=](){emit
                        objClone->setExtraInsurance(extraInsuranceCB->isChecked());
                        objClone->setNStates(nStatesSB->value());
                        objClone->setRentTime(rentTimeSB->value());
                        myLst->push_back(objClone);
                        Product::openHome();
                    });
                }

                else{
                    connect(rentBtn, &QPushButton::clicked, this, [=](){emit limitMessage();});
                }
            }


            //IF ORMOTORCYCLE
            ORMotorcycle* ormv = dynamic_cast<ORMotorcycle*>(i->get());

            if(ormv){

                QLabel* trackCreditsLabel = new QLabel("Track Credits: ");
                        trackCreditsLabel->setGeometry(500 + fieldWidth*2, 450, fieldWidth, fieldHeight);
                        trackCreditsLabel->setStyleSheet("color: white;"
                                                   "font-size: 20px;"
                                                   "font-weight: bold;"
                                                   "border: 2px solid black;"
                                                   "background-color: rgba(0, 0, 0, 100);"
                                                   "opacity: 1;");
                addWidget(trackCreditsLabel);


                QSpinBox* trackCreditsSB = new QSpinBox();
                trackCreditsSB->setGeometry(500 + fieldWidth*3, 450, fieldWidth, fieldHeight);
                trackCreditsSB->setStyleSheet("font-size: 20px;"
                                       "border: 2px solid black;"
                                       "opacity: 1;");
                trackCreditsSB->setMaximum(10);
                addWidget(trackCreditsSB);

                QCheckBox* prevInjCB = new QCheckBox("Previous Injuries");
                prevInjCB->setGeometry(500 + fieldWidth*2, 550, fieldWidth*2, fieldHeight);
                prevInjCB->setStyleSheet("color: white;"
                                       "font-size: 20px;"
                                       "font-weight: bold;"
                                       "border: 2px solid black;"
                                       "background-color: rgba(0, 0, 0, 100);"
                                       "opacity: 1;");
                addWidget(prevInjCB);

                QLabel* raceNameLabel = new QLabel("Race Name: ");
                        raceNameLabel->setGeometry(500 + fieldWidth*2, 650, fieldWidth, fieldHeight);
                        raceNameLabel->setStyleSheet("color: white;"
                                                   "font-size: 20px;"
                                                   "font-weight: bold;"
                                                   "border: 2px solid black;"
                                                   "background-color: rgba(0, 0, 0, 100);"
                                                   "opacity: 1;");
                addWidget(raceNameLabel);


                QLineEdit* raceNameLE = new QLineEdit();
                raceNameLE->setGeometry(500 + fieldWidth*3, 650, fieldWidth, fieldHeight);
                raceNameLE->setStyleSheet( "font-size: 20px;"
                                           "border: 2px solid black;"
                                           "opacity: 1;");
                raceNameLE->setMaxLength(10);
                addWidget(raceNameLE);

                QPushButton* rentBtn = new QPushButton("Rent");
                rentBtn->setGeometry(720 + fieldWidth*2, 750, 280, 50);
                rentBtn->setStyleSheet("QPushButton {color: white;"
                                       "font-size: 16px;"
                                       "font-weight: bold;"
                                       "background-color: rgba(0, 0, 0, 100);"
                                       "opacity: 1;}"
                                       "QPushButton:hover {"
                                       "background-color: rgba(150, 150, 150, 50);}");
                addWidget(rentBtn);

                if(myLst->size() < 5){
                    ORMotorcycle* objClone = ormv->clone();
                    connect(rentBtn, &QPushButton::clicked, this, [=](){emit
                        objClone->setExtraInsurance(extraInsuranceCB->isChecked());
                        objClone->setTrackCredits(trackCreditsSB->value());
                        objClone->setPrevInjuries(prevInjCB->isChecked());
                        objClone->setRaceName(raceNameLE->text());
                        objClone->setRentTime(rentTimeSB->value());
                        myLst->push_back(objClone);
                        Product::openHome();
                    });
                }

                else{
                    connect(rentBtn, &QPushButton::clicked, this, [=](){emit limitMessage();});
                }

            }

            //IF ATV
            Atv* atv = dynamic_cast<Atv*>(i->get());

            if(atv){

                QLabel* trackCreditsLabel = new QLabel("Track Credits: ");
                        trackCreditsLabel->setGeometry(500 + fieldWidth*2, 450, fieldWidth, fieldHeight);
                        trackCreditsLabel->setStyleSheet("color: white;"
                                                   "font-size: 20px;"
                                                   "font-weight: bold;"
                                                   "border: 2px solid black;"
                                                   "background-color: rgba(0, 0, 0, 100);"
                                                   "opacity: 1;");
                addWidget(trackCreditsLabel);


                QSpinBox* trackCreditsSB = new QSpinBox();
                trackCreditsSB->setGeometry(500 + fieldWidth*3, 450, fieldWidth, fieldHeight);
                trackCreditsSB->setStyleSheet("font-size: 20px;"
                                       "border: 2px solid black;"
                                       "opacity: 1;");
                trackCreditsSB->setMaximum(10);
                addWidget(trackCreditsSB);

                QCheckBox* cleanServCB = new QCheckBox("Cleaning Service");
                cleanServCB->setGeometry(500 + fieldWidth*2, 550, fieldWidth*2, fieldHeight);
                cleanServCB->setStyleSheet("color: white;"
                                       "font-size: 20px;"
                                       "font-weight: bold;"
                                       "border: 2px solid black;"
                                       "background-color: rgba(0, 0, 0, 100);"
                                       "opacity: 1;");
                addWidget(cleanServCB);

                QCheckBox* changeTiresCB = new QCheckBox("Tires Change");
                changeTiresCB->setGeometry(500 + fieldWidth*2, 650, fieldWidth*2, fieldHeight);
                changeTiresCB->setStyleSheet("color: white;"
                                       "font-size: 20px;"
                                       "font-weight: bold;"
                                       "border: 2px solid black;"
                                       "background-color: rgba(0, 0, 0, 100);"
                                       "opacity: 1;");
                addWidget(changeTiresCB);

                QPushButton* rentBtn = new QPushButton("Rent");
                rentBtn->setGeometry(720 + fieldWidth*2, 750, 280, 50);
                rentBtn->setStyleSheet("QPushButton {color: white;"
                                       "font-size: 16px;"
                                       "font-weight: bold;"
                                       "background-color: rgba(0, 0, 0, 100);"
                                       "opacity: 1;}"
                                       "QPushButton:hover {"
                                       "background-color: rgba(150, 150, 150, 50);}");
                addWidget(rentBtn);

                if(myLst->size() < 5){
                    Atv* objClone = atv->clone();
                    connect(rentBtn, &QPushButton::clicked, this, [=](){emit
                        objClone->setExtraInsurance(extraInsuranceCB->isChecked());
                        objClone->setTrackCredits(trackCreditsSB->value());
                        objClone->setCleaningServ(cleanServCB->isChecked());
                        objClone->setChangeTires(changeTiresCB->isChecked());
                        objClone->setRentTime(rentTimeSB->value());
                        myLst->push_back(objClone);
                        Product::openHome();
                    });
                }

                else{
                    connect(rentBtn, &QPushButton::clicked, this, [=](){emit limitMessage();});
                }

            }
        }
    }
}
