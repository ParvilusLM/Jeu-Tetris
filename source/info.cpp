#include "info.h"

using namespace std;

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
    //m_txtNomsJ.setLineSpacing(0.6f);


    m_txtScoresJ.setFont(m_fntNoms);
    m_txtScoresJ.setCharacterSize(20);
    m_txtScoresJ.setPosition(22.f*20.f+10.f,21.f*20.f-3.f);
    m_txtScoresJ.setFillColor(sf::Color::Black);
    //m_txtScoresJ.setLineSpacing(0.6f);



    m_txtInfoJeu.setFont(m_fntChiffres);
    m_txtInfoJeu.setCharacterSize(35);
    m_txtInfoJeu.setPosition(3.9f*20.f,20.7f*20.f+5.f);
    m_txtInfoJeu.setFillColor(sf::Color::White);
    m_txtInfoJeu.setLineSpacing(2.2f);

    m_txtNomAEnreg.setFont(m_fntNoms);
    m_txtNomAEnreg.setCharacterSize(30);
    m_txtNomAEnreg.setPosition(18.f*20.f+10.f,17.9f*20.f+5.f);
    m_txtNomAEnreg.setFillColor(sf::Color::White);



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
    m_nomAENreg.clear();
    gestTableauScore();
}

int Info::chargementDonnees()
{
    std::cout<<"Entree Fonction chargement"<<std::endl;

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

    while(nbNoms<3)
    {
        fgets(ligneFichierN,10,fichierNoms);
        std::string nom=ligneFichierN;
        while(nom.size()<2)
        {
            fgets(ligneFichierN,10,fichierNoms);
            nom=ligneFichierN;
        }

        m_vecNoms.insert(m_vecNoms.end(),nom);

        nbNoms++;
        std::cout<<"Valeur string: "<<nom<<nom.empty()<<" : "<<nom.size()<<std::endl;

    }


    std::cout<<"Taille m_vecNoms: "<<m_vecNoms.size()<<std::endl;

    fclose(fichierNoms);



    std::cout<<"Moitie Fonction chargement"<<std::endl;

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

    while(nbScores<3)
    {
        fgets(ligneFichierSc,10,fichierScores);
        std::string score=ligneFichierSc;
        while(score.size()<2)
        {
            fgets(ligneFichierSc,10,fichierScores);
            score=ligneFichierSc;
        }

        m_vecScores.insert(m_vecScores.end(),score);

        nbScores++;
        std::cout<<"Valeur string: "<<score<<score.empty()<<std::endl;

    }

    fclose(fichierScores);
    std::cout<<"Sortie Fonction chargement"<<std::endl;
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
    monFlux.close();

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
    monFlux.close();
}

void Info::gestTableauScore()
{
    m_txtNomsJ.setLineSpacing(0.6f);
    m_streamNomsJ.str("");
    m_streamNomsJ<<m_vecNoms.at(0)<<"\n"<<m_vecNoms.at(1)<<"\n"<<m_vecNoms.at(2);
    m_txtNomsJ.setString(m_streamNomsJ.str());

    m_txtScoresJ.setLineSpacing(0.6f);
    m_streamScoresJ.str("");
    m_streamScoresJ<<m_vecScores.at(0)<<"\n"<<m_vecScores.at(1)<<"\n"<<m_vecScores.at(2);
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

void Info::gestSaisieNom(char characTape)
{
    if(m_nomAENreg.size()<5)
    {
        m_nomAENreg+=characTape;
        m_txtNomAEnreg.setString(m_nomAENreg);
    }

}

void Info::sauvegardeScore()
{
    int posJoueur=0;

    int compt=0;
    int dern_el=m_vecScores.size()-1;
    while(compt<m_vecScores.size())
    {
        int score=std::stoi(m_vecScores.at(dern_el));
        if(m_score==score || m_score>score)
        {
            posJoueur=dern_el+1;
        }
        dern_el--;
        compt++;
    }



    //remplir les vecteurs scores et noms
    posJoueur--;

    m_vecScores.insert(m_vecScores.begin()+posJoueur,nbEnString(m_score));
    m_vecScores.pop_back();

    m_vecNoms.insert(m_vecNoms.begin()+posJoueur,m_nomAENreg);
    m_vecNoms.pop_back();

    std::cout<<"Taille m_vecScores :"<<m_vecScores.size()<<"\n Taille m_vecNoms :"<<m_vecNoms.size()<<std::endl;


    //Sauvegarde dans les fichiers

    std::string const nomFichierS("donnees/scoresJ.plm");
    std::string const nomFichierN("donnees/nomsJ.plm");


    //ecriture dans le fichier score
    {
        int posCurseur=0;
        std::ofstream monFlux(nomFichierS.c_str());

        //monFlux.seekp(posCurseur);
        monFlux<<m_vecScores.at(0)<<std::endl;

        //posCurseur+=m_vecScores.at(0).size()+1;
        //monFlux.seekp(posCurseur);
        monFlux<<m_vecScores.at(1)<<std::endl;

        //posCurseur+=m_vecScores.at(1).size()+1;
        //monFlux.seekp(posCurseur);
        monFlux<<m_vecScores.at(2)<<std::endl;

        monFlux.close();

    }



    //ecriture dans le fichier nom
    {
        int posCurseur=0;
        std::ofstream monFluxN(nomFichierN.c_str());

        //monFluxN.seekp(posCurseur);
        monFluxN<<m_vecNoms.at(0)<<std::endl;

        //posCurseur+=m_vecNoms.at(0).size()+1;
        //monFluxN.seekp(posCurseur);
        monFluxN<<m_vecNoms.at(1)<<std::endl;

        //posCurseur+=m_vecNoms.at(1).size()+1;
        //monFluxN.seekp(posCurseur);
        monFluxN<<m_vecNoms.at(2)<<std::endl;


        monFluxN.close();
    }



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

void Info::afficheNomAEnreg()
{
    m_fenetre->draw(m_txtNomAEnreg);
}

bool Info::surPodium()
{
    bool podium=false;

    int cmpt=0;
    while(cmpt<3)
    {
        if(std::stoi(m_vecScores.at(cmpt))<m_score)
        {
            podium=true;
        }
        cmpt++;
    }

    return podium;
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
