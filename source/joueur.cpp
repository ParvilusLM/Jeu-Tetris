#include "joueur.h"

Joueur::Joueur(sf::RenderWindow& fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;

    m_dirG=false;
    m_dirD=false;
    m_dirB=true;

    m_tBlocs.loadFromFile("donnees/blocs.png");
    m_tGrille.loadFromFile("donnees/grille.png");

    m_sGrille.setTexture(m_tGrille);

    initFileSuiv();
    ajouteTetromino();

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
        nouv_tetromino.forme.v_blocs.at(0).setPosition(35.f*20.f+10.f,18.f*20.f+10.f);
        nouv_tetromino.forme.v_blocs.at(1).setPosition(35.f*20.f+30,18.f*20.f+10.f);
        nouv_tetromino.forme.v_blocs.at(2).setPosition(35.f*20.f+50,18.f*20.f+10.f);
        nouv_tetromino.forme.v_blocs.at(3).setPosition(35.f*20.f+50,18.f*20.f+20+10.f);
    }

    //tetromino T
    if(formeTetro==FORME_T)
    {
        nouv_tetromino.forme.v_blocs.at(0).setPosition(35.f*20.f+10.f,18.f*20.f+10.f);
        nouv_tetromino.forme.v_blocs.at(1).setPosition(35.f*20.f+30,18.f*20.f+10.f);
        nouv_tetromino.forme.v_blocs.at(2).setPosition(35.f*20.f+50,18.f*20.f+10.f);
        nouv_tetromino.forme.v_blocs.at(3).setPosition(35.f*20.f+30,18.f*20.f+20+10.f);
    }

    //tetromino L
    if(formeTetro==FORME_L)
    {
        nouv_tetromino.forme.v_blocs.at(0).setPosition(35.f*20.f+10.f,18.f*20.f+10.f);
        nouv_tetromino.forme.v_blocs.at(1).setPosition(35.f*20.f+30,18.f*20.f+10.f);
        nouv_tetromino.forme.v_blocs.at(2).setPosition(35.f*20.f+50,18.f*20.f+10.f);
        nouv_tetromino.forme.v_blocs.at(3).setPosition(35.f*20.f+10,18.f*20.f+20+10.f);
    }

    //tetromino S
    if(formeTetro==FORME_S)
    {
        nouv_tetromino.forme.v_blocs.at(0).setPosition(35.f*20.f+30,18.f*20.f+10.f);
        nouv_tetromino.forme.v_blocs.at(1).setPosition(35.f*20.f+50,18.f*20.f+10.f);
        nouv_tetromino.forme.v_blocs.at(2).setPosition(35.f*20.f+10,18.f*20.f+20+10.f);
        nouv_tetromino.forme.v_blocs.at(3).setPosition(35.f*20.f+30,18.f*20.f+20+10.f);
    }

    //tetromino I
    if(formeTetro==FORME_I)
    {
        nouv_tetromino.forme.v_blocs.at(0).setPosition(35.f*20.f+10.f,18.f*20.f+10.f);
        nouv_tetromino.forme.v_blocs.at(1).setPosition(35.f*20.f+30,18.f*20.f+10.f);
        nouv_tetromino.forme.v_blocs.at(2).setPosition(35.f*20.f+50,18.f*20.f+10.f);
        nouv_tetromino.forme.v_blocs.at(3).setPosition(35.f*20.f+70,18.f*20.f+10.f);
    }

    //tetromino Z
    if(formeTetro==FORME_Z)
    {
        nouv_tetromino.forme.v_blocs.at(0).setPosition(35.f*20.f+10.f,18.f*20.f+10.f);
        nouv_tetromino.forme.v_blocs.at(1).setPosition(35.f*20.f+30,18.f*20.f+10.f);
        nouv_tetromino.forme.v_blocs.at(2).setPosition(35.f*20.f+30,18.f*20.f+20+10.f);
        nouv_tetromino.forme.v_blocs.at(3).setPosition(35.f*20.f+50,18.f*20.f+20+10.f);
    }

    //tetromino O
    if(formeTetro==FORME_O)
    {
        nouv_tetromino.forme.v_blocs.at(0).setPosition(35.f*20.f+10.f,18.f*20.f+10.f);
        nouv_tetromino.forme.v_blocs.at(1).setPosition(35.f*20.f+30.f,18.f*20.f+10.f);
        nouv_tetromino.forme.v_blocs.at(2).setPosition(35.f*20.f+10.f,18.f*20.f+20+10.f);
        nouv_tetromino.forme.v_blocs.at(3).setPosition(35.f*20.f+30.f,18.f*20.f+20+10.f);
    }


    return nouv_tetromino;

}


void Joueur::initFileSuiv()
{
    m_vecFileSuiv.insert(m_vecFileSuiv.end(),nouvelTetromino());
    m_vecFileSuiv.insert(m_vecFileSuiv.end(),nouvelTetromino());
    m_vecFileSuiv.insert(m_vecFileSuiv.end(),nouvelTetromino());

    //mettre les tetrominos a la bonne place
    int compt=0;
    while(compt<m_vecFileSuiv.size())
    {
        int compt2=0;
        while(compt2<m_vecFileSuiv.at(compt).forme.v_blocs.size())
        {
            if(compt<2)
            {
                if(compt==0)
                {
                    m_vecFileSuiv.at(compt).forme.v_blocs.at(compt2).move(0.f,-8*20.f);
                }
                else
                {
                    m_vecFileSuiv.at(compt).forme.v_blocs.at(compt2).move(0.f,-4*20.f);
                }

            }

            compt2++;
        }

        compt++;
    }
}

void Joueur::ajouteTetromino()
{
    m_vecTetrominos.insert(m_vecTetrominos.end(),m_vecFileSuiv.at(0));

    //mettre le tetromimo a la bonne place
    int dernier_el=m_vecTetrominos.size()-1;
    int compt=0;
    while(compt<m_vecTetrominos.at(dernier_el).forme.v_blocs.size())
    {
        m_vecTetrominos.at(dernier_el).forme.v_blocs.at(compt).move(-15.f*20.f,-4.f*20.f);
        compt++;
    }

    //replacer les tetrominos dans la file suiv

    int comptt=0;
    while(comptt<4)
    {
        m_vecFileSuiv.at(1).forme.v_blocs.at(comptt).move(0,-4.f*20.f);
        m_vecFileSuiv.at(2).forme.v_blocs.at(comptt).move(0,-4.f*20.f);

        comptt++;
    }


    m_vecFileSuiv.erase(m_vecFileSuiv.begin());

    m_vecFileSuiv.insert(m_vecFileSuiv.end(),nouvelTetromino());

}

void Joueur::ajouteTetroFileSuiv()
{
    m_vecFileSuiv.insert(m_vecFileSuiv.end(),nouvelTetromino());
}

void Joueur::ajouteTetroFileDeGarde()
{

}


int Joueur::choixTetromino()
{
    int forme_al;
    forme_al=rand()%7;
    return forme_al;
}

void Joueur::mouvementTetromino()
{
    int dern_el=m_vecTetrominos.size()-1;

    bool collisionG=collisionsGlobales();

    bool collisionF=false;
    bool collisionT=false;

    if(collisionG)
    {
        collisionF=collisionsFond();
        collisionT=collisionsTetrominos();
    }

    if(m_dirG && !collisionG)
    {
        bougerTetromino(mouv_g);
    }
    else if(m_dirD && !collisionG)
    {
        bougerTetromino(mouv_d);
    }
    else if(m_dirB && !collisionG)
    {
        bougerTetromino(mouv_b);
    }
    else
    {
        if(m_dirB && collisionF)
        {
            ajouteTetromino();
        }
        else if(m_dirB && collisionT)
        {
            ajouteTetromino();
        }
        else
        {

        }
    }
}

void Joueur::mouvementTetrominos()
{

}

void Joueur::bougerTetromino(int dir)
{
    int dern_el=m_vecTetrominos.size()-1;

    if(dir==mouv_g)
    {
        int compt=0;
        while(compt < m_vecTetrominos.at(dern_el).forme.v_blocs.size())
        {
            m_vecTetrominos.at(dern_el).forme.v_blocs.at(compt).move(-20.f,0);
            compt++;
        }
    }
    else if(dir==mouv_d)
    {
        int compt=0;
        while(compt < m_vecTetrominos.at(dern_el).forme.v_blocs.size())
        {
            m_vecTetrominos.at(dern_el).forme.v_blocs.at(compt).move(20.f,0);
            compt++;
        }
    }
    else
    {
        int compt=0;
        while(compt < m_vecTetrominos.at(dern_el).forme.v_blocs.size())
        {
            m_vecTetrominos.at(dern_el).forme.v_blocs.at(compt).move(0,20.f);
            compt++;
        }
    }
}

void Joueur::rotationTetromino()
{

}

bool Joueur::collisionsGlobales()
{
    bool collision=false;

    if(collisionsFond() || collisionsBords() || collisionsTetrominos())
    {
        collision=true;
    }

    return collision;
}

bool Joueur::collisionsFond()
{
    bool collision=false;

    int dern_el=m_vecTetrominos.size()-1;

    int compt=0;
    while(compt<m_vecTetrominos.at(dern_el).forme.v_blocs.size())
    {
        if(m_vecTetrominos.at(dern_el).forme.v_blocs.at(compt).getPosition().y+20.f > 560.f)
        {
            collision=true;
        }
        compt++;
    }

    return collision;

}

bool Joueur::collisionsBords()
{
    bool collision=false;

    return collision;
}

bool Joueur::collisionsTetrominos()
{
    bool collision=false;

    std::vector<sf::Vector2f> ensemblePosFictif;

    if(m_dirG)
    {
        int dern_el=m_vecTetrominos.size()-1;

        int compt=0;
        while(compt<m_vecTetrominos.at(dern_el).forme.v_blocs.size())
        {
            sf::Vector2f posF;
            posF.x=m_vecTetrominos.at(dern_el).forme.v_blocs.at(compt).getPosition().x-20.f;
            posF.y=m_vecTetrominos.at(dern_el).forme.v_blocs.at(compt).getPosition().y;

            ensemblePosFictif.insert(ensemblePosFictif.end(),posF);
            compt++;
        }
    }
    else if(m_dirD)
    {
        int dern_el=m_vecTetrominos.size()-1;

        int compt=0;
        while(compt<m_vecTetrominos.at(dern_el).forme.v_blocs.size())
        {
            sf::Vector2f posF;
            posF.x=m_vecTetrominos.at(dern_el).forme.v_blocs.at(compt).getPosition().x+20.f;
            posF.y=m_vecTetrominos.at(dern_el).forme.v_blocs.at(compt).getPosition().y;

            ensemblePosFictif.insert(ensemblePosFictif.end(),posF);
            compt++;
        }
    }
    else
    {
        int dern_el=m_vecTetrominos.size()-1;

        int compt=0;
        while(compt<m_vecTetrominos.at(dern_el).forme.v_blocs.size())
        {
            sf::Vector2f posF;
            posF.x=m_vecTetrominos.at(dern_el).forme.v_blocs.at(compt).getPosition().x;
            posF.y=m_vecTetrominos.at(dern_el).forme.v_blocs.at(compt).getPosition().y+20.f;

            ensemblePosFictif.insert(ensemblePosFictif.end(),posF);
            compt++;
        }
    }

    int compt=0;
    while(compt<ensemblePosFictif.size())
    {
        int compt2=0;
        while(compt2<m_vecTetrominos.size()-1)
        {
            int compt3=0;
            while(compt3<m_vecTetrominos.at(compt2).forme.v_blocs.size())
            {
                if(m_vecTetrominos.at(compt2).forme.v_blocs.at(compt3).getPosition()==ensemblePosFictif.at(compt))
                {
                    collision=true;
                }
                compt3++;
            }

            compt2++;

        }

        compt++;
    }



    return collision;
}

bool Joueur::rangeePleine()
{
    int rangee=1;
    while(rangee<21)
    {

        rangee++;
    }
}

void Joueur::effacementRangee()
{

}

void Joueur::afficheG()
{
    //on affiche la grille
    m_fenetre->draw(m_sGrille);

    //on affiche la file suivante
    int compt=0;
    while(compt<m_vecFileSuiv.size())
    {
        int compt2=0;
        while(compt2<m_vecFileSuiv.at(compt).forme.v_blocs.size())
        {
            m_fenetre->draw(m_vecFileSuiv.at(compt).forme.v_blocs.at(compt2));

            compt2++;
        }

        compt++;
    }

    //on affiche m_vecTetrominos
    int compt2=0;
    while(compt2<m_vecTetrominos.size())
    {
        int compt3=0;
        while(compt3<m_vecTetrominos.at(compt2).forme.v_blocs.size())
        {
            m_fenetre->draw(m_vecTetrominos.at(compt2).forme.v_blocs.at(compt3));

            compt3++;
        }

        compt2++;
    }


    //on affiche file de garde
    int compt3=0;
    while(compt3<m_vecFileDeGarde.size())
    {
        int compt4=0;
        while(compt4<m_vecFileDeGarde.at(compt3).forme.v_blocs.size())
        {
            m_fenetre->draw(m_vecFileDeGarde.at(compt3).forme.v_blocs.at(compt4));

            compt4++;
        }

        compt3++;
    }



}

Joueur::~Joueur()
{

}
