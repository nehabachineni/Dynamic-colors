#include "../include/ob2.h"
#include "bits/stdc++.h"
using namespace std;

sf::RectangleShape obstacle3(sf::Vector2f(460.f, 40.f));

int RandomSidex4();

int RandomSidex4()
{
	int x4[2] = { 440, 0 };

	int ans4 = rand() % 2;

	return x4[ans4];
}

bool GoodCrash4();

bool GoodCrash4()
{
	if (obstacle3.getFillColor() == ball.getFillColor() && obstacle3.getGlobalBounds().intersects(ball.getGlobalBounds()))
	{
		//cout << "gud collision4" << endl;
		//good = 1;
		//count4 = 1;
		return true;
	}

	return false;
}
