/**********************************************************************************
// Home (Código Fonte)
//
// Criação:     18 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Tela de abertura do jogo PacMan
//
**********************************************************************************/

#include "Engine.h"
#include "Home.h"
#include "GameCompleted.h"
#include "Sprite.h"
#include "Scene.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

void GameCompleted::Init()
{
    backg = new Sprite("Resources/GameCompleted.jpg");
}

// ------------------------------------------------------------------------------

void GameCompleted::Finalize()
{
    delete backg;
}

// ------------------------------------------------------------------------------

void GameCompleted::Update()
{
    // sai do jogo com a tecla ESC
    if (window->KeyPress(VK_ESCAPE))
        Engine::Next<Home>();

    // reinicia o game com ENTER
    if (window->KeyPress(VK_RETURN))
        Engine::Next<Level1>();

}

// ------------------------------------------------------------------------------

void GameCompleted::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}

// ------------------------------------------------------------------------------