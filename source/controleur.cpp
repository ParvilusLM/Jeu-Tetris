#include "controleur.h"

Controleur::Controleur(sf::RenderWindow &fenetre):m_fenetre(0),m_decor(0)
{
    m_fenetre= &fenetre;

    m_decor = new Decor(*m_fenetre);
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
    sf::Time repos=sf::seconds(0.5f);
    sleep(repos);

    m_decor->getJoueur().mouvementTetromino();
}

Controleur::~Controleur()
{
    delete m_decor;
}
