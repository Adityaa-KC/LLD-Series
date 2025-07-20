#include<iostream>
#include<vector>
using namespace std;

class Product{
public:
    string name;
    double price;
    Product(string name,double price){
        this->name = name;
        this->price = price;
    }
};

class Cart{
    vector<Product*>products;
public:
    void addProduct(Product *p){
        products.push_back(p);
    }

    const vector<Product*>& getProducts(){
        return products;
    }
};

class calcTotal{
    Cart *cart;
public:
    calcTotal(Cart *cart){
        this->cart = cart;
    }

    double Total(){
        double  total = 0;
        for(auto p : cart->getProducts()){
            total += p->price;
        }
        return total;
    }
};

class printInvoice{
private:
    Cart *cart;
public:
    printInvoice(Cart *cart){
        this->cart = cart;
    }

    void Invoice(){
        calcTotal *tot = new calcTotal(cart);
        cout<<"Product : Price"<<endl;
        for(auto p : cart->getProducts()){
            cout<<p->name<<" : $ "<<p->price<<endl;
        }
        cout<<"Total : $ "<<tot->Total()<<endl;
    }
};

class DBStorage{
public:
    virtual void Save2DB() = 0;
};

class SaveToDB : public DBStorage{
private:
    Cart *cart;
public:
    void Save2DB() override {
        cout<<"saved to Database sucessfully"<<endl;
    }
};

class saveToMongoDB :public DBStorage {
public:
    void Save2DB()override{
        cout<<"Saved to Mongo DB"<<endl;
    }
};

class FileSaved : public DBStorage{
public:
    void Save2DB() override{
        cout<<"File Saved locally"<<endl;
    }
};

int main(){
    Cart *cart = new Cart();

    cart->addProduct(new Product("Laptop",15000));
    cart->addProduct(new Product("KeyBoard",3000));
    cart->addProduct(new Product("Mouse",1000));
    cart->addProduct(new Product("USB",1000));

    printInvoice *PI = new printInvoice(cart);
    PI->Invoice();
    
    saveToMongoDB *mndb = new saveToMongoDB();
    mndb->Save2DB();
    SaveToDB *db = new SaveToDB();
    db->Save2DB();
    FileSaved *fs = new FileSaved();
    fs->Save2DB();
}