#pragma once
#include <ostream>

class FileManipulator
{
private:
	int width;
	int precision;
public:
	FileManipulator(int, int);
	std::ostream& inserter(std::ostream&) const;
};

std::ostream& operator<<(std::ostream&, const FileManipulator&);
