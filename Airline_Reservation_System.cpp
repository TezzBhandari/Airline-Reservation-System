#include <iostream>
#include <iomanip>
#include <windows.h>
#include <limits>
using namespace std;

//Data type for passenger details;
struct passengerNode {
    string flightNumber;
    int ticketNumber;
    string pid;
    string fname;
    string lname;
    int age;
    string email;
    long long phoneNumber;
    string from;
    string destination;
    passengerNode* next;
};


// class for passenger data structure;
class ARS {
private:
    passengerNode* head = NULL;
    passengerNode* tail = NULL;
    int total_seats = 25;
    int seatTaken = 0;
    int TNo = 15001;


public:
    void insertPassenger(string pid, string fname, string lname, int age, string email, long long phoneNumber, string flightNumber, string from, string destination) {
        if (seatTaken >= total_seats) {
            cout << "The flight is full!" <<  endl;
            return;
        }

        passengerNode* passenger = new passengerNode();
        passenger->ticketNumber = TNo;
        TNo++;
        passenger->flightNumber = flightNumber;
        passenger->pid = pid;
        passenger->fname = fname;
        passenger->lname = lname;
        passenger->age = age;
        passenger->email = email;
        passenger->phoneNumber = phoneNumber;
        passenger->from = from;
        passenger->destination = destination;
        seatTaken++;

        // if the list is empty;
        if (head == NULL && tail == NULL) {
            head = passenger;
            tail = passenger;
            cout << "\nFlight Booked\nDetails:\n" << endl;
            cout << "  Ticket Number" << setw(17) << "Flight Number" << setw(15) << "ID Number" << setw(16) << "Name" << setw(16) << "Age" << setw(18) <<  "email" << setw(23) << "From" << setw(23) << "Destination" << setw(16) <<  setw(19) << "Phone Number" << endl;
            cout << " ------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "     " << passenger->ticketNumber << setw(18) << passenger->flightNumber << setw(18) << passenger->pid << setw(13) << passenger->fname << " " << passenger->lname << setw(10) << passenger->age << "\t\t" << passenger->email << setw(16) << passenger->from << setw(18) << passenger->destination << setw(22) << passenger->phoneNumber << endl;
            return;
        }

        //if the list is not empty;
        tail->next = passenger;
        tail = passenger;
        cout << "\nFlight Booked\nDetails:\n" << endl;
        cout << "  Ticket Number" << setw(17) << "Flight Number" << setw(15) << "ID Number" << setw(16) << "Name" << setw(16) << "Age" << setw(18) <<  "email" << setw(23) << "From" << setw(23) << "Destination" << setw(16) <<  setw(19) << "Phone Number" << endl;
        cout << " ------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "     " << passenger->ticketNumber << setw(18) << passenger->flightNumber << setw(18) << passenger->pid << setw(13) << passenger->fname << " " << passenger->lname << setw(10) << passenger->age << "\t\t" << passenger->email << setw(16) << passenger->from << setw(18) << passenger->destination << setw(22) << passenger->phoneNumber << endl;
    }

    // Used for canceling flights;
    void deletePassenger(string flightNumber, string pid) {
        if (head == NULL && tail == NULL) {
            cout << "There is no such passenger in the flight!" << endl;
            return;
        }

        if (head == tail && head->flightNumber == flightNumber && head->pid == pid) {
            cout << "The flight of " << head->fname << " " << head->lname << " is canceled." << endl;
            head = NULL;
            tail = NULL;
            seatTaken--;
            return;
        }

        passengerNode* temp = head;

        if (head->flightNumber == flightNumber && head->pid == pid) {
            head = head->next;
            cout << "The flight of " << temp->fname << " " << temp->lname << " is canceled." << endl;
            delete temp;
            seatTaken--;
            return;
        }

        while (temp->next != NULL) {
            if (temp->next->flightNumber == flightNumber && temp->next->pid == pid) {
                passengerNode* curr = temp->next;
                if (curr == tail) {
                    tail = temp;
                }
                temp->next = curr->next;
                cout << "The flight of " << curr->fname << " " << curr->lname << " is canceled." << endl;
                delete curr;
                seatTaken--;
                return;
            }
            else temp = temp->next;

            if (temp->next == NULL) {
                cout << "There is no such passenger!" << endl;
            }
        }
    }

    // for displaying passenger list
    void displayPassengerList() {
        if (head == NULL && tail == NULL) {
            cout << "No one has booked any flight!" << endl;
            return;
        }
        cout << "  Ticket Number" << setw(17) << "Flight Number" << setw(15) << "ID Number" << setw(16) << "Name" << setw(16) << "Age" << setw(18) <<  "email" << setw(23) << "From" << setw(23) << "Destination" << setw(16) <<  setw(19) << "Phone Number" << endl;
        cout << " ------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        passengerNode* temp = head;
        while (temp != NULL) {
            cout << "     " << temp->ticketNumber << setw(18) << temp->flightNumber << setw(18) << temp->pid << setw(13) << temp->fname << " " << temp->lname << setw(10) << temp->age << "\t\t" << temp->email << setw(16) << temp->from << setw(18) << temp->destination << setw(22) << temp->phoneNumber << endl;
            temp = temp->next;
        }
        cout << "\n";
    }


    void TotalNumberOfPassenger() {
        cout << this->seatTaken << endl;
        cout << "Total Number of available Seats: " << (25 - this->seatTaken) << endl;
    }


    void displaySpecificPassenger(string pid) {
        if (head == NULL && tail == NULL) {
            cout << "There is no such passenger in the list!" << endl;
            return;
        }

        passengerNode* temp = head;

        while (temp != NULL) {
            if (temp->pid == pid) {
                cout << "  Ticket Number" << setw(17) << "Flight Number" << setw(15) << "ID Number" << setw(16) << "Name" << setw(16) << "Age" << setw(18) <<  "email" << setw(23) << "From" << setw(23) << "Destination" << setw(16) <<  setw(19) << "Phone Number" << endl;
                cout << " ------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "     " << temp->ticketNumber << setw(18) << temp->flightNumber << setw(18) << temp->pid << setw(13) << temp->fname << " " << temp->lname << setw(10) << temp->age << "\t\t" << temp->email << setw(16) << temp->from << setw(18) << temp->destination << setw(22) << temp->phoneNumber << endl;
                return;
            }
            else temp = temp->next;
        }
        cout << "There is no such passenger" << endl;
    }
};

//Data type to keep records of flights;
struct FlightNode {
    string flightNumber;
    string from;
    string destination;
    string time;
    int price;
    int key;
    FlightNode* next;
};

class Flights {
private:
    FlightNode* head = NULL;
    FlightNode* tail = NULL;
    int key = 1;

public:
    void insertFlight(string flightNumber, string from, string destination, string time, int price) {
        FlightNode* flight = new FlightNode();
        flight->flightNumber = flightNumber;
        flight->from = from;
        flight->destination = destination;
        flight->time = time;
        flight->price = price;
        flight->key = key;
        key++;

        if (head == NULL && tail == NULL) {
            head = flight;
            tail = flight;
            return;
        }

        tail->next = flight;
        tail = flight;
    }

    //displaying the flight list;
    void displayFlight() {
        if (head == NULL && tail == NULL) {
            cout << "There are no flights" << endl;
            return;
        }

        FlightNode* temp = head;
        cout << "\n  " << "Key" << setw(20) << "Flight Number" << setw(15) << "From" << setw(23) << "Destination" << setw(20) << "Time" << setw(20) << "Price" << endl;
        cout << " -----------------------------------------------------------------------------------------------------------" << endl;
        while (temp != NULL) {

            cout << "   " << temp->key << setw(16) << temp->flightNumber << setw(22) << temp->from << setw(19) << temp->destination << setw(25) << temp->time << setw(14) << "$" << temp->price << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};


void showMenu();

void selectFlight();
void showFlights();
void bookFlight1(string flightNumber, string from, string destination);
void bookFlight2(string flightNumber, string from, string destination);
void bookFlight3(string flightNumber, string from, string destination);
void bookFlight4(string flightNumber, string from, string destination);

void check();
void checkTicket();

void showMyTicket();


void cancelTicket();

void showFlightDetails();

void showSpecificFlights();

int getAge();
int getInt();

// Data Structure for  passenger by flights;
ARS* f1 = new ARS();
ARS* f2 = new ARS();
ARS* f3 = new ARS();
ARS* f4 = new ARS();

//Data structure for storing flights flights
Flights* f = new Flights();

void showMenu() {
    system("CLS");
    cout << "\n\n\t\t\t\t\t Welcome To China Airlines" << endl;
    cout << "\t\t\t\t\t -------------------------\n" << endl;
    cout << "1. Reserve Flight" << endl;
    cout << "2. My Ticket" << endl;
    cout << "3. Cancel Ticket" << endl;
    cout << "4. Show Flight Details" << endl;
    cout << "5. Show List Of Passenger For Specific Flight" << endl;
    cout << "6. Quit Program" << endl;

    int choice;
    cout << "Enter the Corresponding Number For the Feature You Want to Use: ";
    choice = getInt();

    switch(choice) {
        case 1:
            selectFlight();
            break;

        case 2:
            showMyTicket();
            break;

        case 3:
            cancelTicket();
            break;

        case 4:
            showFlightDetails();
            break;

        case 5:
            showSpecificFlights();
            break;

        case 6:
            break;

        default:
            cout << "Invalid Key!" << endl;
            cout << "You need to enter again." << endl;
            Sleep(1500);
            showMenu();
    }
}

void selectFlight() {
    system("CLS");
    showFlights();
    int key;
    cout << "Enter the key for the flight you want to select: ";
    key = getInt();

    switch(key) {
        case 1:
            bookFlight1("CAL-10", "Guangzhou", "Ganzhou");
            break;

        case 2:
            bookFlight2("CAL-15", "Beijing", "Sanghai");
            break;

        case 3:
            bookFlight3("CAL-23", "Wuhan", "Harbin");
            break;

        case 4:
            bookFlight4("CAL-25", "Chengdu", "Sichuwan");
            break;

        default:
            cout << "You have entered wrong key.\nEnter Again!" << endl;
            Sleep(1500);
            selectFlight();
    }
}

void bookFlight1(string flightNumber, string from, string destination) {
    system("CLS");
    string pid;
    string fname;
    string lname;
    int age;
    string email;
    long long phoneNumber;
    cout << "Enter your ID number(passport number, driving citizenship number, etc): ";
    cin >> pid;
    cout << "Enter your first name: ";
    cin >> fname;
    cout << "Enter your last name: ";
    cin >> lname;
    cout << "Enter your Age: ";
    age = getInt();
    cout << "Enter you email: ";
    cin >> email;
    cout << "Enter you phone number: ";
    cin >> phoneNumber;
    f1->insertPassenger(pid, fname, lname, age, email, phoneNumber, flightNumber, from, destination);
    check();
}

void bookFlight2(string flightNumber, string from, string destination) {
    system("CLS");
    string pid;
    string fname;
    string lname;
    int age;
    string email;
    long long phoneNumber;
    cout << "Enter your ID number(passport number, driving citizenship number, etc): ";
    cin >> pid;
    cout << "Enter your first name: ";
    cin >> fname;
    cout << "Enter your last name: ";
    cin >> lname;
    cout << "Enter your Age: ";
    age = getInt();
    cout << "Enter you email: ";
    cin >> email;
    cout << "Enter you phone number: ";
    cin >> phoneNumber;
    f2->insertPassenger(pid, fname, lname, age, email, phoneNumber, flightNumber, from, destination);
    check();
}

void bookFlight3(string flightNumber, string from, string destination) {
    system("CLS");
    string pid;
    string fname;
    string lname;
    int age;
    string email;
    long long phoneNumber;
    cout << "Enter your ID number(passport number, driving citizenship number, etc): ";
    cin >> pid;
    cout << "Enter your first name: ";
    cin >> fname;
    cout << "Enter your last name: ";
    cin >> lname;
    cout << "Enter your age: ";
    age = getInt();
    cin >> email;
    cout << "Enter you phone number: ";
    cin >> phoneNumber;
    f3->insertPassenger(pid, fname, lname, age, email, phoneNumber, flightNumber, from, destination);
    check();
}

void bookFlight4(string flightNumber, string from, string destination) {
    system("CLS");
    string pid;
    string fname;
    string lname;
    int age;
    string email;
    long long phoneNumber;
    cout << "Enter your ID number(passport number, driving citizenship number, etc): ";
    cin >> pid;
    cout << "Enter your first name: ";
    cin >> fname;
    cout << "Enter your last name: ";
    cin >> lname;
    cout << "Enter your Age: ";
    age = getInt();
    cout << "Enter you email: ";
    cin >> email;
    cout << "Enter you phone number: ";
    cin >> phoneNumber;
    f4->insertPassenger(pid, fname, lname, age, email, phoneNumber, flightNumber, from, destination);
    check();
}

void check() {
    char ch;
    cout << "\nEnter Y to exit the program or N to back to Main Menu: ";
    cin >> ch;

    if (ch == 'Y' || ch == 'y') {
        return;
    }
    else if (ch == 'N' || ch == 'n') {
        showMenu();
    }
    else {
        cout << "Pressed wrong key.\nYou have to enter again!" << endl;
        check();
    }
}


void showMyTicket() {
    system("CLS");
    string pid, flightNumber;
    cout << "Enter your Flight Number: ";
    cin >> flightNumber;

    if (flightNumber == "CAL-10") {
        cout << "Enter your ID Number: ";
        cin >> pid;
        f1->displaySpecificPassenger(pid);
        check();
    }

    else if (flightNumber == "CAL-15") {
        cout << "Enter your ID Number: ";
        cin >> pid;
        f2->displaySpecificPassenger(pid);
        check();
    }

    else if (flightNumber == "CAL-23") {
        cout << "Enter your ID Number: ";
        cin >> pid;
        f3->displaySpecificPassenger(pid);
        check();
    }

    else if (flightNumber == "CAL-25") {
        cout << "Enter your ID Number: ";
        cin >> pid;
        f4->displaySpecificPassenger(pid);
        check();
    }

    else {
        cout << "There is no such flight!" << endl;
        checkTicket();
    }
}

void checkTicket() {
    char ch;
    cout << "Press Y to enter again or N to go to the Main Menu: ";
    cin >> ch;

    if (ch == 'Y' || ch =='y') showMyTicket();

    else if (ch == 'N' || ch == 'n') showMenu();

    else {
        cout << "Pressed wrong key.\nYou have to enter again!" << endl;
        checkTicket();
    }
}


void cancelTicket() {
    system("CLS");
    string flightNumber, pid;

    cout << "Enter the Flight Number: ";
    cin >> flightNumber;

    if (flightNumber == "CAL-10") {
        cout << "Enter your ID Number: ";
        cin >> pid;
        f1->deletePassenger(flightNumber, pid);
        check();
    }

    else if (flightNumber == "CAL-15") {
        cout << "Enter your  ID Number: ";
        cin >> pid;
        f2->deletePassenger(flightNumber, pid);
        check();
    }

    else if (flightNumber == "CAL-23") {
        cout << "Enter your ID Number: ";
        cin >> pid;
        f3->deletePassenger(flightNumber, pid);
        check();
    }

    else if (flightNumber == "CAL-25") {
        cout << "Enter your ID Number: ";
        cin >> pid;
        f4->deletePassenger(flightNumber, pid);
        check();
    }

    else {
        cout << "There is no such flight!" << endl;
        checkTicket();
    }
}


void showFlightDetails() {
    system("CLS");
    showFlights();
    check();

}


void showSpecificFlights() {
    system("CLS");
    string flightNumber;
    cout << "Enter the Flight Number: ";
    cin >> flightNumber;

    if (flightNumber == "CAL-10") {
        system("CLS");
        f1->displayPassengerList();
        cout << "\nTotal Number of Seats in the Flight: 25" << endl;
        cout << "Total Number of Passenger in the Flight: ";
        f1->TotalNumberOfPassenger();
        check();
    }

    else if (flightNumber == "CAL-15") {
        system("CLS");
        f2->displayPassengerList();
        cout << "\nTotal Number of Seats in the Flight: 25" << endl;
        cout << "Total Number of Passenger in the Flight: ";
        f2->TotalNumberOfPassenger();
        check();
    }

    else if (flightNumber == "CAL-23") {
        system("CLS");
        f3->displayPassengerList();
        cout << "\nTotal Number of Seats in the Flight: 25" << endl;
        cout << "Total Number of Passenger in the Flight: ";
        f3->TotalNumberOfPassenger();
        check();
    }

    else if (flightNumber == "CAL-25") {
        system("CLS");
        f4->displayPassengerList();
        cout << "\nTotal Number of Seats in the Flight: 25" << endl;
        cout << "Total Number of Passenger in the Flight: ";
        f4->TotalNumberOfPassenger();
        check();
    }

    else {
        cout << "There is no such fight!" << endl;
        checkTicket();
    }

}

void showFlights() {
    f->displayFlight();
}

int getInt() {
    int x = 0;
    while(!(cin >> x)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Try again: ";
    }
    return x;  
}


void InitializeFlight() {
    f->insertFlight("CAL-10", "Guangzhou", "Ganzhou", "12:30 PM", 250);
    f->insertFlight("CAL-15", "Beijing", "Shangai", "9:00 AM", 300);
    f->insertFlight("CAL-23", "Wuhan", "Harbin", "4:00 AM", 215);
    f->insertFlight("CAL-25", "Chengdu", "Sichuwan", "1:30 PM", 150);
}

int main()
{
    InitializeFlight();
    showMenu();
    return 0;
}
