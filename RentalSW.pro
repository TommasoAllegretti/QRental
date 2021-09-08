#-------------------------------------------------
#
# Project created by QtCreator 2021-08-19T11:58:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RentalSW
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        view/mainwindow.cpp \
    model/offroadvehicle.cpp \
    model/rentalobject.cpp \
    model/roadvehicle.cpp \
    model/showroomvehicle.cpp \
    model/ormotorcycle.cpp \
    model/rmotorcycle.cpp \
    model/car.cpp \
    model/atv.cpp \
    view/mainwindowview.cpp \
    controller/controller.cpp \
    controller/homecontroller.cpp \
    view/home.cpp \
    model/rental.cpp \
    controller/productcontroller.cpp \
    view/product.cpp \
    controller/myrentscontroller.cpp \
    view/myrents.cpp \
    globals/globals.cpp

HEADERS += \
        view/mainwindow.h \
    model/deepptr.h \
    model/offroadvehicle.h \
    model/rentalobject.h \
    model/roadvehicle.h \
    model/showroomvehicle.h \
    model/container.h \
    model/ormotorcycle.h \
    model/rmotorcycle.h \
    model/car.h \
    model/atv.h \
    routes/routes.h \
    view/mainwindowview.h \
    controller/controller.h \
    controller/homecontroller.h \
    view/home.h \
    model/rental.h \
    controller/productcontroller.h \
    view/product.h \
    controller/myrentscontroller.h \
    view/myrents.h \
    globals/globals.h
