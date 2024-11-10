#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;
int main()
{
	Texture red;
	Sprite sprite1, sprite2, sprite3, sprite4;
	vector<Sprite> sprites;
	red.loadFromFile("./assets/rcircle.png");
	sprite1.setTexture(red); sprites.push_back(sprite1);
	sprite2.setTexture(red); sprite2.setPosition(672, 0); sprites.push_back(sprite2);
	sprite3.setTexture(red); sprite3.setPosition(672, 472); sprites.push_back(sprite3);
	sprite4.setTexture(red); sprite4.setPosition(0, 472); sprites.push_back(sprite4);

	bool isDragging = false;
	Sprite* selectedSprite = nullptr;

	sf::RenderWindow App(VideoMode(800, 600, 32), "Drag");
	while (App.isOpen())
	{
		Event event;
		while (App.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				App.close();
		}

		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				for (auto& sprite : sprites) {
					if (sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						isDragging = true;
						selectedSprite = &sprite;
						break;
					}
				}
			}
		}

		if (event.type == sf::Event::MouseButtonReleased) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				isDragging = false;
				selectedSprite = nullptr;
			}
		}

		if (isDragging && selectedSprite != nullptr) {
			sf::Vector2i mousePosition = sf::Mouse::getPosition(App);
			selectedSprite->setPosition(mousePosition.x - selectedSprite->getGlobalBounds().width / 2, mousePosition.y - selectedSprite->getGlobalBounds().height / 2);
		}
		App.clear();
		for (const auto& sprite : sprites) {
			App.draw(sprite);
		}
		App.display();
	}
	return 0;
}
