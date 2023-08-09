#include <iostream>
using namespace std;

class List{

    struct Node{
        int data;
        Node *next;
        Node(int data, Node *next): data{data}, next{next}{};
        ~Node(){delete next;}
    };

    Node *theList = nullptr; //list

    public:
    class Iterator{
        Node *p;
        Iterator(Node *p): p{p}{}
        public:
            friend class List; //List has access to all members of Iterator
            //iterator can access the private and protected members of List class
            //not bi directional, Iterator does not have access to private members of List
            int &operator*() {return p->data;}
            Iterator &operator++(){ p = p->next; return *this;} // star makes the pointer an object
            bool operator!=(const Iterator &other) const { return p != other.p; }      
    };

    List &addToFront(int n) { theList = new Node {n, theList}; return *this;}

    //iterate through list 
    int ith (int i){ // travel to i(th) element of the list
        Node *cur = theList;
        for( int index = 0; index < i; ++index){
            cur = cur->next;
        }
        return cur->data; // return the value at the i(th) element of the list
    }

    //other functions for list
    ~List(){ delete theList; }
    Iterator begin(){ return Iterator(theList); }
    Iterator end() { return Iterator(nullptr); }
};

int main(){
    List l;
    l.addToFront(0);
    l.addToFront(1);
    l.addToFront(2);
    l.addToFront(3);
    l.addToFront(4);

    cout<<l.ith(0)<<endl; //value is being added to the front

    cout<<"For loop 1: using iterator defination"<<endl;
    for(List::Iterator it = l.begin(); it != l.end(); ++it){
        cout<< *it <<endl; //accessing the value at it
    }
    
    cout<< " ------- " <<endl;
    cout<<"For loop 2 : auto"<<endl;
    //auto keyword is used for type inferencing 
    //compiler automatically deduce the type of variable based on initializer
    for(auto it = l.begin(); it != l.end(); ++it ){
        cout<<*it<<endl;
    }

    cout<< " ------- " <<endl;
    cout<<"For loop 3 : auto range based loop"<<endl;
    //range based loop - work with any container that supports iteration, and custom classes that have begin() and end() methods
    for(const auto i:l){ 
        cout<<i<<endl;
    }
    cout<< " ------- " <<endl;
    cout<<"For loop 4: auto reference "<<endl;

    for(auto &i : l){
        i++; //can mutate the values because it is a reference 
        cout << i << endl;
    }

    cout<< " ------- " <<endl;
    cout<<"For loop 5: test "<<endl;

    //print again to check if values are permantly modified by reference
    for(const auto i : l){
        cout<<i<<endl;
    }
    //it has been modifed 

    return 0;

}