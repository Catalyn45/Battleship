#include "Game.h"


Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    IMG_Init(IMG_INIT_PNG);

}
void Game::CreateWindow(char* titlu,int w,int h)
{
    this->window=SDL_CreateWindow(titlu,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w,h,0);
}
void Game::CreateGame(char* titlu,int w,int h)
{
    this->CreateWindow(titlu,w,h);
    this->CreateRenderer();
    this->sm=new ScreenManager(this->window,this->renderer);
    this->t= new TextureManagement(this->renderer);
    this->n=100;
    for(int i=0;i<=99;i++)
        this->numere[i]=i;
    time=SDL_GetTicks();

    f.open("nave.txt");
    int a;
    for(int i=0;i<501;i++)
    {
        f>>a;
        for(int j=0;j<10;j++)
        {
            f>>this->nav[i].ships[j];
            f>>this->nav[i].linie[j];
            f>>this->nav[i].coloana[j];
            f>>this->nav[i].directie[j];
        }

    }
    f.close();
}



bool Game::onClick(GameObject* obj)
{
    if(this->e.type==SDL_MOUSEBUTTONDOWN)
        if(this->e.button.button==SDL_BUTTON_LEFT)
        {
            int x,y;
            SDL_GetMouseState(&x,&y);
                if(x>=obj->getX() && y>=obj->getY() && x<=obj->getX()+obj->getW() && y<=obj->getY()+obj->getH())
                    return true;
        }
    return false;
}
bool Game::isRunning()
{
    if(SDL_PollEvent(&this->e))
        if(e.type==SDL_QUIT)
            this->running=false;
    return this->running;
}

bool Game::corespunzator(GameObject* obj,int lungime,int x,int y,int directie,Matrice a[10][10])
{
    if(directie==1)
    {
        if(y+lungime-1>9)
            return false;
        if(y>=1)
            {
                if(a[x][y-1].ship==true)
                    return false;
                if(x>=1)
                    if(a[x-1][y-1].ship==true)
                        return false;
                if(x<=8)
                    if(a[x+1][y-1].ship==true)
                        return false;
            }
        if(y<+lungime<=9)
            {
                if(a[x][y+lungime].ship==true)
                    return false;
                if(x>=1)
                    if(a[x-1][y+lungime].ship==true)
                        return false;
                if(x<=8)
                    if(a[x+1][y+lungime].ship==true)
                        return false;
            }
        for(int i=0;i<lungime;i++)
        {
            if(a[x][y+i].ship==true)
                return false;
            if(x>=1)
                if(a[x-1][y+i].ship==true)
                    return false;
            if(x<=8)
                if(a[x+1][y+i].ship==true)
                    return false;
        }
    }
    else
    {
        if(x+lungime-1>9)
            return false;
        if(x>=1)
            {
                if(a[x-1][y].ship==true)
                    return false;
                if(y>=1)
                    if(a[x-1][y-1].ship==true)
                        return false;
                if(y<=8)
                    if(a[x-1][y+1].ship==true)
                        return false;
            }
        if(x<+lungime<=9)
            {
                if(a[x+lungime][y].ship==true)
                    return false;
                if(y>=1)
                    if(a[x+lungime][y-1].ship==true)
                        return false;
                if(y<=8)
                    if(a[x+lungime][y+1].ship==true)
                        return false;
            }
        for(int i=0;i<lungime;i++)
        {
            if(a[x+i][y].ship==true)
                return false;
            if(y>=1)
                if(a[x+i][y-1].ship==true)
                    return false;
            if(x<=8)
                if(a[x+i][y+1].ship==true)
                    return false;
        }
    }
    return true;
}
void Game::MatriceInamica()
{

    srand(SDL_GetTicks());
    int r=rand()%109;
    for(int i=0;i<10;i++)
        {
            this->PlaceShip(this->a,this->nav[r].linie[i],this->nav[r].coloana[i],t->ships_enemy[nav[r].ships[i]],this->nav[r].directie[i],416);
        }
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
bool Game::Incadrare(GameObject* obj,int l)
{
    int x,y;
    if(this->direction==1)
    {
        x=obj->getX();
        y=obj->getY()+(obj->getH()/2);
    }
    else
    {
        x=obj->getX()+(obj->getW()/2);
        y=obj->getY();
    }

    if(x>=17 && y>=215 && x<=17+37*10-1 && y<=215+37*10-1)
    {
            int xx=(y-215)/37;
            int yy=(x-17)/37;
            if(this->direction==1)
            {
                if(yy+l-1<=9)
                    {
                        if(yy>=1)
                            {
                                if(b[xx][yy-1].ship==true)
                                    return false;
                                if(xx>=1)
                                    if(b[xx-1][yy-1].ship==true)
                                        return false;
                                if(xx<=8)
                                    if(b[xx+1][yy-1].ship==true)
                                        return false;
                            }
                        if(yy+l<=9)
                            {
                                if(b[xx][yy+l].ship==true)
                                    return false;
                                if(xx>=1)
                                    if(b[xx-1][yy+l].ship==true)
                                        return false;
                                if(xx<=8)
                                    if(b[xx+1][yy+l].ship==true)
                                        return false;

                            }
                        for(int i=0;i<l;i++)
                            {
                                if(this->b[xx][yy+i].ship==true)
                                    return false;
                                if(xx>=1)
                                    if(this->b[xx-1][yy+i].ship==true)
                                        return false;
                                if(xx<=8)
                                    if(this->b[xx+1][yy+i].ship==true)
                                        return false;

                            }
                        this->xpozit=xx;
                        this->ypozit=yy;
                        this->lasti=l;
                        return true;
                    }
            }
            else
            {
                if(xx+l-1<=9)
                    {
                        if(xx>=1)
                            {
                                if(b[xx-1][yy].ship==true)
                                    return false;
                                if(yy>=1)
                                    if(b[xx-1][yy-1].ship==true)
                                        return false;
                                if(yy<=8)
                                    if(b[xx-1][yy+1].ship==true)
                                        return false;
                            }
                        if(xx+l<=9)
                            {
                                if(b[xx+l][yy].ship==true)
                                    return false;
                                if(yy>=1)
                                    if(b[xx+l][yy-1].ship==true)
                                        return false;
                                if(yy<=8)
                                    if(b[xx+l][yy+1].ship==true)
                                        return false;
                            }
                        for(int i=0;i<l;i++)
                            {
                                if(this->b[xx+i][yy].ship==true)
                                    return false;
                                if(yy>=1)
                                    if(this->b[xx+i][yy-1].ship==true)
                                        return false;
                                if(yy<=8)
                                    if(this->b[xx+i][yy+1].ship==true)
                                        return false;

                            }
                        this->xpozit=xx;
                        this->ypozit=yy;
                        this->lasti=l;
                        return true;
                    }
            }
    }
    return false;
}
void Game::Render()
{

    if(start)
        sm->ScreenRunning(this->a,this->b,this->t,this->getWindowX(),this->getWindowY(),this->ItemDragging,this->dragging,this->preparing,this->yourturn,this->playing);
    else
        if(this->winner)
            sm->ScreenWinner(this->t);
        else
        if(this->loser)
            sm->ScreenLoser(this->t);
        else
            sm->ScreenMain(this->t);
}
bool Game::onHover(GameObject* obj)
{
    int x,y;
        SDL_GetMouseState(&x,&y);
            if(x>=obj->getX() && y>=obj->getY() && x<=obj->getX()+obj->getW() && y<=obj->getY()+obj->getH())
                return true;
    return false;
}
void Game::Generare()
{
    int a,b;
    a=std::rand()%15;
    b=std::rand()%20;
    this->a[a][b].valoare=true;
    this->a[this->x][this->y].valoare=false;
    this->x=a;
    this->y=b;
}
void Game::ChangeObjDirection(GameObject* obj,int dir)
{
    int h,w;
    h=obj->getH();
    w=obj->getW();
    obj->indextextura[obj->placed]=dir;
    if(dir==1)
       obj->setSizeDinamic(h,w,obj->placed);
    else
        obj->setSizeDinamic(w,h,obj->placed);

}
void Game::PlaceShip(Matrice xa[10][10],int x,int y,GameObject* obj,int direction,int xdefect)
{
    obj->placed++;
    this->ChangeObjDirection(obj,direction);
    if(direction==1)
        {
            for(int i=0;i<obj->nrblockuri;i++)
            {
                xa[x][y+i].ship=true;
                xa[x][y+i].indexship=obj->nrblockuri;
                xa[x][y+i].indexplaced=obj->placed;
            }
            obj->setPositionDinamic(xdefect+37*y,215+37*x-3,obj->placed);
        }
    else
        {
            for(int i=0;i<obj->nrblockuri;i++)
            {
                xa[x+i][y].ship=true;
                xa[x+i][y].indexship=obj->nrblockuri;
                xa[x+i][y].indexplaced=obj->placed;
            }
            obj->setPositionDinamic(xdefect+37*y-3,215+37*x,obj->placed);
        }

}
void Game::changedir()
{

    int h,w;
    h=this->ItemDragging->getH();
    w=this->ItemDragging->getW();


    if(this->direction==1)
        {
            this->direction=2;
            this->ItemDragging->indextextura[0]=2;
            this->ItemDragging->setSize(w,h);
        }
    else
        {
            this->direction=1;
            this->ItemDragging->indextextura[0]=1;
            this->ItemDragging->setSize(w,h);
        }
}
void Game::eliminare(int a[100],int x,int &n)
{
    n--;
    for(int i=x;i<n;i++)
        a[i]=a[i+1];
}
void Game::Cautare_binara(int x,int a[100],int left,int right,int &n)
{
    if(left<=right)
    {
        int mid=(left+right)/2;
        if(a[mid]==x)
            this->eliminare(a,mid,n);
        else
            if(x<a[mid])
                Cautare_binara(x,a,left,mid-1,n);
            else
                Cautare_binara(x,a,mid+1,right,n);
    }
}
void Game::Curatare()
{
    this->primax=-1;
    this->primay=-1;
    this->xant=-1;
    this->yant=-1;
    this->n=100;
    for(int i=0;i<=99;i++)
        this->numere[i]=i;
    this->direction=1;
    for(int i=0;i<=9;i++)
        for(int j=0;j<=9;j++)
            {
                this->b[i][j].valoare=this->b[i][j].ship=false;
                this->a[i][j].used=this->a[i][j].ship=this->a[i][j].revealed=false;
                this->b[i][j].used=this->b[i][j].revealed=false;
                this->a[i][j].valoare=false;

                this->a[i][j].indexplaced=0;
                this->a[i][j].indexship=-1;
                this->b[i][j].indexplaced=0;
                this->b[i][j].indexship=-1;

            }
    std::stringstream smr;
    for(int i=2;i<=5;i++)
    {
        smr<<t->ships[i]->maxim;
        t->ships[i]->placed=0;
        t->ships_enemy[i]->placed=0;
        t->ChangeText(this->renderer,t->text[i],(smr.str()+"x").c_str());
        smr.str("");
        t->ships[i]->destroyed=0;
        t->ships_enemy[i]->destroyed=0;
        t->ships[i]->nrblockuri=i;
        t->ships_enemy[i]->nrblockuri=i;
        for(int j=0;j<=5;j++)
        {
            t->ships[i]->shooted[j]=0;
            t->ships_enemy[i]->shooted[j]=0;
        }
    }
    this->placed=0;
}
bool Game::Single(Matrice xa[10][10],int x,int y)
{
    for(int i=this->maxim(0,x-1);i<=this->minim(9,x+1);i++)
        for(int j=this->maxim(0,y-1);j<=this->minim(9,y+1);j++)
        {
            if((i!=x || j!=y) && (i==x || j==y))
                if(xa[i][j].used==false)
                    return true;
        }
        return false;
}
void Game::Update()
{
    if(SDL_GetTicks()-time>=fps)
    {
        this->afisare=true;
        this->time=SDL_GetTicks();
    }
    else
        this->afisare=false;

    if(this->start)
    {
        a[this->y][this->x].valoare=false;
        if(preparing)
        {
            for(int i=2;i<=5;i++)
                if(this->onClick(t->ships[i]) && t->ships[i]->movable && t->ships[i]->maxim-t->ships[i]->placed>0)
                {
                    this->dragging=true;
                    this->ItemDragging=t->ships_transparent[i];
                    this->indexdragging=i;
                    break;
                }
             for(int i=0;i<this->lasti && this->ypozit+i<10;i++)
                        this->b[this->xpozit][this->ypozit+i].valoare=false;
             for(int i=0;i<this->lasti && this->xpozit+i<10;i++)
                        this->b[this->xpozit+i][this->ypozit].valoare=false;
            if(this->dragging)
            {

                if(this->Incadrare(this->ItemDragging,this->ItemDragging->nrblockuri))
                   {
                       if(this->direction==1)
                            for(int i=0;i<this->ItemDragging->nrblockuri;i++)
                                this->b[this->xpozit][ypozit+i].valoare=true;
                       else
                            for(int i=0;i<this->ItemDragging->nrblockuri;i++)
                                this->b[this->xpozit+i][ypozit].valoare=true;

                        if(this->e.type==SDL_MOUSEBUTTONDOWN && e.button.button==SDL_BUTTON_LEFT)
                        {
                            this->ItemDragging->setPosition(0,0);
                            this->PlaceShip(this->b,this->xpozit,this->ypozit,t->ships[this->indexdragging],this->direction,24);
                            this->placed++;
                            this->dragging=false;
                            std::stringstream strm;
                            strm<<t->ships[this->indexdragging]->maxim-t->ships[this->indexdragging]->placed;
                            t->ChangeText(this->renderer,t->text[this->indexdragging],(strm.str()+"x").c_str());
                            if(this->direction==2)
                                changedir();
                        }
                   }
                if(!this->onHover(t->ships[this->indexdragging]) && this->e.type==SDL_MOUSEBUTTONDOWN  && e.button.button==SDL_BUTTON_LEFT)
                    {
                        this->dragging=false;
                        this->ItemDragging->setPosition(0,0);
                        if(this->direction==2)
                            changedir();
                    }


            }
            else
            {
                if(this->onHover(t->start_game) && this->placed==10)
                {
                    t->start_game->ishover=true;
                    t->clear_game->ishover=t->menu_game->ishover=false;
                }
                else
                if(this->onHover(t->clear_game))
                {
                    t->clear_game->ishover=true;
                    t->start->ishover=t->menu_game->ishover=false;
                }
                else
                if(this->onHover(t->menu_game))
                {
                    t->menu_game->ishover=true;
                    t->clear_game->ishover=t->start_game->ishover=false;
                }
                else
                    t->menu_game->ishover=t->clear_game->ishover=t->start_game->ishover=false;

                if(this->onClick(t->menu_game)&& prev!=SDL_MOUSEBUTTONDOWN)
                    this->start=false,this->Curatare();
                else
                if(onClick(t->clear_game) && prev!=SDL_MOUSEBUTTONDOWN)
                    this->Curatare();
                else
                if(onClick(t->start_game) && prev!=SDL_MOUSEBUTTONDOWN && this->placed==10)
                {
                    //this->Curatare();
                    this->preparing=false;
                    this->playing=true;
                    this->yourturn=true;
                    t->init_playing(this->renderer);
                    this->MatriceInamica();

                }

            }
            if(this->dragging && this->e.type==SDL_MOUSEBUTTONDOWN && this->e.button.button==SDL_BUTTON_RIGHT && prev!=SDL_MOUSEBUTTONDOWN)
                    this->changedir();
        }
        else
        if(playing)
        {
            if(yourturn)
            {
                int x1,y1;
                SDL_GetMouseState(&x1,&y1);
                if(x1>=416 && y1>=215 && x1<=416+37*10-1 && y1<=215+10*37-1)
                {

                    int x=x1-416;
                    int y=y1-215;
                    if(x%37<30 && y%37<30)
                    {
                        if(a[y/37][x/37].used==false)
                            a[y/37][x/37].valoare=true;
                        if(this->e.type==SDL_MOUSEBUTTONDOWN && this->prev != SDL_MOUSEBUTTONDOWN)
                            if(a[y/37][x/37].used==false)
                                {
                                    this->shot(this->a,y/37,x/37,0);
                                    if(this->a[y/37][x/37].ship==false)
                                        {
                                            yourturn=false;
                                            t->turn->texture=t->enemyturn;
                                            this->mytime=SDL_GetTicks();
                                        }

                                }

                            this->x=x/37;
                            this->y=y/37;
                    }

                }
            }
            if(yourturn==false)
                {
                    int xz,yz;
                    int srand(SDL_GetTicks());
                    if(SDL_GetTicks()-this->mytime>1000)
                        {
                            if(this->primax==-1)
                            {

                                int xzz=rand()%(this->n);
                                yz=this->numere[xzz]%10;
                                xz=this->numere[xzz]/10;
                                if(Single(this->b,xz,yz))
                                {
                                    this->Cautare_binara(this->numere[xzz],this->numere,0,this->n-1,this->n);
                                    this->shot(this->b,xz,yz,1);
                                    if(this->b[xz][yz].ship==true)
                                        {
                                            this->xant=xz;
                                            this->yant=yz;
                                            this->primax=xz;
                                            this->primay=yz;
                                            this->mytime=SDL_GetTicks();
                                        }
                                    else
                                    {
                                    this->yourturn=true;
                                    t->turn->texture=t->yourturn;
                                    }
                                }
                                else
                                    this->Cautare_binara(this->numere[xzz],this->numere,0,this->n-1,this->n);
                            }
                            else
                            {
                                xz=this->xant;
                                yz=this->yant;
                                algoritm(this->b,xz,yz);
                                if((xz!=this->xant || yz!=this->yant) && this->b[xz][yz].used==false)
                                        {
                                            this->shot(this->b,xz,yz,1);

                                            this->Cautare_binara(xz*10+yz,this->numere,0,this->n-1,this->n);

                                            this->mytime=SDL_GetTicks();
                                            if(this->b[xz][yz].ship==false)
                                                yourturn=true,t->turn->texture=t->enemyturn;
                                            else
                                                this->xant=xz,this->yant=yz;
                                        }
                                else
                                {
                                   if(t->ships[this->b[this->xant][this->yant].indexship]->shooted[this->b[this->xant][this->yant].indexplaced]==t->ships[this->b[this->xant][this->yant].indexship]->nrblockuri)
                                        {
                                            this->primax=-1;
                                            this->primay=-1;
                                            this->xant=-1;
                                            this->yant=-1;
                                        }
                                    else
                                        this->xant=this->primax,this->yant=this->primay;
                                }

                            }

                        }
                }
            if(this->onHover(t->menu_game))
                t->menu_game->ishover=true;
            else
                t->menu_game->ishover=false;
            if(this->onClick(t->menu_game)&& prev!=SDL_MOUSEBUTTONDOWN && prev!=SDL_MOUSEBUTTONDOWN)
                this->start=false,t->init_preparing(this->renderer),this->Curatare();

        }
    }
    else
    if(winner)
    {
        if(onHover(t->menu_game))
            t->menu_game->ishover=true,t->play_again->ishover=false;
        else
        if(onHover(t->play_again))
            t->play_again->ishover=true,t->menu_game->ishover=false;
        else
        t->play_again->ishover=t->menu_game->ishover=false;

        if(onClick(t->menu_game) && this->prev!=SDL_MOUSEBUTTONDOWN)
        {
            this->start=false,t->init_preparing(this->renderer),this->Curatare();
            this->winner=false;
        }
        if(onClick(t->play_again) && this->prev!=SDL_MOUSEBUTTONDOWN)
        {
            this->winner=false;
            this->start=true;
            t->init_preparing(this->renderer);
            this->Curatare();
            this->preparing=true;
        }
    }
    else
    if(loser)
    {
        if(onHover(t->menu_game))
            t->menu_game->ishover=true,t->play_again->ishover=false;
        else
        if(onHover(t->play_again))
            t->play_again->ishover=true,t->menu_game->ishover=false;
        else
        t->play_again->ishover=t->menu_game->ishover=false;

        if(onClick(t->menu_game) && this->prev!=SDL_MOUSEBUTTONDOWN)
        {
            this->start=false,t->init_preparing(this->renderer),this->Curatare();
            this->loser=false;
        }
        if(onClick(t->play_again) && this->prev!=SDL_MOUSEBUTTONDOWN)
        {
            this->loser=false;
            this->start=true;
            t->init_preparing(this->renderer);
            this->Curatare();
            this->preparing=true;
        }
    }
    else
    {
        if(this->onHover(t->start))
            t->start->ishover=true;
        else
        if(this->onHover(t->options))
            t->options->ishover=true;
        else
        if(this->onHover(t->exit))
            t->exit->ishover=true;
        else
            t->start->ishover=t->options->ishover=t->exit->ishover=false;
        if(prev!=SDL_MOUSEBUTTONDOWN && this->onClick(t->start))
            {
                this->start=true;
                this->preparing=true;
                t->init_preparing(this->renderer);
            }
        if(prev!=SDL_MOUSEBUTTONDOWN && this->onClick(t->exit))
            this->running=false;
    }
    this->prev=this->e.type;
    if(this->distruseEnemy==10)
    {
        this->distruseEnemy=0;
        this->distrusePlayer=0;
        this->start=false;
        t->init_winner();
        this->winner=true;
    }
    else
    if(this->distrusePlayer==10)
    {
        this->distruseEnemy=0;
        this->distrusePlayer=0;
        this->start=false;
        t->init_loser();
        this->loser=true;
    }
}
void Game::Umplere(Matrice xa[10][10],int x,int y,int xant,int yant)
{

            for(int i=maxim(x-1,0);i<=minim(x+1,9);i++)
                for(int j=maxim(y-1,0);j<=minim(y+1,9);j++)
                    {
                        if((i!=x || j!=y) && (i!=xant || j!=yant))
                        {
                            if(xa[i][j].ship==true)
                                Umplere(xa,i,j,x,y);
                            else
                                {
                                    xa[i][j].used=true;
                                    if(xa==this->b)
                                        this->Cautare_binara(i*10+j,this->numere,0,this->n-1,this->n);
                                }

                        }
                    }

}
void Game::shot(Matrice a[10][10],int x,int y,int atacator)
{
    if(a[x][y].ship==true)
            {
                a[x][y].revealed=true;
                if(atacator==0)
                    t->ships_enemy[a[x][y].indexship]->shooted[a[x][y].indexplaced]++;
                if(atacator==1)
                    t->ships[a[x][y].indexship]->shooted[a[x][y].indexplaced]++;

                if( atacator==0)
                    {
                        if(t->ships_enemy[a[x][y].indexship]->shooted[a[x][y].indexplaced] == t->ships_enemy[a[x][y].indexship]->nrblockuri)
                        {
                            t->ships_enemy[a[x][y].indexship]->show[a[x][y].indexplaced]=true;
                            t->ships_enemy[a[x][y].indexship]->destroyed++;
                            std::stringstream smm;
                            smm<< t->ships_enemy[a[x][y].indexship]->maxim-t->ships_enemy[a[x][y].indexship]->destroyed;
                            t->ChangeText(this->renderer,t->text[a[x][y].indexship],(smm.str()+"x").c_str());
                            smm.str("");
                            this->distruseEnemy++;
                            this->Umplere(a,x,y,-1,-1);

                        }
                    }
                if(atacator==1)
                    {
                        if(t->ships[a[x][y].indexship]->shooted[a[x][y].indexplaced] == t->ships[a[x][y].indexship]->nrblockuri)
                            {

                                t->ships[a[x][y].indexship]->destroyed++;
                                this->distrusePlayer++;
                                this->Umplere(a,x,y,-1,-1);
                            }
                    }
            }
    a[x][y].used=true;
}

int Game::getWindowX()
{
    int x,y;
    SDL_GetWindowSize(this->window,&x,&y);
    return x;
}
int Game::maxim(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
int Game::minim(int a,int b)
{
    if(a<b)
        return a;
    return b;
}
void Game::algoritm(Matrice xa[10][10],int &x,int &y)
{
    int pvx=x;
    int pvy=y;
    bool verifica=false;
    for(int i=this->maxim(pvx-1,0);i<=this->minim(pvx+1,9);i++)
                for(int j=this->maxim(pvy-1,0);j<=this->minim(pvy+1,9);j++)
                    if((pvx==i || pvy==j) && (i!=pvx || j!=pvy))
                    {
                        if(xa[i][j].used==true && xa[i][j].ship==true)
                            {
                                verifica=true;
                                if(x>0 && x<9)
                                    x=pvx+(pvx-i);
                                if(y>0 && y<9)
                                    y=pvy+(pvy-j);
                            }

                    }
    if(verifica==false)
    {
        for(int i=this->maxim(pvx-1,0);i<=this->minim(pvx+1,9);i++)
                for(int j=this->maxim(pvy-1,0);j<=this->minim(pvy+1,9);j++)
                     if((pvx==i || pvy==j) && (i!=pvx || j!=pvy))
                        {
                            if(xa[i][j].used==false)
                                x=i,y=j;
                        }

    }

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
