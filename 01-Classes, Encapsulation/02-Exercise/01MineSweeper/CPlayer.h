#pragma once
class CPlayer
{
public:
	CPlayer();
	CPlayer(char*);
	CPlayer(unsigned, unsigned, bool, char*);
	CPlayer(bool, char*);
	CPlayer(const CPlayer&);
	CPlayer& operator = (const CPlayer&);

	~CPlayer();

	int setScore(unsigned);
	int setLives(unsigned);
	int setState(bool);
	int setNick(char*);

	unsigned getScore() const;
	unsigned getLives() const;
	bool getState() const;
	char* getNick() const;

	void Print() const;

private:
	unsigned score;
	unsigned lives;
	bool state;
	char* nick;
};

