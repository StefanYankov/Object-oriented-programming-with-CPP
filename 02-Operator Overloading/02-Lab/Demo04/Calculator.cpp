#include "Calculator.h"

Calculator::Calculator()
{
	this->SetInputExpression(new char[] {"0"});
}

Calculator::Calculator(const char* inputExpression)
{
	this->SetInputExpression(inputExpression);
}

Calculator::Calculator(const Calculator& other)
{
	this->SetInputExpression(other.GetInputExpression());
}

Calculator& Calculator::operator=(const Calculator& other)
{
	if (this != &other)
	{
		this->SetInputExpression(other.GetInputExpression());
	}
	return *this;
}

Calculator::~Calculator()
{
	if (inputExpression!=nullptr)
	{
		delete[] inputExpression;
	}
}

char* Calculator::GetInputExpression() const
{
	return this->inputExpression;
}

void Calculator::SetInputExpression(const char* inputExpression)
{
	if (!IsValidExpression(inputExpression))
	{
		throw std::invalid_argument("Invalid argument.");
	}

	if (this->inputExpression != nullptr)
	{
		delete[] this->inputExpression;
	}

	this->inputExpression = new char[strlen(inputExpression) + 1];
	strcpy_s(this->inputExpression, strlen(inputExpression) + 1, inputExpression);
}

int Calculator::CalculateResult() const
{
	int length = strlen(this->GetInputExpression());
	int result = 0;
	int leftOperand = 0;
	int rightOperand = 0;
	bool isRightOperand = false;
	char operation = ' ';

	for (int i = 0; i < length; i++)
	{
		if ((operation!= ' ' && leftOperand !=0 && rightOperand!=0) && (this->GetInputExpression()[i]=='-' || this->GetInputExpression()[i] == '+' 
			|| this->GetInputExpression()[i] == '/' || this->GetInputExpression()[i] == '*'))
		{
			switch (operation)
			{
			case '+': result = leftOperand + rightOperand;
				break;
			case '-': result = leftOperand - rightOperand;
				break;
			case  '/':
				if (rightOperand == 0)
				{
					throw std::invalid_argument("Cannot divide by zero");
				}
				result = leftOperand / rightOperand;
				break;
			case '*':
				result = leftOperand * rightOperand;
				break;
			}
			leftOperand = result;
			rightOperand = 0;
			operation = ' ';
		}

		if (this->GetInputExpression()[i] == '-' || this->GetInputExpression()[i] == '+' || this->GetInputExpression()[i] == '/' || this->GetInputExpression()[i] == '*')
		{
			operation = this->GetInputExpression()[i];
			isRightOperand = true;
		}
		else
		{
			if (!isRightOperand)
			{
				leftOperand = leftOperand * 10 + (this->GetInputExpression()[i] - '0');
			}
			else
			{
				rightOperand = rightOperand*10 + (this->GetInputExpression()[i] - '0');
			}
		}
	}

	return result;
}


bool Calculator::IsValidExpression(const char* expression) const
{
	int length = strlen(expression);

	for (int i = 0; i < length; i++)
	{
		if ((expression[i] <'0' || expression[i] > '9') && (expression[i] != '+' && expression[i] !='-' && expression[i]!='/' && expression[i] !='*'))
		{
			return false;
		}
	}

	return true;
}
