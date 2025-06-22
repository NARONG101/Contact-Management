#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Structure to store contact details
struct Contact {
    int id;
    string name;
    string phone;
    string email;
};

// Global vector to store all contacts
vector<Contact> contacts;

// Function to pause execution and wait for user input
void pause() {
    cout << "\nPress Enter to return to main menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Function to create a new contact
void createContact() {
    Contact c;
    cout << "Enter Contact ID: ";
    cin >> c.id;
    cin.ignore(); // Clear input buffer

    cout << "Enter Name: ";
    getline(cin, c.name);

    cout << "Enter Phone: ";
    getline(cin, c.phone);

    cout << "Enter Email: ";
    getline(cin, c.email);

    // Add contact to the list
    contacts.push_back(c);
    cout << "Contact added successfully!\n";

    pause(); // Wait for user before returning to menu
}

// Function to update an existing contact
void updateContact() {
    int id;
    bool found = false;
    cout << "Enter Contact ID to update: ";
    cin >> id;
    cin.ignore();

    // Search for the contact by ID
    for (auto& c : contacts) {
        if (c.id == id) {
            found = true;

            // Update contact details
            cout << "Enter New Name: ";
            getline(cin, c.name);
            cout << "Enter New Phone: ";
            getline(cin, c.phone);
            cout << "Enter New Email: ";
            getline(cin, c.email);

            cout << "Contact updated successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Contact not found!\n";
    }

    pause();
}

// Function to search for a contact by ID
void searchContact() {
    int id;
    bool found = false;
    cout << "Enter Contact ID to search: ";
    cin >> id;
    cin.ignore();

    // Loop through all contacts to find the one with matching ID
    for (const auto& c : contacts) {
        if (c.id == id) {
            found = true;
            cout << "\nContact Found:\n";
            cout << "ID: " << c.id << "\nName: " << c.name
                 << "\nPhone: " << c.phone << "\nEmail: " << c.email << endl;
            break;
        }
    }

    if (!found) {
        cout << "Contact not found!\n";
    }

    pause();
}

// Function to delete a contact
void deleteContact() {
    int id;
    bool found = false;
    cout << "Enter Contact ID to delete: ";
    cin >> id;
    cin.ignore();

    // Search for the contact by ID and delete if found
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->id == id) {
            contacts.erase(it);
            found = true;
            cout << "Contact deleted successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Contact not found!\n";
    }

    pause();
}

// ✅ Function to display all contacts
void viewAllContacts() {
    if (contacts.empty()) {
        cout << "No contacts found.\n";
    } else {
        cout << "\nAll Contacts:\n";
        // Loop through all contacts and display each one
        for (const auto& c : contacts) {
            cout << "-----------------------------\n";
            cout << "ID: " << c.id << "\nName: " << c.name
                 << "\nPhone: " << c.phone << "\nEmail: " << c.email << "\n";
        }
    }

    pause();
}

// Function to show the main menu
void showMenu() {
    cout << "\n==============================\n";
    cout << "Contact List Manager\n";
    cout << "==============================\n";
    cout << "1. Create Contact\n";
    cout << "2. Update Contact\n";
    cout << "3. Search Contact\n";
    cout << "4. Delete Contact\n";
    cout << "5. View All Contacts\n"; // NEW OPTION
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

// Main function to control program flow
int main() {
    int choice;

    do {
        showMenu();        // Display menu
        cin >> choice;     // Get user's choice
        cin.ignore();      // Clear input buffer

        // Perform action based on choice
        switch (choice) {
            case 1: createContact(); break;
            case 2: updateContact(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: viewAllContacts(); break; // Call new function
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n"; pause(); break;
        }

    } while (choice != 6); // Keep running until user chooses Exit

    return 0;
}
