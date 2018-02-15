//
//  cannonball.h
//  Øving 2
//
//  Created by Magnus Pedersen on 20.01.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef _ving_2_cannonball_h
#define _ving_2_cannonball_h
#include <iostream>

double acclY();
double velY(double startfart,double tid);

double velIntY (double startfart,double tid);
double posX(double startfart, double tid);
double posIntX(double startfart, double tid);
double posY(double startfart, double tid);
double posIntY(double startfart, double tid);

void printTime (double sekunder);
double flightTime (double startfartY);

void getUserInput(double *vinkel, double *absfart);
double getVelocityX(double vinkel, double absfart);
double getVelocityY(double vinkel, double absfart);
void getVelocityVector(double vinkel, double absfart, double *velocityX, double *velocityY);

double getDistanceTraveled(double velocityX, double velocityY);
double optimalAngleForMaxDistance(double absfart);
double targetPractice(double distanceToTarget, double velocityX, double velocityY);

#endif
