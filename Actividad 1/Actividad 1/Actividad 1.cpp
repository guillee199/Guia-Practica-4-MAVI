#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
int main()
{
	Texture crosshair;
	Sprite sprite;
	crosshair.loadFromFile("./assets/crosshair.png");
	sprite.setTexture(crosshair); sprite.setScale(0.5f, 0.5f); sprite.setPosition(368, 268);

	sf::RenderWindow App(VideoMode(800, 600, 32), "Crosshair");
	while (App.isOpen())
	{
		App.clear();
		App.draw(sprite);
		App.display();
	}
	return 0;
}

