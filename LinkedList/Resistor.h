#pragma once
#include <string>
#include <iostream>

struct Resistor
{
	Resistor() = default;
	Resistor(std::string Type, double Denomination, double Power, double Accuracy);
	std::string type;
	double denomination = 0;
	double power = 0;
	double accuracy = 0;

	friend std::ostream& operator<< (std::ostream& out, const Resistor& resistor);
	~Resistor() = default;
};