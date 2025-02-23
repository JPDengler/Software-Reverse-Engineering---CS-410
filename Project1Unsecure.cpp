#include <iostream>
using namespace std;

// Global user information
string client1 = "Vincent Vega";        int service1 = 1;
string client2 = "Jules Davis";      int service2 = 2;
string client3 = "Joey Frank";     int service3 = 1;
string client4 = "Johnny Apple";     int service4 = 1;
string client5 = "Beatrix Kiddo";     int service5 = 2;

// Security Issue: Hardcoded user data makes the program static and exposes user information in source code.
// Suggestion: Use a class or struct to store user data dynamically in a list.

// "Super secure" password
string passcode = "123"; 

// Security Issue: Hardcoded password exposes credentials in source code, making it easy to extract.
// Suggestion: Use hashed and salted passwords with a secure authentication mechanism.

/**
 * Prompts for login credentials. Checks the password.
 * @return 1 = success, 2 = failure.
 */
int CheckUserPermissionAccess() {
    string userEntry, passEntry;

    cout << "Enter username:\n";
    cin >> userEntry;

    cout << "Enter password:\n";
    cin >> passEntry;

    // Security Issue: Username is collected but not verified, making it useless.
    // Security Issue: Simple string comparison for authentication is insecure.
    // Suggestion: Implement a user database with proper authentication.
    
    if (passcode.compare(passEntry) == 0) {
        return 1;
    } else {
        return 2;
    }
}

/**
 * Displays a nicely formatted list of client info.
 */
void DisplayInfo() {
    cout << "  Client Name     |  Service Selected" << endl;
    cout << "  ---------------|------------------" << endl;
    cout << "1. " << client1 << " - Plan " << service1 << endl;
    cout << "2. " << client2 << " - Plan " << service2 << endl;
    cout << "3. " << client3 << " - Plan " << service3 << endl;
    cout << "4. " << client4 << " - Plan " << service4 << endl;
    cout << "5. " << client5 << " - Plan " << service5 << endl;

    // Security Issue: Output is static and hardcoded; it cannot dynamically adjust.
    // Suggestion: Store clients in a list or database for flexible data management.
}

/**
 * Allows user to update a client’s service selection.
 */
void ChangeCustomerChoice() {
    int clientNum, newPlan;

    cout << "Enter client number to modify:\n";
    cin >> clientNum;

    // Security Issue: Input is not validated. If a user enters a non-integer or out-of-range number, it could cause issues.
    // Suggestion: Use input validation and error handling.

    cout << "New service choice (1 = Brokerage, 2 = Retirement)\n";
    cin >> newPlan;

    // Security Issue: Input for new service choice is not validated. An invalid value could cause incorrect behavior.
    // Suggestion: Validate input against expected values (1 or 2).

    switch (clientNum) {
        case 1: service1 = newPlan; break;
        case 2: service2 = newPlan; break;
        case 3: service3 = newPlan; break;
        case 4: service4 = newPlan; break;
        case 5: service5 = newPlan; break;
        default: cout << "Invalid client number.\n"; break;
    }

    // Security Issue: Hardcoded indices mean clients are manually referenced, limiting scalability.
    // Suggestion: Use an array, vector, or database for storing clients and dynamically updating them.
}

/**
 * Main function: Handles authentication and menu selection.
 * @return 0 upon exit.
 */
int main() {
    // Creator info
    cout << "Welcome to the unsecure Investment Portal!\n";

    // Authentication loop
    int authResult;
    do {
        authResult = CheckUserPermissionAccess();
        if (authResult != 1) {
            cout << "Incorrect Password. Try again!\n";
        }
    } while (authResult != 1);

    // Security Issue: No login attempt limit, allowing brute force attacks. 
    // Suggestion: Implement a limit on incorrect login attempts with a cooldown period.

    // User menu loop
    int option;
    do {
        cout << "\nMENU:\n";
        cout << "1 - Show Clients\n";
        cout << "2 - Modify Client Service\n";
        cout << "3 - Exit\n";
        cout << "Choice: ";
        cin >> option;

        // Security Issue: Input is not validated; invalid input can cause program instability.
        // Suggestion: Check if input is a valid integer within the expected range.

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
