#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

class Reservation {
public:
    string customerName;
    string timeSlot;

    Reservation() {
        cout << "Enter your Name:";
        getline(cin, customerName);
    }

    Reservation(string name, string time) : customerName(name), timeSlot(time){}

};

class Restaurant {
public:
    vector<string> availableTimeSlots;

   
    Restaurant() {
        for (int hour = 01; hour <= 21; hour++) {
            availableTimeSlots.push_back(to_string(hour) + ":00");
        }
    }


 
    void displayAvailableTimeSlots() {
        cout << "Available Time Slots:" << endl;
        for (const auto& slot : availableTimeSlots) {
            cout << slot << endl;
        }
    }

  
    void acceptReservation(string name, string time) {
        bool slotFound = false;

        for (auto t = availableTimeSlots.begin(); t != availableTimeSlots.end(); ++t) {
            if (*t == time) {
                slotFound = true;
                availableTimeSlots.erase(t);
                Reservation reservation(name, time);
                cout << "Reservation confirmed for " << name << " at " << time << endl;
                break;
            }
        }

        if (!slotFound) {
            cout << "Sorry, the selected time slot is not available." << endl;
        }
    }


};

void Menu() {
    int choice;
    Restaurant restaurant;
    string n, s;
    int a;

    do {
        cout << "\t\tRESTURANT RESERVATION SYSTEM" << endl << endl;
        cout << "1. View Available Time Slots." << endl;
        cout << "2. Book reservation." << endl;
        cout << "3. Exit." << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;
        cin.ignore();


        switch (choice) {
        case 1:
            system("cls");
            restaurant.displayAvailableTimeSlots();
            cout << "Enter AnyKey to return to menu";
            cin >> a;
            if (a) {
                system("cls");
                Menu();
            }
            
            break;
        case 2:
            system("cls");
            cout << "Enter your Name: ";
            getline(cin, n);

            cout << "Enter your Time Slot (e.g., 14:00): ";
            getline(cin, s);

            restaurant.acceptReservation(n, s);
            break;
        case 3:
            cout << "Thank You." << endl;
            break;
        default:
            cout << "Enter Valid Input" << endl;
        }

    } while (choice != 3);

}

int main() {

    Menu();
 
    return 0;
}