
#include "Game.h"
#include <iostream>
#include <string>
std::string x;
bool Game::Init()
{
    return false;
}

void Game::Test()
{
    std::cout << "Starting Test\n";
    
 
}
void Game::ProcessInputs()
{
    std::cout << "Processing Inputs\n";
    std::cout << "DONE!\n";
}

void Game::Update()
{
    std::cout << "Update\n";
    std::cout << "DONE!\n";
}

void Game::Draw()
{
    std::cout << "Draw\n";
    std::cout << "DONE!\n";
}

Game::Game()
    : m_bIsRunning{true}
{

}

Game::~Game()
{

}

void Game::Run()
{
    if (!Init())
        m_bIsRunning = true;
        
    
    if (m_bIsRunning)
    {
        Test();
        ProcessInputs();
        Update();
        Draw();
        
    }
    std::cout << "BYE BYE";

}


