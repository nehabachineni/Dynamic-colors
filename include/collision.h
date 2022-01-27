#include "../include/ob3.h"
#include "bits/stdc++.h"
using namespace std;

bool BadCrash();
int bad = 0;
bool BadCrash()
{

	if (obstacle.getFillColor() != ball.getFillColor() && obstacle.getGlobalBounds().intersects(ball.getGlobalBounds()))
		//cout << "bad collision0" << endl;
		bad = 1;

	if (obstacle1.getFillColor() != ball.getFillColor() && obstacle1.getGlobalBounds().intersects(ball.getGlobalBounds()))
		//cout << "bad collision1" << endl;
		bad = 1;
	if (obstacle2.getFillColor() != ball.getFillColor() && obstacle2.getGlobalBounds().intersects(ball.getGlobalBounds()))
		//cout << "bad collision2" << endl;
		bad = 1;
	if (obstacle3.getFillColor() != ball.getFillColor() && obstacle3.getGlobalBounds().intersects(ball.getGlobalBounds()))
		//cout << "bad collision3" << endl;
		bad = 1;

	if (bad == 1)
		return true;
	else
	{
		return false;
	}
}