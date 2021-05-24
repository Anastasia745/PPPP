#include "Transport.h"

Transport::Transport(std::tuple<int, int, double> tuple, int dist)
{
	this->Price = std::get<0>(tuple);
	this->Speed = std::get<1>(tuple);
	this->Volume = std::get<2>(tuple);
	this->distance = dist;
}

Train::Train()
{
	this->Price = 200;
	this->Speed = 100;
	this->Volume = 500;
	this->distance = 0;
}

Train::Train(std::tuple<int, int, double> tuple, int dist) : Transport(tuple, dist)
{
	this->Price = std::get<0>(tuple);
	this->Speed = std::get<1>(tuple);
	this->Volume = std::get<2>(tuple);
	this->distance = dist;
}

Train::~Train()
{}

double Transport::sumCost(int mass, int dist)
{
	return (mass / Volume) * sumTime(dist) * Price;
}

double Transport::sumTime(int dist)
{
	return dist / Speed;
}

int Transport::getDistance()
{
	return this->distance;
}

Car::Car()
{
	this->Price = 100;
	this->Speed = 60;
	this->Volume = 50;
	this->distance = 0;
}

Car::Car(std::tuple<int, int, double> tuple, int dist) : Transport(tuple, dist)
{
	this->Price = std::get<0>(tuple);
	this->Speed = std::get<1>(tuple);
	this->Volume = std::get<2>(tuple);
	this->distance = dist;
}

Car::~Car()
{}

Plane::Plane()
{
	this->Price = 500;
	this->Speed = 300;
	this->Volume = 100;
	this->distance = 0;
}

Plane::Plane(std::tuple<int, int, double> tuple, int dist) : Transport(tuple, dist)
{
	this->Price = std::get<0>(tuple);
	this->Speed = std::get<1>(tuple);
	this->Volume = std::get<2>(tuple);
	this->distance = dist;
}

Plane::~Plane()
{}