#ifndef OBSERVER_H //preprocessor symbol that checks if symbol observer_h has been defined before
#define OBSERVER_H //it not defined, defines observer symbol

//abstract observer class 

//pure virtual
class Observer{
    public:
        virtual ~Observer() = default;
        virtual void update( double t, double h, double p) = 0;
};

#endif /* ifndef OBSERVER_H */
