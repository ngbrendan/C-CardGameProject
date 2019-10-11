#pragma once
#include <iostream>

using namespace std;

class player {
public:
	string name;
	int win = 0;
	int card;
	float ratio;
};

class dealer {
public:
	int card;
	int counter = 0;
	int draw = 0;
};