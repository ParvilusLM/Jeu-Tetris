#include <iostream>
#include<SFML/Graphics.hpp>

#include "controleur.h"

using namespace sf;

bool jeuEnCours=false;
bool jeuPause=false;
bool jeuFinPartie=false;
int sourisX=0,sourisY=0;
bool tetroLibre=false;



int main()
{
    srand(time(0));


    RenderWindow fenetre(VideoMode(900,700),"Tetris");

    Controleur controleurJ(fenetre);

    sf::Clock horl;
    float timer=0;
    float delai=0.2f;

    while(fenetre.isOpen())
    {
        float temps = horl.getElapsedTime().asSeconds();
		horl.restart();
        timer+=temps;

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
                  }
            }


            if(evenement.type==Event::MouseButtonPressed && jeuEnCours && !jeuPause)
            {
                  Mouse::Button button = evenement.mouseButton.button;
                  if (button == Mouse::Left) // Bouton gauche
                  {

                  }
            }

            if(evenement.type==Event::MouseButtonPressed && jeuEnCours && !jeuPause)
            {
                  Mouse::Button button = evenement.mouseButton.button;
                  if (button == Mouse::Right) // Bouton droite
                  {

                  }
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)  && jeuEnCours && !jeuPause)
            {
                controleurJ.rotationTertro(ROTATION_D);
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && jeuEnCours && !jeuPause)
            {

            }


            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && jeuEnCours && !jeuPause)
            {
                if(timer>delai)
                {
                    controleurJ.mouvementTetro(mouv_g);
                    timer=0;
                }

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && jeuEnCours && !jeuPause)
            {
                if(timer>delai)
                {
                    controleurJ.mouvementTetro(mouv_d);
                    timer=0;
                }

            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && jeuEnCours && !jeuPause)
            {
                controleurJ.rotationTertro(ROTATION_G);
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::C) && jeuEnCours && !jeuPause)
            {
                controleurJ.stockerTetroActif();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)  && jeuEnCours)
            {
                controleurJ.pauseJeu();
            }



            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && jeuEnCours && !jeuPause)
            {

            }




        }

        if(jeuEnCours)
        {
            if(!jeuPause)
            {
                controleurJ.gestMajDonnees();
            }

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
