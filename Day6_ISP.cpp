#include<iostream>
using namespace std;

//Interface-Segregation Principle :  This principle state that if neccesary we can create multiple interfaces(Abstract Classes) in order to reduce complexiety and make code more understandable

// Example : 

class shape{
public:
    virtual void area() = 0;
    virtual void volume() = 0;
};

class square : public shape{
public:
    void area() override {
        cout<<"Area of square is side * side"<<endl;
    }
    void volume() override{
        cout<<"No Need of this function in this block "<<endl;
    }
};

class rectangle : public shape{
public:
    void area() override {
        cout<<"Area of rectangle is length * breadth"<<endl;
    }
    void volume() override{
        cout<<"No Need of this function in this block "<<endl;
    }
};

class cube : public shape{
public:
    void area() override {
        cout<<"Area of square is 6 * side * side"<<endl;
    }
    void volume() override{
        cout<<"Volume of square is side * side * side"<<endl;
    }
};

// Here we can see that there is no need of volume function in 2-D shapes like square and Rectangle but it is unneccesarily inherited so cope up with this situation we can create more interface classes.

// Corrected code :

class shape2d{
public:
    virtual void area() = 0 ;
};

class shape3d{
public:
    virtual void area() = 0;
    virtual void volume() = 0;
};

class Square : public shape2d{
public:
    void area() override {
        cout<<"Area of square is side * side"<<endl;
    }
};

class Rectangle : public shape2d{
public:
    void area() override {
        cout<<"Area of rectangle is length * breadth"<<endl;
    }
};

class Cube : public shape3d{
public:
    void area() override {
        cout<<"Area of square is 6 * side * side"<<endl;
    }
    void volume() override{
        cout<<"Volume of square is side * side * side"<<endl;
    }
};

// Now Above this is the correct demonstration of the Interface-Segregation Principle.