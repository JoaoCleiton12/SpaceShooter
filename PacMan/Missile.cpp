
#include "Missile.h"
#include "Level1.h"
#include "Level2.h"
#include "Space.h"
#include "Object.h"


Missile::Missile() {
	//cria boundbox
	BBox(new Circle(4));


	sprite = new Sprite("Resources/Missile.new.png");
	
	velocidade = 300;

	type = MISSEL;
}
	int cont = 0;

Missile::~Missile() {
	delete sprite;
}

void Missile::OnCollision(Object* obj)
{
	// MISSEL colide com bloco
	if (obj->Type() == INIMIGO) {
		Level1::scene->Delete(obj, MOVING);
		cont++;
	}

	// experimente deixar o bloco cair em vez de removê-lo da cena
	//((Block*) obj)->velY = 200.0f;
}

void Missile::Update() {

	Translate(0, -velocidade * gameTime);

	if (y < 0) {
		Level1::scene->Delete();
	}

}