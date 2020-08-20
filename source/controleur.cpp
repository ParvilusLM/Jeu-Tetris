#include "controleur.h"

Controleur::Controleur(sf::RenderWindow &fenetre):m_fenetre(0),m_decor(0)
{
    m_fenetre= &fenetre;

    delai=0.1f;
    timer=0;

    m_decor = new Decor(*m_fenetre);
}

void Controleur::debutJeu()
{
    m_decor->getJoueur().effacementDonnees();
    m_decor->getJoueur().initJoueur();
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
    if(m_decor->getMenu().getTypeMenu()==MenuPrincipal)
    {
        afficheInfo();
    }

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
    m_decor->getInfo().afficheInfo();


    if(jeuPause)
    {
        afficheMenu();
        if(m_decor->getMenu().getTypeMenu()==MenuEnregScore)
        {
            m_decor->getInfo().afficheNomAEnreg();
        }

    }
}

void Controleur::afficheInfo()
{
    m_decor->getInfo().afficheInfo();
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

    if(jeuFinPartie)
    {
        jeuPause=true;

        if(m_decor->getInfo().surPodium())
        {
            m_decor->getMenu().setTypeMenu(MenuEnregScore);
        }
        else
        {
            m_decor->getMenu().setTypeMenu(MenuFinPartie);
        }

        jeuFinPartie=false;
    }

    if(jeuSauvegarde)
    {
        m_decor->getInfo().sauvegardeScore();
        jeuSauvegarde=false;
    }


    if(jeuRejouer)
    {
        debutJeu();
        jeuRejouer=false;
    }

    m_decor->getInfo().gestInfoPartEnCours();


}

void Controleur::mouvementTetro(int dir)
{
    m_decor->getJoueur().changerDirTetro(dir);
    m_decor->getJoueur().mouvementTetromino();

}

void Controleur::saisieL(char lettre)
{
    m_decor->getInfo().gestSaisieNom(lettre);
}

void Controleur::sauvegardeScore()
{
    m_decor->getInfo().sauvegardeScore();
    jeuSauvegarde=false;
}

void Controleur::stockerTetroActif()
{
    m_decor->getJoueur().ajouteTetroFileDeGarde();
}

void Controleur::reinitTablScore()
{
   m_decor->getInfo().gestTableauScore();
}

void Controleur::pauseJeu()
{
    if(jeuPause)
    {
        jeuPause=false;
    }
    else
    {
        jeuPause=true;
        m_decor->getMenu().setTypeMenu(MenuPause);

    }

}


Controleur::~Controleur()
{
    delete m_decor;
}
