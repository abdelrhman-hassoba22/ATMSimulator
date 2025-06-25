#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

// these vars i needed.
double palance = 1000;
int deposit = 0;
int withdrawal = 0;
int passwd = 0;
int choise = 0;
char option = 'o';

// this fun to display the menu of etm.
void etm_menu() {
    cout << "*** Menu ***" << endl;
    cout << "1) Palance " << endl;
    cout << "2) Withdrawal " << endl;
    cout << "3) Deposit " << endl;
    cout << "4) exit " << endl;
}

// func to check from correct password and continue the process.
void process() {
    char tryAgain;
    
    do {
        cout << "enter your password:" << endl;
        cin >> passwd;
        
        if (passwd != 1234) {
            cout << "your password is wrong\n";
            cout << "Do you want to try again? (y/n): ";
            cin >> tryAgain;
            
            if (tolower(tryAgain) != 'y') {
                cout << "Thank you for using our service. Goodbye!\n";
                return; // الخروج من البرنامج
            }
        } else {
            cout << "your password is correct\n";
            this_thread::sleep_for(chrono::milliseconds(2000));
            etm_menu();
            
            do {
                cout << "enter your choise" << endl;
                cin >> choise;
                
                switch (choise) {
                    case 1:
                        cout << "your palance is " << palance << endl;
                        break;
                    case 2:
                        cout << "Worning your palance " << palance << " don't withdrawal more your palance" << endl;
                        cout << "enter your Amount " << endl;
                        cin >> withdrawal;
                        if (withdrawal > palance) {
                            cout << "sorry you can't withdrawal this amount\n";
                        } else {
                            cout << "done" << endl;
                            palance -= withdrawal;
                            cout << "your palance now is " << palance << endl;
                        }
                        break;
                    case 3:
                        cout << "your palance is " << palance << endl;
                        cout << "enter your amount want to deposit\n";
                        cin >> deposit;
                        palance += deposit;
                        cout << "your palance now is " << palance << endl;
                        break;
                    case 4:
                        cout << "Thank you for use our service" << endl;
                        break;
                    default:
                        cout << "your choise is not valid " << endl;
                }
            } while (choise != 4);
            
            return; // الخروج بعد إتمام العملية
        }
    } while (true);
}

int main() {
    process();
    return 0;
}
