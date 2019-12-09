#include "Naveta.h"

Naveta::Naveta(int nrblockuri,SDL_Renderer* renderer,char* file):GameObject(renderer,file)
{

    this->nrblockuri=nrblockuri;
}

Naveta::~Naveta()
{
    //dtor
}
