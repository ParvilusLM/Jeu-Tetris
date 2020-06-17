#include <iostream>
#include<SFML/Graphics.hpp>

#include "controleur.h"

using namespace sf;

bool jeuEnCours=false;
bool jeuPause=false;
bool jeuFinPartie=false;
int sourisX=0,sourisY=0;


int main()
{
    srand(time(0));


    RenderWindow fenetre(VideoMode(900,700),"Tetris");

    Controleur controleurJ(fenetre);

    while(fenetre.isOpen())
    {
        Event evenement;
        while(fenetre.pollEvent(evenement))
        {
            if(evenement.type==Event::Closed)
            {
                fenetre.close();
            }

            if(evenement.type==Event::MouseMoved)
            {
                sourisX=evenement.mouseMove.x;
                sourisY=evenement.mouseMove.y;
                if(!jeuEnCours)
                {
                    controleurJ.gestionDplSouris();
                }
            }

            if(evenement.type==Event::MouseButtonPressed && !jeuEnCours)
            {
                  Mouse::Button button = evenement.mouseButton.button;
                  if (button == Mouse::Left) // Bouton gauche
                  {
                      controleurJ.gestionSelecSouris();

                      if(jeuEnCours)
                      {

                      }
                  }
            }

        }

        if(jeuEnCours)
        {

            controleurJ.gestMajDonnees();
        }
        else
        {

        }

        fenetre.clear(Color(82,82,82));

        controleurJ.afficheFondEc();

        if(jeuEnCours)
        {
            controleurJ.afficheJeu();
        }
        else
        {
            controleurJ.afficheMenu();
        }

        fenetre.display();
    }

    return 0;
}
