#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Character.h"
#include "Platform.h"
#include <iostream>

using namespace sf;
using namespace std;

static const float VIEW_HEIGHT = 512.f;

void resizeView(const RenderWindow& window, View& view) {
	float aspectratio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectratio, VIEW_HEIGHT);
}

int main(){
	RenderWindow window(VideoMode(512,512), "test", Style::Close | Style::Resize);
	View view(Vector2f(0.f,0.f),Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	Texture playertexture;
	playertexture.loadFromFile("Content/tux/tux_2_lienzo_escalado_5.png");

	Character character1(&playertexture, Vector2u(3, 9), 0.3f,150.f);

	Platform platform1(nullptr, Vector2f(400.f, 200.f), Vector2f(500.f, 200.f));
	Platform platform2(nullptr, Vector2f(400.f, 200.f), Vector2f(0.f, 0.f));

	float deltatime = 0.f;
	Clock clock;
	
	while (window.isOpen()) {
		deltatime = clock.restart().asSeconds();
		Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case Event::Closed:
					window.close();
					break;
				case Event::Resized:
					resizeView(window, view);
					break;
				case Event::TextEntered:
					if (true) {
						//cout << animation.uvrect.top <<endl;
						//cout << animation.uvrect.left << endl;
					}
					break;
				default:
					break;
			}
		}
		if (Mouse::isButtonPressed(Mouse::Button::Left)) {
			Vector2i mousepos = Mouse::getPosition(window);
			//character1.setPosition((float)mousepos.x,(float)mousepos.y);
		}

		character1.update(deltatime);
		view.setCenter(character1.getPosition());
		platform1.getCollider().checkCollision(character1.getCollider(), 0.f);
		platform2.getCollider().checkCollision(character1.getCollider(), 0.f);

		window.clear(Color(220,220,220,255));

		window.setView(view);

		character1.draw(window);
		platform1.draw(window);
		platform2.draw(window);
		window.display(); 
	}
	return 0;
}

/* MOVER EL SHAPE CON TECLADO
if (Keyboard::isKeyPressed(Keyboard::Key::A))
			circle.move(-0.1f,0.f);
		if (Keyboard::isKeyPressed(Keyboard::Key::D))
			circle.move(0.1f, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::Key::W))
			circle.move(0.f, -0.1f);
		if (Keyboard::isKeyPressed(Keyboard::Key::S))
			circle.move(0.f, 0.1f);
		//if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
		if (Mouse::isButtonPressed(Mouse::Button::Left))
			window.clear();

			if (event.text.unicode < 128) {
				printf("%c: ", event.text.unicode);
				cout << event.text.unicode <<endl;
			}

	Sprite sprite;
	sprite.setTexture(playertexture);
	sprite.setOrigin(playertexture.getSize().x / 2.f, playertexture.getSize().y / 2.f);
	sprite.setScale(0.2f,0.2f);

	RectangleShape rectangle(Vector2f(100.f,150.f));
	rectangle.setFillColor(Color(255,255, 255,255));
	rectangle.setOrigin(rectangle.getSize().x / 2.f, rectangle.getSize().y / 2.f);

	CircleShape circle(5.f);
	circle.setFillColor(Color(255,255,255,255));

	Vector2u textureplayersize = playertexture.getSize();
	textureplayersize.x /= 3;
	textureplayersize.y /= 9;

	player.setTextureRect(IntRect(textureplayersize.x * 2, textureplayersize.y * 8, textureplayersize.x, textureplayersize.y));

*/