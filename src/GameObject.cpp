#include "GameObject.h"

GameObject::GameObject(SDL_Renderer* renderer,char* file)
{
    this->texture=IMG_LoadTexture(renderer,file);
    this->texture_dinamic[1]=this->texture;
    this->indextextura[0]=1;
}
GameObject::GameObject(SDL_Renderer* renderer,SDL_Texture* textura)
{
    this->texture=textura;
}
void GameObject::setPosition(int x,int y)
{
    this->dimensiuni.x = x;
    this->dimensiuni.y = y;
}
void GameObject::setSize(int h,int w)
{
    this->dimensiuni.h = h;
    this->dimensiuni.w = w;
}
void GameObject::setPositionDinamic(int x,int y,int i)
{
    this->dimensiuni_dinamice[i].x=x;
    this->dimensiuni_dinamice[i].y=y;
}
void GameObject::setSizeDinamic(int h,int w,int i)
{
    this->dimensiuni_dinamice[i].h=h;
    this->dimensiuni_dinamice[i].w=w;
}
int GameObject::getH()
{
    return this->dimensiuni.h;
}
int GameObject::getW()
{
    return this->dimensiuni.w;
}
int GameObject::getX()
{
    return this->dimensiuni.x;
}
int GameObject::getY()
{
    return this->dimensiuni.y;
}
void GameObject::setX(int x)
{
    this->dimensiuni.x=x;
}
void GameObject::setY(int y)
{
    this->dimensiuni.y=y;
}
void GameObject::setW(int w)
{
    this->dimensiuni.w=w;
}
void GameObject::setH(int h)
{
    this->dimensiuni.h=h;
}
GameObject::~GameObject()
{
    //dtor
}
