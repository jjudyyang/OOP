#ifndef CURRENT_CONDITIONS_DISPLAY
#define CURRENT_CONDITIONS_DISPLAY

#include "Observer.h"
#include "DisplayElement.h"
#include "Subject.h"
#include <iostream>

class CurrentConditionsDisplay : public Observer, public DisplayElement{
    double temperature = 0.0f;
    double humidity = 0.0f;
    Subject *weatherData = nullptr; //pointer to concrete subject class

    public:
        CurrentConditionsDisplay()= default; //default constructor 
        CurrentConditionsDisplay(Subject *wd) : weatherData(wd){ //constructor which sets pointer
            weatherData->registerObserver(this); 
        }
        void update(double t, double h, double p) override ;
        void display() const override;

};
void CurrentConditionsDisplay::update(double t, double h, double p){
    temperature = t;
    humidity = h;
    display();
}

void CurrentConditionsDisplay::display() const {
    std::cout <<"Current Conditions: "<< temperature
    << "F degree and " << humidity << "%humidity"<<std::endl;
}

#endif