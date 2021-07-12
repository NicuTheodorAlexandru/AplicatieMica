#include "QtWidgetsApplication3.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Vehicle.h"
#include "ServiceVehicle.h"
#include "ParkingLot.h"
#include "Ticket.h"
#include "ServiceTicket.h"
#include <random>

int main(int argc, char* argv[])
{
    srand(time(NULL));
    std::string fileVehicles = "vehicles.csv";
    std::string fileTickets = "tickets.csv";
    std::string fileParkingLot = "parking_lot.csv";
    Repository<Vehicle>* repoVehicle = new Repository<Vehicle>{ fileVehicles };
    Repository<ParkingLot>* repoParkingLot = new Repository<ParkingLot>{ fileParkingLot };
    Repository<Ticket>* repoTicket = new Repository<Ticket>{ fileTickets };
    ServiceVehicle* serviceVehicle = new ServiceVehicle{ repoVehicle };
    ServiceParkingLot* serviceParkingLot = new ServiceParkingLot{ repoParkingLot };
    ServiceTicket* serviceTicket = new ServiceTicket{ repoTicket };
    QApplication a(argc, argv);
    QtWidgetsApplication3 w;
    w.serviceVehicle = serviceVehicle;
    w.serviceParkingLot = serviceParkingLot;
    w.serviceTicket = serviceTicket;
    w.show();
    int res = a.exec();
    delete serviceVehicle;
    delete serviceParkingLot;
    delete serviceTicket;
    return res;
}
