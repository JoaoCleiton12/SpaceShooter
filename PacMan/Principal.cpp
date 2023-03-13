/**********************************************************************************
// PacMan (Código Fonte)
// 
// Criação:     01 Jan 2013
// Atualização: 04 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Exercício sobre detecção de colisão
//
**********************************************************************************/

#include "Engine.h"
#include "Resources.h"
#include "Home.h"

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, 
                     _In_opt_ HINSTANCE hPrevInstance, 
                     _In_ LPSTR lpCmdLine, 
                     _In_ int nCmdShow)
{
    // cria engine
    Engine * engine = new Engine();

    // configura a janela do jogo
    engine->window->Mode(WINDOWED);
    engine->window->Size(960, 720);
    engine->window->Color(25, 25, 25);
    engine->window->Title("PacMan");
    engine->window->Icon(IDI_ICON);

    // configura dispositivo gráfico
    //engine->graphics->VSync(true);
    
    // inicia o jogo
    engine->Start(new Home());

    // destrói engine e jogo
    delete engine;
}

// ----------------------------------------------------------------------------

