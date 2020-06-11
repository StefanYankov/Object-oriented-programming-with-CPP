#include "FileManipulator.h"
#include <iomanip>

FileManipulator::FileManipulator(int width, int precision)
{
	this->width = width;
	this->precision = precision;
}

std::ostream& FileManipulator::inserter(std::ostream& out) const
{
	return out << std::setw(width) << std::setprecision(precision) << std::fixed;
}

std::ostream& operator<<(std::ostream& out, const FileManipulator& fileManipulator)
{
	return fileManipulator.inserter(out);
}
