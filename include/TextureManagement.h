#ifndef TEXTUREMANAGEMENT_H
#define TEXTUREMANAGEMENT_H
#include <Game.h>
#include <SDL2/SDL_ttf.h>
class GameObject;

class TextureManagement
{
    public:
        TTF_Font* font;
        SDL_Color White;
        TextureManagement(SDL_Renderer* renderer);
        virtual ~TextureManagement();
        SDL_Texture* textura;
        GameObject* textura1;
        GameObject* textura2;
        GameObject* start;
        GameObject* patratel;
        GameObject* options;
        GameObject* exit;
        GameObject* winscreen;
        GameObject* background;
        GameObject* background_game;
        GameObject* patratel_hover;
        GameObject* hover;
        GameObject* text[6];
        GameObject* ships[6];
        GameObject* ships_enemy[6];
        GameObject* ships_transparent[6];
        GameObject* menu_game;
        GameObject* clear_game;
        GameObject* start_game;
        SDL_Texture* patrat_used;
        GameObject* hover_game;
        GameObject* remaining;
        void init_winner();
        void init_loser();
        GameObject* turn;
        GameObject* play_again;
        GameObject* back_win;
        GameObject* back_lost;
        SDL_Texture* patrat_revealed;
        SDL_Texture* yourturn;
        SDL_Texture* enemyturn;
        void init_preparing(SDL_Renderer* renderer);
        void init_playing(SDL_Renderer* renderer);
        SDL_Texture* TextureFromText(SDL_Renderer* renderer,char* text);
        void ChangeText(SDL_Renderer* renderer,GameObject* obj,const char* text);
    protected:

    private:
};

#endif // TEXTUREMANAGEMENT_H
