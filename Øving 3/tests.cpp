//
//  tests.cpp
//  Øving 3
//
//  Created by Magnus Pedersen on 30.01.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "tests.h"
#include "utilities.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdlib.h>

using namespace std;
void incrementByValueNumTimes(int *startValue, int *numTimes, int *increment)//bytt til incrementByReference
{
    for (int i = 0; i < *numTimes; i++)
    {
        *startValue += *increment;
    }
}
void testPart2()
{
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    //incrementByValueNumTimes(&v0, &increment, &iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations << endl;
    //<< " result: " << incrementByValueNumTimes(&v0, 2, 10) << endl;
}
void swapNumbers(int *x, int *y) //Funksjonen bør bruke pekere for å bytte verdiene (altså tallene)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int randomizeArray(int tabell[], int lengde)
{
    for (int i=0;i<lengde;i++)
    {
        srand( static_cast<unsigned int>(time(NULL)));
        tabell[i]=rand()%101;
    }
    return *tabell;
}
void printArray(int tabell[], int lengde)
{
    for (int i=0; i<lengde; i++)
    {
        cout << tabell[i];
    }
}
int sortArray(int tabell[],int lengde) //insertion sort
{
    int i, j ,temp;
    for (i = 1; i < lengde; i++) {
        j = i;
        while (j > 0 && tabell[j - 1] > tabell[j])
        {
            temp = tabell[j];
            tabell[j] = tabell[j - 1];
            tabell[j - 1] = temp;
            j--;
        }
    }
    return *tabell;
}
int medianOfArray(int tabell[], int lengde)
{
    sortArray(tabell, lengde);
    double median = lengde%2 ? tabell[lengde/2] : (tabell[lengde/2-1] + tabell[lengde/2])/2;
    return median;
}
void testPart3()
{
    int percentages[20];
    randomizeArray(percentages, 20);
    swapNumbers(&percentages[0], &percentages[1]);
    sortArray(percentages, 20);
    cout << "Median: " << medianOfArray(percentages, 20);
}
void randomizeCString(char tabell[],int lengde, char nedreGrense, char ovreGrense)
{
    for (int i = 0; i < lengde; i++)
    {
        tabell[i] = randomCharWithLimits(nedreGrense, ovreGrense);
    }
}
void readInputToCString(char tabell[],int lengde, char nedre, char ovre)
{
    char innputt;
    char innskriving;
    int start = 0;
    while (start < lengde)
    {
        cout << "Skriv inn tegn til tabellen innenfor " << ovre << " og " << nedre << ":" << endl;
        cin >> innskriving;
        innputt = toupper(innskriving);
        if (innputt>=nedre && innputt<=ovre)
        {
            tabell[start]=innputt;
            start++;
        }
        else
        {
            cout << "Dette var utenfor grensene. Vennligst prøv på nytt." << endl;
        }
    }
}
int countOccurencesOfCharacter(char tabell[], int lengde, char bokstav)
{
    int occurences = 0;
    for (int i = 0; i < lengde; i++)
    {
        if (tabell[i]==bokstav)
        {
            occurences++;
        }
    }
    return occurences;
}
void gjennomsnitt(char tabell[], int lengde)
{
	int gradeCount[6];
	for (int i = 0; i < 6; i++)
    {
		gradeCount[i] = countOccurencesOfCharacter(tabell, lengde, i + 65);//65 starter på A
	}
	int sum = 0;
	for (int j = 0; j < 6; j++)
    {
		sum += gradeCount[j]*(j+1);
	}
	double  snitt = sum / lengde;
    
	cout << "Snittkarakter: " << setprecision(2) << snitt << " | Bokstavkarakter: " << (char)(snitt+64) << endl;
}
void testPart4()
{
    /*char grades[9];
    randomizeCString(grades, 8, 'A', 'F'); //får bare like karakterer, pga. de generes til samme tid.
    cout << grades << endl;*/
    char grades[41];//En plass til 0'eren
	int lengde = 40;
    
	//randomizeCString(grades, lengde, 'A', 'F');
    
	readInputToCString(grades, lengde, 'A', 'F');
	cout << "Karakterer: " << grades << endl;
	gjennomsnitt(grades, lengde);
}