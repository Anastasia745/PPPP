#pragma once
#include "Transport.cpp"

class Factory
{
public:
	Transport createDefaultTransport() {};
	Transport createTransport(std::tuple<int, int, double>, int) {};
};
class CarFactory : public Factory
{
	Transport createDefaultTransport();
	Transport createTransport(std::tuple<int, int, double> tuple, int dist);
};
class PlaneFactory : public Factory
{
	Transport createDefaultTransport();
	Transport createTransport(std::tuple<int, int, double> tuple, int dist);
};
class TrainFactory : public Factory
{
	Transport createDefaultTransport();
	Transport createTransport(std::tuple<int, int, double> tuple, int dist);
};