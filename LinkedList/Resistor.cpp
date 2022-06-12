#include "Resistor.h"

Resistor::Resistor(std::string Type, double Denomination, double Power, double Accuracy)
	: type(Type), denomination(Denomination), power(Power), accuracy(Accuracy)
{
}

std::ostream& operator<< (std::ostream& out, const Resistor& resistor)
{
	out << resistor.type << std::endl;
	out << resistor.denomination << "Ohm"  << std::endl;
	out << resistor.power << "Wt" << std::endl;
	out << resistor.accuracy << "%" << std::endl;

	return out;
}