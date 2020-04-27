#pragma once
#include <string>

class Hob
{
private:
	std::string size;
	int timer;
	int temperature;
protected:
	void SetSize(std::string);
public:
	Hob();
	Hob(std::string, int, int);
	//~Hob(); no dynamic memory
	Hob(const Hob&);
	Hob& operator=(const Hob&);
	
	std::string GetSize() const;

	int GetTimer() const;
	void SetTimer(int);

	int GetTemperature() const;
	void SetTemperature(int);

	void ReduceTimer();
};

