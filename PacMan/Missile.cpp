
#include "Missile.h"
#include "Level1.h"
#include "Level2.h"


Missile::Missile(Image* img) {
	sprite = new Sprite(img);
	velocidade = 300;
}

Missile::~Missile() {
	delete sprite;
}

void Missile::Update() {

	Translate(0, -velocidade * gameTime);

	if (y < 0) {
		Level1::scene->Delete();
	}

}