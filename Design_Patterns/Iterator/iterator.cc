//make abstract class to factor out common functions 
class AbstractIterator{
    public:
        virtual int &operator*() = 0; // abstract class
        virtual AbstractIterator &operator++();
        virtual bool operator=(const AbstractIterator &other)const=0;
        virtual ~AbstractIterator();
};

//increment operator
//= operator

class List{
    //...
    public:
        class Iterator: public AbstractIterator{
            //override abstract iterator function and implement them
    };

};

class Set{
    public:
        class Iterator: public AbstractIterator{
            //override abstract iterator function and implement them here
        };

};

//now it is possible to write code which works for both sets and lists
//since both iterators inherit from abstract iterator

//e.g. this would work for both lists and sets 
void for_each(AbstractIterator &start, AbstractIterator &end, void(*f)(int)){
    while(start != end){ // have not been implemented yet 
        f(*start);
        ++start;
    }
}