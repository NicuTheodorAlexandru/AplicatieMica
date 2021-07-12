#include "QtWidgetsApplication3.h"

void QtWidgetsApplication3::LayoutIncome()
{
    QVBoxLayout* layout = new QVBoxLayout();
    layoutWindow->addLayout(layout);
    //
    QLabel* labelStartDate = new QLabel("Data inceput");
    layout->addWidget(labelStartDate);
    lineEditIncomeStartDate = new QLineEdit();
    layout->addWidget(lineEditIncomeStartDate);
    //
    QLabel* labelEndDate = new QLabel("Data final");
    layout->addWidget(labelEndDate);
    lineEditIncomeEndDate = new QLineEdit();
    layout->addWidget(lineEditIncomeEndDate);
    //
    QLabel* labelIncome = new QLabel("Venit");
    layout->addWidget(labelIncome);
    lineEditIncome = new QLineEdit();
    layout->addWidget(lineEditIncome);
    //
    QPushButton* buttonIncome = new QPushButton("Genereaza venit");
    connect(buttonIncome, SIGNAL(clicked(bool)), this, SLOT(on_buttonIncomeClicked()));
    layout->addWidget(buttonIncome);
}

void QtWidgetsApplication3::LayoutAddTicket()
{
    //
    QVBoxLayout* LayoutAddTicket = new QVBoxLayout();
    layoutWindow->addLayout(LayoutAddTicket);
    //
    QLabel* labelIdVehicul = new QLabel("Id Vehicul");
    LayoutAddTicket->addWidget(labelIdVehicul);
    lineEditIdVehicul = new QLineEdit();
    LayoutAddTicket->addWidget(lineEditIdVehicul);
    //
    QLabel* labelDataIntrare = new QLabel("Data Intrare");
    LayoutAddTicket->addWidget(labelDataIntrare);
    lineEditDataIntrare = new QLineEdit();
    LayoutAddTicket->addWidget(lineEditDataIntrare);
    //
    QLabel* labelDataIesire = new QLabel("Data Iesire");
    LayoutAddTicket->addWidget(labelDataIesire);
    lineEditDataIesire = new QLineEdit();
    LayoutAddTicket->addWidget(lineEditDataIesire);
    //
    QLabel* labelCost = new QLabel("Cost");
    LayoutAddTicket->addWidget(labelCost);
    lineEditCost = new QLineEdit();
    LayoutAddTicket->addWidget(lineEditCost);
    //
    QPushButton* buttonAddTicket = new QPushButton("Adauga tichet");
    connect(buttonAddTicket, SIGNAL(clicked(bool)), this, SLOT(on_buttonAddTicketClicked()));
    LayoutAddTicket->addWidget(buttonAddTicket);
}

void QtWidgetsApplication3::LayoutAddParkingLot()
{
    QVBoxLayout* LayoutAddParkingLot = new QVBoxLayout();
    layoutWindow->addLayout(LayoutAddParkingLot);
    //
    QLabel* labelInaltimeMaxima = new QLabel("Inaltime Maxima");
    LayoutAddParkingLot->addWidget(labelInaltimeMaxima);
    lineEditInaltimeMaxima = new QLineEdit();
    LayoutAddParkingLot->addWidget(lineEditInaltimeMaxima);
    //
    QLabel* labelLatimeMaxima = new QLabel("Latime Maxima");
    LayoutAddParkingLot->addWidget(labelLatimeMaxima);
    lineEditLatimeMaxima = new QLineEdit();
    LayoutAddParkingLot->addWidget(lineEditLatimeMaxima);
    //
    QLabel* labelLungimeMaxima = new QLabel("Lungime Maxima");
    LayoutAddParkingLot->addWidget(labelLungimeMaxima);
    lineEditLungimeMaxima = new QLineEdit();
    LayoutAddParkingLot->addWidget(lineEditLungimeMaxima);
    //
    QLabel* labelGreutateMaxima = new QLabel("Greutate Maxima");
    LayoutAddParkingLot->addWidget(labelGreutateMaxima);
    lineEditGreutateMaxima = new QLineEdit();
    LayoutAddParkingLot->addWidget(lineEditGreutateMaxima);
    //
    QPushButton* buttonAddParkingLot = new QPushButton("Adauga lot parcare");
    connect(buttonAddParkingLot, SIGNAL(clicked(bool)), this, SLOT(on_buttonAddParkingLotClicked()));
    LayoutAddParkingLot->addWidget(buttonAddParkingLot);
}

void QtWidgetsApplication3::LayoutAddVehicle()
{
    QVBoxLayout* layoutAddVehicle = new QVBoxLayout();
    layoutWindow->addLayout(layoutAddVehicle);
    QLabel* labelNumarInmatriculare = new QLabel("NumarInmatriculare");
    layoutAddVehicle->addWidget(labelNumarInmatriculare);
    lineEditNumarInmatriculare = new QLineEdit();
    layoutAddVehicle->addWidget(lineEditNumarInmatriculare);
    //
    QLabel* labelInaltime = new QLabel("Inaltime");
    layoutAddVehicle->addWidget(labelInaltime);
    lineEditInaltime = new QLineEdit();
    layoutAddVehicle->addWidget(lineEditInaltime);
    //
    QLabel* labelLatime = new QLabel("Latime");
    layoutAddVehicle->addWidget(labelLatime);
    lineEditLatime = new QLineEdit();
    layoutAddVehicle->addWidget(lineEditLatime);
    //
    QLabel* labelLungime = new QLabel("Lungime");
    layoutAddVehicle->addWidget(labelLungime);
    lineEditLungime = new QLineEdit();
    layoutAddVehicle->addWidget(lineEditLungime);
    //
    QLabel* labelGreutate = new QLabel("Greutate");
    layoutAddVehicle->addWidget(labelGreutate);
    lineEditGreutate = new QLineEdit();
    layoutAddVehicle->addWidget(lineEditGreutate);
    //
    QPushButton* buttonAddVehicle = new QPushButton("Adauga vehicul");
    connect(buttonAddVehicle, SIGNAL(clicked(bool)), this, SLOT(on_buttonAddVehicleClicked()));
    layoutAddVehicle->addWidget(buttonAddVehicle);
}

void QtWidgetsApplication3::on_buttonIncomeClicked(bool checked)
{
    DateTime* start = Utils::ModelFromString<DateTime>(lineEditIncomeStartDate->text().toStdString());
    DateTime* end = Utils::ModelFromString<DateTime>(lineEditIncomeEndDate->text().toStdString());
    lineEditIncome->setText(QString(std::to_string(serviceTicket->Income(start, end)).c_str()));
    delete start;
    delete end;
}

void QtWidgetsApplication3::on_buttonAddTicketClicked(bool checked)
{
    unsigned int vehicleId = std::stoul(lineEditIdVehicul->text().toStdString());
    unsigned int lotId = serviceParkingLot->GetBestParkingLot(serviceVehicle->GetVehicleById(vehicleId));
    DateTime* entryTime = Utils::ModelFromString<DateTime>(lineEditDataIntrare->text().toStdString());
    DateTime* leaveTime = Utils::ModelFromString<DateTime>(lineEditDataIesire->text().toStdString());
    float cost = std::stof(lineEditCost->text().toStdString());
    serviceTicket->AddTicket(vehicleId, lotId, entryTime, leaveTime, cost);
}

void QtWidgetsApplication3::on_buttonAddParkingLotClicked(bool checked)
{
    float height = std::stof(lineEditInaltimeMaxima->text().toStdString());
    float width = std::stof(lineEditLatimeMaxima->text().toStdString());
    float length = std::stof(lineEditLungimeMaxima->text().toStdString());
    unsigned int weight = std::stof(lineEditGreutateMaxima->text().toStdString());
    serviceParkingLot->AddParkingLot(height, width, length, weight);
}

void QtWidgetsApplication3::on_buttonAddVehicleClicked(bool checked)
{
    std::string num = lineEditNumarInmatriculare->text().toStdString();
    float height = std::stof(lineEditInaltime->text().toStdString());
    float width = std::stof(lineEditLatime->text().toStdString());
    float length = std::stof(lineEditLungime->text().toStdString());
    unsigned int weight = std::stof(lineEditGreutate->text().toStdString());
    serviceVehicle->AddVehicle(num, height, width, length, weight);
}

QtWidgetsApplication3::QtWidgetsApplication3(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    layoutWindow = new QHBoxLayout();
    //QPushButton* button = new QPushButton("Add another Button");
    //QObject::connect(button, SIGNAL(clicked()), this, SLOT(on_buttonClick()));
    //layout->addWidget(button);
    // add vehicle
    //
    LayoutAddVehicle();
    LayoutAddParkingLot();
    LayoutAddTicket();
    LayoutIncome();
    QWidget* window = new QWidget();
    window->setLayout(layoutWindow);
    setCentralWidget(window);
}