#include<iostream>
#include<vector>
using namespace std;
// Single Responsiility Principle - SOP

class Product{
public:
    string name;
    double price;

    Product(string name,double price){
        this->name = name;
        this->price = price;
    }
};
class shoppingCart{
private:
    vector<Product*>products;
public:
    void addProduct(Product *p){
        products.push_back(p);
    }

    const vector<Product*>& getProduct(){
        return products;
    }

    double calculateTotal(){
        double total = 0;
        for (auto p : products){
            total += p->price;
        }
        return total;
    }
};

class shoppingCartPrinter{
private:
    shoppingCart *cart;
public:
    shoppingCartPrinter(shoppingCart *cart){
        this->cart = cart;
    }

    void printInvoice(){
        cout<<"Shopping Cart Invoice :\n";
        for(auto p : cart->getProduct()){
            cout<< p->name <<" : $"<<p->price<<endl;
        }
        cout<<"Total Price : : $"<<cart->calculateTotal()<<endl;
    }

};

class saveToDB{
private:
    shoppingCart *cart;

public:
    saveToDB(shoppingCart *cart){
        this->cart = cart;
    }

    void save2db(){
        cout<<"Data saved to database successfully !"<<endl;
    }
};

int main(){
    shoppingCart *cart = new shoppingCart();
    
    cart->addProduct(new Product("Laptop",15000));
    cart->addProduct(new Product("Keyboard",3000));
    cart->addProduct(new Product("Mouse",2000));

    shoppingCartPrinter *printer = new shoppingCartPrinter(cart);
    printer->printInvoice();

    saveToDB *db = new saveToDB(cart);
    db->save2db();

    return 0;

}