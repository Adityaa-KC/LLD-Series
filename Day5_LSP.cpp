#include<iostream>
using namespace std;
// Liskov Substitution Principle states that a child class must be substitutable in place of base class when accessed by client.

class witdrwableAccount {
public:
    string name;
    double balance = 100000;
    virtual void withdraw(double mon) = 0;
    virtual void deposit(double mon) = 0;
    virtual void showBal() = 0;
};

class Non_witdrwableAccount {
public:
    string name;
    double balance = 100000;
    virtual void deposit(double mon) = 0;
    virtual void showBal() = 0;
}; 

class currentAcc : public witdrwableAccount{
public:

    currentAcc(string name){
        this->name = name;
        cout<<"Welcome "<<name<<" to your Current Account."<<endl;
    }
    void withdraw(double mon) override {
        if (mon > balance){
            cout<<"Insufficient funds in your Account !!!"<<endl;
        }
        else{
            balance -= mon;
            cout<<mon<<"$ withdrawn successfully from your Account."<<endl;
            cout<<"Remaining Balance : "<<balance<<"$"<<endl;
        }
    }

    void deposit(double mon) override {
        balance += mon ;
        cout<<mon<<"$ deposited sucessfully in your Account"<<endl;
        cout<<"Updated balance : $"<<balance<<endl;
    }

    void showBal() override {
        cout<<"Your Account balance is : $"<<balance<<endl;
    }

};


class FixedAcc : public Non_witdrwableAccount{
public:
    FixedAcc(string name){
        this->name = name;
        cout<<"Welcome "<<name<<" to your Fixed Account."<<endl;
    }

    void deposit(double mon) override {
        balance += mon ;
        cout<<mon<<"$ deposited sucessfully in your Account"<<endl;
        cout<<"Updated balance : $"<<balance<<endl;
    }

    void showBal() override {
        cout<<"Your Account balance is : $"<<balance<<endl;
    }

};

int main(){

    currentAcc *CA = new currentAcc("ADITYA");
    CA->deposit(5000);
    CA->withdraw(20000);
    CA->showBal();
    cout<<endl<<endl;

    FixedAcc *FA = new FixedAcc("AYUSH");
    FA->deposit(5000);
    FA->showBal();
}