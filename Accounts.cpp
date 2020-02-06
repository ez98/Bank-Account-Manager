#include "Accounts.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Accounts::Accounts() { //Constructor

}

Accounts::~Accounts() { //Destructor

}

bool Accounts::add_account(vector<Account>& accounts, string name){
	size_t size = accounts.size();
	for (size_t i{ 0 }; i < size; i++) {
		if (accounts[i].get_name() == name) {
			return false;
		}
		else
			continue;
		break;
	}
	Account addAccount(name);
	accounts.push_back(addAccount);
	return true;
}

void Accounts::set_account_balance(vector<Account>& accounts,int i,long double bal) {
	accounts[i].set_balance(bal);
}
void Accounts::account_deposit(vector <Account>& accounts, int i, long double dep) {
	accounts[i].set_deposit(dep);
}
void Accounts::account_withdraw(vector<Account>& accounts, int i, long double wthdrl) {
	if (accounts[i].set_withdrawl(wthdrl))
		cout << "\n$" << wthdrl << " has been successfully withdrawn from your account." << endl;
	else
		cout << "\nInsufficient Funds." << endl;
}
void Accounts::view_balance(std::vector<Account>& accounts, int i) {
	cout << "\nBalance: $" << accounts[i].view_balance() << endl;
}
void Accounts::transfer(vector <Account>& accounts, int i) { //make sure to subtract funds that have been transfered and check to see if available
	int j;
	long double tran;
	display_accounts(accounts);
	cout << "Choose an Account to transfer to: ";
	cin >> j;
	cout << "\nHow much would you like to transfer to " << accounts[j - 1].get_name() << "'s account?: $";
	cin >> tran;
	if (accounts[i].set_tranfer(tran)) 
	{
		accounts[j - 1].set_deposit(tran);
		cout << "\n$" << tran << " has been successfully tranfered to " << accounts[j - 1].get_name() << "'s account." << endl;
	}
	else
	{
		cout << "Insufficent funds!" << endl;
	}
	
}
void Accounts::display_accounts(vector<Account>& accounts) const {
	size_t size = accounts.size();
	cout << "----- ACCOUNTS -----" << endl;
	for (size_t i{ 0 }; i < size; i++) {
		cout << i + 1 << ".)" << accounts[i].get_name() << endl;
	}
}
void Accounts::name(vector<Account>& accounts, int i) {
	cout << accounts[i].get_name() << endl;
}