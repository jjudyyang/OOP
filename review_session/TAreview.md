### Review Session 

this - disambiguate data field from parameter 
this->real = real;

to access member through pointer, dereference 

objectName->memberName = (*objectName).memberName 

## Constructor
- no arugments, default ctor
- class have only one default constructor
- return type is **implict**, ctor always returns the object constructed 
- if ctor not written, compiler produces default 

- if we define own ctor, lose both implicity declared ctor and list initialization 

some members can only be intialized by MIL
- const 
- reference 
- object members where the object class doesn't have default ctor

## Destructor 
- method called when object is destroyed 
- heap allocated and delete is called 
- or when it goes out of scope

- default dtor - calls dtors for all data fields that are objects 
- will not call delete on pointers
- no return type 

## LValue and RValue
- lvalue - can access address 
- denoted by &

- rvalue - is not lvalue
- denoted by &&

## Copy Ctor
- used to create copies of objects 
- compiler generates implict copy of fields, only makes shallow copies 

ClassName (const ClassName & other)

deep copy created 
Node (const Node & other): value{n.value}, next{nullptr}, prev{nullptr}{
    if(other.next){
        next = new Node(other.next);
    }
    if(other.prev){
        prev = new Node(*other.prev);
        prev->next = this;
    }
}

## Copy Assignment Operator 
- assign exisitng object to another existing object
- n = m
- not copy ctor because already constructed

Node & Node::operator=( const Node & other){
    if(this == &other){
        return *this; // check for self assignemnt
    }
    Node *copy = next ? new Node{*other.next} : nullptr;
    delete next;
    next = copy;
    copy = nullptr;
    value = other.value;
    if(next != nullptr){
        next->prev = this;
    }
    return *this;
}

##Copy/Swap Idiom 
TODO

## Move Constructor 
- construct object from rvalue (values returned from function/operators, literals)
- avoid copying 

Node::Node( Node && o): value{o.value}, next{o.next}{
    if(next != nullptr) next->prev = this;
    o.next = nullptr;
}

## Move Assignment
Node n1{3}, n2{1};
n2 = plus(n1, 2);

## Const Modifer 
- given const object, only const methods can modify 

## Static Modifier
- member of class is static which indicates not associated with any object of class,
- stored globally and independently 
- non-const static variable must be initialized outside of class 

Member functions can also be declared static

## Comparing Objects 
- operator overloading, can use <,>, <=, >=, ==


Writing "= default" after declaration will allow compiler to generate a comparison operator that compares all the fields in lexicographical order 

## Spaceship
auto operator<=> (const C&, const C&) = default

## Nested Classes 
- classes that doesn't make sense to exist on its own
- example is implementing "wrapper" class - for some structure to restrict others' ability to alter the class 

class LinkedList{
    struct Node{
        int val;
        Node *next;
    };

    int numNodes;
    Node *head;
    Node *tail;

    public:
        LinkedList();
        LinkedList( int amount, int what );
        void insertHead( int value ); void insertTail( int value );
        void remove(int index);
};
- access Node via LinkedList::Node
- Node struct is private, not able to create instances of Node's outside of the LinkedList class 

## Iterators 
- implemented with the following functions with in the container class 

- (Container::Iterator)
- Container::end()
- Container::Iterator::operator++()
- Container::Iterator::operator!=(const Iterator &other)
- Container::Iterator::operator*()

## Class Relationships
- inheritance (is-a) : class B is class A. An instance of class B can be used in any situation where an instance of class A can be used 
- converse is not true. Class A cannot always be used where instance of class B can be used 
- if a class A has a pointer to an instance of class B, you cannot know if the relationship is composition or aggregation wihtout looking at documentation or code 

- aggregation (has-a): class A has an instance of class B. This means that class A is not responsible for deleting the instance of class B
- if object of class A is deleted, the instance of class B associated with it lives on
- multiple objects of class A can share the same instance of class B

class B {...}

class A{
    B b1; // this is composition 
    B *b2; // this could be composition or aggregation
}

## Inheritance 
class A{
    int a;
    public:
        explicit A(int a) : a{a} {}
};
class B : public A{
    int b;
    public:
        B(int a, int b): A{a}, b{a} {}
};

## Encapsulation and Inheritance 
- if A has fields that are private, B cannot access these fields
- protected keyword: members that are protected can be accessed directly by subclasses but cannot be accessed by the public 
- ^^ also breaks encapsulation

## virtual AND override 
- declaring method virtual means if we override it in subclass, the subclass version of method will be called through polymorphic pointers or reference 

## Pure Virutal ( = 0 )
- subclasses need to provide an implementation

## Abstract Classes 
- not instantiable, can not create objects of abstract classes 
- purpose to allow subclasses to inherit from a base class containing information that is common to all subclasses, but it doesn't make sense to have instance of the base class 
- subclass of abstract class is also abstract unless it implemented all pure virutal methods of the base class, which case it becomes concrete

- we make the destructor virutal because it is ALWAYS called when a derived class is destroyed 

- virtual destructors must have implementation because destructor is called in reverse order of inheritance when a derived class is destroyed 

## Object Slicing
-  when derived class object is assigned to a base class object, additional attributes of a derived class objec are sliced off to form the base class object

## Exception Handling 
- catch exceptions with try and catch blocks 
- can throw anything in C++ including exception objects, strings, integers, etc
- always throw as references -> object slicing and to ensure the destructor for the exception is run 

### Levels of Exception Safety 
- basic 
    - data in valid state and all class invariants are maintained
- strong 
    - data will appear as if nothing happened 
- no throw 
    - exception is never thrown and the function must always succed 

## Smart Pointers
- prevent mem leaks 
- wraps a 'raw' pointer to manage the lifetime of the object being pointed to

## RAII
- wrapper class for raw pointers 
- relies on the C++ guarantee that when an exception is raised, stack allocated memory will be reclaimed
- destructors for stack objects will be run when the object goes out of scope

unique_ptr : holds owned pointer to heap data
shared_ptr : holds owned pointer to heap data, allowing shared ownership
weak_ptr : holds non-owning pointer to heap data, must be converted to shared_ptr before use

## Casting 
- convert a variable of type to another type 
static_cast - always suceed, user guareentee 
dynamic_cast - ...
reinterpret_cast - anything to anything




