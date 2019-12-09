#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <GameObject.h>
#include <TextureManagement.h>
#include <cstdlib>
#include <ScreenManager.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <fstream>


class ScreenManager;
class TextureManagement;
struct Matrice{
bool valoare=false;
bool used=false;
bool ship=false;
bool revealed=false;
int indexship=-1;
int indexplaced=0;
};
struct navete{
int ships[10];
int linie[10];
int coloana[10];
int directie[10];
};
class Game
{
    public:
        Game();
        virtual ~Game();
        SDL_Event e;
        bool afisare=true;
        int fps=1000/60;
        std::fstream f;
        Uint32 prev=SDL_MOUSEBUTTONUP;
        Matrice a[10][10];
        Matrice b[10][10];
        navete nav[109];
        void Clear();
        void Umplere(Matrice a[10][10],int x,int y,int xant,int yant);
        Uint32 time=-1;
        bool Single(Matrice xa[10][10],int x,int y);
        bool start=false;
        bool running=true;
        int n=100;
        int numere[100];
        int placed=0;
        int maxim(int a,int b);
        int minim(int a,int b);
        bool dragging=false;
        bool preparing=false;
        bool playing=false;
        int primax=-1;
        int primay=-1;
        void eliminare(int a[100],int x,int &n);
        void Cautare_binara(int x,int a[100],int left,int right,int &n);
        int xant=-1;
        int yant=-1;
        void algoritm(Matrice xa[10][10],int &x,int &y);
        GameObject* ItemDragging;
        bool isRunning();
        void CreateRenderer();
        void PlaceShip(Matrice a[10][10],int x,int y,GameObject* obj,int direction,int xdefect);
        int direction=1;
        void changedir();
        void CreateWindow(char* title,int w,int h);
        void Destroy();
        int distrusePlayer=0;
        int distruseEnemy=0;
        int xpozit=0;
        bool corespunzator(GameObject* obj,int lungime,int x,int y,int directie,Matrice a[10][10]);
        int ypozit=0;
        void CreateGame(char* titlu,int w,int h);
        void Display();
        void Generare();
        bool Incadrare(GameObject* obj,int l);
        bool HoverOn(int x,int y);
        ScreenManager* sm;
        TextureManagement* t;
        int indexdragging=0;
        int x=0;
        Uint32 mytime;
        void Curatare();
        int y=0;
        int lasti=0;
        void ChangeObjDirection(GameObject* obj,int dir);
        bool yourturn=false;
        bool loser=false;
        bool winner=false;
        bool onClick(GameObject* obj);
        bool onHover(GameObject* obj);
        void Update();
        void Render();
        void MatriceInamica();
        void shot(Matrice a[10][10],int x,int y,int atacator);
        int getWindowX();
        int getWindowY();
        SDL_Window* window;
        SDL_Renderer* renderer;

    protected:

    private:
};

#endif // GAME_H
