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
#include <string.h>

#include "weather_service.h"
#include "core.h"


// Main menu (hub) for application
void menuMain(struct WeatherRecord* data, int nRecords)
{
	int selection;

	do
	{
		printf("=======================================================\n"
		  	   "         Ontario Weather Analysis Service\n"
			   "                  Year: %d\n"
			   "=======================================================\n"
			   "1. View all data\n"
			   "2. View by region (sorted DESCENDING by precip.)\n"
			   "3. View by month (sorted ASCENDING by precip.)\n"
			   "4. View by location name (sorted DESCENDING by precip.)\n"
			   "-------------------------------------------------------\n"
			   "0. Exit\n"
			   "-------------------------------------------------------\n"
			   "Selection: ", data->date.year);
		selection = inputIntRange(0, 4);
		putchar('\n');
		switch (selection)
		{
			case 0:
				printf("Application Terminated!\n");
				break;
			case 1:
				viewAll(data, nRecords);
				break;
			case 2:
				viewByRegion(data, nRecords);
				break;
			case 3:
				viewByMonth(data, nRecords);
				break;
			case 4:
				viewByLocation(data, nRecords);
				break;
		}
	} while (selection);
}

// Display all data of weatherData.txt
void viewAll(const struct WeatherRecord* data, int nRecords)
{
	int i = 0;

	printf("Year Month Precip.Amt Unit Region Name\n");
	printf("---- ----- ---------- ---- ------ ---------------\n");

	while (i < nRecords)
	{
		printf("%d    %02d %10.1lf %4c %6d %s\n",
			data[i].date.year,
			data[i].date.month,
			data[i].precipAmt,
			data[i].unit,
			data[i].location.regionCode,
			data[i].location.name);
		i++;

		if (i % VIEW_ALL_PAGE_LIMIT == 0)
		{
			suspend();
		}
	}
	printf("\n");
}

// Display precipitation sorted by region
void viewByRegion(const struct WeatherRecord* data, int nRecords)
{
	int precipTotal = 0;
	double precipAvg = 0;
	int i, j;

	struct SortData sortData[N_REGIONS] = { {0} };
	struct ByRegion regionData[N_REGIONS] =
	{
		{10, "Western"}, 
		{20, "Northern"},
		{30, "Eastern"},
		{40, "Central"}
	};

	// Assign the 'regionData' of sortData to 'regionData' initialized
	for (i = 0; i < N_REGIONS; i++)
	{
		sortData[i].regionData = regionData[i];
	}

	// Calculate the sum of repcipitation for each region
	for (i = 0; i < nRecords; i++)
	{
		for (j = 0; j < N_REGIONS + 1; j++)
		{
			if (data[i].location.regionCode == ((j + 1) * 10))
			{
				sortData[j].precip += convertToMm(data[i].precipAmt, data[i].unit);
			}
		}
	}

	// Call function to sort by descending order
	descendBubbleSort(sortData, N_REGIONS);

	// Call function to calculate total precipitation
	precipTotal = calPrecipTotal(sortData, N_REGIONS);

	// Call function to calculate average precipitaton 
	precipAvg = (double)precipTotal / N_REGIONS;

	// Display result
	printf("Region Name     Precip(mm)\n"
	       "------ -------- ----------\n");
	for (i = 0; i < N_REGIONS; i++)
	{
		printf("%6d %-8s %10d\n", sortData[i].regionData.regionNum, sortData[i].regionData.regionName, sortData[i].precip);
	}

	printf("------ -------- ----------\n"
		   "         Total: %10d\n"
		   "       Average: %10.2lf\n\n", precipTotal, precipAvg);

}

// Display precipitation sorted by month
void viewByMonth(const struct WeatherRecord* data, int nRecords)
{
	int precipTotal = 0;
	double precipAvg = 0;
	int i, j;

	struct SortData sortData[N_MONTHS] = { {0} };
	struct ByMonth monthData[N_MONTHS] =
	{
		{"January"},	{"February"},	{"March"},		{"April"},  
		{"May"},		{"June"},		{"July"},		{"August"}, 
		{"September"},  {"October"},	{"November"},	{"December"}
	};

	// Assign the 'monthData' of sortData to 'monthData' initialized
	for (i = 0; i < N_MONTHS; i++)
	{
		sortData[i].monthData = monthData[i];
	}

	// Calculate the sum of repcipitation for each month
	for (i = 0; i < nRecords; i++)
	{
		for (j = 0; j < N_MONTHS + 1; j++)
		{
			if (data[i].date.month == j + 1)
				sortData[j].precip += convertToMm(data[i].precipAmt, data[i].unit);
		}
	}

	// Call function to sort by ascending order
	ascendBubbleSort(sortData, N_MONTHS);

	// Call function to calculate total precipitation
	precipTotal = calPrecipTotal(sortData, N_MONTHS);

	// Calculate average monthly precipitation
	precipAvg = (double)precipTotal / N_MONTHS;

	// Display result
	printf("Month     Precip(mm)\n"
		   "--------- ----------\n");
	for (i = 0; i < N_MONTHS; i++)
	{
		printf("%-9s %10d\n", sortData[i].monthData.monthName, sortData[i].precip);
	}
	printf("--------- ----------\n"
		   "   Total: %10d\n"
		   " Average: %10.2lf\n\n", precipTotal, precipAvg);
}

// Display precipitation sorted by location
void viewByLocation(const struct WeatherRecord* data, int nRecords)
{
	int precipTotal = 0;
	double precipAvg = 0;
	int i, j;

	struct SortData sortData[N_LOCATIONS] = { {0} };
	struct ByLocation locationData[N_LOCATIONS] =
	{
		{"Chatham-Kent"},	{"Essex"},		{"Halton"},
		{"Kenora"},			{"Ottawa"},		{"Renfrew"},
		{"Simcoe"},			{"Thunder Bay"}
	};

	// Assign the 'locationData' of sortData to 'locationData' initialized
	for (i = 0; i < N_LOCATIONS; i++)
	{
		sortData[i].locationData = locationData[i];
	}

	// Calculate the sum of repcipitation for each location
	for (i = 0; i < nRecords; i++)
	{
		for (j = 0; j < N_LOCATIONS + 1; j++)
		{
			if (!strcmp(data[i].location.name, sortData[j].locationData.locationName))
			{
				sortData[j].precip += convertToMm(data[i].precipAmt, data[i].unit);
			}
		}
	}

	// Call function to sort by descending order
	descendBubbleSort(sortData, N_LOCATIONS);

	// Call function to calculate total precipitation
	precipTotal = calPrecipTotal(sortData, N_LOCATIONS);

	// Calculate average precipitation
	precipAvg = (double)precipTotal / N_LOCATIONS;

	// Display result
	printf("Location        Precip(mm)\n"
	       "--------------- ----------\n");
	for (i = 0; i < N_LOCATIONS; i++)
	{
		printf("%15s %10d\n", sortData[i].locationData.locationName, sortData[i].precip);
	}
	printf("--------------- ----------\n"
		   "         Total: %10d\n"
		   "       Average: %10.2lf\n\n", precipTotal, precipAvg);

}

// Import weather data from file into an Weather struct pointer (returns the number of records read)
int importWeatherDataFile(FILE* fp, struct WeatherRecord* data, int max)
{
	int recs = 0;

	if (fp != NULL)
	{
		while (recs < max &&
			fscanf(fp, "%d,%d,%lf,%c,%d,%15[^\n]\n",
				&data[recs].date.year, &data[recs].date.month,
				&data[recs].precipAmt, &data[recs].unit,
				&data[recs].location.regionCode,
				data[recs].location.name) == 6)
		{
			recs++;
		}
	}
	return recs;
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Calculate annual precipitation
int calPrecipTotal(const struct SortData* data, int max)
{
	int totalPrecip = 0;
	int i = 0;

	for (i = 0; i < max; i++)
	{
		totalPrecip += data[i].precip;
	}

	return totalPrecip;
}

// Convert precipitation to Mm
int convertToMm(double precip, char unit)
{
	int precipAmt = 0;

	if (unit == 'c') // Convert cm to mm.
	{
		precipAmt = (int)(precip * 10);
	}
	else
	{
		precipAmt = (int)precip;
	}

	return precipAmt;
}

// Ascending order bubble sort function
void ascendBubbleSort(struct SortData* sortData, int itemCount)
{
	int i, j;
	struct SortData temp;

	for (i = itemCount - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (sortData[j].precip > sortData[j + 1].precip)
			{
				temp = sortData[j];
				sortData[j] = sortData[j + 1];
				sortData[j + 1] = temp;
			}
		}
	}
}

// Descending order bubble sort function
void descendBubbleSort(struct SortData* sortData, int itemCount)
{
	int i, j;
	struct SortData temp;

	for (i = itemCount - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (sortData[j].precip < sortData[j + 1].precip)
			{
				temp = sortData[j];
				sortData[j] = sortData[j + 1];
				sortData[j + 1] = temp;
			}
		}
	}
}