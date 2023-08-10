#ifndef STATISTICS_DISPLAY
#define STATISTICS_DISPLAY
#include "Observer.h"
#include "Subject.h"
#include "DisplayElement.h"
#include <iostream>

class StatisticDisplay : public Observer, public DisplayElement{
    double tempSum = 0.0f;
    double minTemp = 0.0f;
    double maxTemp = 0.0f;
    int numberOfReadings = 0;
    Subject *weatherData = nullptr;

    StatisticDisplay() = default;  //default ctor
    StatisticDisplay(Subject *wd) : weatherData(wd){ //signing object up as observer
        weatherData->registerObserver(this);
    }
    void update(double t, double h, double p) override;
    void display() const override;

};

//define the fucntions for statistic display class 
void StatisticDisplay::update(double t, double h, double p){
    tempSum += t; //sum of all of the tempatures 
    ++numberOfReadings; // increase the number of readings
    if(t < minTemp){
        minTemp = t;
    }else if (t > maxTemp){
        maxTemp = t;
    }
    display(); //display the changes afterwards 
}

void StatisticDisplay::display()const {
    	std::cout << "Avg/Max/Min Temperature = " <<
		tempSum / numberOfReadings << "/" << maxTemp << "/" << minTemp << '\n';
} 
//note, do not need to put override 

#endif