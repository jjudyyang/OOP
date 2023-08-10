#include <iostream>
#include <memory>

using namespace std;

struct Fruit { 
    virtual ~Fruit(){}; 
};
struct Apple : public Fruit{  
    string nameA = "apple";
};
struct Banana : public Fruit{  
    string nameB = "banana";
};

void whatFruit(shared_ptr<Fruit> f){}

int main(){
    //1. static casting 
    //  used when user is taking full responsibility of type conversion 
    //  can guarantee the conversion will happen correctly 
    //  NOTE: performs conversions at compile-time without any runtime checks
    double d = 5.6;
    int i = 4;
    i = static_cast<int>(d);
    cout << i << endl; // output 5, floor is applied (last part is cut off)

    //can you cast the other way! yes 
    double d2 = 4.2;
    int i2 = 2;
    d2 = static_cast<double>(i2); // inside angle brackets is what we want to cast it into
    cout<< d2 << endl; //becomes 2

    //extension, could also cast string to char? char to string? NO YOU CAN'T
    string myString = "j";
    //char myChar = static_cast<string>(myString); //doesn't compile

    //TYPES OF CONVERSIONS OF STATIC CAST
        //1. Numeric Conversions 
        // between INT, DOUBLE, FLOAT

        //2. Pointer Conversion
        // converting between pointers to related classes 
        // converting between pointers to a base class and derived class with an inheritance hierarchy

        // 4. Implict Conversions 
        // between built types like 'char' and 'int'
        // true/false 0/1

    //2. Reinterpret Casting 
        // new_type = reinterpret_cast<new_type>(expression);
    //  used to reintrept an object as another object
    //  one poiner or reference type to another
    //  regardless of compatibility

    //notes example.
        // all pointers point to some address in memory, and that all addresses have a numeric value
        // use reinterpret_cast to reinterpret the pointer as its numeric value


    Apple a;
    Banana *b = reinterpret_cast<Banana *>(&a);
    cout << b->nameB << endl; // outputs apple
    //if variable names different, still reinterpreted

    //3. Const Cast
    // used to bypass restrictions with const 
    // stop const poisoning
    int x = 3;
    const int &y = x; //y is a const reference to x
    const_cast<int &>(y) = 4;
    cout << y << endl; // outputs 4 even tho const was defined to be 3

    //4. Dynamic Cast
    // used as a safe check to see if type is convertible
    // if not then throws an exception
    // must have at least 1 virtual method to supprt dynamic cast so polymorphic
    // make decisions based on RTTI (run time type information)
    Fruit *f = new Apple;
    Apple *ap = dynamic_cast<Apple *>(f);
    cout << ap->nameA << endl; //apple

    // SMART POINTER CASTING

    //DYNAMIC
    //1. Dynamic Pointer Casting for smart pointers
    shared_ptr<Fruit> ba = make_shared<Banana>();

    if (dynamic_pointer_cast<Apple>(ba)){
        cout<< "Apple"<<endl;
    }else if(dynamic_pointer_cast<Banana>(ba)){
        cout<<"Banana"<<endl;
    }else{
        cout<<"Fruit"<<endl;
    }

    //STATIC
    //2. Static Pointer Casting for smart pointers 
    shared_ptr<Fruit> ba2 = make_shared<Banana>();
    if (static_pointer_cast<Banana>(ba2)){
        cout<< "Banana"<<endl;
    }

    //3. Const pointer casting for smart pointer
    shared_ptr<int> foo;
    shared_ptr<const int> bar;

    foo = make_shared<int>(10);
    bar = const_pointer_cast<const int>(foo); // 10
    cout<< * bar << endl;    

    return 0;
}