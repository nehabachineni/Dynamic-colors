
//#include "../include/ball.h"
//#include "../include/ob1.h"

#include "../include/collision.h"
#include "bits/stdc++.h" //<> will also work

using namespace std;
using namespace sf;

sf::Text score;
sf::Text scrnum;
sf::Text wrongmove;
sf::Text high;
sf::Text hinum;
sf::Text reset;
sf::Text newhi;
sf::RectangleShape scorebar(sf::Vector2f(900.f, 70.f));

sf::Color ranColor();
void updatewindow(sf::RenderWindow& window);
void updatewindow(sf::RenderWindow& window)
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

sf::Color ranColor()
{

	sf::Color colour[6] = { Color::Blue, Color::Red, Color::Cyan, Color::Yellow, Color::Magenta, Color::White };

	int x = rand() % 6;

	return colour[x];
}

int main()
{

	int SCORE = 0;
	// read from file ;if empty hi=0;
	// not empty ... then hi=value in it

	string myText;

	fstream MyReadFile("highscore.txt");
	int HI = 0;

	getline(MyReadFile, myText);

	HI = stoi(myText);
	int prev = HI;

	MyReadFile.close();

	sf::RenderWindow window(sf::VideoMode(900, 972), "ESCAPE THE UNKNOWN", sf::Style::Close);

	sf::Font font;
	if (!font.loadFromFile("./fonts/Retro Gaming.ttf"))
	{
		cout << "BAD! :< :( :{  :[  :/";
	}

	score.setFont(font); // font is a sf::Font
	score.setString("SCORE:");
	score.setCharacterSize(24); // in pixels, not points!
	score.setFillColor(sf::Color::Black);

	scrnum.setFont(font);
	scrnum.setPosition(101, 0);
	scrnum.setCharacterSize(24);
	scrnum.setFillColor(sf::Color::Green);

	newhi.setFont(font);
	newhi.setPosition(300, 600);
	newhi.setCharacterSize(24);
	newhi.setString("new high score made!");
	newhi.setFillColor(sf::Color::Green);

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

			ballfunc(ball);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && BadCrash() == true)
			{

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
			prev = HI;

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
				obstacle.setPosition(RandomSidex1(), -30); //IF OBSTACLES REACH THE END MAKE THEM COME BACK
				count1 = 0;
				//good1 = 0;
			}

			if (obstacle1.getPosition().y >= 968)
			{
				obstacle1.setPosition(RandomSidex2(), -30);
				count2 = 0;
				//good2 = 0;
			}

			if (obstacle2.getPosition().y >= 968)
			{
				obstacle2.setPosition(RandomSidex3(), -30);
				count3 = 0;
				//good3 = 0;
			}

			if (obstacle3.getPosition().y >= 968)
			{
				obstacle3.setPosition(RandomSidex4(), -30);
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
			updatewindow(window);
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
			if (SCORE > prev)
			{
				window.draw(newhi);
			}
		}
		//cout << SCORE << endl;

		if (SCORE > HI)
		{
			//cout << "okay";
			HI = SCORE;
			fstream MyFile("highscore.txt", ios::out | ios::trunc); //clear file

			MyFile << HI;
			MyFile.close();
		}
		window.display();
	}

	return 0;
}
