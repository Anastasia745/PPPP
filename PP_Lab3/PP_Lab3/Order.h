#pragma once
#include "Data.h"
#include "Transport.cpp"
#include "Factory.cpp"
#include "Track.h"
#include <string>
constexpr auto SIZE = 16;

enum Type { Turbo, Standart, Economy };

class Order
{
	double cost;
	int volume;
	std::string startPoint;
	std::string finishPoint;
	enum::Type type;
	Track track;
	Factory* train_factory = new TrainFactory();
	Factory* car_factory = new CarFactory();
	Factory* plane_factory = new PlaneFactory();
	Data* data = Data::singleton();

public:
	Order();
	Order(Type, std::string, std::string, int);
	~Order();
	int decr(std::string);
	int** matrixUpd(Type);
	int* optim(int**, int, int);
	Track best(std::string, std::string, Type, int);
};