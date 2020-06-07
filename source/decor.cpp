#include "decor.h"

Decor::Decor(sf::RenderWindow& fenetre):m_fenetre(0),m_joueur(0),m_menu(0),m_info(0),m_son(0)
{
    m_fenetre=&fenetre;

    m_joueur=new Joueur(*m_fenetre);
    m_menu=new Menu(*m_fenetre);
    m_info=new Info(*m_fenetre);
    m_son=new Son();



    m_tFondG.loadFromFile("donnees/cadreG.png");
    m_sFondG.setTexture(m_tFondG);
}


Joueur& Decor::getJoueur()
{
    return *m_joueur;
}

Menu& Decor::getMenu()
{
    return *m_menu;
}

Info& Decor::getInfo()
{
    return *m_info;
}

Son& Decor::getSon()
{
    return *m_son;
}

void Decor::afficheFondEc()
{
    m_fenetre->draw(m_sFondG);
}

Decor::~Decor()
{
    delete m_joueur;
    delete m_menu;
    delete m_info;
    delete m_son;
}

