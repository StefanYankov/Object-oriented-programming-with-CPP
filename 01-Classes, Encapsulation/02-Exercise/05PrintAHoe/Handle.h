#pragma once
class Handle
{
public:
	Handle();
	Handle(int, int);

	int GetDiameter() const;
	void SetDiameter(int);

	int GetLength() const;
	void SetLength(int);
private:
	int diameter;
	int length;
};

