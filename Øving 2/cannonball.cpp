//
//  cannonball.cpp
//  Øving 2
//
//  Created by Magnus Pedersen on 20.01.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "cannonball.h"
#include <iostream>
#include <cmath>
using namespace std;
double startPos()
{
    /*double startPos;
    cout << "Startposisjon: " << endl;
    cin >> startPos;*/
    return 0;
}
double acclY()
{
    return -9.81;
}
double velY(double startFart,double tid)
{
    double fartY = startFart + acclY()*tid;
    return fartY;
}
double velIntY (double startfart,double tid)
{
    double antallSteg = tid/0.1;
    for (double i = 0; i < antallSteg; i++)
    {
            startfart = startfart + acclY()*0.1;
    }
    return startfart;
}
double posX(double startfart, double tid)
{
   	return (startPos() + startfart * tid);
}

double posIntX(double startfart, double tid)
{
	double x = startPos();
	double antallSteg = tid / 0.1;
	for (double i = 0; i < antallSteg; i++)
    {
		x = x + startfart * 0.1;
	}
	return x;
}

double posY(double startfart, double tid)
{
	return (startPos() + startfart * tid + 0.5 * acclY() * tid * tid);
}

double posIntY(double startfart, double tid)
{
	double y = startPos();
	double antallSteg = tid / 0.1;
	for (double i = 0; i < antallSteg; i++)
    {
		y = y + velIntY(startfart, tid)*0.1;
	}
	return y;
}
void printTime (double sekunder)
{
    int tid = sekunder;
    int time, min;
    time=tid/3600;
    tid=tid%3600;
    min=tid/60;
    tid=tid%60;
    tid=tid;
    cout << "Tiden er: " << time << " timer, " << min << " minutter, " << tid << " sekunder." << endl;
}
double flightTime (double startfartY)
{
    return -startfartY/acclY();
}
void getUserInput(double *vinkel, double *absfart)
{
    cout << "Skriv inn vinkel: " << endl;
    cin >> *vinkel;
    cout << "Skriv inn fart: " << endl;
    cin >> *absfart;
}

double getVelocityX(double absfart, double vinkel)
{
    return absfart*cos(vinkel);
}
double getVelocityY(double absfart, double vinkel)
{
    return absfart*sin(vinkel);
}
void getVelocityVector(double vinkel, double absfart, double *velocityX, double *velocityY)
{
    *velocityX = getVelocityX(absfart, vinkel);
    *velocityY = getVelocityY(absfart, vinkel);
}
double getDistanceTraveled(double velocityX, double velocityY)
{
    double tid = flightTime(velocityY);
    return posX(velocityX, tid);
}
double optimalAngleForMaxDistance(double absfart)
{
    double distance=0.001;
    double longestDistance = 0;
    double velocityX, velocityY;
    double angel=0;
    double theta = 0;
    while (distance>longestDistance)
    {
        longestDistance = distance;
        angel+=0.0001;
        theta = ((angel*3.14)/180);
        getVelocityVector(theta, absfart, &velocityX, &velocityY);
        distance = getDistanceTraveled(velocityX, velocityY);
    }
    return angel;
}
double targetPractice(double distanceToTarget, double velocityX, double velocityY)
{
    return getDistanceTraveled(velocityX,velocityY)-distanceToTarget;
}

