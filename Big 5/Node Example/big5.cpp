#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node();
    Node(int d);

    //big 5
    ~Node();
    Node(const Node &other);
    Node(Node &&other);
    Node &operator=(const Node &other);
    Node &operator=(Node &&other);
};

//implementation 

Node::Node():data{0}, next{nullptr}{
    cout<<"default constructor called" << endl;
}

Node::Node(int d): data{d}, next{nullptr}{
    cout<<"Overloaded constructor called" << endl;
}

Node::~Node(){
    cout <<"Destructor called"<<endl;
    delete next;
}

//copy constructor 
Node::Node(const Node &other): data{other.data}, next{other.next}{
    cout<<"copy constructor called"<<endl;
}

Node::Node(Node &&other): data{other.data}, next{other.next}{
    cout<<"move constructor called" <<endl;
    //kill the old one
    other.next = nullptr;
    other.data = 0;
}

//want to return a reference to a node
//"this" refers to a pointer of the current object 
//"*this" dereferences the pointer to give you current object 
//remember when this is given a star, it is the current object

Node &Node::operator=(const Node &other){
    cout<<"copy assignment operator"<<endl;
    
    if(this == &other){
        return *this;
    }
    delete next; //deletes the next for the current object (to prevent memory leaks)
    data = other.data; //sets this object data to other object data
    next = other.next ? new Node(*other.next) : nullptr; //if (condition) : true : false
    //if next node of other is not nullptr, creates new node and intializes it to the pointer of *other.next
    return *this; // return object itself 

}

//moves data from other to this
//since &&other is an r value (temporary), after move assignment, other might be left in a valid but unspecifed state
Node &Node::operator=(Node &&other){
    cout<<"move assignment operator"<<endl;
    swap(data, other.data); 
    swap(next, other.next);
    return *this;
}

int main(){
    cout<<"Big 5 Test: "<<endl;
    cout << "----------" << endl;

    Node *a = new Node(3); // overloading ctor
    Node *b = new Node(*a); //copy ctor

    cout << "----------" << endl;

    Node *c = new Node; // default ctor
    *c = *b; //copy assn

    cout << "----------" << endl;

    Node *d = new Node(move(*c)); //move ctor

    cout << "----------" << endl;

    Node *e = new Node;
    *e = move(*d); // move assignment

    cout << "----------" << endl;

    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
}