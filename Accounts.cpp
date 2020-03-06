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
	for (auto& a : accounts) {
		if (a.get_name() == name)
			return false;
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
bool Accounts::display_accounts(vector<Account>& accounts) const {
	int i = 1;
	if (accounts.size() == 0) {
		return false;
	}
	cout << "----- ACCOUNTS -----" << endl;
	for (auto& x : accounts) {
		cout << i++ <<".) "<< x.get_name() << endl;
	}
}
void Accounts::name(vector<Account>& accounts, int i) {
	cout << accounts[i].get_name() << endl;
}

void Accounts::delete_account(std::vector<Account>& accounts, int i)
{
	accounts.erase(accounts.begin() + i);
	std::cout << "Successfully Deleted." << std::endl;
}
