// Singleton Design Pattern 

#include<iostream>
#include<mutex>
using namespace std;

// In simle words this design pattern states that the object should be made once.

class Singleton {
private:
    static Singleton* instance;
    static mutex mtx;
    Singleton(){
        cout<<"Welcome to Singleton Class !! New object Created successfully"<<endl;
    }
public:
    static Singleton* createInstance(){
        if (instance == nullptr){
            lock_guard<mutex>lock(mtx);
            if (instance == nullptr){
            return instance = new Singleton();
            }
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main(){
    Singleton *s1 = Singleton::createInstance();
    Singleton *s2 = Singleton::createInstance();
    if (s1==s2){
        cout<<"Yeah, they are the same instance. 🎉";
    }
    else
        cout<<"Nope, they are not the same instance. 😭";

}