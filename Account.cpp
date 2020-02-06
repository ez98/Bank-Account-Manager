#include "Account.h"
#include <string>

Account::Account() {

}
Account::Account(std::string name) //Constructor 
    :name(name){
}
Account::Account(const Account &source) //Copy Constructor
    :Account { source.name } {

}
Account::~Account() { //Destructor

}
void Account::set_name(std::string n){
    name = n;
    }
std::string Account::get_name(){
    return name;
    }

double Account::view_balance(){
    return balance;
    }
//hi

