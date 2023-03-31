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
#include "GameOver.h"
#include "Sprite.h"
#include "Scene.h"
#include "Level1.h"

// ------------------------------------------------------------------------------

void GameOver::Init()
{
    backg = new Sprite("Resources/GameOver.jpg");
}

// ------------------------------------------------------------------------------

void GameOver::Finalize()
{
    delete backg;
}

// ------------------------------------------------------------------------------

void GameOver::Update()
{
    // sai do jogo com a tecla ESC
    if (window->KeyPress('N'))
        Engine::Next<Home>();

    // reinicia o game com ENTER
    if (window->KeyPress('Y'))
        Engine::Next<Level1>();

}

// ------------------------------------------------------------------------------

void GameOver::Draw()
{
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}

// ------------------------------------------------------------------------------