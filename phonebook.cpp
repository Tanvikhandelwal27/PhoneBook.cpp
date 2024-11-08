#include <iostream> 
#include <iomanip> 
#include <string> 
#include <map> 
 
using namespace std; 
 
class PhoneBook { 
private: 
    map<string, string> contacts; 
 
public: 
    void addContact(const string& name, const string& phoneNumber) { 
        contacts[name] = phoneNumber; 
        cout << "Contact added successfully." << endl; 
    } 
 
    void displayContacts() const { 
        if (contacts.empty()) { 
            cout << "Phone book is empty." << endl; 
        } else { 
            cout << setw(15) << "Name" << setw(15) << "Phone Number" << 
endl; 
            cout << setfill('-') << setw(30) << "" << setfill(' ') << 
endl; 
            for (const auto& entry : contacts) { 
                cout << setw(15) << entry.first << setw(15) << 
entry.second << endl; 
            } 
        } 
    } 
 
    string getPhoneNumber(const string& name) const { 
        auto it = contacts.find(name); 
        if (it != contacts.end()) { 
            return it->second; 
        } else { 
            return "Contact not found."; 
        } 
    } 
}; 
 
int main() { 
    PhoneBook phoneBook; 
 
    int choice; 
    do { 
        cout << "\nPhone Book Menu\n"; 
        cout << "1. Add Contact\n"; 
        cout << "2. Display Contacts\n"; 
        cout << "3. Search Contact\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: { 
                string name, phoneNumber; 
                cout << "Enter name: "; 
                cin >> name; 
                cout << "Enter phone number: "; 
                cin >> phoneNumber; 
                phoneBook.addContact(name, phoneNumber); 
                break; 
            } 
            case 2: 
                phoneBook.displayContacts(); 
                break; 
            case 3: { 
                string name; 
                cout << "Enter name to search: "; 
                cin >> name; 
                cout << "Phone number: " << 
phoneBook.getPhoneNumber(name) << endl; 
                break; 
            } 
            case 4: 
                cout << "Exiting Phone Book. Goodbye!" << endl; 
                break; 
            default: 
                cout << "Invalid choice. Please try again." << endl; 
        } 
    } while (choice != 4); 
 
    return 0; 
}