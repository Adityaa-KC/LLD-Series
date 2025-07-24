// Factory Design Pattern

#include<iostream>
using namespace std;

// Simple Factorty Method Example: 

class Burger{
public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};

class BasicBurger : public Burger{
public:
    void prepare() override{
        cout<<"Preparing Basic Burger!!"<<endl;
    }
};

class StdBurger : public Burger{
public:
    void prepare() override{
        cout<<"Preparing Standard Burger!!"<<endl;
    }
};

class PremiumBurger : public Burger{
public:
    void prepare() override{
        cout<<"Preparing Premium Burger!!"<<endl;
    }
};

class BurgerFactory{

public:
    static Burger* createburger(string type){
        if (type == "basic"){
            return new BasicBurger();
        }
        else if (type == "standard"){
            return new StdBurger();
        }
        else if (type == "premium"){
            return new PremiumBurger();
        }
        return nullptr;
    }
};

// int main(){

//     Burger *myburger = BurgerFactory::createburger("basic");

//     if (myburger){
//         myburger->prepare();
//     }
    
//     Burger *yourBurger = BurgerFactory::createburger("standard");
    
//     if (yourBurger){
//         yourBurger->prepare();
//     }

// }

// Factory Method Example:

class Burger1{
public:
    virtual void prepare() = 0;
    virtual ~Burger1() {}
};

class BasicBurger1 : public Burger1{
public:
    void prepare() override{
        cout<<"Preparing Basic Burger with less cheese and veggies"<<endl;
    }
};

class StdBurger1 : public Burger1{
public:
    void prepare() override{
        cout<<"Preparing Standard Burger with cheese,patties and more veggies"<<endl;
    }
};

class PremBurger1 : public Burger1{
public:
    void prepare() override{
        cout<<"Preparing Premium Burger with extra cheese, double patties and more veggies"<<endl;
    }
};


class BasicWheatBurger1 : public Burger1{
public:
    void prepare() override{
        cout<<"Preparing Basic Wheat Burger with less cheese and veggies"<<endl;
    }
};

class StdWheatBurger1 : public Burger1{
public:
    void prepare() override{
        cout<<"Preparing Standard Wheat Burger with cheese,patties and more veggies"<<endl;
    }
};

class PremWheatBurger1 : public Burger1{
public:
    void prepare() override{
        cout<<"Preparing Premium Wheat Burger with extra cheese, double patties and more veggies"<<endl;
    }
};

class GarlicBread{
public:
    virtual void Prepare() = 0;
    virtual ~GarlicBread() {}
};

class BasicGarlicBread : public GarlicBread{
public:
    void Prepare(){
        cout<<"Basic Garlic Bread making in progress"<<endl;
    }
};

class StdGarlicBread : public GarlicBread{
public:
    void Prepare(){
        cout<<"Standard Garlic Bread making in progress"<<endl;
    }
};

class PremiumGarlicBread : public GarlicBread{
public:
    void Prepare(){
        cout<<"Premium Garlic Bread making in progress"<<endl;
    }
};


class BasicWheatGarlicBread : public GarlicBread{
public:
    void Prepare(){
        cout<<"Basic Wheat Garlic Bread making in progress"<<endl;
    }
};

class StdWheatGarlicBread : public GarlicBread{
public:
    void Prepare(){
        cout<<"Standard Wheat Garlic Bread making in progress"<<endl;
    }
};

class PremiumWheatGarlicBread : public GarlicBread{
public:
    void Prepare(){
        cout<<"Premium Wheat Garlic Bread making in progress"<<endl;
    }
};



class BurgerFactory1{
public:
    virtual Burger1* CreateBurger(string type) = 0;
    virtual GarlicBread* CreateGarlic(string type) = 0;
    virtual ~BurgerFactory1() {}
};

class KingBurger : public BurgerFactory1{
public:
    Burger1* CreateBurger(string type) override{
        if (type == "basic"){
            return new BasicWheatBurger1();
        }
        else if (type == "standard"){
            return new StdWheatBurger1();
        }
        else if (type == "premium"){
            return new PremWheatBurger1();
        }
        return nullptr;
    }

    GarlicBread* CreateGarlic(string type){
        if (type == "basic"){
            return new BasicGarlicBread();
        }
        else if (type == "standard"){
            return new StdGarlicBread();
        }
        else if (type == "premium"){
            return new PremiumGarlicBread();
        }
        return nullptr;
    }


};

class SinghBurger : public BurgerFactory1{
public:
    Burger1* CreateBurger(string type) override{
        if (type == "basic"){
            return new BasicBurger1();
        }
        else if (type == "standard"){
            return new StdBurger1();
        }
        else if (type == "premium"){
            return new PremBurger1();
        }
        return nullptr;
    }

    GarlicBread* CreateGarlic(string type){
        if (type == "basic"){
            return new BasicWheatGarlicBread();
        }
        else if (type == "standard"){
            return new StdWheatGarlicBread();
        }
        else if (type == "premium"){
            return new PremiumWheatGarlicBread();
        }
        return nullptr;
    }
};


int main(){
    KingBurger *kb = new KingBurger();
    SinghBurger *sb = new SinghBurger();

    Burger1 *MyBurger = kb->CreateBurger("premium");
    Burger1 *YourBurger = sb->CreateBurger("premium");

    GarlicBread *MyGarlic = kb->CreateGarlic("premium");
    GarlicBread *YourGarlic = sb->CreateGarlic("premium");

    if (MyBurger){
        MyBurger->prepare();
    }
    if (YourBurger){
        YourBurger->prepare();
    }
    
    if (MyGarlic){
        MyGarlic->Prepare();
    }
    if (YourGarlic){
        YourGarlic->Prepare();
    }
}