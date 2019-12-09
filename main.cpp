#include <iostream>
#include <game.h>
#include <GameObject.h>
Game* joc=new Game();

int main(int argc,char* argv[])
{
    joc->CreateGame("primul meu joc",800,600);
        {
            while(joc->isRunning())
            {
                joc->Clear();

                joc->Update();
              //  if(joc->afisare)
                   // {
                        joc->Render();
                        joc->Display();
                   // }
            }
            joc->Destroy();
        }
    return 0;
}
