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

#ifndef CORE_H
#define CORE_H

//////////////////////////////
// USER INTERFACE FUNCTIONS //
//////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Validate if input value is a integer type
int inputInt(void);

// Validate if input value is in a range of integer
int inputIntRange(int lowBound, int upBound);

#endif // !CORE_H