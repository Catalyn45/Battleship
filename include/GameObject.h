#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <Game.h>
class GameObject
{
    public:
        GameObject(SDL_Renderer* renderer,char* file);
        GameObject(SDL_Renderer* renderer,SDL_Texture* textura);
        virtual ~GameObject();
        void setPosition(int x,int y);
        void setSize(int h,int w);
        int getX();
        int getY();
        int getW();
        int getH();
        int destroyed=0;
        bool show[6]={true,true,true,true,true,true};
        int nrblockuri=0;
        bool movable=false;
        bool ishover=false;
        void setX(int x);
        void setY(int y);
        void setW(int w);
        int shooted[6]={0,0,0,0,0,0};
        int placed=0;
        int maxim=0;
        int indextextura[5];
        void setH(int h);
        void setPositionDinamic(int x,int y,int i);
        void setSizeDinamic(int h,int w,int i);
        SDL_Texture* texture;
        SDL_Texture* texture_dinamic[3];
        SDL_Rect dimensiuni;
        SDL_Rect dimensiuni_dinamice[5];
    protected:

    private:
};

#endif // GAMEOBJECT_H
