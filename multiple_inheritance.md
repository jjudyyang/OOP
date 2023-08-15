## Multiple Inheritance 
- can inherit from more than one class
- syntax for multiple inheritance is to give comma-seperated list of classes 
- ie class Monotreme: public Mammal, public Oviparous {}
- use scope resolution operator :: to specify which method we want 

### Issues 
- deadly diamond of death 

class A {
    public:
        int a = 100;
        A() {}
        virtual ~A(){}
};

class B: virtual public A{
    public:
        int b = 200;
        B() {}
        virtual ~B(){}
};

class C: virtual public A{
    public:
        int c = 300;
        C() {}
        virtual ~C(){}
};

class D: public B, public C{
    public:
    int d = 400;
    D(){}
    virtual ~D(){}
}

## Virtual Base class 
- when a base class is virtually inherited, it ensures that only one instance of its data members is shared among all the derived classes, regardless of how many times it appears in the inheritance hierachy
- this prevents duplicate instances of the base class data and resolves ambiguity 

ie. designing frameworks or libraries where you want to ensure a single shared instance of common base class 
