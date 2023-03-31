/**********************************************************************************
// Home (Arquivo de Cabeçalho)

//
// Descrição:   Tela de Game
//
**********************************************************************************/

#ifndef _SPACESHIP_GAMECOMPLETED_H_
#define _SPACESHIP_GAMECOMPLETED_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"

// ------------------------------------------------------------------------------

class GameCompleted : public Game
{
private:
    Sprite* backg = nullptr;       // pano de fundo

public:
    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// -----------------------------------------------------------------------------

#endif
