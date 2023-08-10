#ifndef WEATHER_DATA_H
#define WEATHER_DATA_H

#include <list>
#include "Observer.h"
#include "Subject.h"

class WeatherData : public Subject{
    public:
        WeatherData() = default;

        void registerObserver( Observer *o) override {observers.push_back(o);}
        void removeObserver( Observer *o) override;
        void notifyObserver() override;


        //functions relevant to weather data
        void measurementChanged() { notifyObserver();}
        void setMeasurements(const double &t, const double &h, const double &p);

    //private variables 
    private:
        double tempature = 0.0f;
        double humidity = 0.0f;
        double pressure = 0.0f;
        list< Observer *> observers = {}; //vector of observers 

}

//implementing the functions (would do in .cc file)
WeatherData::removeObserver(Observer *o){
    if(!observers.empty())
        std::erase(observers, o);
}

WeatherData::WeatherData(Observer *o){
    //iterate throughthe list of vectors and update each one
    for( auto o: observers){
        o->update(tempature, humidity, pressure);
    }
}

WeatherData::setMeasurements(const double &t, const double &h, const double &p){
    temperature = t;
    humidity = h;
    pressure = p;
    measurementChanged();
}

#endif