# Introducere
Scurt proiect pentru practica. Aplicatia este incompleta, nu are CRUD terminat pe partea de ui/service, nu are validare si nici exception handling si sunt sigur ca mai are bug-uri.
## Models
### DateTime
Container pentru data si timp; are comparatori definiti, la fel si conversia la std::string. Formatul este urmatorul:
* Y1234 - anul 1234
* m12 - luna 12
* D10 - ziua 10
* H13 - ora 13
* M50 - minutul 50
Ordinea lor nu conteaza(netestat)
### ParkingLot
Contine limite pentru greutate, inaltime, lungime si latime, reprezentand un loc de parcare si daca este ocupat sau nu. Are definita conversa la std::string.
### Ticket
Reprezinta un tichet de parcare, avand data intrare, data iesire, cost, id-ul lotului si vehiculului. Se poate accesa costul(read-only), daca este intre 2 dati si are conversia la std::string definita.
### Vehicle
Reprezinta un vehicul avand numar de inmatriculare, inaltime, lungime, latime si greutate. I se pot accesa toate datele(read-only) si poate fi convertit la std::string.
## Repo
### Repository
Este o clasa folosita pentru a memora, salva si incarca date. Primeste un filename(pentru stocare) si poate avea ca tip orice clasa care poate fi convertita la std::string fiind facuta cu template. Foloseste o harta care contine un pointer la element si un id folosit la stocare si pentru cautarea obiectelor. Are functiile CRUD definite si i se poate accesa iteratorul(inceput si sfarsit). Permite si cautarea unui element dupa id sau invers. La instantiere umple map-ul cu date din filename. La distrugere le salveaza.
## Utils
### IdGenerator
Genereaza un id random, poate fi accesat de oriunde(public static).
### Utils
 E folosita la a converti de la std::string la oricare dintre clasele de la model. Formatul trebuie sa fie acelasi ca de la conversia de la model la std::string. E construita folosind template si trebuie specificata clasa. Poate fi accesata de oriunde(public static).
## Service
### ServiceParkingLot 
Ia ca parametru un repo<ParkingLot>*. Permite adaugarea unui loc de parcare(luand parametri necesari, nu obiect). Permite si cautarea celui mai bun loc de parcare in functie de vehicul(returneaza un scor, -1 e eroare, scor mai mic = mai bun).
### ServiceTicket
Ia ca parametru un repo<Ticket>*. Permite adaugarea unui tichet(luand parametri necesari, nu obiect). Permite returnarea venitului intre 2 DateTime.
### ServiceVehicle
Ia ca parametru un repo<Vehicle>*. Permite adaugarea unui tichet(luand parametri necesari, nu obiect). Permite cautarea unui Vehicle dupa id.