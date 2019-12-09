#include "Game.h"

Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);

}
void Game::CreateWindow(char* titlu,int w,int h)
{
    this->window=SDL_CreateWindow(titlu,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w,h,0);
}
void Game::CreateGame(char* titlu,int w,int h)
{
    this->CreateWindow(titlu,w,h);
    this->CreateRenderer();
}
bool Game::isRunning()
{
    if(SDL_PollEvent(&this->e))
        if(e.type==SDL_QUIT)
            return false;
    return true;
}

void Game::Clear()
{
    SDL_RenderClear(this->renderer);
}
void Game::Destroy()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
}
void Game::Display()
{
    SDL_RenderPresent(this->renderer);
}
void Game::Render(TextureManagement* t)
{
    for(int i=0;i*40<=this->getWindowY();i++)
        for(int j=0;j*40<=this->getWindowX();j++)
        {
            t->textura->setPosition(j*40,i*40);
            SDL_RenderCopy(this->renderer,t->textura->texture,NULL,&t->textura->dimensiuni);
        }
}
void Game::Update()
{

}
int Game::getWindowX()
{
    int x,y;
    SDL_GetWindowSize(this->window,&x,&y);
    return x;
}
int Game::getWindowY()
{
    int x,y;
    SDL_GetWindowSize(this->window,&x,&y);
    return y;
}
void Game::CreateRenderer()
{
    this->renderer=SDL_CreateRenderer(this->window,-1,0);
    SDL_SetRenderDrawColor(renderer,255,255,255,0);
}
Game::~Game()
{
    //dtor
}
