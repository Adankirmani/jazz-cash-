#include<iostream>
#include <algorithm>
using namespace std;
int main() {
    int Choice;
    string regUsername, regPassword, email;
    string logUsername, logPassword;
    bool isRegistered ;
    bool isLoggedIn;
    cout << "                            Jazz Cash" << endl;

    while (true) {
        cout << "Enter 1 for Register " << endl;
        cout << "Enter 2 for Login " << endl;
        cout << "Enter 3 for Send Money " << endl;
        cout << "Enter 4 for Pay Bills " << endl;
        cout << "Enter 5 for Check Balance " << endl;
         cout<< "Enter 0 to Exit" << endl;
        cout << "Please enter your choice: " << endl;
        cin >> Choice;
        cin.ignore();
        if (Choice < 0 || Choice > 5) {
            cout << "Invalid option. Please try again." << endl;
            continue;
        }
        if (Choice == 0) {
            cout << "Exiting the system."<<endl;
            break;
        }
        if (Choice == 1) {
            if (!isRegistered) {
                cout << "Please enter your username: ";
                getline(cin, regUsername);
                if (!regUsername.empty()) {
                    cout << "Please enter your email: ";
                    getline(cin, email);
                    cout << "Please enter your password: ";
                    getline(cin, regPassword);
                    isRegistered = true;
                    cout << "Thanks for the registration." << endl;
                } else {
                    cout << "Username cannot be empty." << endl;
                }
            } else {
                cout << "You've already registered. Please log in." << endl;
            }
        } 
        else if (Choice == 2) {
            if (isRegistered && !isLoggedIn) {
                cout << "Please enter your username: ";
                getline(cin, logUsername);
                if (logUsername.empty()) {
                    cout << "Username cannot be empty." << endl;
                    continue;
                }
                cout << "Please enter your password: ";
                getline(cin, logPassword);
                if (regUsername == logUsername && regPassword == logPassword) {
                    isLoggedIn = true;
                    cout << "Login successfully." << endl;
                } else {
                    cout << "Incorrect username or password." << endl;
                }
            } else if (isLoggedIn) {
                cout << "Already logged in." << endl;
            } else {
                cout << "Please register before logging in." << endl;
            }
        } 
        else if (Choice == 3) {
    if (!isLoggedIn) {
        cout << "You must be logged in to send money." << endl;
        continue;
    }
    string receiverName, bankName; 
    int result, Amount;
    string number;
    cout << "Please enter the receiver's name: " << endl;
    getline(cin, receiverName);
    if (receiverName.empty()) {
        cout << "Receiver's name cannot be empty." << endl;
        continue;
    } 
    cout << "Please enter 1 for Easypaisa transfer " << endl;
    cout << "Please enter 2 for Bank account transfer" << endl;
    cout << "Please enter 3 for Jazz Cash transfer" << endl;
    cout << "Please enter your choice: ";
    cin >> result;
    cin.ignore();
   if (result == 1) {
        cout << "Please enter the 11-digit Easypaisa number: " << endl;
        getline(cin, number);
        if (number.length() == 11 && std::all_of(number.begin(), number.end(), ::isdigit)) {
            cout << "Please enter the amount you want to send: " << endl;
            cin >> Amount;
            cout << "Sending RS " << Amount << " to " << receiverName << " and their Easypaisa number is " << number << "." << endl;
        } else {
            cout << "Enter a valid 11-digit Easypaisa number." << endl;
        }
    } else if (result == 2) {
        cout << "Enter your Full bank name: ";
        getline(cin, bankName);
        if (bankName.empty()) {
            cout << "Bank name cannot be empty." << endl;
            continue;
        }
        if (bankName == "BankIslami" || bankName == "bankislami" ||
            bankName == "BankAlfalah" || bankName == "bankalfalah" ||
            bankName == "FaysalBank" || bankName == "faysalbank") {
            cout << "This Bank is not available in this app." << endl;
        } else {
            cout << "Please enter the Bank Account number without spaces or slashes: ";
            getline(cin, number);
            if (number.length() == 12 && std::all_of(number.begin(), number.end(), ::isdigit)) {
                cout << "Please enter the amount you want to send: ";
                cin >> Amount;
                if (Amount <= 0) {
                    cout << "Please enter a valid amount to send." << endl;
                } else {
                    cout << "Sending RS " << Amount << " to " << receiverName << " Bank Account number: " << number << "." << endl;
                }
            } else {
                cout << "Enter a valid 12-digit bank account number." << endl;
            }
        }
    } else if (result == 3) {
        cout << "Please enter the Jazz Cash number: " << endl;
        getline(cin, number);
        cout << "Please enter the amount you want to send: " << endl;
        cin >> Amount;
        if (number.length() == 11 && std::all_of(number.begin(), number.end(), ::isdigit)) {
            cout << "Sending RS " << Amount << " to " << receiverName << " Jazz Cash number: " << number << "." << endl;    
        } else {
            cout << "Enter a valid Jazz Cash number." << endl;
        }
    }
}        else if (Choice == 4) {
        	if (!isLoggedIn) {
                cout << "You must be logged in to Pay Bills" << endl;
                continue;
            }
            int type, bill;
            string serial_no;
            cout << "Enter the type of bill you want to pay" << endl;
            cout << "Enter 1 for Water Bill" << endl;
            cout << "Enter 2 for Gas Bill" << endl;
            cout << "Enter 3 for Electricity Bill" << endl;
            cout << "Please enter your choice: ";
            cin >> type;
           if (type < 1 || type > 3) {
        cout << "Invalid bill type. Please choose again." << endl;
        continue;
    }
            if (type == 1) {
                cout << "Water Bill" << endl;
                cout << "Enter the 8 digit serial number: ";
                cin >> serial_no;
                cout << "Enter total water bill to be paid: ";
                cin >> bill;
                if (serial_no.length() == 8 && std::all_of(serial_no.begin(), serial_no.end(),::isdigit)) {
                    cout << "Bill paid successfully." << endl;
                } else {
                    cout << "Enter correct serial number." << endl;
                }
            } else if (type == 2) {
                cout << "Gas Bill" << endl;
                cout << "Enter the 8 digit serial number: ";
                cin >> serial_no;
                cout << "Enter total gas bill to be paid: ";
                cin >> bill;
                if (serial_no.length() == 8) {
                    cout << "Bill paid successfully." << endl;
                } else {
                    cout << "Enter correct serial number." << endl;
                }
            } else if (type == 3) {
                cout << "Electricity Bill" << endl;
                cout << "Enter 8 digit serial number: ";
                cin >> serial_no;
                cout << "Enter total electricity bill to be paid: ";
                cin >> bill;
                if (serial_no.length() == 8) {
                    cout << "Bill paid successfully." << endl;
                } else {
                    cout << "Enter correct serial number." << endl;
                }
            } else {
                cout << "Enter the correct type." << endl;
            }
        } 
        else if (Choice == 5) {
        	if (!isLoggedIn) {
                cout << "You must be logged in to Check Balance." << endl;
                continue;
            }
            string Mobile_number;
            cout << "Checking balance..." << endl;
            cout << "Enter your 11 digit mobile number: ";
            cin >> Mobile_number;
            if (Mobile_number.length() == 11) {
                cout << "Your account balance is 'XXXXX'." << endl;
            } else {
                cout << "Enter correct mobile number." << endl;
            }
        } 
        else {
            cout << "Invalid option. Please try again." << endl;
        }
    }
    return 0;
}