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

#ifndef WEATHER_SERVICE_H
#define WEATHER_SERVICE_H

#define VIEW_ALL_PAGE_LIMIT 15

#define N_REGIONS 4
#define N_MONTHS 12
#define N_LOCATIONS 8

#define REGION_NAME_LEN 8
#define MONTH_NAME_LEN 9
#define LOCATION_NAME_LEN 15

struct Date 
{
    int month;
    int year;
};

struct Location 
{
    int regionCode;
    char name[LOCATION_NAME_LEN + 1];
};

struct WeatherRecord 
{
    struct Date date;
    double precipAmt;
    struct Location location;
    char unit;
};

struct ByRegion
{
    int regionNum;
    char regionName[REGION_NAME_LEN + 1];
};

struct ByMonth
{
    char monthName[MONTH_NAME_LEN + 1];
};

struct ByLocation
{
    char locationName[LOCATION_NAME_LEN + 1];
};

struct SortData
{
    int precip;
    struct ByRegion regionData;
    struct ByMonth monthData;
    struct ByLocation locationData;
};

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// Main menu (hub) for application
void menuMain(struct WeatherRecord* data, int nRecords);

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// Display all data of weatherData.txt
void viewAll(const struct WeatherRecord* data, int nRecords);

// Display precipitation sorted by region
void viewByRegion(const struct WeatherRecord* data, int nRecords);

// Display precipitation sorted by month
void viewByMonth(const struct WeatherRecord* data, int nRecords);

// Display precipitation sorted by location
void viewByLocation(const struct WeatherRecord* data, int nRecords);


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import weather data from file into an Weather struct pointer (returns the number of records read)
int importWeatherDataFile(FILE* fp, struct WeatherRecord* data, int max);


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Calculate annual precipitation
int calPrecipTotal(const struct SortData* data, int max);

// Convert precipitation to Mm
int convertToMm(double precip, char unit);

// Ascending order bubble sort function
void ascendBubbleSort(struct SortData* sortdata, int itemCount);

// Descending order bubble sort function
void descendBubbleSort(struct SortData* sortData, int itemCount);

#endif // !WEATHER_SERVICE_H

