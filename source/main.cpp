#include <iostream>
#include<SFML/Graphics.hpp>

#include "controleur.h"

using namespace sf;

bool jeuEnCours=false;
bool jeuPause=false;
bool jeuFinPartie=false;
bool jeuDebut=false;
bool jeuRejouer=false;
int sourisX=0,sourisY=0;
bool tetroLibre=false;



int main()
{
    srand(time(0));


    RenderWindow fenetre(VideoMode(900,700),"Tetris");

    Controleur controleurJ(fenetre);

    sf::Clock horl;
    float timer=0;
    float delai=0.1f;

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
                else if(jeuEnCours && jeuPause)
                {
                    controleurJ.gestionDplSouris();
                }
                else
                {

                }
            }


            switch(evenement.type)
            {
            case Event::MouseButtonPressed:
                if(jeuEnCours)
                {

                    if(jeuPause)
                    {
                        Mouse::Button button = evenement.mouseButton.button;

                        if (button == Mouse::Left) // Bouton gauche
                        {
                            controleurJ.gestionSelecSouris();
                        }

                        if (button == Mouse::Right) // Bouton droite
                        {

                        }

                    }
                    else
                    {
                        Mouse::Button button = evenement.mouseButton.button;

                        if (button == Mouse::Left) // Bouton gauche
                        {

                        }

                        if (button == Mouse::Right) // Bouton droite
                        {

                        }
                    }
                }
                else
                {
                    Mouse::Button button = evenement.mouseButton.button;
                    if (button == Mouse::Left) // Bouton gauche
                    {
                        controleurJ.gestionSelecSouris();
                        if(jeuDebut)
                        {
                            controleurJ.debutJeu();
                        }
                    }
                }
                break;

            case Event::KeyPressed:
                if(jeuEnCours)
                {

                    if(!jeuPause)
                    {
                        if(sf::Keyboard::isKeyPressed(Keyboard::Left))
                        {
                            if(timer>delai)
                            {
                                controleurJ.mouvementTetro(mouv_g);
                                timer=0;
                            }
                        }
                        else if(sf::Keyboard::isKeyPressed(Keyboard::Right))
                        {
                            if(timer>delai)
                            {
                                controleurJ.mouvementTetro(mouv_d);
                                timer=0;
                            }
                        }
                        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                        {
                            controleurJ.rotationTertro(ROTATION_D);
                        }
                        else if(sf::Keyboard::isKeyPressed(Keyboard::Down))
                        {

                        }
                        else if(sf::Keyboard::isKeyPressed(Keyboard::Z))
                        {
                            controleurJ.rotationTertro(ROTATION_G);
                        }
                        else if(sf::Keyboard::isKeyPressed(Keyboard::C))
                        {
                            controleurJ.stockerTetroActif();
                        }
                        else if(sf::Keyboard::isKeyPressed(Keyboard::Escape))
                        {
                            controleurJ.pauseJeu();
                        }
                        else if(sf::Keyboard::isKeyPressed(Keyboard::Space))
                        {

                        }
                        else
                        {

                        }

                    }
                    else
                    {
                        if(sf::Keyboard::isKeyPressed(Keyboard::Escape))
                        {
                            controleurJ.pauseJeu();
                        }
                    }
                }
                else
                {

                }
                break;

            default:;
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
