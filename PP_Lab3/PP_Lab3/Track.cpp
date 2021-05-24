#include "Track.h"

Track::Track()
{
	this->cost = 0;
	this->time = 0;
	this->volume = 0;
}

Track::~Track()
{

}

Track::Track(Transport transport1, int volume)
{
	cost = transport1.sumCost(volume, transport1.getDistance());
	time = transport1.sumTime(transport1.getDistance());
}

Track::Track(Transport transport1, Transport transport2, Transport transport3, int volume)
{
	cost = transport1.sumCost(volume, transport1.getDistance()) + transport2.sumCost(volume, transport2.getDistance());
	time = transport1.sumTime(transport1.getDistance()) + transport2.sumTime(transport2.getDistance());
	cost += transport3.sumCost(volume, transport3.getDistance());
	time += transport3.sumTime(transport3.getDistance());
}

Track::Track(Transport transport1, Transport transport2, Transport transport3, Transport transport4, Transport transport5, int volume)
{
	cost = transport1.sumCost(volume, transport1.getDistance()) + transport2.sumCost(volume, transport2.getDistance()) + transport3.sumCost(volume, transport3.getDistance());
	time = transport1.sumTime(transport1.getDistance()) + transport2.sumTime(transport2.getDistance()) + transport3.sumTime(transport3.getDistance());
	cost += transport4.sumCost(volume, transport4.getDistance());
	time += transport4.sumTime(transport4.getDistance());
	cost += transport5.sumCost(volume, transport5.getDistance());
	time += transport5.sumTime(transport5.getDistance());
}

Track::Track(Transport transport1, Transport transport2, Transport transport3, Transport transport4, Transport transport5, Transport transport6, Transport transport7, int volume)
{
	cost = transport1.sumCost(volume, transport1.getDistance()) + transport2.sumCost(volume, transport2.getDistance()) + transport3.sumCost(volume, transport3.getDistance()) + transport4.sumCost(volume, transport4.getDistance());
	time = transport1.sumTime(transport1.getDistance()) + transport2.sumTime(transport2.getDistance()) + transport3.sumTime(transport3.getDistance()) + transport4.sumTime(transport4.getDistance());
	cost += transport5.sumCost(volume, transport5.getDistance()) + transport6.sumCost(volume, transport6.getDistance());
	time += transport5.sumTime(transport5.getDistance()) + transport6.sumTime(transport6.getDistance());
	cost += transport7.sumCost(volume, transport7.getDistance());
	time += transport7.sumTime(transport7.getDistance());
}

double Track::getCost()
{
	return this->cost;
}