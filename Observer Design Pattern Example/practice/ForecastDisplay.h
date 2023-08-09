#ifndef FORECAST_DISPLAY_H
#define FORECAST_DISPLAY_H

#include "Observer.h"
#include "Subject.h"
#include "DisplayElement.h"
#include <iostream>

class ForecastDisplay: public Observer, public DisplayElement{
    double currentPressure = 29.92f;
    double prevPressure = 0.0f;
    Subject *weatherData = nullptr;

    public:
    ForecastDisplay() = default;
    ForecastDisplay(Subject *wd) : weatherData(wd){
        weatherData->registerObserver(this);
    }
    void update(double t, double h, double p) override;
    void display() const override;

};

void ForecastDisplay::update(double t, double h, double p){
    prevPressure = currentPressure;
    currentPressure = p;
    display();
}

void ForecastDisplay::display() const{
	std::cout << "Forcast: ";
		if (currentPressure > prevPressure)
			std::cout << "Improving weather on the way!\n";
		else if (currentPressure == prevPressure)
			std::cout << "Forcast: More of the same\n";
		else if (currentPressure < prevPressure)
			std::cout << "Forcast: Watch out for cooler, rainy weather\n";
}

#endif