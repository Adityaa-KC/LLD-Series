#include<iostream>
using namespace std;

// SIGNATURE RULES

// 1. Method Argument Rule: This rule states that a child class must have the arguments that base class has passed in a function.
// Example :

class Base{
public:
    virtual void func1(string s1){
        cout<<s1;
    }
};

class Child: public Base{
public:
    void func1(string s1) override {
        cout<<s1;
    }
};

//Above we are performing function overriding and in this we are following method argument rule which is followed because when virtual function was overridden then same arguments were passd.

// 2. Return type rule : This rule states that the child class can return the base class object and also the parent class but cannot return the parent class's parent class object.

// Example :

class Animal{
public:
    void getAnimal(){
    cout<<"This is Animal class ."<<endl;
    }
};

class Dog : public Animal{
public:
    void getAnimal(){
    cout<<"This is Dog class ."<<endl;
    }
};

int main(){
    // Dog *ani = new Animal();  This will give error.
    Animal *ani = new Dog();
    Dog *anim = new Dog();
    ani->getAnimal();
    anim->getAnimal();
}

// Exception rule : This rule state that only narrow class or same class errors can be called by a class .



// #Property rule :
// 1. Invariant Rule 
// 2. History Constraints

// 1. Invariant Rule : This rule states that base class sets some boundaries that must be followed by child class.

// Example :
class Account{
public:
    Account(){
        cout<<"Important information : Balance should be +ve "<<endl;
    }
    int balance = 10000;
    void getbalance(){
        cout<<balance;
    }
};


class CheatAcc : public Account{
public:
    int balance = -10;
    void getbalance(){
        cout<<balance;
    }
};

// Here the child is not following the rule that balance should be positive so the invariant rule is broken.

// History Constraints : This rule states that the history of the base class should be followed .

// Example : In base class withdrawls are allowed so it will also be in child class.

// # Method Rule :
// 1. Pre-Condition 
// 2. Post-Condition

// 1. Pre-Condition : Child class can weaker the rule ,it is allowed

// Example :

class createPass{
public:
    createPass(){
        cout<<"Pass length should be greater than 8 character"<<endl;
    }
};

class childcreatePass : public createPass{
public:
    childcreatePass(){
        cout<<"Pass length should be greater than 6 character"<<endl;
    }
};

// Here the inherited class reduced the pass length criteria but still it can be substituted in place of base class because client will create a pass of length more than 8 character because they has the knowledge of base class which has a limit of pass length more than 8 chars and this scenario also fits in child class .

// 2. Post-Condition : This condition says that rule in child class can be more strengthened.

// Example :

class car{
public:
    
    car(){
        cout<<"Welcome to our car"<<endl;
    }
    
    void brake(){
        cout<<"Brakes are applied "<<endl;
    }
};


class Eleccar : public car{
public:
    
    Eleccar(){
        cout<<"Welcome to our Electric car"<<endl;
    }
    
    void brake(){
        cout<<"Brakes are applied "<<endl;
        cout<<"Battery chsrging has started !!!"<<endl;
    }

};

// Here child class has strengthened the base class feature by adding battery charging feature during brake.

