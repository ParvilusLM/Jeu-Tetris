#include "joueur.h"

Joueur::Joueur(sf::RenderWindow& fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;

    m_tBlocs.loadFromFile("donnees/blocs.png");

}

Tetromino Joueur::nouvelTetromino()
{
    int formeTetro=choixTetromino();

    Tetromino nouv_tetromino;

    sf::Sprite element_bloc;
    element_bloc.setOrigin(10.f,10.f);
    element_bloc.setTexture(m_tBlocs);

    if(formeTetro==FORME_J)
    {
        element_bloc.setTextureRect(sf::IntRect(0,0,20,20));
    }
    else if(formeTetro==FORME_T)
    {
        element_bloc.setTextureRect(sf::IntRect(20,0,20,20));
    }
    else if(formeTetro==FORME_L)
    {
        element_bloc.setTextureRect(sf::IntRect(40,0,20,20));
    }
    else if(formeTetro==FORME_S)
    {
        element_bloc.setTextureRect(sf::IntRect(60,0,20,20));
    }
    else if(formeTetro==FORME_I)
    {
        element_bloc.setTextureRect(sf::IntRect(80,0,20,20));
    }
    else if(formeTetro==FORME_Z)
    {
        element_bloc.setTextureRect(sf::IntRect(100,0,20,20));
    }
    else
    {
        element_bloc.setTextureRect(sf::IntRect(120,0,20,20));
    }


    int compt=0;
    while(compt<4)
    {
        nouv_tetromino.forme.v_blocs.insert(nouv_tetromino.forme.v_blocs.end(),element_bloc);

        compt++;
    }

    nouv_tetromino.nb_blocs=4;

    /* Arrangement des blocs du tetromino */

    //tetromino J
    if(formeTetro==FORME_J)
    {
        nouv_tetromino.forme.v_blocs.at(0).setPosition(17.f*20.f+(4.f*20.f)+10.f,8.f*8.f);
        nouv_tetromino.forme.v_blocs.at(1).setPosition(17.f*20.f+(4.f*20.f)+30,8.f*8.f);
        nouv_tetromino.forme.v_blocs.at(2).setPosition(17.f*20.f+(4.f*20.f)+50,8.f*8.f);
        nouv_tetromino.forme.v_blocs.at(3).setPosition(17.f*20.f+(4.f*20.f)+50,8.f*8.f+20);
    }

    //tetromino T
    if(formeTetro==FORME_T)
    {

    }

    //tetromino L
    if(formeTetro==FORME_L)
    {

    }

    //tetromino S
    if(formeTetro==FORME_S)
    {

    }

    //tetromino I
    if(formeTetro==FORME_I)
    {

    }

    //tetromino Z
    if(formeTetro==FORME_Z)
    {

    }

    //tetromino O
    if(formeTetro==FORME_O)
    {

    }

}

void Joueur::ajouteTetromino()
{



}

void Joueur::ajouteTetroFileSuiv()
{

}

void Joueur::ajouteTetroFileDeGarde()
{

}


int Joueur::choixTetromino()
{
    int forme_al;
    forme_al=rand()%7;
    forme_al++;
    return forme_al;
}

void Joueur::mouvementTetromino()
{

}

void Joueur::mouvementTetrominos()
{

}

void Joueur::rotationTetromino()
{

}

void Joueur::collisionsGlobales()
{

}

bool Joueur::collisionsFond()
{

}

bool Joueur::collisionsBords()
{

}

bool Joueur::collisionsTetrominos()
{

}

bool Joueur::rangeePleine()
{

}

void Joueur::effacementRangee()
{

}

void Joueur::afficheTetrominos()
{

}

Joueur::~Joueur()
{

}
