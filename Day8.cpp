// Strategy Design Pattern 

// We are going to understand this with the help of taking an example of Robots where we 
// will use multiple classes for the different works that a robot can do.

#include<iostream>
using namespace std;

class Robot{
public:
    void talk(){
       cout<<"I can Talk"; 
    }
    void walk(){
        cout<<"I can Walk";
    }
    void projection(){
        cout<<"This is the projection class";
    }
};

class Talkable : public Robot{
public:
    void projection(){
        cout<<"This is talkable class projection";
    }
};

class NonTalkable : public Robot{
public:
    void projection(){
        cout<<"This is Non-talkable class projection";
    }
    void talk(){
       cout<<"I cannot Talk"; 
    }
};

class Walkable : public Talkable{
public:
    void projection(){
        cout<<"This is the projection in walkable inherited from Talkable ";
    }
};

class NonWalkable : public Talkable{
public:
    void projection(){
        cout<<"This is the projection in Non-Walkable inherited from Talkable ";
    }
    void walk(){
        cout<<"I cannot walk";
    }
};

// And same heredity continue with Non-Talkable wala class !

// This is a wrong type because if we want to introduce new feature then we will have 
// to make changes in our classes which will violate our principle 

// Corrected Code :

class Talkable{
public:
    virtual void talkable() = 0;
};

class Walkable{
public:
    virtual void walkable() = 0;
};

class Flyable{
public:
    virtual void flyable() = 0;
};

class Projection{
public:
    virtual void projection() = 0;
};

class Robot2{
public: 
    // Talkable t;
    // Flyable f;
    // Walkable w;
    // Projection p;
};

// This is how we can make classes without breaking OCP and DRY principles 
// Currently i have not made the inherited class but we can make any robot by using these 
// rules and also we are able to add new methods to perform different functions.