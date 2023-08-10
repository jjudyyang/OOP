#ifndef SUBJECT_H //if not defined 
#define SUBJECT_H //then define
#include "Observer.h"

//abstract subject class

class Subject{
    public:
        virtual ~Subject()= default; //destructor
        virtual void registerObserver(Observer *o) = 0;
        virtual void removeObserver(Observer *o) = 0;
        virtual void notifyObserver(Observer *o) = 0;
};


#endif 