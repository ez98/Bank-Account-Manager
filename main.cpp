#include <iostream>
#include <string>
#include  <vector>
#include "Account.h"
#include <windows.h>
#include "../../../source/repos/BankAccount/BankAccount/Accounts.h"

using namespace std;
//Consider adding a transfer money option and changing account option
/*Make a case where once they add a new account, everything is handled within that case
and if they logout, they return to the main menu. There they can add a new account.*/
void show_list();
void main_menu();
string name();
char get_choice();
void add_account(vector <Account>& accounts, Accounts& my_accounts, string name);
int choose_account();
void welcome(vector <Account>& accounts, Accounts& my_accounts, int i);

void show_list(){
    cout << "\n1.) Set Balance." << endl;
    cout << "2.) Deposit." << endl;
    cout << "3.) Withdrawal." << endl;
    cout << "4.) Check Balance." << endl;
    cout << "5.) Transfer Funds." << endl;
    cout << "L.) Logout." << endl;
    cout << endl; 
    }
void main_menu() {
    cout << "\n1.) Add New Account." << endl;
    cout << "2.) Log-in to Existing Account." << endl;
    cout << "E.) Exit" << endl;
    cout << endl;
}
string name() {
    char choice;
    string name;
    string savings{ "Savings" };
    string checkings{ "Checkings" };
    cout << "1.) Savings" << endl;
    cout << "2.) Checkings" << endl;
    cout << "3.) Custom Account" << endl;
    choice = get_choice();
    cin.ignore();
    if (choice == '1')
        return savings;
    if (choice == '2')
        return checkings;
    if (choice == '3') 
    {
        cout << "Enter account name: ";
        getline(cin, name);
        return name;
    }
}
char get_choice() {
    char choice;
    cout << "\nEnter your choice: ";
    cin >> choice;
    cout << endl;
    return choice;
}
void add_account(vector <Account>& accounts, Accounts& my_accounts,string name) {
    if (my_accounts.add_account(accounts, name))
    {
        cout << "Account Added: " << name << endl;
        cout << "Account is ready for log-in!" << endl;
    }
    else
    { 
        cout << name << " already exists as an account." << endl;
    }

}
int choose_account() {
    int account;
    cout << "Choose an account: ";
    cin >> account;
    cout << endl;
    return account;
}
void welcome(vector <Account>& accounts, Accounts& my_accounts, int i){
    cout << "=================================" << endl;
    cout << "Managing Account: " << accounts[i].get_name() << endl;
    cout << "=================================" << endl;
}
int main(){

    vector <Account> accounts;
    Accounts my_accounts;
    string add_name;
    bool managing_menu{true};
    bool managing_account{false};
    cout << "========================================" << endl;
    cout << "Welcome to your Bank Account Manager." << endl;
    cout << "========================================" << endl;
    Sleep(1000);
    
    while (managing_menu) 
    {
        main_menu(); //Display Menu
        char choice = get_choice();
        cin.ignore();
        switch (choice) {
        case '1': 
        { //If they create a new account, we create a case to add the acct and display the acct manager
            add_name = name();
            add_account(accounts, my_accounts, add_name);
            Sleep(1000);
            break;
        }
        case '2': //make sure to check if accounts exists first, let user know that no acct exists and send back to menu
        {
            my_accounts.display_accounts(accounts);
            int i = choose_account() - 1; 
            welcome(accounts, my_accounts, i);
            managing_account = true;
            while (managing_account) {
                show_list();
                char choice = get_choice();
                cin.ignore();
                switch (choice) {
                case '1': 
                {
                    long double bal;
                    cout << "Set your balance: $";
                    cin >> bal;
                    my_accounts.set_account_balance(accounts, i, bal);
                    break;
                }
                case '2':
                {
                    long double dep;
                    cout << "Deposit: $";
                    cin >> dep;
                    my_accounts.account_deposit(accounts, i, dep);
                    break;
                }
                case '3': 
                {
                    long double wthdrl;
                    cout << "Withdraw: $";
                    cin >> wthdrl;
                    my_accounts.account_withdraw(accounts, i, wthdrl);
                    break;
                }
                case '4': 
                {
                    my_accounts.view_balance(accounts, i);
                    break;
                }
                case '5': 
                {
                    my_accounts.transfer(accounts, i);
                    break;
                }
                case ('l'):
                case ('L'):
                {
                    cout << "Goodbye, "; my_accounts.name(accounts, i);
                    managing_account = false;
                    break;
                }
                default:
                    cout << "Invalid Choice." << endl;
                    break;

                }
            }
            break;
        }
        }
    }
        return 0;
    }
 