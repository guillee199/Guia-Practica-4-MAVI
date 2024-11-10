#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

    class Enemy {
    public:
        sf::Sprite sprite;
        sf::Texture texture;

        Enemy(const std::string& textureFile) {
            texture.loadFromFile(textureFile);
            sprite.setTexture(texture);
            sprite.setScale(0.1f, 0.1f);
            respawn();
        }

        void respawn() {
            sprite.setPosition(rand() % 800 - 100, rand() % 600 - 100);
        }

        bool isClicked(float mouseX, float mouseY) {
            return sprite.getGlobalBounds().contains(mouseX, mouseY);
        }
};

class Crosshair {
public:
    sf::Sprite sprite;
    sf::Texture texture;

    Crosshair(const std::string& textureFile) {
        texture.loadFromFile(textureFile);
        sprite.setTexture(texture);
        sprite.setScale(0.2f, 0.2f);

    }

    void setPosition(float x, float y) {
        sprite.setPosition(x, y);
    }
};

int main() {
    
    srand(static_cast<unsigned int>(time(0)));
   
    sf::RenderWindow App(sf::VideoMode(800, 600), "Clickale");

    Crosshair crosshair("./assets/crosshair.png");
    
    int enemiesDefeated = 0;

    Enemy enemy("./assets/et.png");

    while (App.isOpen()) {
        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                App.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    float mouseX = event.mouseButton.x;
                    float mouseY = event.mouseButton.y;

                    if (enemy.isClicked(mouseX, mouseY)) {
                        enemiesDefeated++;
                        enemy.respawn();
                    }
                }
            }
        }

        sf::Vector2i mousePos = sf::Mouse::getPosition(App);
        crosshair.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

        App.clear(sf::Color::Black);

        App.draw(enemy.sprite);
        App.setMouseCursorVisible(false);
        App.draw(crosshair.sprite);
        App.display();
        if (enemiesDefeated >= 5) {
            App.close();
        }
    }

    return 0;
}
