#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <functional> // Standard C++ hash function; openssl is another option - dependencies required

using namespace std;

// Struct to store client data dynamically
struct Client {
    string name;
    int service;
};

// Dynamic client database (stored in vector)
vector<Client> clients = {
    {"Vincent Vega", 1},
    {"Jules Davis", 2},
    {"Joey Frank", 1},
    {"Johnny Apple", 1},
    {"Beatrix Kiddo", 2}
};

// Function to hash passwords using std::hash (not cryptographically secure)
string hashPassword(const string &password) {
    hash<string> hasher;
    return to_string(hasher(password)); // Converts hash to string
}

// Simulated secure user database (hashed with std::hash)
unordered_map<string, string> userDatabase = {
    {"admin", hashPassword("abc123")},
    {"user1", hashPassword("test")}
};

/**
 * Prompts for login credentials. Checks username & password securely.
 * @return 1 = success, 2 = failure.
 */
int CheckUserPermissionAccess() {
    string userEntry, passEntry;
    int attempts = 0;

    while (attempts < 3) {
        cout << "Enter username:\n";
        cin >> userEntry;

        cout << "Enter password:\n";
        cin >> passEntry;

        // Hash the entered password before comparison
        string hashedPass = hashPassword(passEntry);

        // Validate username and password
        if (userDatabase.find(userEntry) != userDatabase.end() &&
            userDatabase[userEntry] == hashedPass) {
            return 1;
        } else {
            cout << "Incorrect username or password. Try again.\n";
            attempts++;
        }
    }

    cout << "Too many failed login attempts. Exiting program.\n";
    exit(1);
}

/**
 * Displays a formatted list of client info.
 */
void DisplayInfo() {
    cout << "  Client Name     |  Service Selected" << endl;
    cout << "  ---------------|------------------" << endl;

    for (size_t i = 0; i < clients.size(); i++) {
        cout << i + 1 << ". " << clients[i].name << " - Plan " << clients[i].service << endl;
    }
}

/**
 * Allows user to update a client’s service selection with validation.
 */
void ChangeCustomerChoice() {
    int clientNum, newPlan;

    cout << "Enter client number to modify (1-5): ";
    while (!(cin >> clientNum) || clientNum < 1 || clientNum > clients.size()) {
        cout << "Invalid input. Enter a number between 1 and " << clients.size() << ":\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "New service choice (1 = Brokerage, 2 = Retirement): ";
    while (!(cin >> newPlan) || (newPlan != 1 && newPlan != 2)) {
        cout << "Invalid input. Enter 1 or 2:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    clients[clientNum - 1].service = newPlan;
    cout << "Service updated successfully.\n";
}

/**
 * Main function: Handles authentication and menu selection.
 * @return 0 upon exit.
 */
int main() {
    cout << "Welcome to the Secure Investment Portal!\n";

    // Authentication
    int authResult = CheckUserPermissionAccess();

    // User menu loop
    int option;
    do {
        cout << "\nMENU:\n";
        cout << "1 - Show Clients\n";
        cout << "2 - Modify Client Service\n";
        cout << "3 - Exit\n";
        cout << "Choice: ";

        while (!(cin >> option) || (option < 1 || option > 3)) {
            cout << "Invalid choice. Please select a valid menu option (1-3):\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Processing...\n";

        if (option == 1) {
            DisplayInfo();
        } else if (option == 2) {
            ChangeCustomerChoice();
        }

    } while (option != 3);

    cout << "Goodbye.\n";
    return 0;
}
