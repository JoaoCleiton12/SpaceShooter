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
#include <chrono>
#include <thread>
#include <iostream>
#include <Windows.h>
#include "Missile.h"
#include <random>
#include "GameCompleted.h"
using namespace std::this_thread;

using std::ifstream;
using std::string;
using namespace std;

// ------------------------------------------------------------------------------

Scene* Level1::scene = nullptr;

float line1 = 62.0f;
float line2 = 92.0f;
float line3 = 122.0f;
float line4 = 152.0f;
float line5 = 182.0f;


// define um número pseudoaleatório que será a posX do meteoro na tela
random_device rd;
mt19937 mt(rd());
uniform_int_distribution<> dis(0, 450);


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

    // posição dos meteoros
    tile1 = new Image("Resources/Meteoro.png");

    Spaceship* meteoro;
    meteoro = new Spaceship(tile1);
    meteoro->MoveTo(window->CenterX() - dis(mt), line1);
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

    roundTime.Start();
    roundTime2.Start();
    roundTime3.Start();
    roundTime4.Start();


    roundTimeGamer.Start();
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

    
    // condição para nascer 3 meteoros a cada 2 segundos
    if (roundTime.Elapsed(tempo1)) {

        Spaceship* meteoro;
        meteoro = new Spaceship(tile1);
        meteoro->MoveTo(window->CenterX() - dis(mt), line1);
        scene->Add(meteoro, MOVING);

        meteoro = new Spaceship(tile1);
        meteoro->MoveTo(window->CenterX() - dis(mt), line1);
        meteoro->velY = 50;
        scene->Add(meteoro, MOVING);

        meteoro = new Spaceship(tile1);
        meteoro->MoveTo(window->CenterX() + dis(mt), line1);
        meteoro->velY = 150;
        scene->Add(meteoro, MOVING);

        roundTime.Reset();
    }

    // condição para nascer +4 meteoros a cada 5 segundos
    if (roundTime2.Elapsed(tempo2)) {
        Spaceship* meteoro;
        meteoro = new Spaceship(tile1);
        meteoro->MoveTo(window->CenterX() - dis(mt), line1);
        meteoro->velY = 200;
        scene->Add(meteoro, MOVING);

        meteoro = new Spaceship(tile1);
        meteoro->MoveTo(window->CenterX() + dis(mt), line1);
        meteoro->velY = 200;
        scene->Add(meteoro, MOVING);


        roundTime2.Reset();

    }

    //condição para nascer +5 meteoros a cada 8 segundos
    if (roundTime3.Elapsed(tempo3)) {
        Spaceship* meteoro;
        meteoro = new Spaceship(tile1);
        meteoro->MoveTo(window->CenterX() - dis(mt), line1);
        meteoro->velY = 200;
        scene->Add(meteoro, MOVING);

        meteoro = new Spaceship(tile1);
        meteoro->MoveTo(window->CenterX() + dis(mt), line1);
        meteoro->velY = 200;
        scene->Add(meteoro, MOVING);

        meteoro = new Spaceship(tile1);
        meteoro->MoveTo(window->CenterX() + dis(mt), line1);
        meteoro->velY = 200;
        scene->Add(meteoro, MOVING);

        meteoro = new Spaceship(tile1);
        meteoro->MoveTo(window->CenterX() - dis(mt), line1);
        meteoro->velY = 200;
        scene->Add(meteoro, MOVING);


        roundTime3.Reset();
    }

    //condição para nascer +6 meteoros a cada 15 segundos
    if (roundTime4.Elapsed(tempo4)) {
        Spaceship* meteoro;
        meteoro = new Spaceship(tile1);
        meteoro->MoveTo(window->CenterX() - dis(mt), line1);
        meteoro->velY = 200;
        scene->Add(meteoro, MOVING);

        meteoro = new Spaceship(tile1);
        meteoro->MoveTo(window->CenterX() + dis(mt), line1);
        meteoro->velY = 200;
        scene->Add(meteoro, MOVING);

        meteoro = new Spaceship(tile1);
        meteoro->MoveTo(window->CenterX() + dis(mt), line1);
        meteoro->velY = 200;
        scene->Add(meteoro, MOVING);

        meteoro = new Spaceship(tile1);
        meteoro->MoveTo(window->CenterX() - dis(mt), line1);
        meteoro->velY = 200;
        scene->Add(meteoro, MOVING);


        roundTime4.Reset();
    }


    //testar se os objetos colidem
    /*
    if (detectarColisao == true) {
        Engine::Next<GameOver>();
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
    else if (window->KeyPress('P')) {
        Engine::Next<GameOver>();
    }
    else if (roundTimeGamer.Elapsed(tempoGame)) {
        Sleep(1000);
        Engine::Next<GameCompleted>();
    } else {
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