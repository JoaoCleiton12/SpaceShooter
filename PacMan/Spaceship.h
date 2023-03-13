/**********************************************************************************
// Ghost (Arquivo de Cabeçalho)
// 
// Criação:     01 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Fantasmas do PacMan
//
**********************************************************************************/

#ifndef _PACMAN_GHOST_H_
#define _PACMAN_GHOST_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites
#include "Player.h"                     // jogador do PacMan

// ---------------------------------------------------------------------------------

class Spaceship : public Object
{
private:
    Sprite * sprite = nullptr;          // sprite do player
    Player * player = nullptr;          // ponteiro para jogador

public:
    float velX = 0;                     // velocidade horizontal
    float velY = 0;                     // velocidade vertical

    Spaceship(Player * p);                  // construtor
    ~Spaceship();                           // destrutor

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

inline void Spaceship::Draw()
{ sprite->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif