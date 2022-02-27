#include <SFML/Graphics.hpp>
sf::CircleShape ball(26.f);

void ballfunc(sf::CircleShape& ball);

void ballfunc(sf::CircleShape& ball)

{

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
}