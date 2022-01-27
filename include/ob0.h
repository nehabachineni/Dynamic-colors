
#include "../include/ball.h"
#include "bits/stdc++.h"
using namespace std;

sf::RectangleShape obstacle(sf::Vector2f(470.f, 40.f));

int RandomSidex1();

int RandomSidex1()
{
	int x1[2] = { 430, 0 };

	int ans1 = rand() % 2;

	return x1[ans1];
}

bool GoodCrash1();

bool GoodCrash1()
{
	if (obstacle.getFillColor() == ball.getFillColor() && obstacle.getGlobalBounds().intersects(ball.getGlobalBounds()))
	{
		//cout << "gud collision1" << endl;
		//good = 1;
		//count1 = 1;
		return true;
	}

	return false;
}