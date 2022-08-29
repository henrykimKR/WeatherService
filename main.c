/*
***********************************************************************************
						       Final Assessment
Full Name  : Seonghoon Kim			| Tsun Lung Lo			| Kin Shing Herman Yiu
Student ID#: 143080216				| 152179214				| 148733215
Email      : shkim61@myseneca.ca	| tlo18@myseneca.ca		| kyiu3@myseneca.ca
Section    : NAA					| NAA					| NAA

Authenticity Declaration:
We declare this submission is the result of our own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of our own creation.
***********************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "weather_service.h"

#define MAX_WEATHER 250
#define WEATHER_DATAFILE "weatherData.txt"

int main(void)
{
	struct WeatherRecord records[MAX_WEATHER] = { { {0} } };

	int nInputRecords;

	FILE* fp = fopen(WEATHER_DATAFILE, "r");

	nInputRecords = importWeatherDataFile(fp, records, MAX_WEATHER);

	menuMain(records, nInputRecords);

	return 0;
}