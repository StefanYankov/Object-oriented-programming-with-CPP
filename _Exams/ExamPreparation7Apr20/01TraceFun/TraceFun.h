#pragma once
#include <iostream>
class TraceFun
{
private:
	char* funName;
	std::ostream& out;
public:
	TraceFun();
	TraceFun(const char*, std::ostream&);
	~TraceFun();

	char* GetFunName() const;
	void SetFunName(const char*);

	std::ostream& GetOut() const;
	void SetOut(std::ostream&);

};

