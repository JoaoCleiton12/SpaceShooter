// Descri��o:   M�sseis do jogo

#ifndef _SPACE_MISSILE_H_
#define _SPACE_MISSILE_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"              // tipos espec�ficos da engine
#include "Object.h"             // interface de object
#include "Sprite.h"             // interface de sprites
#include "Image.h"

class Missile : public Object {
private:
	Sprite* sprite;
	float velocidade;

public:
	Missile(Image* img);
	~Missile();
	void Update();
	void Draw();
};

inline void Missile::Draw() {
	sprite->Draw(x, y, z);
}

#endif