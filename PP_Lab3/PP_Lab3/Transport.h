#pragma once
#include "Data.h"

class Transport
{
protected:
	int Speed;
	int Volume;
	int Price;
	int distance;
public:
	Transport();
	Transport(std::tuple<int, int, double>, int);
	double sumCost(int, int);
	double sumTime(int);
	int getDistance();
};

class Train : public Transport
{
public:
	Train();
	Train(std::tuple<int, int, double>, int);
	~Train();
};

class Plane : public Transport
{
public:
	Plane();
	Plane(std::tuple<int, int, double>, int);
	~Plane();
};

class Car : public Transport
{
public:
	Car();
	Car(std::tuple<int, int, double>, int);
	~Car();
};