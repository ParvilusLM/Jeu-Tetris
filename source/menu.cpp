#include "menu.h"

Menu::Menu(sf::RenderWindow &fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;

    m_tMenuP.loadFromFile("donnees/menuP.png");
    m_tMenuI.loadFromFile("donnees/instruct.png");
    m_tMenuI1.loadFromFile("donnees/instruct1.png");
    m_tMenuI2.loadFromFile("donnees/instruct2.png");
    m_tMenuI3.loadFromFile("donnees/instruct3.png");
    m_tMenuPause.loadFromFile("donnees/pause.png");
    m_tMenuFinP.loadFromFile("donnees/gameOver.png");

    //definitions boiteEBoutons
    boiteEBJ.width=8.f*20.f;
    boiteEBJ.height=2.f*20.f;
    boiteEBJ.left=18.f*20.f;
    boiteEBJ.top=14.5f*20.f;

    boiteEBI.width=2.f*20.f;
    boiteEBI.height=1.6f*20.f;
    boiteEBI.left=18.f*20.f;
    boiteEBI.top=26.2f*20.f;

    boiteEBQ.width=2.f*20.f;
    boiteEBQ.height=1.6f*20.f;
    boiteEBQ.left=24.f*20.f;
    boiteEBQ.top=26.2f*20.f;

    boiteEBPr.width=2.2f*20.f;
    boiteEBPr.height=2.2f*20.f;
    boiteEBPr.left=15.9f*20.f;
    boiteEBPr.top=28.9f*20.f;

    boiteEBSuiv.width=2.2f*20.f;
    boiteEBSuiv.height=2.2f*20.f;
    boiteEBSuiv.left=26.9f*20.f;
    boiteEBSuiv.top=28.9f*20.f;

    boiteEBOk.width=4.2f*20.f;
    boiteEBOk.height=2.2f*20.f;
    boiteEBOk.left=20.4f*20.f;
    boiteEBOk.top=28.9f*20.f;

    boiteEBPR.width=6.f*20.f;
    boiteEBPR.height=2.f*20.f;
    boiteEBPR.left=19.f*20.f;
    boiteEBPR.top=15.f*20.f;

    boiteEBPI.width=6.f*20.f;
    boiteEBPI.height=2.f*20.f;
    boiteEBPI.left=19.f*20.f;
    boiteEBPI.top=18.f*20.f;

    boiteEBPQ.width=6.f*20.f;
    boiteEBPQ.height=2.f*20.f;
    boiteEBPQ.left=19.f*20.f;
    boiteEBPQ.top=21.f*20.f;

    boiteEBFQ.width=2.5f*20.f;
    boiteEBFQ.height=2.1f*20.f;
    boiteEBFQ.left=16.f*20.f;
    boiteEBFQ.top=23.9f*20.f;

    boiteEBFR.width=2.5f*20.f;
    boiteEBFR.height=2.1f*20.f;
    boiteEBFR.left=25.5f*20.f;
    boiteEBFR.top=23.9f*20.f;

    m_typeMenu=MenuPrincipal;
    initMenuP();
    initMenuI();
    initMenuI1();
    initMenuI2();
    initMenuI3();
    initMenuP();
    initMenuPause();
    initMenuFinPart();

}

void Menu::initMenuP()
{
    m_sMenuP.setTexture(m_tMenuP);


}

void Menu::initMenuI()
{
    m_sMenuI.setTexture(m_tMenuI);
}

void Menu::initMenuI1()
{
    m_sMenuI1.setTexture(m_tMenuI1);
}

void Menu::initMenuI2()
{
    m_sMenuI2.setTexture(m_tMenuI2);
}

void Menu::initMenuI3()
{
    m_sMenuI3.setTexture(m_tMenuI3);
}

void Menu::initMenuPause()
{
    m_sMenuPause.setTexture(m_tMenuPause);
}

void Menu::initMenuFinPart()
{
    m_sMenuFinP.setTexture(m_tMenuFinP);
}

void Menu::setTypeMenu(int menuActuel)
{
    if(menuActuel==MenuPrincipal)
    {
        m_typeMenu=MenuPrincipal;
    }
    else if(menuActuel==MenuInstructions1)
    {
        m_typeMenu=MenuInstructions1;
    }
    else if(menuActuel==MenuInstructions2)
    {
        m_typeMenu=MenuInstructions2;
    }
    else if(menuActuel==MenuInstructions3)
    {
        m_typeMenu=MenuInstructions3;
    }
    else if(menuActuel==MenuPause)
    {
        m_typeMenu=MenuPause;
    }
    else if(menuActuel==MenuFinPartie)
    {
        m_typeMenu=MenuFinPartie;
    }
    else
    {

    }
}

void Menu::afficheMenuP()
{
    m_fenetre->draw(m_sMenuP);
}

void Menu::afficheMenuI()
{
    m_fenetre->draw(m_sMenuI);
}

void Menu::afficheMenuI1()
{
    m_fenetre->draw(m_sMenuI1);
}

void Menu::afficheMenuI2()
{
    m_fenetre->draw(m_sMenuI2);
}

void Menu::afficheMenuI3()
{
    m_fenetre->draw(m_sMenuI3);
}

void Menu::afficheMenuPause()
{
    m_fenetre->draw(m_sMenuPause);
}

void Menu::afficheMenuFinPart()
{
    m_fenetre->draw(m_sMenuFinP);
}

void Menu::afficheMenu()
{
    if(m_typeMenu==MenuPrincipal)
    {
        afficheMenuP();
    }
    else if(m_typeMenu==MenuInstructions1)
    {
        afficheMenuI();
        afficheMenuI1();
    }
    else if(m_typeMenu==MenuInstructions2)
    {
        afficheMenuI();
        afficheMenuI2();
    }
    else if(m_typeMenu==MenuInstructions3)
    {
        afficheMenuI();
        afficheMenuI3();
    }
    else if(m_typeMenu==MenuPause)
    {
        afficheMenuPause();
    }
    else if(m_typeMenu==MenuFinPartie)
    {
        afficheMenuFinPart();
    }
    else
    {

    }

}

void Menu::retourMenuP()
{
    m_typeMenu=MenuPrincipal;
    m_elementActif=AUCUN_EL_ACT;
}

void Menu::elementActif()
{

    if(m_typeMenu==MenuPrincipal)
    {
        if(collisionTS(boiteEBJ))
        {
            m_elementActif=JOUER_ACTIF;
        }
        else if(collisionTS(boiteEBI))
        {
            m_elementActif=INSTRUCTIONS_ACTIF;
        }
        else if(collisionTS(boiteEBQ))
        {
            m_elementActif=QUITTER_ACTIF;
        }
        else
        {
            m_elementActif=AUCUN_EL_ACT;
        }

    }
    else if(m_typeMenu==MenuInstructions1)
    {
        if(collisionTS(boiteEBOk))
        {
            m_elementActif=OK_ACTIF;
        }
        else if(collisionTS(boiteEBSuiv))
        {
            m_elementActif=SUIVANT_ACTIF;
        }
        else
        {
            m_elementActif=AUCUN_EL_ACT;
        }
    }
    else if(m_typeMenu==MenuInstructions2)
    {
        if(collisionTS(boiteEBOk))
        {
            m_elementActif=OK_ACTIF;
        }
        else if(collisionTS(boiteEBSuiv))
        {
            m_elementActif=SUIVANT_ACTIF;
        }
        else if(collisionTS(boiteEBPr))
        {
            m_elementActif=PRECEDENT_ACTIF;
        }
        else
        {
            m_elementActif=AUCUN_EL_ACT;
        }

    }
    else if(m_typeMenu==MenuInstructions3)
    {
        if(collisionTS(boiteEBOk))
        {
            m_elementActif=OK_ACTIF;
        }
        else if(collisionTS(boiteEBPr))
        {
            m_elementActif=PRECEDENT_ACTIF;
        }
        else
        {
            m_elementActif=AUCUN_EL_ACT;
        }

    }
    else if(m_typeMenu==MenuPause)
    {
        if(collisionTS(boiteEBPR))
        {
            m_elementActif=PAUSER_ACTIF;
        }
        else if(collisionTS(boiteEBPI))
        {
            m_elementActif=PAUSEI_ACTIF;
        }
        else if(collisionTS(boiteEBPQ))
        {
            m_elementActif=PAUSEQ_ACTIF;
        }
        else
        {
            m_elementActif=AUCUN_EL_ACT;
        }

    }
    else if(m_typeMenu==MenuFinPartie)
    {
        if(collisionTS(boiteEBFQ))
        {
            m_elementActif=FINPQ_ACTIF;
        }
        else if(collisionTS(boiteEBFR))
        {
            m_elementActif=FINPR_ACTIF;
        }
        else
        {
            m_elementActif=AUCUN_EL_ACT;
        }

    }
    else
    {

    }

}

void Menu::selectionElActif()
{
    if(m_typeMenu==MenuPrincipal)
    {
        if(m_elementActif==JOUER_ACTIF)
        {
            jeuEnCours=true;
            jeuDebut=true;
        }
        else if(m_elementActif==INSTRUCTIONS_ACTIF)
        {
            m_typeMenu=MenuInstructions1;
        }
        else if(m_elementActif==QUITTER_ACTIF)
        {
            quitterJeu();
        }
        else
        {

        }

    }
    else if(m_typeMenu==MenuInstructions1)
    {
        if(m_elementActif==OK_ACTIF)
        {
            if(!jeuEnCours)
            {
                m_typeMenu=MenuPrincipal;
            }
            else
            {
                m_typeMenu=MenuPause;
            }
        }
        else if(m_elementActif==SUIVANT_ACTIF)
        {
            m_typeMenu=MenuInstructions2;
        }
        else
        {

        }
    }
    else if(m_typeMenu==MenuInstructions2)
    {
        if(m_elementActif==PRECEDENT_ACTIF)
        {
            m_typeMenu=MenuInstructions1;
        }
        else if(m_elementActif==OK_ACTIF)
        {
            if(!jeuEnCours)
            {
                m_typeMenu=MenuPrincipal;
            }
            else
            {
                m_typeMenu=MenuPause;
            }

        }
        else if(m_elementActif==SUIVANT_ACTIF)
        {
            m_typeMenu=MenuInstructions3;
        }
        else
        {

        }
    }
    else if(m_typeMenu==MenuInstructions3)
    {
        if(m_elementActif==PRECEDENT_ACTIF)
        {
            m_typeMenu=MenuInstructions2;
        }
        else if(m_elementActif==OK_ACTIF)
        {
            if(!jeuEnCours)
            {
                m_typeMenu=MenuPrincipal;
            }
            else
            {
                m_typeMenu=MenuPause;
            }
        }
        else
        {

        }
    }
    else if(m_typeMenu==MenuPause)
    {
        if(m_elementActif==PAUSER_ACTIF)
        {
            jeuPause=false;
        }
        else if(m_elementActif==PAUSEI_ACTIF)
        {
            m_typeMenu=MenuInstructions1;
        }
        else if(m_elementActif==PAUSEQ_ACTIF)
        {
            jeuPause=false;
            jeuEnCours=false;
            jeuDebut=false;
            m_typeMenu=MenuPrincipal;
        }
        else
        {

        }
    }
    else if(m_typeMenu==MenuFinPartie)
    {
        if(m_elementActif==FINPQ_ACTIF)
        {
            jeuPause=false;
            jeuEnCours=false;
            jeuDebut=false;
            jeuFinPartie=false;
            m_typeMenu=MenuPrincipal;
        }
        else if(m_elementActif==FINPR_ACTIF)
        {
            jeuPause=false;
            jeuRejouer=true;
            m_typeMenu=MenuPrincipal;
        }
        else
        {

        }
    }
    else
    {

    }

}

bool Menu::collisionTS(sf::FloatRect elem)
{
    bool collision=false;
    if((elem.left<sourisX && elem.left+elem.width>sourisX) && (elem.top<sourisY && elem.top+elem.height>sourisY))
    {
        collision=true;
    }
    return collision;
}

void Menu::quitterJeu()
{
    m_fenetre->close();
}

Menu::~Menu()
{

}
