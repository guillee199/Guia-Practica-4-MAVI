#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

int main() {
	Texture rcircle, bcircle;
	rcircle.loadFromFile("./assets/rcircle.png");
	bcircle.loadFromFile("./assets/rcircleb.png");
	vector<Sprite>sprites;
	
	sf::RenderWindow App(VideoMode(800, 600, 32), "Splats");
	while (App.isOpen())
	{
		Event event;
		while (App.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				App.close();
		}

		if (event.type == sf::Event::MouseButtonPressed) {
			Sprite circle;

			if (event.mouseButton.button == Mouse::Left) {
				circle.setTexture(rcircle);
				circle.setScale(1,1);
			}
			else if (event.mouseButton.button == Mouse::Right) {
				circle.setTexture(bcircle);
			}
			circle.setPosition(event.mouseButton.x - 64, event.mouseButton.y - 64);

			sprites.push_back(circle);
		}

		App.clear();
		for (const auto& circle : sprites) {
			App.draw(circle);
		}
		App.display();
	}
	
	
	
	return 0;

}