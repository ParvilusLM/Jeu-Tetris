#include "controleur.h"

Controleur::Controleur(sf::RenderWindow &fenetre):m_fenetre(0),m_decor(0)
{
    m_fenetre= &fenetre;

    delai=0.3f;
    timer=0;

    m_decor = new Decor(*m_fenetre);
}


void Controleur::rotationTertro(int sensR)
{
    m_decor->getJoueur().rotationTetromino(sensR);
}


void Controleur::afficheFondEc()
{
    m_decor->afficheFondEc();
}


void Controleur::afficheMenu()
{
    m_decor->getMenu().afficheMenu();
}

void Controleur::gestionDplSouris()
{
    m_decor->getMenu().elementActif();
}

void Controleur::gestionSelecSouris()
{
    m_decor->getMenu().selectionElActif();
}

void Controleur::afficheJeu()
{
    m_decor->getJoueur().afficheG();
}

void Controleur::afficheInfo()
{

}

void Controleur::gestMajDonnees()
{
    float temps= horloge.getElapsedTime().asSeconds();
    horloge.restart();
    timer+=temps;

    if(timer>delai)
    {
        m_decor->getJoueur().mouvementTetromino();
        timer=0;
    }

}

void Controleur::mouvementTetro(int dir)
{
    m_decor->getJoueur().changerDirTetro(dir);
    m_decor->getJoueur().mouvementTetromino();
}

void Controleur::stockerTetroActif()
{
    m_decor->getJoueur().ajouteTetroFileDeGarde();
}

void Controleur::pauseJeu()
{
    std::cout<<"Fonction pauseJeu"<<std::endl;
    if(jeuPause)
    {
        jeuPause=false;
    }
    else
    {
        jeuPause=true;

    }

}

Controleur::~Controleur()
{
    delete m_decor;
}
