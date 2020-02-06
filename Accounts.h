#ifndef _ACCOUNTS_H_
#define _ACCOUNTS_H_
#include <string>
#include <vector>
#include "../../../../Desktop/CPPWorkspace/OO-P/Account.h"

class Accounts {
private:
	std::vector <Account> accounts;
public:
	Accounts();

	~Accounts();

	bool add_account(std::vector <Account> &accounts, std::string name); //Adds an Account

	void transfer(std::vector <Account> &accounts, int i); //Transfer Funds. Take in 2 integers. One for the current account and the other to transfer the fund to

	void set_account_balance(std::vector <Account> &accounts, int i, long double bal); // Update Account Balance

	void account_deposit(std::vector <Account>& accounts, int i, long double dep); //Deposit Funds into Account

	void account_withdraw(std::vector<Account>& accounts, int i, long double wthdrl); //Withdraw from balance

	void view_balance(std::vector<Account>& accounts, int i);

	void display_accounts(std::vector<Account>& accounts) const; //Displays a list of accounts available

	void name(std::vector<Account>& accounts, int i);
};











#endif
