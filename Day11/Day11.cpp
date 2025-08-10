// Building Food Delivery App (TOMATO)

// Functional Requirements:
// Users can search for restaurants based on location 
// Users can add items to cart
// Users can checkout by making payments 
// User should be notified once order placed successfully 

// Non-Functional Requirements:
// Each part of design should be scalable and modifiable 

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class menuItem{
private: 
    string code, name;
    int price;
public:
    menuItem(string code,string name,int price){
        this->code = code;
        this->name = name;
        this->price = price;
    }

    void getDetails(){
        cout<<"Code : "<<code<<endl;
        cout<<"Name : "<<name<<endl;
        cout<<"Price : "<<price<<endl;
    }

    int get_price(){
        return price;
    }
    
    string get_code() const {
        return code;
    }
};

class Restaurant{
private:
    static int fixed_restaurant_id;
    int restaurant_id;
    string name, location;
    vector<menuItem>menu;
public:
    Restaurant(string name,string location){
        this->name = name;
        this->location = location;
        restaurant_id = ++ fixed_restaurant_id;
    }

    string getLocation(){
        return location;
    }

    void getRestaurant(){
        cout<<"Restaurant name : "<<name<<endl;
        cout<<"Restaurant location : "<<location<<endl;
        cout<<"Restaurant id : "<<restaurant_id<<endl<<endl;
    }

    void additem(menuItem m){
        menu.push_back(m);
    }

    void show_Menu(){
        for (auto m : menu){
            m.getDetails();
        }
    }
    
    const vector<menuItem>& get_Menu() const{
        return menu;
    }
};

int Restaurant::fixed_restaurant_id = 0;

class Restaurant_Manager{
private:
    vector<Restaurant*>restaurant;

    Restaurant_Manager(){
        cout<<"A new restaurant manager created succesfully !!!"<<endl;
    }

    static Restaurant_Manager* Manager;

public:

    static Restaurant_Manager* CreateManager(){
        if (Manager == nullptr){
            Manager = new Restaurant_Manager();
        }
        return Manager;
    }

    void addRestaurant(Restaurant *r){
        restaurant.push_back(r);
    }

    void SearchByLocation(string Location){
        int i = 0;
        for (auto rest : restaurant){
            if (rest->getLocation() == Location){
                cout<<"Restaurant found successfully \n";
                cout<<"Restaurant Details : "<<endl;
                rest->getRestaurant();
                i++;
            }
        }
        if (!i){
            cout<<"No restaurants available at the location you entered ....."<<endl;
        }
        else {
            cout<<i<<" restaurant found successfully ."<<endl;
        }
    }

};

Restaurant_Manager* Restaurant_Manager :: Manager = nullptr;

class Cart{
private:
    Restaurant *rest = nullptr;
    vector<menuItem*>menu;
    double totalcost = 0;
public:

    Cart(){
        cout<<"Cart initialized successfully ....."<<endl;
    }

    void setRestaurant(Restaurant* r) {
        this->rest = r;
    }
    
    void add_to_cart(menuItem *item){
        if (!rest){
            cout<<"create restaurant first then add item to cart ."<<endl;
            return;
        }
        bool itemFound = false;
        for (const auto& restaurantItem : rest->get_Menu()){
            if (restaurantItem.get_code() == item->get_code()){
                itemFound = true;
                break;
            }
        }

        if (itemFound){
            menu.push_back(item);
            cout<<"Item added to cart successfully!\n";

        }
        else{
            cout<<"Error : No such item availaible in restaurant \n";
        }
    }

    void remove_from_cart(){
        menu.pop_back();
        cout<<"Item removed successfully "<<endl;
    }

    void get_Details(){
        for (auto p : menu){
            p->getDetails();
            totalcost += p->get_price();
        }
    }
    
    void get_Totalcost(){
        for (auto p : menu){
            totalcost += p->get_price();
        }
    }

    void total_cost(){
        get_Totalcost();
        if (totalcost == 0){
            cout<<"The cart is empty please selct some items before proceeding"<<endl;
            return ;
        }
        cout<<"\nThe total cost of items in the cart is : "<<totalcost<<endl;
    }

    double get_Total_cost(){
        return totalcost;
    }

};

class User{
private:
    static int fixed_user_id;
    int user_id;
    string name;
    string address;
    Cart cart;

public:
    User(string name,string address){
        this->name = name;
        this->address = address;
        this->user_id = ++fixed_user_id;
    }

    void get_User(){
        cout<<"User Details : \n";
        cout<<"User Name : "<<name<<endl;
        cout<<"User ID : "<<user_id<<endl;
        cout<<"User Address : "<<address<<endl<<endl;
    }

    string get_add(){
        return address;
    }

    void add_item(menuItem *it){
       cart.add_to_cart(it);
    }

    void remove_item(){
        cart.remove_from_cart();
    }

    void show_Cart(){
        cart.get_Details();
    }

    double get_total_cost(){
        cart.get_Total_cost();
    }
};

int User :: fixed_user_id = 0;

class pickup_order;
class delivery_order;

class order_factory{
public:
    virtual void create_order() = 0 ;
};

class now_order_factory : public order_factory{
private:
    pickup_order *pickup;
    delivery_order *delivery;

public:
    void create_order() override{
        cout<<"Order confirmed !!"<<endl;
    }
};

class schedule_order_factory : public order_factory{
private:
    string schedule_time;
    pickup_order *pickup;
    delivery_order *delivery;

public:
    void create_order() override{
        cout<<"\nEnter the schedule time (Hr:Min) : ";
        cin>>schedule_time;
        cout<<"Order confirmed !! && SCHEDULED TIME IS :"<<schedule_time<<endl;
    }
};

class Payment_Strategy;

class Order{
private:
    int order_id,inp;
    vector<menuItem>items;
    User *user;
    Restaurant *rest;
    Payment_Strategy *strategy = nullptr;
public:
    string get_user_add(){
        return user->get_add();
    }
    
    string get_rest_add(){
        return rest->getLocation();
    }

    virtual string get_type() = 0;

    void payment_gateway_selection(){
        cout<<"Which is your prefferd mode of payment : "<<endl;
        cout<<"1. Card \n2. UPI \n3.Netbanking"<<endl;
        cin>>inp;

        if (inp == 1){
            strategy = new card();
        }
        else if (inp == 2){
            strategy = new UPI();
        }
        else if (inp == 3){
            strategy = new NetBanking();
        }
        else{
            cout<<"Error : Enter a valid input !!!"<<endl;
            payment_gateway_selection();
        }
    }

    void payment_reciept(){
        payment_gateway_selection();
        strategy->pay_for_order(user->get_total_cost());
    }
};

class pickup_order : public Order{
private:
    string restAddress;
public:

    pickup_order(){
        restAddress = "";
    }

    void set_Address(){
        restAddress = get_rest_add(); 
    }
    
    string get_Address(string address){
        return restAddress; 
    }

    string get_type() override{
        return "Pickup";
    }
};

class delivery_order : public Order{
private:
    string userAddress;
public:
    delivery_order(){
        userAddress = "";
    }

    void set_Address(){
        userAddress = get_user_add(); 
    }

    string get_Address(){
        return userAddress; 
    }

    string get_type() override{
        return "Delivery";
    }
};

class Payment_Strategy{
public:
    virtual void pay_for_order(int price) = 0;

    virtual ~Payment_Strategy() = default;
};

class card : public Payment_Strategy{
public:

    card(){
        cout<<"Payment mode is card !!"<<endl;
    }

    void pay_for_order(int price) override{
        cout<<"So the payment of Rs. "<<price<<" for your order is done through card."<<endl;
    }
};

class UPI : public Payment_Strategy{
public:

    UPI(){
        cout<<"Payment mode is UPI !!"<<endl;
    }

    void pay_for_order(int price) override{
        cout<<"So the payment of Rs. "<<price<<" for your order is done through UPI."<<endl;
    }
};

class NetBanking : public Payment_Strategy{
public:

    NetBanking(){
        cout<<"Payment mode is Net Banking !!"<<endl;
    }

    void pay_for_order(int price) override{
        cout<<"So the payment of Rs. "<<price<<" for your order is done through NetBanking."<<endl;
    }
};

class Order_Manager{
    static Order_Manager *instance ;

    Order_Manager(){
        cout<<"New order manager created successfully !!"<<endl;
    }
public: 

     static Order_Manager* create_order_manager(){
        if (instance == nullptr){
            return instance = new Order_Manager();
        }
        return instance;
    }

    vector<Order*>order_list;

    void add_order(Order *order){
        order_list.push_back(order);
    }

    auto List_order(){
        for(auto m : order_list){
            return m;
        }
    }
};

Order_Manager *Order_Manager :: instance = nullptr;



int main(){
    // Restaurant *r = new Restaurant("Haldiram","Delhi");
    // Restaurant *k = new Restaurant("Bikaner","Mumbai");
    // r->getRestaurant();
    // k->getRestaurant();
    // r->additem(menuItem("p1","Chole Kulche",50));

    Restaurant_Manager* Manager1 = Restaurant_Manager::CreateManager();
    Restaurant_Manager* Manager2 = Restaurant_Manager::CreateManager();
    
    Manager1->addRestaurant(new Restaurant("AKC Bhojanalaya","Delhi"));
    Manager1->addRestaurant(new Restaurant("Haldiram","Delhi"));
    // Manager1->addRestaurant(k);
    Manager1->SearchByLocation("Delhi");

    User *user1 = new User("Aditya","Delhi");
    // User *user2 = new User("AKC","Bhopal");
    // user1->get_User();
    // user1->
    user1->add_item(new menuItem("p1","Chole Bhature",30));
    user1->show_Cart();

    // user2->get_User();


}