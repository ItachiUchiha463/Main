#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <math.h>
struct People {
	int Number, Heigth, ClothesNumber, ShoesNumber;
	double Weight;
	char Surname[40], Name[30];
};
using namespace std;
void EnterOnePeople(People& people);
void CreateFile(People& people);
void AppendToFile(People& people);
