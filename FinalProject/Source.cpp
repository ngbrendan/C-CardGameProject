//Brendan Nguyen
//Final Project
//High-Low Game

#include <iostream>
#include <vector>
#include "player.h"
#include <string>
#include <time.h>

using namespace std;

string cards[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" }; //allow to display int value to card value

void createline(int n, char symbol) //loop to draw borders
{
	for (int i = 0; i < n; i++)
	{
		cout << symbol;
	}
	cout << endl;
}

player retrieve_info(player &p) //retrieve players name
{
	createline(46, '=');
	cout << "\t\tHIGH-LOW GAME" << endl;
	createline(46, '=');
	cout << "\nPlease Insert Name: ";
	cin >> p.name;

	return p;
}

void dealcards(dealer &d, player &p) //assigns random cards to player and dealer
{
	d.card = (rand() % (12 + 1 - 0) + 0);
	p.card = (rand() % (12 + 1 - 0) + 0);
}

void results(dealer d, player p) //display continuing game results
{
	double ratio;
	ratio = (p.win / d.counter);
	cout << "WIN/PLAYS/DRAW: " << p.win << '/' << d.counter << '/' <<d.draw << endl;
}

void play(dealer &d, player &p)
{
	string input;
	char choice;
	char resp;

	do {
		system("cls"); //clears screen to make it cleaner
		dealcards(d, p); //draws cards for dealer and player

		createline(46, '=');
		cout << "\t        CARDS ARE DEALT!" << endl;
		cout << "\n   CARD ORDER: A-2-3-4-5-6-7-8-9-10-J-Q-K" << endl;
		cout << "\nIs your card higher or lower than the dealer?\n" << endl;
		cout << "\t\tDEALER HAND: " << cards[d.card] << endl;
		createline(46, '=');

		cout << "\n" << p.name << ", choose higher or lower (h/l): "; //prompt user for choice of high or low

		cin >> input;
		choice = input[0];

		while (choice != 'h' && choice != 'l') //make sure input takes in first character and is 'h' or 'l'
		{
			cout << "Invalid input! Choose (h/l): ";
			cin >> input;
			choice = input[0];
		}

		if (choice == 'h') //display choice chosen;
			cout << "\nYou chose Higher!" << endl;
		else
			cout << "\nYou chose Lower!" << endl;

		cout << "\n" << p.name << "'s HAND: " << cards[p.card] << endl; //display player's card
		cout << endl;

		if (p.card > d.card) //if player card is higher than dealer
		{
			if (choice == 'h') //check if player chooses higher
			{
				createline(46, '=');
				cout << "\tYOU WIN! Your card was higher." << endl;
				createline(46, '=');
				p.win++;
				d.counter++;
			}
			else
			{
				createline(46, '=');
				cout << "\tYOU LOSE! Your card was higher." << endl;
				createline(46, '=');
				d.counter++;
			}
		}

		if (p.card < d.card) //if player card is lower than dealer
		{
			if (choice == 'l') //check if player chooses lower
			{
				createline(46, '=');
				cout << "\tYOU WIN! Your card was lower." << endl;
				createline(46, '=');
				p.win++;
				d.counter++;
			}
			else
			{
				createline(46, '=');
				cout << "\tYOU LOSE! Your card was lower." << endl;
				createline(46, '=');
				d.counter++;
			}
		}

		if (p.card == d.card) //if careds are equal
		{
			createline(46, '=');
			cout << "\tDRAW! Cards are the same" << endl;
			createline(46, '=');
			d.draw++;
		}

		cout << endl;
		results(d, p); //display results

		cout << "\nContinue? (y\\Y): ";
		cin >> input;
		resp = input[0];
	} while (resp == 'y' || resp == 'Y'); //ask player to continue playing or not

}

int main()
{
	srand(time(0)); //allows program to regenerate a random number
	player player;
	dealer dealer;

	retrieve_info(player);
	play(dealer, player);

	system("pause");
	return 0;
}
