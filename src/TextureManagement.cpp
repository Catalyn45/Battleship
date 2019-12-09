#include "TextureManagement.h"

TextureManagement::TextureManagement(SDL_Renderer* renderer)
{
    this->font=TTF_OpenFont("font1.ttf",200);
    this->textura1=new GameObject(renderer,"imagini/platforma.png");
    this->textura1->setSize(40,40);
    this->textura2=new GameObject(renderer,"imagini/platforma2.png");
    this->textura=this->textura1->texture;
    this->start=new GameObject(renderer,"imagini/Start.png");
    this->options=new GameObject(renderer,"imagini/Options.png");
    this->exit=new GameObject(renderer,"imagini/Exit.png");
    this->winscreen=new GameObject(renderer,"imagini/Winner.png");
    this->background=new GameObject(renderer,"imagini/background.jpg");
    this->hover=new GameObject(renderer,"imagini/hover.png");
    this->background_game=new GameObject(renderer,"imagini/background_game.jpg");
    this->patratel=new GameObject(renderer,"imagini/patratel.png");
    this->patratel_hover=new GameObject(renderer,"imagini/patratel_hover.png");


    this->ships[2]=new GameObject(renderer,"imagini/ship_2.png");
    this->ships_transparent[2]=new GameObject(renderer,"imagini/ship_2_transparent.png");

    this->ships[3]=new GameObject(renderer,"imagini/ship_3.png");
    this->ships_transparent[3]=new GameObject(renderer,"imagini/ship_3_transparent.png");

    this->ships[4]=new GameObject(renderer,"imagini/ship_4.png");
    this->ships_transparent[4]=new GameObject(renderer,"imagini/ship_4_transparent.png");

    this->ships[5]=new GameObject(renderer,"imagini/ship_5.png");
    this->ships_transparent[5]=new GameObject(renderer,"imagini/ship_5_transparent.png");

    this->patrat_used=IMG_LoadTexture(renderer,"imagini/patrat_used.png");
    this->patrat_revealed=IMG_LoadTexture(renderer,"imagini/patrat_revealed.png");

    this->ships[2]->texture_dinamic[2]=IMG_LoadTexture(renderer,"imagini/ship_2_vertical.png");
    this->ships[3]->texture_dinamic[2]=IMG_LoadTexture(renderer,"imagini/ship_3_vertical.png");
    this->ships[4]->texture_dinamic[2]=IMG_LoadTexture(renderer,"imagini/ship_4_vertical.png");
    this->ships[5]->texture_dinamic[2]=IMG_LoadTexture(renderer,"imagini/ship_5_vertical.png");

    this->ships_transparent[2]->texture_dinamic[2]=IMG_LoadTexture(renderer,"imagini/ship_2_transparent_vertical.png");
    this->ships_transparent[3]->texture_dinamic[2]=IMG_LoadTexture(renderer,"imagini/ship_3_transparent_vertical.png");
    this->ships_transparent[4]->texture_dinamic[2]=IMG_LoadTexture(renderer,"imagini/ship_4_transparent_vertical.png");
    this->ships_transparent[5]->texture_dinamic[2]=IMG_LoadTexture(renderer,"imagini/ship_5_transparent_vertical.png");
    this->White={255,255,255};


    this->back_win=new GameObject(renderer,"imagini/back_win.png");


    this->back_lost=new GameObject(renderer,"imagini/back_lost.png");



    this->start_game=new GameObject(renderer,"imagini/Start_game.png");
    this->menu_game=new GameObject(renderer,"imagini/menu_game.png");
    this->clear_game=new GameObject(renderer,"imagini/clear_game.png");
    this->hover_game=new GameObject(renderer,"imagini/hover_game.png");

    this->yourturn=IMG_LoadTexture(renderer,"imagini/Yourturn.png");
    this->enemyturn=IMG_LoadTexture(renderer,"imagini/Enemyturn.png");
    this->turn=new GameObject(renderer,this->yourturn);
    this->remaining=new GameObject(renderer,"imagini/remaining.png");

    this->play_again=new GameObject(renderer,"imagini/play_again.png");

    this->start->setSize(104,609);
    this->start->setPosition(100,100);

    this->options->setSize(104,609);
    this->options->setPosition(100,230);

    this->exit->setSize(104,609);
    this->exit->setPosition(100,360);

    this->background->setSize(600,800);
    this->background->setPosition(0,0);

}

SDL_Texture* TextureManagement::TextureFromText(SDL_Renderer* renderer,char* text)
{
    return SDL_CreateTextureFromSurface(renderer,TTF_RenderText_Solid(this->font,text,this->White));
}

void TextureManagement::init_winner()
{
    back_win->setSize(600,800);
    back_win->setPosition(0,0);
    menu_game->setPosition(330,417);
    play_again->setSize(43,161);
    play_again->setPosition(330,350);

}
void TextureManagement::init_loser()
{
    back_lost->setSize(600,800);
    back_lost->setPosition(0,0);
    menu_game->setPosition(330,387);
    play_again->setSize(43,161);
    play_again->setPosition(330,320);
}
void TextureManagement::init_preparing(SDL_Renderer* renderer)
{

    this->background_game->setSize(600,800);
    this->background_game->setPosition(0,0);

    this->text[2]=new GameObject(renderer,this->TextureFromText(renderer,"4x"));
    this->text[3]=new GameObject(renderer,this->TextureFromText(renderer,"3x"));
    this->text[4]=new GameObject(renderer,this->TextureFromText(renderer,"2x"));
    this->text[5]=new GameObject(renderer,this->TextureFromText(renderer,"1x"));

    this->turn->setSize(25,182);
    this->turn->setPosition(30,140);

    this->remaining->setPosition(260,8);
    this->remaining->setSize(9,210);

    this->patratel->setSize(30,30);
    this->patratel->setPosition(0,0);

    this->winscreen->setSize(600,800);
    this->winscreen->setPosition(0,0);

    this->start_game->setSize(43,161);
    this->clear_game->setSize(43,161);
    this->menu_game->setSize(43,161);
    this->hover_game->setSize(43,161);

    this->start_game->setPosition(322,19);
    this->clear_game->setPosition(322,72);
    this->menu_game->setPosition(322,125);


    this->text[2]->setSize(30,37);
    this->text[2]->setPosition(29,20);


    this->text[3]->setSize(30,37);
    this->text[3]->setPosition(29,56);

    this->text[4]->setSize(30,37);
    this->text[4]->setPosition(29,100);


    this->text[5]->setSize(30,37);
    this->text[5]->setPosition(29,143);

    this->ships[2]->setSize(31,72);
    this->ships[2]->setPositionDinamic(82,20,0);
    this->ships_transparent[2]->setSize(31,72);
    this->ships[2]->setPosition(82,20);
    this->ships[2]->setSizeDinamic(31,72,0);

    this->ships[3]->setSize(40,109);
    this->ships_transparent[3]->setSize(40,109);
    this->ships[3]->setPositionDinamic(82,55,0);
    this->ships[3]->setPosition(82,55);
    this->ships[3]->setSizeDinamic(40,109,0);

    this->ships[4]->setSize(40,145);
    this->ships_transparent[4]->setSize(40,145);
    this->ships[4]->setPositionDinamic(82,100,0);
    this->ships[4]->setPosition(82,100);
    this->ships[4]->setSizeDinamic(40,145,0);

    this->ships[5]->setSize(40,185);
    this->ships_transparent[5]->setSize(40,185);
    this->ships[5]->setPositionDinamic(82,140,0);
    this->ships[5]->setPosition(82,140);
    this->ships[5]->setSizeDinamic(40,185,0);

    this->ships_enemy[2]=new GameObject(renderer,ships[2]->texture);
    this->ships_enemy[3]=new GameObject(renderer,ships[3]->texture);
    this->ships_enemy[4]=new GameObject(renderer,ships[4]->texture);
    this->ships_enemy[5]=new GameObject(renderer,ships[5]->texture);

    for(int i=2;i<=5;i++)
        {
            ships[i]->movable=true;
            ships_transparent[i]->nrblockuri=i;
            ships[i]->nrblockuri=i;
            ships_enemy[i]->dimensiuni=ships[i]->dimensiuni;
            ships_enemy[i]->texture_dinamic[1]=ships[i]->texture_dinamic[1];
            ships_enemy[i]->texture_dinamic[2]=ships[i]->texture_dinamic[2];
            ships_enemy[i]->nrblockuri=i;
            for(int j=0;j<=5;j++)
                {
                    ships_enemy[i]->show[j]=false;
                    ships_enemy[i]->dimensiuni_dinamice[j]=ships[i]->dimensiuni_dinamice[j];
                }
        }
    ships_enemy[5]->maxim=ships[5]->maxim=1;
    ships_enemy[4]->maxim=ships[4]->maxim=2;
    ships_enemy[3]->maxim=ships[3]->maxim=3;
    ships_enemy[2]->maxim=ships[2]->maxim=4;
}
void TextureManagement::init_playing(SDL_Renderer* renderer)
{

    this->ships_transparent[2]->setPosition(328,34);
    this->ships_transparent[3]->setPosition(328,65);
    this->ships_transparent[4]->setPosition(328,107);
    this->ships_transparent[5]->setPosition(328,145);

    this->ChangeText(renderer,this->text[2],"4x");
    this->ChangeText(renderer,this->text[3],"3x");
    this->ChangeText(renderer,this->text[4],"2x");
    this->ChangeText(renderer,this->text[5],"1x");

    this->text[2]->setPosition(272,34);
    this->text[3]->setPosition(272,65);
    this->text[4]->setPosition(272,107);
    this->text[5]->setPosition(272,145);

    for(int i=2;i<=5;i++)
        this->ships_enemy[i]->destroyed=0;

}
void TextureManagement::ChangeText(SDL_Renderer* renderer,GameObject* obj,const char* text)
{
    obj->texture=SDL_CreateTextureFromSurface(renderer,TTF_RenderText_Solid(this->font,text,this->White));
}
TextureManagement::~TextureManagement()
{
    //dtor
}
