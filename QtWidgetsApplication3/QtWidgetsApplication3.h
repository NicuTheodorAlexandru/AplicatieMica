#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication3.h"
#include "ServiceVehicle.h"
#include "ServiceParkingLot.h"
#include <qboxlayout.h>
#include <QPushButton>
#include <QLabel>
#include <qlineedit.h>
#include <iostream>
#include "ServiceTicket.h"
#include "Utils.h"

class QtWidgetsApplication3 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication3(QWidget *parent = Q_NULLPTR);
    ServiceVehicle* serviceVehicle;
    ServiceParkingLot* serviceParkingLot;
    ServiceTicket* serviceTicket;
public slots:
    void on_buttonAddVehicleClicked(bool checked = false);
    void on_buttonAddParkingLotClicked(bool checked = false);
    void on_buttonAddTicketClicked(bool checked = false);
    void on_buttonIncomeClicked(bool checked = false);
private:
    void LayoutAddVehicle();
    void LayoutAddParkingLot();
    void LayoutAddTicket();
    void LayoutIncome();
    QHBoxLayout* layoutWindow;
    Ui::QtWidgetsApplication3Class ui;
    //
    QLineEdit* lineEditIncomeStartDate;
    QLineEdit* lineEditIncomeEndDate;
    QLineEdit* lineEditIncome;
    //
    QLineEdit* lineEditInaltime;
    QLineEdit* lineEditLatime;
    QLineEdit* lineEditNumarInmatriculare;
    QLineEdit* lineEditGreutate;
    QLineEdit* lineEditLungime;
    //
    QLineEdit* lineEditInaltimeMaxima;
    QLineEdit* lineEditLatimeMaxima;
    QLineEdit* lineEditLungimeMaxima;
    QLineEdit* lineEditGreutateMaxima;
    //
    QLineEdit* lineEditIdVehicul;
    QLineEdit* lineEditDataIntrare;
    QLineEdit* lineEditDataIesire;
    QLineEdit* lineEditCost;
};
