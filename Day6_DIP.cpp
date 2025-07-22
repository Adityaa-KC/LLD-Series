#include<iostream>
using namespace std;

// Dependency-Inversion Principle : This principle states that high level module can not communicate directly(tightly coupled) but can communicate through an interface(abstract class).

// Example code :

class DB{
public:
    virtual void savetodb() = 0;
};

class Save2MongoDB : public DB{
public:
    void savetodb() override{
        cout<<"Saved to Mongo Database"<<endl;
    }
};

class Save2MSQLDB : public DB{
public:
    void savetodb() override{
        cout<<"Saved to My SQL Database"<<endl;
    }
};

class userService{
private:
    DB *db;
public:
    userService(DB * database){
        db = database;
    }

    void save2db(){
        db->savetodb();
    }
};

int main(){

    Save2MongoDB *mgdb = new Save2MongoDB();
    Save2MSQLDB *msql = new Save2MSQLDB();

    userService *us1 = new userService(mgdb);
    userService *us2 = new userService(msql);

    us1->save2db();
    us2->save2db();
}

// Here we have used database class as an interface between classes that are saving data to database and user service class, This perfectly demonstrates the Dependency Inversion Principle

