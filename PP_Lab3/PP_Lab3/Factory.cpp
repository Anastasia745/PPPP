#include "Factory.h"

Transport CarFactory::createDefaultTransport()
{
	return Car();
}

Transport CarFactory::createTransport(std::tuple<int, int, double> tuple, int dist)
{
	return Car(tuple, dist);
}

Transport PlaneFactory::createDefaultTransport()
{
	return Plane();
}

Transport PlaneFactory::createTransport(std::tuple<int, int, double> tuple, int dist)
{
	return Plane(tuple, dist);
}

Transport TrainFactory::createDefaultTransport()
{
	return Train();
}

Transport TrainFactory::createTransport(std::tuple<int, int, double> tuple, int dist)
{
	return Train(tuple, dist);
}