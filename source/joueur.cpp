#include "joueur.h"

Joueur::Joueur(sf::RenderWindow& fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;

    m_dirG=false;
    m_dirD=false;
    m_dirB=true;

    m_tBlocs.loadFromFile("donnees/blocs.png");
    m_tGrille.loadFromFile("donnees/grille.png");
    m_tBFant.loadFromFile("donnees/bloc_fantome.png");

    m_sGrille.setTexture(m_tGrille);

    initFileSuiv();
    ajouteTetromino();

}

Tetromino Joueur::nouvelTetromino()
{
    int formeTetro=choixTetromino();

    Tetromino nouv_tetromino;
    nouv_tetromino.formeTetromino=formeTetro;

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
    m_posInitTetro.clear();
    if(m_vecFileDeGarde.size()!=0 && tetroLibre)
    {
        m_vecTetrominos.insert(m_vecTetrominos.end(),m_vecFileDeGarde.at(0));

        //mettre le tetromimo a la bonne place
        int dernier_el=m_vecTetrominos.size()-1;
        int compt=0;
        while(compt<m_vecTetrominos.at(dernier_el).forme.v_blocs.size())
        {
            m_vecTetrominos.at(dernier_el).forme.v_blocs.at(compt).move(14.f*20.f,-4.f*20.f);
            m_posInitTetro.insert(m_posInitTetro.end(),m_vecTetrominos.at(dernier_el).forme.v_blocs.at(compt).getPosition());
            compt++;
        }

        m_vecFileDeGarde.clear();
        tetroLibre=false;
    }
    else
    {

        m_vecTetrominos.insert(m_vecTetrominos.end(),m_vecFileSuiv.at(0));

        //mettre le tetromimo a la bonne place
        int dernier_el=m_vecTetrominos.size()-1;
        int compt=0;
        while(compt<m_vecTetrominos.at(dernier_el).forme.v_blocs.size())
        {
            m_vecTetrominos.at(dernier_el).forme.v_blocs.at(compt).move(-15.f*20.f,-4.f*20.f);
            m_posInitTetro.insert(m_posInitTetro.end(),m_vecTetrominos.at(dernier_el).forme.v_blocs.at(compt).getPosition());
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

}

void Joueur::ajouteTetroFileSuiv()
{
    m_vecFileSuiv.insert(m_vecFileSuiv.end(),nouvelTetromino());
}

void Joueur::ajouteTetroFileDeGarde()
{
    if(m_vecFileDeGarde.size()==0)
    {
        //m_vecFileDeGarde.clear();
        int dern_el=m_vecTetrominos.size()-1;

        m_vecFileDeGarde.insert(m_vecFileDeGarde.end(), m_vecTetrominos.at(dern_el));

        //repositionner le tetromino
        int dernier_el=m_vecFileDeGarde.size()-1;
        int compt=0;
        while(compt<m_vecFileDeGarde.at(dernier_el).forme.v_blocs.size())
        {
            m_vecFileDeGarde.at(dernier_el).forme.v_blocs.at(compt).setPosition(m_posInitTetro.at(compt).x-14*20.f,m_posInitTetro.at(compt).y+4*20.f);
            compt++;
        }

        m_vecTetrominos.erase(m_vecTetrominos.end());
        ajouteTetromino();

    }
    else
    {
        tetroLibre=true;
    }
}


void Joueur::gestionTetroFantome()
{
    m_vecTetroFantome.clear();

    m_vecTetroFantome.insert(m_vecTetroFantome.end(), m_vecTetrominos.at(m_vecTetrominos.size()-1));

    //changer la texture des blocs
    int compt=0;
    while(compt<m_vecTetroFantome.at(0).forme.v_blocs.size())
    {
        m_vecTetroFantome.at(0).forme.v_blocs.at(compt).setTexture(m_tBFant);
        m_vecTetroFantome.at(0).forme.v_blocs.at(compt).setTextureRect(sf::IntRect(0,0,20,20));

        compt++;
    }

    //le tetro jusqu'a collision
    bool collisionF=false;
    bool collisionT=false;

    while(!collisionF && !collisionT)
    {
        if(collisionsTetrominos(TETRO_FANTOME))
        {
            collisionT=true;

        }
        else if(collisionsFond(TETRO_FANTOME))
        {
            collisionF=true;
        }
        else
        {
            int dern_el=m_vecTetroFantome.size()-1;
            int compt=0;
            while(compt < m_vecTetroFantome.at(dern_el).forme.v_blocs.size())
            {
                m_vecTetroFantome.at(dern_el).forme.v_blocs.at(compt).move(0,20.f);
                compt++;
            }
        }
    }


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
        collisionF=collisionsFond(TETRO_NORMAL);
        collisionT=collisionsTetrominos(TETRO_NORMAL);
    }

    if(m_dirG && !collisionG)
    {
        bougerTetromino(mouv_g);
    }
    else if(m_dirD && !collisionG)
    {
        bougerTetromino(mouv_d);
    }
    else if(m_dirB && !collisionF && !collisionT)
    {
        bougerTetromino(mouv_b);
    }
    else
    {
        if(m_dirB && collisionF)
        {
            if(rangeePleine())
            {
                effacementRangee();
                mouvementTetrominos();
            }

            ajouteTetromino();
        }
        else if(m_dirB && collisionT)
        {
            if(rangeePleine())
            {
                effacementRangee();
                mouvementTetrominos();
            }
            ajouteTetromino();
        }
        else
        {

        }
    }

    m_dirB=true;
    m_dirG=false;
    m_dirD=false;

    gestionTetroFantome();
}

void Joueur::mouvementTetrominos()
{
    int compt=0;
    while(compt<m_vecRangeeASupp.size())
    {
        int compt2=0;
        while(compt2<m_vecTetrominos.size())
        {
            int compt3=0;
            while(compt3<m_vecTetrominos.at(compt2).forme.v_blocs.size())
            {
                if(m_vecTetrominos.at(compt2).forme.v_blocs.at(compt3).getPosition().y<m_vecRangeeASupp.at(compt)*20.f+8*20.f+10)
                {
                    m_vecTetrominos.at(compt2).forme.v_blocs.at(compt3).move(0,20.f);
                }
                compt3++;
            }
            compt2++;
        }
        compt++;
    }
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

void Joueur::rotationTetromino(int sensR)
{
    std::vector<sf::Vector2f> m_posFictTetro;

    int dern_el=m_vecTetrominos.size()-1;

    int compt=0;
    while(compt<m_vecTetrominos.at(dern_el).forme.v_blocs.size())
    {
        m_posFictTetro.insert(m_posFictTetro.end(),m_vecTetrominos.at(dern_el).forme.v_blocs.at(compt).getPosition());
        compt++;
    }


    int formeTetro=m_vecTetrominos.at(dern_el).formeTetromino;

    //determiner le centre de rotation
    sf::Vector2f centreRot;

    if(formeTetro==FORME_J)
    {
        centreRot.x=m_posFictTetro.at(1).x;
        centreRot.y=m_posFictTetro.at(1).y;
    }
    else if(formeTetro==FORME_T)
    {
        centreRot.x=m_posFictTetro.at(1).x;
        centreRot.y=m_posFictTetro.at(1).y;
    }
    else if(formeTetro==FORME_L)
    {
        centreRot.x=m_posFictTetro.at(1).x;
        centreRot.y=m_posFictTetro.at(1).y;
    }
    else if(formeTetro==FORME_S)
    {
        centreRot.x=m_posFictTetro.at(0).x;
        centreRot.y=m_posFictTetro.at(0).y;
    }
    else if(formeTetro==FORME_I)
    {
        if(m_posFictTetro.at(1).x==m_posFictTetro.at(2).x && m_posFictTetro.at(1).y<m_posFictTetro.at(2).y)
        {
            centreRot.x=m_posFictTetro.at(1).x-10.f;
            centreRot.y=m_posFictTetro.at(1).y+10.f;
        }
        else if(m_posFictTetro.at(1).x==m_posFictTetro.at(2).x && m_posFictTetro.at(1).y>m_posFictTetro.at(2).y)
        {
            centreRot.x=m_posFictTetro.at(1).x+10.f;
            centreRot.y=m_posFictTetro.at(1).y-10.f;
        }
        else if(m_posFictTetro.at(1).x < m_posFictTetro.at(2).x && m_posFictTetro.at(1).y==m_posFictTetro.at(2).y)
        {
            centreRot.x=m_posFictTetro.at(1).x+10.f;
            centreRot.y=m_posFictTetro.at(1).y+10.f;
        }
        else if(m_posFictTetro.at(1).x > m_posFictTetro.at(2).x && m_posFictTetro.at(1).y==m_posFictTetro.at(2).y)
        {
            centreRot.x=m_posFictTetro.at(1).x-10.f;
            centreRot.y=m_posFictTetro.at(1).y-10.f;
        }
        else
        {

        }
    }
    else if(formeTetro==FORME_Z)
    {
        centreRot.x=m_posFictTetro.at(1).x;
        centreRot.y=m_posFictTetro.at(1).y;
    }
    else
    {

    }


    //effectuer la rotation de chaque bloc
    if(formeTetro!=FORME_O)
    {
        int comptt=0;
        while(comptt<4)
        {
            //std::cout<<"Centre de rotation : "<<centreRot.x<<" , "<<centreRot.y<<std::endl;

            float xd=0.f,yd=0.f;
            xd=m_posFictTetro.at(comptt).x-centreRot.x;
            yd=m_posFictTetro.at(comptt).y-centreRot.y;

            //std::cout<<"xd: "<<xd<<std::endl;
            //std::cout<<"yd: "<<yd<<std::endl;

            float xf=0.f,yf=0.f;

            if(sensR==ROTATION_G)
            {
                xf=centreRot.x+(yd*1);
                yf=centreRot.y+(-xd*1);
            }
            else
            {
                xf=centreRot.x+(-yd*1);
                yf=centreRot.y+(xd*1);
            }


            //std::cout<<"Position xf: "<<xf<<std::endl;
            //std::cout<<"Position yf: "<<yf<<std::endl;

            m_vecTetrominos.at(dern_el).forme.v_blocs.at(comptt).setPosition(xf,yf);

            comptt++;
        }
    }

}

bool Joueur::collisionsGlobales()
{
    bool collision=false;

    if(collisionsFond(TETRO_NORMAL) || collisionsBords() || collisionsTetrominos(TETRO_NORMAL))
    {
        collision=true;
    }

    return collision;
}

bool Joueur::collisionsFond(int typeTetro)
{
    int typeT=typeTetro;
    bool collision=false;

    if(typeT==TETRO_NORMAL)
    {
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

    }
    else
    {
        int dern_el=m_vecTetroFantome.size()-1;

        int compt=0;
        while(compt<m_vecTetroFantome.at(dern_el).forme.v_blocs.size())
        {
            if(m_vecTetroFantome.at(dern_el).forme.v_blocs.at(compt).getPosition().y+20.f > 560.f)
            {
                collision=true;
            }
            compt++;
        }
    }


    return collision;

}

bool Joueur::collisionsBords()
{
    bool collisionB=false;

    int dern_el=m_vecTetrominos.size()-1;

    int compt=0;
    while(compt<m_vecTetrominos.at(dern_el).forme.v_blocs.size())
    {
        if(m_vecTetrominos.at(dern_el).forme.v_blocs.at(compt).getPosition().x-20.f<17*20.f && m_dirG )
        {
            collisionB=true;
        }

        if( m_vecTetrominos.at(dern_el).forme.v_blocs.at(compt).getPosition().x+20.f>27*20.f && m_dirD)
        {
            collisionB=true;
        }

        compt++;
    }

    return collisionB;
}

bool Joueur::collisionsTetrominos(int typeTetro)
{
    int typeT=typeTetro;
    bool collision=false;
    std::vector<sf::Vector2f> ensemblePosFictif;

    if(typeT==TETRO_NORMAL)
    {
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

    }
    else
    {
        int dern_el=m_vecTetroFantome.size()-1;

        int compt=0;
        while(compt<m_vecTetroFantome.at(dern_el).forme.v_blocs.size())
        {
            sf::Vector2f posF;
            posF.x=m_vecTetroFantome.at(dern_el).forme.v_blocs.at(compt).getPosition().x;
            posF.y=m_vecTetroFantome.at(dern_el).forme.v_blocs.at(compt).getPosition().y+20.f;

            ensemblePosFictif.insert(ensemblePosFictif.end(),posF);
            compt++;
        }


        int comptt=0;
        while(comptt<ensemblePosFictif.size())
        {
            int compt2=0;
            while(compt2<m_vecTetrominos.size()-1)
            {
                int compt3=0;
                while(compt3<m_vecTetrominos.at(compt2).forme.v_blocs.size())
                {
                    if(m_vecTetrominos.at(compt2).forme.v_blocs.at(compt3).getPosition()==ensemblePosFictif.at(comptt))
                    {
                        collision=true;
                    }
                    compt3++;
                }

                compt2++;

            }

            comptt++;
        }
    }


    return collision;
}

bool Joueur::rangeePleine()
{
    m_vecRangeeASupp.clear();
    bool rangeePl=false;
    int rangee=0;
    while(rangee<20)
    {
        int casesRempli=0;

        int compt=0;
        while(compt<m_vecTetrominos.size())
        {
            int compt2=0;
            while(compt2<m_vecTetrominos.at(compt).forme.v_blocs.size())
            {
                if(m_vecTetrominos.at(compt).forme.v_blocs.at(compt2).getPosition().y==8*20.f+rangee*20.f+10.f)
                {
                    casesRempli++;
                }
                compt2++;
            }

            compt++;
        }

        if(casesRempli==10)
        {
            rangeePl=true;
            m_vecRangeeASupp.insert(m_vecRangeeASupp.end(),rangee);
            std::cout<<"Ranger a supprimer: "<<rangee<<std::endl;
        }

        rangee++;
    }

    return rangeePl;
}

void Joueur::effacementRangee()
{
    int compt=0;
    while(compt<m_vecRangeeASupp.size())
    {
        int indice1=0;
        int nombreT=m_vecTetrominos.size();
        int compt2=0;
        while(compt2<nombreT)
        {
            int indice2=0;
            int nombreBloc=m_vecTetrominos.at(indice1).forme.v_blocs.size();
            int compt3=0;
            while(compt3<nombreBloc)
            {
                if(m_vecTetrominos.at(indice1).forme.v_blocs.at(indice2).getPosition().y==m_vecRangeeASupp.at(compt)*20.f+8*20.f+10)
                {
                    if(m_vecTetrominos.at(indice1).forme.v_blocs.size()>1)
                    {
                        std::cout<<"\n Effacement simple \n"<<std::endl;
                        m_vecTetrominos.at(indice1).forme.v_blocs.erase(m_vecTetrominos.at(indice1).forme.v_blocs.begin()+indice2);
                        std::cout<<"Effacement bloc. Restant:"<<m_vecTetrominos.at(indice1).forme.v_blocs.size()<<std::endl;
                    }
                    else
                    {
                        if(m_vecTetrominos.size()==1)
                        {
                            std::cout<<"\n Effacement du dernier tetromino \n"<<std::endl;
                            m_vecTetrominos.clear();
                            indice1--;
                            std::cout<<"Effacement  de tout les Tetrominos. Restant:"<<m_vecTetrominos.size()<<std::endl;
                        }
                        else
                        {
                            std::cout<<"\n Effacement tetromino \n"<<std::endl;
                            m_vecTetrominos.erase(m_vecTetrominos.begin()+indice1);
                            indice1--;
                            std::cout<<"Effacement Tetromino. Restant:"<<m_vecTetrominos.size()<<std::endl;
                        }

                    }
                    indice2--;
                }
                indice2++;
                compt3++;
            }


            indice1++;
            compt2++;
        }

        compt++;
    }
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

    if(m_vecTetroFantome.size()!=0)
    {
        int compt4=0;
        while(compt4<m_vecTetroFantome.at(0).forme.v_blocs.size())
        {
            m_fenetre->draw(m_vecTetroFantome.at(0).forme.v_blocs.at(compt4));
            compt4++;
        }
    }



}

void Joueur::changerDirTetro(int dir)
{
    if(dir==mouv_g)
    {
        m_dirG=true;
        m_dirD=false;
        m_dirB=false;

    }
    else if(dir==mouv_d)
    {
        m_dirG=false;
        m_dirD=true;
        m_dirB=false;
    }
    else
    {

    }
}

Joueur::~Joueur()
{

}

