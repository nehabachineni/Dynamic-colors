#include "../include/ob0.h"
#include "bits/stdc++.h"
using namespace std;

sf::RectangleShape obstacle1(sf::Vector2f(480.f, 40.f));

int RandomSidex2();

int RandomSidex2()
{
	int x2[2] = { 0, 420 };

	int ans2 = rand() % 2;

	return x2[ans2];
}

bool GoodCrash2();

bool GoodCrash2()
{
	if (obstacle1.getFillColor() == ball.getFillColor() && obstacle1.getGlobalBounds().intersects(ball.getGlobalBounds()))
	{
		//cout << "gud collision2" << endl;
		//good = 1;
		//count2 = 1;
		return true;
	}

	return false;
}
