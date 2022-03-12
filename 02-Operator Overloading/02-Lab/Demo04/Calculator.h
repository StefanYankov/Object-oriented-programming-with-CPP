#pragma once
#include <ostream>

class Calculator
{
private:
	char* inputExpression{};
	bool IsValidExpression(const char* expression) const;
public:

	Calculator();
	Calculator(const char* inputExpression);
	Calculator(const Calculator& other);
	Calculator& operator=(const Calculator& other);
	~Calculator();

	char* GetInputExpression() const;
	void SetInputExpression(const char* inputExpression);

	int CalculateResult() const;


	//std::ostream& Inserter(std::ostream& out) const;
};

//std::ostream& operator<<(std::ostream& os, const Calculator& calculator);