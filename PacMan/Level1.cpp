/**********************************************************************************
// Level1 (Código Fonte) 
// 
// Criação:     18 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Nível 1 do jogo PacMan
//
**********************************************************************************/

#include "Engine.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"
#include "Player.h"
#include "Pivot.h"
#include <string>
#include <fstream>
#include "Spaceship.h"
#include "GameOver.h"


using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------

Scene* Level1::scene = nullptr;

float line1 = 62.0f;
float line2 = 92.0f;
float line3 = 122.0f;
float line4 = 152.0f;
float line5 = 182.0f;

void Level1::Init()
{
    

    // cria gerenciador de cena
    scene = new Scene();

    // cria background
    backg = new Sprite("Resources/Level1.jpg");

    // cria jogador
    Player * player = new Player();
    scene->Add(player, MOVING);

    // cria pontos de mudança de direção
    Pivot * pivot;
    bool left, right, up, down;
    float posX, posY;
    //-----------------------------------------------
    tile1 = new Image("Resources/Meteoro.png");

    // posição dos meteoros
    Spaceship* meteoro;
    meteoro = new Spaceship(tile1);
    meteoro->MoveTo(window->CenterX() - 320.0f, line1);
    scene->Add(meteoro, MOVING);

    meteoro = new Spaceship(tile1);
    meteoro->MoveTo(window->CenterX() - 240.0f, line1);
    scene->Add(meteoro, MOVING);

    meteoro = new Spaceship(tile1);
    meteoro->MoveTo(window->CenterX() - 160.0f, line1);
    scene->Add(meteoro, MOVING);

    //--------------------------------------------------

    // cria pivôs a partir do arquivo
    ifstream fin;
    fin.open("PivotsL1.txt");
    fin >> left;
    while (!fin.eof())
    {
        if (fin.good())
        {
            // lê linha de informações do pivô
            fin >> right; fin >> up; fin >> down; fin >> posX; fin >> posY;
            pivot = new Pivot(left, right, up, down);
            pivot->MoveTo(posX, posY);
            scene->Add(pivot, STATIC);
        }
        else
        {
            // ignora comentários
            fin.clear();
            char temp[80];
            fin.getline(temp, 80);
        }
        fin >> left;
    }
    fin.close();
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
    delete backg;
    delete scene;
    delete tile1;
}

// ------------------------------------------------------------------------------

void Level1::Update()
{
    //colocar alguma condição para quando passar um determinado tempo
    // nascer mais meteoros na tela
    /*
    if () {
        Spaceship* meteoro;
        meteoro = new Spaceship(tile1);
        meteoro->MoveTo(window->CenterX() - 320.0f, line1);
        scene->Add(meteoro, MOVING);

        meteoro = new Spaceship(tile1);
        meteoro->MoveTo(window->CenterX() - 240.0f, line1);
        scene->Add(meteoro, MOVING);

        meteoro = new Spaceship(tile1);
        meteoro->MoveTo(window->CenterX() - 160.0f, line1);
        scene->Add(meteoro, MOVING);
    }
    */

    // habilita/desabilita bounding box
    if (window->KeyPress('B'))
    {
        viewBBox = !viewBBox;
    }

    if (window->KeyPress(VK_ESCAPE))
    {
        // volta para a tela de abertura
        Engine::Next<Home>();
    }
    else if (window->KeyPress('N'))
    {
        // passa manualmente para o próximo nível
        Engine::Next<Level2>();
    }
    else
    {
        // atualiza cena
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
    // desenha cena
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scene->Draw();

    // desenha bounding box dos objetos
    if (viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------