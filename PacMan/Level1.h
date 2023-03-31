/**********************************************************************************
// Level1 (Arquivo de Cabeçalho)
// 
// Criação:     18 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Nível 1 do jogo PacMan
//
**********************************************************************************/

#ifndef _PACMAN_LEVEl1_H_
#define _PACMAN_LEVEL1_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Timer.h"

// ------------------------------------------------------------------------------

class Level1 : public Game
{
public:
    Sprite * backg = nullptr;       // background
    bool viewBBox = false;          // habilita visualização da bounding box
    Image* tile1 = nullptr;

    Timer roundTime;                // contador do game
    float tempo1 = 2.0f;
    Timer roundTime2;
    float tempo2 = 5.0f;
    Timer roundTime3;
    float tempo3 = 8.0f;
    Timer roundTime4;
    float tempo4 = 15.0f;

    Timer roundTimeGamer;
    float tempoGame = 5.0f;         // tempo limite do game

public:
    static Scene* scene;         // gerenciador de cena
    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

// -----------------------------------------------------------------------------

#endif