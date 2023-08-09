#include "WeatherData.h"
#include "CurrentConditionsDisplay.h"
#include "StatisticsDisplay.h"
#include "ForcastDisplay.h"
#include "HeatIndex.h"
#include <iostream>
#include <memory>

int main()
{
	//creating weather station object
	auto weatherData = WeatherData();
	auto currentDisplay = CurrentConditionsDisplay(&weatherData); //connecting current condition display
	auto statsDisplay = StatisticsDisplay(&weatherData); //connecting statistics display
	auto forcastDisplay = ForcastDisplay(&weatherData); //connecting forcast display
	auto heatIndex = HeatIndex(&weatherData); // connecting heat index 
	weatherData.setMeasurements(80, 65, 30.4f); //updating the measurements 
	weatherData.setMeasurements(82, 70, 29.2f); // updating 
	weatherData.setMeasurements(78, 90, 29.2f);
	return 0;
}
