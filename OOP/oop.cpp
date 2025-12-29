#include<bits/stdc++.h>
using namespace std;

class Bank{

    int Balance;

public:
    void setBalance(int Balance){
        this->Balance = Balance;
    }

    int showBalance(){
        return Balance;
    }

    // Default constructor
    Bank(){
        this->Balance = 0;
        cout << "Constructor Called" << endl;
    }

    // parameterized Constuctor
    Bank(int Balance){
        this->Balance = Balance;
        cout << "Parameterized Called" << endl;
    }

    // copy constructor
    Bank(Bank &obj){
        this->Balance = obj.Balance;
        cout << "this the copy constructor" << endl;
    }

    ~Bank(){
        cout << "This it the destructor" << endl;
    }

};

int main(){

    Bank customer; // statice memory allocation

    Bank* customer2 = new Bank; // dynamic memory allocation

    Bank customer3 = customer;
    
    Bank customer4(*customer2);

    delete customer2;

    return 0;

}