/**********************************************************************************
// Level2 (Arquivo de Cabeçalho)
// 
// Criação:     18 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Nível 2 do jogo PacMan
//
**********************************************************************************/

#ifndef _PACMAN_LEVEl2_H_
#define _PACMAN_LEVEL2_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"

// ------------------------------------------------------------------------------

class Level2 : public Game
{
private:
    Sprite * backg = nullptr;       // background
    Scene * scene = nullptr;        // gerenciado de cena
    bool viewBBox = false;          // habilita visualização da bounding box
    
public:

    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

// -----------------------------------------------------------------------------

#endif