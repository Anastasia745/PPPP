#pragma once
#include "Transport.h"

class Track
{
	double cost;
	double time;
	int volume;

public:
	Track();
	Track(Transport, int);
	Track(Transport, Transport, Transport, int);
	Track(Transport, Transport, Transport, int);
	Track(Transport, Transport, Transport, Transport, Transport, int);
	Track(Transport, Transport, Transport, Transport, Transport, Transport, Transport, int);
	double getCost();
	~Track();
};