#include <SFML/Graphics.hpp>

class Shape {
public:
    sf::Sprite sprite;
    sf::Texture textureSquare;
    sf::Texture textureCircle;
    bool isCircle;

    Shape() {
        textureSquare.loadFromFile("./assets/cuad_yellow.png");
        textureCircle.loadFromFile("./assets/rcircleg.png");

        sprite.setTexture(textureSquare);
        sprite.setPosition(375.f, 275.f);
        sprite.setScale(0.25f, 0.25f);
        isCircle = false;
    }

    void toggleShape() {
        isCircle = !isCircle; 
        sprite.setTexture(isCircle ? textureCircle : textureSquare);
        sprite.setScale(isCircle ? 1.0f : 0.25f, isCircle ? 1.0f : 0.25f);
    }

    void move(float x, float y) {
        float newX = sprite.getPosition().x + x;
        float newY = sprite.getPosition().y + y;

        sf::FloatRect bounds = sprite.getGlobalBounds();

        if (newX >= 0 && newX <= 800 - bounds.width) {
            sprite.move(x, 0);
        }
        if (newY >= 0 && newY <= 600 - bounds.height) {
            sprite.move(0, y);
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(sprite);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Atrapado");

    Shape shape;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            shape.move(-1.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            shape.move(1.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            shape.move(0.f, -1.f); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            shape.move(0.f, 1.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            shape.toggleShape();
            sf::sleep(sf::milliseconds(200));
        }

        window.clear(sf::Color::Black);
        shape.draw(window);
        window.display();
    }

    return 0;
}



