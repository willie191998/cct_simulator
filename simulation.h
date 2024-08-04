/*WILSON ANORUE
27th SEPT 2020, 07:03:37 */
#ifndef SIMULATION_H
#define SIMULATION_H

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cmath>

class Components;
class Answer;
class Matrix;
class Stack;
class Comp_pointer;
class Inductor ;
class Capacitor ;
class Resistor ;
class Voltagesource ;
class Currentsource ;
extern void Comparrange_input ();

extern Answer Y[5];
extern Inductor Ind[5];
extern Capacitor Cap[5];
extern Resistor Res[5];
extern Voltagesource VS[5];
extern Currentsource CS[5];

#endif