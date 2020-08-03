#include "info.h"

Info::Info(sf::RenderWindow& fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;
    m_score=0;
    m_niveau=1;
    m_nombrLignes=0;



}

void Info::initInfo()
{
    //les fonts
    m_fntChiffres.loadFromFile("donnees/keypunc.ttf");
    m_fntNoms.loadFromFile("donnees/ALGER.ttf");

    //les textes
    m_txtNiveau.setFont(m_fntChiffres);
    m_txtNiveau.setCharacterSize(30);
    m_txtNiveau.setPosition(19.2f*20.0f,17.1f*20.f);
    m_txtNiveau.setFillColor(sf::Color::Black);


    m_txtNomsJ.setFont(m_fntNoms);
    m_txtNomsJ.setCharacterSize(30);
    m_txtNomsJ.setPosition(18.3f*20.0f,21.f*20.f);
    m_txtNomsJ.setFillColor(sf::Color::Black);


    m_txtScoresJ.setFont(m_fntNoms);
    m_txtScoresJ.setCharacterSize(30);
    m_txtScoresJ.setPosition(22.f*20.0f,21.f*20.f);
    m_txtScoresJ.setFillColor(sf::Color::Black);



    m_txtInfoJeu.setFont(m_fntNoms);
    m_txtInfoJeu.setCharacterSize(30);
    m_txtInfoJeu.setPosition(3.9f*20.0f,20.7f*20.f);
    m_txtInfoJeu.setFillColor(sf::Color::Black);
}

void Info::reinitInfo()
{
    m_score=0;
    m_niveau=1;
    m_nombrLignes=0;
}

void Info::chargementDonnees()
{
    FILE * fichierNoms=NULL;

}

void Info::gestTableauScore()
{

}

void Info::gestInfoPartEnCours(int action)
{

}

void Info::gestMeilleurJ()
{

}

void Info::maj_Info()
{

}

void Info::afficheInfo()
{

}

template <class T> std::string Info::nbEnString(T nb)
{
    std::ostringstream chaineCar;
    chaineCar << nb;
    return chaineCar.str();
}

Info::~Info()
{

}
