#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>

class Account {
    
private:
    std::string name;
    double balance{ 0.0 };
    
public:
    Account();
    Account(std::string name);
    Account(const Account &source);
    ~Account();

    void set_balance(double long bal){
        balance = bal;
        std::cout << "\n$" << bal << " has been successfully set as your account balance." << std::endl << std::endl;
        }
    void set_deposit(long double bal){
        balance += bal;
        std::cout << "\n$" << bal << " has been succesfully deposited into your account." << std::endl << std::endl;
        } 
    bool set_withdrawl(long double bal){
        if(balance - bal >= 0){
            balance -= bal;
            return true;
            }
        else 
            return false;
    }
    bool set_tranfer(long double bal) {
        if (balance - bal >= 0) {
            balance -= bal;
            return true;
        }
        else
            return false;
    }
    
    std::string get_name();
    void set_name(std::string n);
    double view_balance();
    
};


#endif // _ACCOUNT_H_
