
#include "bits/stdc++.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

sf::Color ranColor();

bool BadCrash();
bool GoodCrash1();
bool GoodCrash2();
bool GoodCrash3();
bool GoodCrash4();

int RandomSidex1();
int RandomSidex2();
int RandomSidex3();
int RandomSidex4();

sf::Color ranColor()
{

	sf::Color colour[6] = { Color::Blue, Color::Red, Color::Cyan, Color::Yellow, Color::Magenta, Color::White };

	int x = rand() % 6;

	return colour[x];
}

sf::RectangleShape obstacle(sf::Vector2f(470.f, 40.f));
sf::RectangleShape obstacle1(sf::Vector2f(480.f, 40.f));
sf::RectangleShape obstacle2(sf::Vector2f(450.f, 40.f));
sf::RectangleShape obstacle3(sf::Vector2f(460.f, 40.f));

sf::CircleShape ball(26.f);

int RandomSidex1()
{
	int x1[2] = { 430, 0 };

	int ans1 = rand() % 2;

	return x1[ans1];
}

int RandomSidex2()
{
	int x2[2] = { 0, 420 };

	int ans2 = rand() % 2;

	return x2[ans2];
}

int RandomSidex3()
{
	int x3[2] = { 0, 450 };

	int ans3 = rand() % 2;

	return x3[ans3];
}

int RandomSidex4()
{
	int x4[2] = { 440, 0 };

	int ans4 = rand() % 2;

	return x4[ans4];
}

int bad = 0;
int good = 0;

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

//int HI = 0;

int main()
{

	int SCORE = 0;
	// read from file ;if empty hi=0;
	// not empty ... then hi=value in it

	string myText;

	fstream MyReadFile("highscore.txt");
	int HI = 0;

	getline(MyReadFile, myText);

	//if (MyReadFile.peek() != std::ifstream::traits_type::eof()) //file not empty
		HI = stoi(myText);
	//else
	//{
		//HI = 0;
	//}

	MyReadFile.close();

	//fstream MyFile("highscore.txt", ios::out | ios::trunc);
	//MyFile << HI;

	sf::RenderWindow window(sf::VideoMode(900, 972), "ESCAPE THE UNKNOWN", sf::Style::Close);

	sf::Font font;
	if (!font.loadFromFile("./fonts/Retro Gaming.ttf"))
	{
		cout << "BAD! :< :( :{  :[  :/";
	}

	sf::Text score;
	sf::Text scrnum;
	sf::Text wrongmove;
	sf::Text high;
	sf::Text hinum;
	sf::Text reset;

	score.setFont(font); // font is a sf::Font
	score.setString("SCORE:");
	score.setCharacterSize(24); // in pixels, not points!
	score.setFillColor(sf::Color::Black);

	scrnum.setFont(font);
	scrnum.setPosition(101, 0);
	scrnum.setCharacterSize(24);
	scrnum.setFillColor(sf::Color::Green);

	wrongmove.setFont(font);
	wrongmove.setString("OOPSS");
	wrongmove.setPosition(235, 400);
	wrongmove.setCharacterSize(100);
	wrongmove.setFillColor(sf::Color::White);

	high.setFont(font); // font is a sf::Font
	high.setString("HI:");
	high.setPosition(345, 0);
	high.setCharacterSize(24); // in pixels, not points!
	high.setFillColor(sf::Color::Black);

	hinum.setFont(font);
	hinum.setPosition(400, 0);
	hinum.setCharacterSize(24);
	hinum.setFillColor(sf::Color::Green);

	reset.setFont(font);
	reset.setString("RESET");
	reset.setPosition(377, 641);
	reset.setCharacterSize(24);
	reset.setFillColor(sf::Color::Green);

	ball.setFillColor(sf::Color::White);

	obstacle.setFillColor(sf::Color::Yellow);
	obstacle.setPosition(RandomSidex1(), -150);

	obstacle1.setFillColor(sf::Color::Cyan);
	obstacle1.setPosition(RandomSidex2(), 93);

	obstacle2.setFillColor(sf::Color::Blue);
	obstacle2.setPosition(RandomSidex3(), 336);

	obstacle3.setFillColor(sf::Color::Magenta);
	obstacle3.setPosition(RandomSidex4(), 579);

	sf::RectangleShape scorebar(sf::Vector2f(900.f, 70.f));
	scorebar.setFillColor(sf::Color(180, 180, 180));

	sf::RectangleShape resetrec(sf::Vector2f(180.f, 50.f));
	resetrec.setFillColor(sf::Color::White);
	resetrec.setPosition(335, 632);

	Vector2u size = window.getSize();
	int width = size.x;
	int height = size.y;

	ball.setPosition(Vector2f(width / 2 - 30, height - 100));

	Clock clock1;
	Clock clock2;
	Clock clock3;
	Clock clock4;
	Clock clock5;
	Clock clock6;
	Clock clock7;

	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;

	string scorestr = "";

	while (window.isOpen())
	{
		sf::Event event;
		int r = 0;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
				return 0;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // moving ball to the right
			{
				if (ball.getPosition().x < 840)
					ball.move(25, 0);
				//cout << ball.getPosition().x << endl;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // moving ball to the left
			{
				if (ball.getPosition().x > 10)
					ball.move(-25, 0);

				//cout << ball.getPosition().x << endl;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // moving ball upwards
			{
				if (ball.getPosition().y > 80)
				{
					ball.move(0, -25);
				}

				//cout << ball.getPosition().y << endl;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) // moving ball downwards
			{
				if (ball.getPosition().y < 908)
					ball.move(0, 25);

				//cout << ball.getPosition().y << endl;
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && BadCrash() == true)
			{

				//float x = Mouse::getPosition().x - 513;
				//float y = Mouse::getPosition().y - 91;
				//cout << x << " " << y << endl;
				//float x1 = resetrec.getPosition().x;
				//float x2 = resetrec.getPosition().x + resetrec.getSize().x;
				//float y1 = resetrec.getPosition().y;
				//float y2 = (resetrec.getPosition().y + resetrec.getSize().y);
				//cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;

				if (resetrec.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
				{
					r = 1;

					//cout << "okay r" << endl;
				}
			}
		}

		if (r == 1)
		{
			ball.setPosition(Vector2f(width / 2 - 30, height - 100));
			scrnum.setPosition(101, 0);
			score.setPosition(0, 0);
			bad = 0;
			count1 = 0;
			count2 = 0;
			count3 = 0;
			count4 = 0;
			SCORE = 0;

			obstacle.setPosition(RandomSidex1(), -150);
			obstacle1.setPosition(RandomSidex2(), 93);
			obstacle2.setPosition(RandomSidex3(), 336);
			obstacle3.setPosition(RandomSidex4(), 579);
		}

		Time elapsed1 = clock1.getElapsedTime(); // color ball
		Time elapsed2 = clock2.getElapsedTime(); // downward movement of obstacles
		Time elapsed3 = clock3.getElapsedTime(); // color ob0
		Time elapsed4 = clock4.getElapsedTime(); // color ob1
		Time elapsed5 = clock5.getElapsedTime(); // color ob2
		Time elapsed6 = clock6.getElapsedTime(); // color ob3
		Time elapsed7 = clock7.getElapsedTime(); // score update

		scorestr = to_string(SCORE);

		scrnum.setString(scorestr);

		string histr;

		histr = to_string(HI);

		hinum.setString(histr);

		if (BadCrash() == false)
		{
			if (elapsed7.asSeconds() >= 0.6300) //for score update hehe
			{

				SCORE++;

				//cout << good1 << " " << count1 << endl;
				//cout << "GoodCrash1=  " << GoodCrash1() << endl;
				//cout << "count1=  " << count1 << endl;

				clock7.restart();
			}
		}

		if (BadCrash() == false && GoodCrash1() == true && count1 == 0)
		{

			SCORE = SCORE + 20;
			count1 = 1;
			//cout << "ob1" << endl;
		}
		//cout << "GoodCrash2=  " << GoodCrash2() << endl;
		//cout << "count2=  " << count2 << endl;

		if (BadCrash() == false && GoodCrash2() == true && count2 == 0)
		{
			SCORE = SCORE + 20;
			count2 = 1;
			//cout << "obs2" << endl;
		}
		if (BadCrash() == false && GoodCrash3() == true && count3 == 0)
		{
			SCORE = SCORE + 20;
			count3 = 1;
			//cout << "ob3" << endl;
		}
		if (BadCrash() == false && GoodCrash4() == true && count4 == 0)
		{
			SCORE = SCORE + 20;
			count4 = 1;
			//cout << "ob4" << endl;
		}

		if (elapsed1.asSeconds() >= 6.0000) //for the ball coloring
		{
			sf::Color k = ranColor();
			//cout<<k<<endl;
			ball.setFillColor(k);

			clock1.restart();
		}

		if (elapsed2.asSeconds() >= 0.0114) //for movement of obstacles  //0.0114
		{
			obstacle.move(0, 2);
			obstacle1.move(0, 2);
			obstacle2.move(0, 2);
			obstacle3.move(0, 2);

			clock2.restart();

			if (obstacle.getPosition().y >= 968)
			{
				obstacle.setPosition(0, -30); //IF OBSTACLES REACH THE END MAKE THEM COME BACK
				count1 = 0;
				//good1 = 0;
			}

			if (obstacle1.getPosition().y >= 968)
			{
				obstacle1.setPosition(420, -30);
				count2 = 0;
				//good2 = 0;
			}

			if (obstacle2.getPosition().y >= 968)
			{
				obstacle2.setPosition(0, -30);
				count3 = 0;
				//good3 = 0;
			}

			if (obstacle3.getPosition().y >= 968)
			{
				obstacle3.setPosition(440, -30);
				count4 = 0;
				//good4 = 0;
			}
		}

		if (elapsed3.asSeconds() >= 6.0000)
		{
			sf::Color k = ranColor();
			//cout<<k<<endl;
			obstacle.setFillColor(k);

			clock3.restart();
		}

		if (elapsed4.asSeconds() >= 4.0000)
		{
			sf::Color k = ranColor();
			//cout<<k<<endl;
			obstacle1.setFillColor(k);

			clock4.restart();
		}

		if (elapsed5.asSeconds() >= 6.0000)
		{
			sf::Color k = ranColor();
			//cout<<k<<endl;
			obstacle2.setFillColor(k);

			clock5.restart();
		}

		if (elapsed6.asSeconds() >= 4.0000)
		{
			sf::Color k = ranColor();
			//cout<<k<<endl;
			obstacle3.setFillColor(k);

			clock6.restart();
		}

		window.clear();

		if (BadCrash() == false || r == 1)
		{
			window.draw(obstacle);
			window.draw(obstacle1);
			window.draw(obstacle2);
			window.draw(obstacle3);
			window.draw(ball);

			window.draw(scorebar);
			window.draw(score);
			window.draw(scrnum);
			window.draw(high);
			window.draw(hinum);
		}

		//cout << "..." << bad << endl;
		//int stop = 0;
		if (BadCrash() && r == 0)
		{
			window.clear(Color(180, 180, 180));
			window.draw(wrongmove);
			score.setFillColor(Color::White);
			score.setPosition(360, 550);
			scrnum.setPosition(460, 550);
			window.draw(score);
			window.draw(scrnum);
			window.draw(resetrec);
			window.draw(reset);
		}
		//cout << SCORE << endl;
		if (SCORE > HI)

		{

			HI = SCORE;
			fstream MyFile("highscore.txt", ios::out | ios::trunc); //clear file
			//cout << HI << endl;
			MyFile << HI;
			MyFile.close();
		}
		window.display();
	}

	return 0;
}
