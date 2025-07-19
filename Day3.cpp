#include<iostream>
using namespace std;
class Car{
private:
    string model;
    string Engnum;
    string Brand;
    int speed = 0;
public:
    Car(string m,string Engno,string brand){
        this->model = m;
        this->Engnum = Engno;
        this->Brand = brand;
    }
    void carDet();
    void startEng();
    void stopEng();
    void brake();
    void accelerate();
};

class manualCar : public Car{
public:
    void change_gear();
    void fuel_indication();
};

class elecCar : public Car{
public:
    void Battery_percentage();
    void is_batt_charging();
};

void Car :: carDet(){
    cout<<"Details of the following car is : "<<endl;
    cout<<"Brand :"<<Brand<<endl;
    cout<<"Engine number :"<<Engnum<<endl;
    cout<<"Model :"<<model<<endl;
}

void Car :: startEng(){
    cout<<endl<<endl;
    cout<<"            -----------------------------------"<<endl<<endl;
    cout<<"Car engine has been started successfully !!"<<endl;
    speed += 20;
}

void Car :: stopEng(){
    cout<<"Engine is going to stop and brakes are activated."<<endl;
    speed = 0;
    cout<<"Engine has been stopped..."<<endl<<endl;
        cout<<"            -----------------------------------"<<endl<<endl<<endl;
}

void Car :: brake(){
    if (speed >= 0){
        speed -= 10;
        cout<<"Brake applied succesfully !!"<<endl;
    }
    cout<<"Current speed : "<<speed<<endl;
}

void Car :: accelerate(){
    if (speed < 200){
        speed += 20;
        cout<<"Speed increased by 20 Km/h "<<endl;
    }
    else{
        cout<<"Please slow down Maximum limit reached !!"<<endl;
    }
    cout<<"Current speed : "<<speed<<endl;
}

void manualCar :: change_gear(){
    cout<<"Gear changed";
}



int main(){
    Car* car = new Car("Manual Transmission","ENG1234","BMW");
    car->carDet();
    car->startEng();
    car->accelerate();
    car->brake();
    car->stopEng();
}
