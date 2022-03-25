#pragma once
class Hoe
{
private:
	char * handleEnd = nullptr;
	char handleElement;
	int handleLength;
	char* head = nullptr;
public:
	Hoe();
	Hoe(char handleElement, int handleLength, char* head);
	Hoe(const Hoe& other); // copy constructor
	~Hoe();

	// operator overloading
	Hoe& operator=(const Hoe& other);

	Hoe& operator++(); // pre-fix increment operator overload
	Hoe operator++(int); // adding a dummy argument so we can distinguish from pre-fix

	Hoe& operator--();
	Hoe operator--(int);

	// getters & setters
	char* GetHandleEnd() const;
	void SetHandleEnd(char* handleEnd);

	char GetHandleElement() const;
	void SetHandleElement(char handleElement);

	int GetHandleLength() const;
	void SetHandleLength(int handleLength);

	char* GetHead() const;
	void SetHead(char*  head);

	// member functions
	void Print() const;
};

