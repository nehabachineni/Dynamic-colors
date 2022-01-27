#include "../include/ob1.h"
#include "bits/stdc++.h"
using namespace std;

sf::RectangleShape obstacle2(sf::Vector2f(450.f, 40.f));

int RandomSidex3();

int RandomSidex3()
{
	int x3[2] = { 0, 450 };

	int ans3 = rand() % 2;

	return x3[ans3];
}
bool GoodCrash3();
bool GoodCrash3()
{
	if (obstacle2.getFillColor() == ball.getFillColor() && obstacle2.getGlobalBounds().intersects(ball.getGlobalBounds()))
	{
		//cout << "gud collision3" << endl;
		//good = 1;
		//count3 = 1;
		return true;
	}

	return false;
}
