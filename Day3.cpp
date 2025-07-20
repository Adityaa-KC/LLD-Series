#include<iostream>
using namespace std;
class Car{
private:
    string model;
    string Engnum;
    string Brand;
public:
    int speed = 0;
    Car(){
       cout<<"Welcome in the Beast Car !!"<<endl<<endl;
    }
    Car(string m,string Engno,string brand){
        this->model = m;
        this->Engnum = Engno;
        this->Brand = brand;
    }
    void setInfo();
    void carDet();
    void startEng();
    void stopEng();
    void brake();
    void accelerate();
};

class manualCar : public Car{
    int fuel = 10;
public:
    manualCar(){
        // setInfo();
    }
    void change_gear();
    void fuel_indication();
};

class elecCar : public Car{
    int bp = 100 ;
public:
    elecCar(){
        // setInfo();
    }
    void Battery_percentage();
    void is_batt_charging();
};

void Car :: setInfo(){
    cout<<"Enter model type :";
    cin>>model;
    cout<<"Enter Engine number :";
    cin>>Engnum;
    cout<<"Enter Car brand :";
    cin>>Brand;
    cout<<endl<<endl;
}



void Car :: carDet(){
    cout<<"Details of the following car is : "<<endl;
    cout<<"Brand :"<<Brand<<endl;
    cout<<"Engine number :"<<Engnum<<endl;
    cout<<"Model :"<<model<<" Transmission"<<endl;
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
    if (speed > 0){
        speed -= 10;
        cout<<"Brake applied succesfully !!"<<endl;
    }
    else 
    cout<<"Vehicle is standing "<<endl;
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
    cout<<"Gear changed"<<endl;
    fuel -= 1;
}

void manualCar :: fuel_indication(){
    if (fuel > 5)
    cout<<"Sufficient fuel"<<endl;
    else if (fuel>3)
    cout<<"Medium fuel"<<endl;
    else 
    cout<<"Go to Petrol Pump URGENTLY "<<endl;
}

void elecCar :: Battery_percentage(){
    cout<<"Battery Percentage : "<<bp<<"%"<<endl;
}

void elecCar :: is_batt_charging(){
    if (speed == 0)
    cout<<"Battery is charging "<<endl;
    else 
    cout<<"Battery is not charging "<<endl;
}



int main(){
    Car* car = new Car("Manual Transmission","ENG1234","BMW");
    car->carDet();
    car->startEng();
    car->accelerate();
    car->brake();
    car->stopEng();
    
    elecCar car2;
    car2.carDet();
    car2.startEng();
    car2.accelerate();
    car2.Battery_percentage();
    car2.is_batt_charging();
    car2.brake();
    car2.stopEng();
    
    manualCar car3;
    car3.carDet();
    car3.startEng();
    car3.accelerate();
    car3.change_gear();
    car3.fuel_indication();
    car3.brake();
    car3.stopEng();
}
