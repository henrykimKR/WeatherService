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
#include "core.h"

// This module was referenced from Milestones.
// This module helps the weather_service module.

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer 
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("\n< Press [ENTER] key to continue >");
    clearInputBuffer();
    putchar('\n');
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Validate if input value is a integer type
int inputInt(void)
{
	char newLine = 'x';
	int value = 0;
	int flag = 1;

	do
	{
		if (newLine == '\n')
		{
			flag = 0;
		}
		else
		{
			scanf("%d%c", &value, &newLine);

			if (newLine == '\n')
			{
				flag = 0;
			}
			else
			{
				clearInputBuffer();
				printf("Error! Input a whole number: ");
				flag = 1;
			}
		}
	} while (flag);

	return value;
}

// Validate if input value is in a range of integer
int inputIntRange(int lowBound, int upBound)
{
	int value = 0;
	int flag = 1;

	do
	{
		value = inputInt();

		if (value >= lowBound && value <= upBound)
		{
			flag = 0;
		}
		else
		{
			printf("ERROR! Value must be between %d and %d inclusive: ", lowBound, upBound);
			flag = 1;
		}

	} while (flag);

	return value;

}

