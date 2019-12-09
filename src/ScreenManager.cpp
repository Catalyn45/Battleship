#include "ScreenManager.h"
ScreenManager::ScreenManager(SDL_Window* window, SDL_Renderer* renderer)
{
    this->window=window;
    this->renderer=renderer;
}
void ScreenManager::ScreenPreparing(Matrice a[10][10],Matrice b[10][10],TextureManagement* t,int x,int y,GameObject* ItemDragging,bool dragging)
{

            if(t->start_game->ishover)
                SDL_RenderCopy(renderer,t->hover_game->texture,NULL,&t->start_game->dimensiuni);
            else
            if(t->clear_game->ishover)
                SDL_RenderCopy(renderer,t->hover_game->texture,NULL,&t->clear_game->dimensiuni);
            else
            if(t->menu_game->ishover)
                SDL_RenderCopy(renderer,t->hover_game->texture,NULL,&t->menu_game->dimensiuni);

            SDL_RenderCopy(renderer,t->start_game->texture,NULL,&t->start_game->dimensiuni);
            SDL_RenderCopy(renderer,t->clear_game->texture,NULL,&t->clear_game->dimensiuni);
            SDL_RenderCopy(renderer,t->menu_game->texture,NULL,&t->menu_game->dimensiuni);
            for(int i=2;i<=5;i++)
                for(int j=0;j<=t->ships[i]->placed;j++)
                    SDL_RenderCopy(this->renderer,t->ships[i]->texture_dinamic[t->ships[i]->indextextura[j]],NULL,&t->ships[i]->dimensiuni_dinamice[j]);
                if(dragging)
                    {
                        drag(ItemDragging);
                        SDL_RenderCopy(renderer,ItemDragging->texture_dinamic[ItemDragging->indextextura[0]],NULL,&ItemDragging->dimensiuni);
                    }
            for(int i=2;i<=5;i++)
                SDL_RenderCopy(renderer,t->text[i]->texture,NULL,&t->text[i]->dimensiuni);


}
void ScreenManager::ScreenPlaying(Matrice a[10][10],Matrice b[10][10],TextureManagement* t,int x,int y,bool yourturn)
{

    SDL_RenderCopy(this->renderer,t->turn->texture,NULL,&t->turn->dimensiuni);
    SDL_RenderCopy(this->renderer,t->remaining->texture,NULL,&t->remaining->dimensiuni);

    for(int i=2;i<=5;i++)
        SDL_RenderCopy(this->renderer,t->ships_transparent[i]->texture,NULL,&t->ships_transparent[i]->dimensiuni);

    if(t->menu_game->ishover)
        SDL_RenderCopy(renderer,t->hover_game->texture,NULL,&t->menu_game->dimensiuni);

    t->menu_game->setPosition(30,73);

    SDL_RenderCopy(this->renderer,t->menu_game->texture,NULL,&t->menu_game->dimensiuni);


    for(int i=2;i<=5;i++)
        {
            for(int j=1;j<=t->ships[i]->placed;j++)
                    SDL_RenderCopy(this->renderer,t->ships[i]->texture_dinamic[t->ships[i]->indextextura[j]],NULL,&t->ships[i]->dimensiuni_dinamice[j]);
            for(int j=1;j<=t->ships_enemy[i]->placed;j++)
                if(t->ships_enemy[i]->show[j])
                    SDL_RenderCopy(this->renderer,t->ships_enemy[i]->texture_dinamic[t->ships_enemy[i]->indextextura[j]],NULL,&t->ships_enemy[i]->dimensiuni_dinamice[j]);
            SDL_RenderCopy(renderer,t->text[i]->texture,NULL,&t->text[i]->dimensiuni);
        }

    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            {
                   if(a[i][j].revealed)
                     {
                        t->patratel->setPosition(j*37+416,i*37+215);
                        SDL_RenderCopy(this->renderer,t->patrat_revealed,NULL,&t->patratel->dimensiuni);
                     }
                    if(b[i][j].revealed)
                     {
                        t->patratel->setPosition(j*37+24,i*37+215);
                        SDL_RenderCopy(this->renderer,t->patrat_revealed,NULL,&t->patratel->dimensiuni);
                     }
            }
}


void ScreenManager::ScreenMain(TextureManagement* t)
{
            SDL_RenderCopy(renderer,t->background->texture,NULL,&t->background->dimensiuni);

            if(t->start->ishover)
                SDL_RenderCopy(renderer,t->hover->texture,NULL,&t->start->dimensiuni);
            else
            if(t->options->ishover)
                SDL_RenderCopy(renderer,t->hover->texture,NULL,&t->options->dimensiuni);
            else
            if(t->exit->ishover)
                SDL_RenderCopy(renderer,t->hover->texture,NULL,&t->exit->dimensiuni);

            SDL_RenderCopy(renderer,t->start->texture,NULL,&t->start->dimensiuni);
            SDL_RenderCopy(renderer,t->options->texture,NULL,&t->options->dimensiuni);
            SDL_RenderCopy(renderer,t->exit->texture,NULL,&t->exit->dimensiuni);
}
void ScreenManager::ScreenWinner(TextureManagement* t)
{
            SDL_RenderCopy(this->renderer,t->back_win->texture,NULL,&t->back_win->dimensiuni);

            if(t->menu_game->ishover)
                SDL_RenderCopy(this->renderer,t->hover_game->texture,NULL,&t->menu_game->dimensiuni);
            else
            if(t->play_again->ishover)
                SDL_RenderCopy(this->renderer,t->hover_game->texture,NULL,&t->play_again->dimensiuni);


            SDL_RenderCopy(this->renderer,t->menu_game->texture,NULL,&t->menu_game->dimensiuni);
            SDL_RenderCopy(this->renderer,t->play_again->texture,NULL,&t->play_again->dimensiuni);

}
void ScreenManager::ScreenLoser(TextureManagement* t)
{
            SDL_RenderCopy(this->renderer,t->back_lost->texture,NULL,&t->back_lost->dimensiuni);

            if(t->menu_game->ishover)
                SDL_RenderCopy(this->renderer,t->hover_game->texture,NULL,&t->menu_game->dimensiuni);
            else
            if(t->play_again->ishover)
                SDL_RenderCopy(this->renderer,t->hover_game->texture,NULL,&t->play_again->dimensiuni);


            SDL_RenderCopy(this->renderer,t->menu_game->texture,NULL,&t->menu_game->dimensiuni);
            SDL_RenderCopy(this->renderer,t->play_again->texture,NULL,&t->play_again->dimensiuni);
}
void ScreenManager::ScreenRunning(Matrice a[10][10],Matrice b[10][10],TextureManagement* t,int x,int y,GameObject* ItemDragging,bool dragging,bool preparing,bool yourturn,bool playing)
{
    SDL_RenderCopy(this->renderer,t->background_game->texture,NULL,&t->background_game->dimensiuni);
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            {
                SDL_Texture* block;
                if(b[i][j].valoare==true)
                        block=t->patratel_hover->texture;
                else
                if(b[i][j].used==true)
                   if(b[i][j].revealed)
                        block=t->patrat_revealed;
                   else
                    block=t->patrat_used;
                else
                    block=t->patratel->texture;
                t->patratel->setPosition(j*37+24,i*37+215);

                SDL_RenderCopy(this->renderer,block,NULL,&t->patratel->dimensiuni);

                if(a[i][j].valoare==true)
                    block=t->patratel_hover->texture;
                else
                if(a[i][j].used==true)
                   if(a[i][j].revealed)
                        block=t->patrat_revealed;
                   else
                    block=t->patrat_used;
                else
                    block=t->patratel->texture;
                t->patratel->setX(j*37+416);
                SDL_RenderCopy(this->renderer,block,NULL,&t->patratel->dimensiuni);

            }
              if(preparing)
                this->ScreenPreparing(a,b,t,x,y,ItemDragging,dragging);
              else
              if(playing)
                this->ScreenPlaying(a,b,t,x,y,yourturn);
}
void ScreenManager::drag(GameObject* obj)
{
    int x,y;
    SDL_GetMouseState(&x,&y);
    obj->setPosition(x-obj->getW()/2,y-obj->getH()/2);
}
ScreenManager::~ScreenManager()
{
    //dtor
}
