#include "CPlayer.h"
#include <string.h>
#include <iostream> // added for the Print() method
#pragma warning(disable: 4996) // added so I don't get compile time erros with strcpy

CPlayer::CPlayer() // or we can go without a default ctor and add default parameters to CPlayer(unsigned score = 0, unsigned lives = 5, bool state = true, char* nick = const_cast<char*>("Player"));
{
	score = 0;
	lives = 5;
	state = true;
	nick = new char[7];
	strcpy(nick, "Player");
}

CPlayer::CPlayer(char* nick)
{
	score = 0;
	lives = 5;
	state = true;
	this -> nick = new char[strlen(nick) + 1];
	strcpy(this-> nick, nick);
}

CPlayer::CPlayer(unsigned score, unsigned lives, bool state, char* nick )
{
	this->score = score;
	this->lives = lives;
	this->state = state;
	this->nick = new char[strlen(nick) + 1];
	strcpy(this->nick, nick);
}

CPlayer::CPlayer(bool state, char* nick)
{
	score = 0;
	lives = 5;
	this->state = state;
	this->nick = new char[strlen(nick) + 1];
	strcpy(this->nick, nick);
}

CPlayer::CPlayer(const CPlayer& rhs) // copy ctor as part of the big 5. Ctor also added to the header file
{
	score = rhs.score;
	lives = rhs.lives;
	state = rhs.state;
	nick = new char[strlen(rhs.nick) + 1];
	strcpy(nick, rhs.nick);
}

CPlayer&::CPlayer::operator = (const CPlayer& rhs) // operator '=' overload . Overload also added to the header file
{
	if (this != &rhs)
	{
		score = rhs.score;
		lives = rhs.lives;
		state = rhs.state;
		delete[] nick;
		nick = nullptr;
		nick = new char[strlen(rhs.nick) + 1];
		strcpy(nick, rhs.nick);
	}
	return *this;
}

CPlayer::~CPlayer() 
{
	std::cout << "Player " << this->nick << " has been deleted." << std::endl; // to test if destructor works as intended
	if (nick != nullptr)
	{
		delete[] nick;
		nick = nullptr;
	}
}


unsigned CPlayer::getScore() const
{
	return score;
}
int CPlayer::setScore(unsigned score)
{
	this->score = score;
	return this->score;
}

unsigned CPlayer::getLives() const
{
	return lives;
}
int CPlayer::setLives(unsigned lives)
{
	this->lives = lives;
	return this->lives;
}

bool CPlayer::getState() const
{
	return state;
}
int CPlayer::setState(bool state)
{
	this->state = state;
	return state;
}

char* CPlayer::getNick() const
{
	return nick;
}
int CPlayer::setNick(char* nick)
{
	this->nick = nick;
	return 0;
}

//to test if all of the constructors are working properly. Method also added to the header file

void CPlayer::Print() const
{
	std::cout << "Player: " <<this->nick  << std::endl
		<< "With score: " << this->score  << std::endl
		<< "With lives: " << this->lives  << std::endl
		<< "With state: " << this->state  << std::endl;
}
