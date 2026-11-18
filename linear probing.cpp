
#include <iostream>
#include <string>
using namespace std;

class TelephoneBook {
    int size;
    string name[100];
    long long phone[100];
    bool occupied[100];

public:
    TelephoneBook(int s) {
        size = s;

        for (int i = 0; i < size; i++) {
            occupied[i] = false;
        }
    }

    int hashFunction(string key) {
        int sum = 0;

        for (int i = 0; i < key.length(); i++) {
            sum += key[i];
        }

        return sum % size;
    }

    void insert(string n, long long p) {
        int index = hashFunction(n);
        int start = index;

        while (occupied[index]) {
            index = (index + 1) % size;

            if (index == start) {
                cout << "Hash Table is Full!\n";
                return;
            }
        }

        name[index] = n;
        phone[index] = p;
        occupied[index] = true;

        cout << "Record inserted successfully!\n";
    }

    void search(string n) {
        int index = hashFunction(n);
        int start = index;

        while (occupied[index]) {
            if (name[index] == n) {
                cout << "Name: " << name[index] << endl;
                cout << "Phone Number: " << phone[index] << endl;
                return;
            }

            index = (index + 1) % size;

            if (index == start)
                break;
        }

        cout << "Client not found!\n";
    }

    void display() {
        cout << "\nTelephone Book:\n";

        for (int i = 0; i < size; i++) {
            if (occupied[i]) {
                cout << i << " -> "
                     << name[i] << " : "
                     << phone[i] << endl;
            }
            else {
                cout << i << " -> Empty\n";
            }
        }
    }
};

int main() {
    int n, choice;
    string name;
    long long phone;

    cout << "Enter size of Hash Table: ";
    cin >> n;

    TelephoneBook tb(n);

    do {
        cout << "\n===== TELEPHONE BOOK =====\n";
        cout << "1. Insert Client\n";
        cout << "2. Search Client\n";
        cout << "3. Display Telephone Book\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Client Name: ";
                cin >> name;

                cout << "Enter Phone Number: ";
                cin >> phone;

                tb.insert(name, phone);
                break;

            case 2:
                cout << "Enter Name to Search: ";
                cin >> name;

                tb.search(name);
                break;

            case 3:
                tb.display();
                break;

            case 4:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}

