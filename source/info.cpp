#include "info.h"

Info::Info(sf::RenderWindow& fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;
    m_score=0;
    m_niveau=1;
    m_nombrLignes=0;

    initInfo();
    chargementDonnees();
    gestTableauScore();
    gestInfoPartEnCours();

}

void Info::initInfo()
{
    //les fonts
    m_fntChiffres.loadFromFile("donnees/keypunc.ttf");
    m_fntNoms.loadFromFile("donnees/ALGER.ttf");

    //les textes
    m_txtNiveau.setFont(m_fntChiffres);
    m_txtNiveau.setCharacterSize(20);
    m_txtNiveau.setPosition(19.2f*20.f,17.1f*20.f);
    m_txtNiveau.setFillColor(sf::Color::Black);


    m_txtNomsJ.setFont(m_fntNoms);
    m_txtNomsJ.setCharacterSize(20);
    m_txtNomsJ.setPosition(18.3f*20.f+4.f,21.f*20.f-3.f);
    m_txtNomsJ.setFillColor(sf::Color::Black);
    m_txtNomsJ.setLineSpacing(0.6f);


    m_txtScoresJ.setFont(m_fntNoms);
    m_txtScoresJ.setCharacterSize(20);
    m_txtScoresJ.setPosition(22.f*20.f+10.f,21.f*20.f-3.f);
    m_txtScoresJ.setFillColor(sf::Color::Black);
    m_txtScoresJ.setLineSpacing(0.6f);



    m_txtInfoJeu.setFont(m_fntChiffres);
    m_txtInfoJeu.setCharacterSize(35);
    m_txtInfoJeu.setPosition(3.9f*20.f,20.7f*20.f+5.f);
    m_txtInfoJeu.setFillColor(sf::Color::White);
    m_txtInfoJeu.setLineSpacing(2.2f);


    //info sur le niveau en cours
    m_score=0;
    m_niveau=1;
    m_nombrLignes=0;
}

void Info::reinitInfo()
{
    m_score=0;
    m_niveau=1;
    m_nombrLignes=0;
}

int Info::chargementDonnees()
{

    //gestion fichier noms des joueurs
    std::string const nomFichierN("donnees/nomsJ.plm");
    FILE* fichierNoms=NULL;
    char ligneFichierN[6]={0};
    int caractereLu=0,nbNoms=0,noNoms=0,noLigneChoisi=0;

    fichierNoms=fopen(nomFichierN.c_str(),"r");
    if(fichierNoms==NULL)
    {
        fclose(fichierNoms);
        initDonneesN();
        fichierNoms=fopen(nomFichierN.c_str(),"r");
    }

    do
    {
        caractereLu=fgetc(fichierNoms);
        if(caractereLu == '\n')
            nbNoms++;

    }while(caractereLu != EOF);

    while(noNoms<3)
    {
        noLigneChoisi=noNoms;
        rewind(fichierNoms);

        while(noLigneChoisi>0)
        {
            caractereLu=fgetc(fichierNoms);
            if(caractereLu == '\n')
                noLigneChoisi--;
        }


        m_vecNoms.insert(m_vecNoms.end(),fgets(ligneFichierN,10,fichierNoms));

        noNoms++;

    }

    int compt=0;
    while(compt<m_vecNoms.size())
    {
        //std::cout<<m_vecNoms.at(compt)<<std::endl;
        compt++;
    }
    fclose(fichierNoms);

    //gestion des scores des joueurs
    std::string const nomFichierScores("donnees/scoresJ.plm");
    FILE* fichierScores=NULL;
    char ligneFichierSc[6]={0};
    caractereLu=0,noLigneChoisi=0;
    int nbScores=0,noScores=0;

    fichierScores=fopen(nomFichierScores.c_str(),"r");
    if(fichierScores==NULL)
    {
        fclose(fichierScores);
        initDonneesScores();
        fichierScores=fopen(nomFichierScores.c_str(),"r");

    }

    do
    {
        caractereLu=fgetc(fichierScores);
        if(caractereLu == '\n')
            nbScores++;

    }while(caractereLu != EOF);

    while(noScores<3)
    {
        noLigneChoisi=noScores;
        rewind(fichierScores);

        while(noLigneChoisi>0)
        {
            caractereLu=fgetc(fichierScores);
            if(caractereLu == '\n')
                noLigneChoisi--;
        }


        m_vecScores.insert(m_vecScores.end(),fgets(ligneFichierSc,10,fichierScores));

        noScores++;

    }

    int comptt=0;
    while(comptt<m_vecScores.size())
    {
        //std::cout<<m_vecScores.at(comptt)<<std::endl;
        comptt++;
    }
    fclose(fichierScores);



}

void Info::initDonneesN()
{
    std::string const nomFichierN("donnees/nomsJ.plm");
    std::ofstream monFlux(nomFichierN.c_str());

    int nbN=3;
    while(nbN>0)
    {
        monFlux<<"Nul"<<std::endl;
        nbN--;
    }


}

void Info::initDonneesScores()
{
    std::string const nomFichierS("donnees/scoresJ.plm");
    std::ofstream monFlux(nomFichierS.c_str());

    int nbN=3;
    while(nbN>0)
    {
        monFlux<<"0"<<std::endl;
        nbN--;
    }
}

void Info::gestTableauScore()
{
    m_streamNomsJ.str("");
    m_streamNomsJ<<m_vecNoms.at(0)<<"\n"<<m_vecNoms.at(1)<<"\n"<<m_vecNoms.at(2);
    m_txtNomsJ.setString(m_streamNomsJ.str());

    m_streamScoresJ.str("");
    m_streamScoresJ<<m_vecScores.at(0)<<"\n"<<m_vecScores.at(0)<<"\n"<<m_vecScores.at(0);
    m_txtScoresJ.setString(m_streamScoresJ.str());

}

void Info::gestInfoPartEnCours()
{
    if(nbLignesTemp!=0 && scoreTemp!=0)
    {
        m_nombrLignes+=nbLignesTemp;
        m_score+=scoreTemp;


        scoreTemp=0;
        nbLignesTemp=0;
    }

    //
    m_streamInfoJeu.str("");
    m_streamInfoJeu<<nbEnString(m_score)<<"\n"<<nbEnString(m_niveau)<<"\n"<<nbEnString(m_nombrLignes);
    m_txtInfoJeu.setString(m_streamInfoJeu.str());


}

void Info::gestMeilleurJ()
{

}

void Info::maj_Info()
{

}

void Info::afficheInfo()
{
    if(jeuEnCours)
    {
        m_fenetre->draw(m_txtInfoJeu);
    }
    else
    {
        m_fenetre->draw(m_txtNomsJ);
        m_fenetre->draw(m_txtScoresJ);
    }
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
