#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include <Game.h>

class TextureManagement;
struct Matrice;

class ScreenManager
{
    public:
        ScreenManager(SDL_Window* window,SDL_Renderer* renderer);
        virtual ~ScreenManager();
        SDL_Window* window;
        SDL_Renderer* renderer;
        void ScreenMain(TextureManagement* t);
        void ScreenWinner(TextureManagement* t);
        void ScreenLoser(TextureManagement* t);
        void ScreenPreparing(Matrice a[10][10],Matrice b[10][10],TextureManagement* t,int x,int y,GameObject* ItemDragging,bool dragging);
        void drag(GameObject* obj);
        void ScreenPlaying(Matrice a[10][10],Matrice b[10][10],TextureManagement* t,int x,int y,bool yourturn);
        void ScreenRunning(Matrice a[10][10],Matrice b[10][10],TextureManagement* t,int x,int y,GameObject* ItemDragging,bool dragging,bool preparing,bool yourturn,bool playing);
    protected:

    private:
};

#endif // SCREENMANAGER_H
