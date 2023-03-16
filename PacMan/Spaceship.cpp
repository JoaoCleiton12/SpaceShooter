/**********************************************************************************
// Ghost (C�digo Fonte)
// 
// Cria��o:     01 Jan 2013
// Atualiza��o: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Fantasmas do PacMan
//
**********************************************************************************/

#include "Space.h"
#include "Player.h"
#include "Spaceship.h"
#include "Level1.h"

// ---------------------------------------------------------------------------------

Spaceship::Spaceship(Image * p)
{
    // tamanho do bloco � 40x60
    BBox(new Rect(-20, -30, 19, 29));

    // sprite do bloco
    sprite = new Sprite(p);

    // velocidades iniciais
    velX = 0.0f;
    velY = 100.0f;

    // tipo do objeto
    type = INIMIGO;

}

// ---------------------------------------------------------------------------------

Spaceship::~Spaceship()
{
    delete sprite;
}


// ---------------------------------------------------------------------------------

void Spaceship::Update()
{
    // desloca o bloco
    Translate(velX * gameTime, velY * gameTime);

    // destr�i ao sair da janela
    if (y > window->Height())
        Level1::scene->Delete();
}

// ---------------------------------------------------------------------------------
