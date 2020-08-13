#ifndef DEF_INFO
#define DEF_INFO

#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
#include "enums.h"
#include "varG.h"
#include "constantes.h"
#include "sstream"
#include <fstream>
#include <string>
#include <array>

class Info
{
public:
    Info(sf::RenderWindow& fenetre);
    void initInfo();
    void reinitInfo();
    int chargementDonnees();
    void initDonneesN();
    void initDonneesScores();
    void gestTableauScore();
    void gestInfoPartEnCours();
    void gestMeilleurJ(char characTape);
    void maj_Info();
    void afficheInfo();
    void afficheNomAEnreg();
    bool surPodium();

    template <class T> std::string nbEnString(T nb);
    ~Info();


private:
    sf::RenderWindow *m_fenetre;
    sf::Text m_txtNiveau;
    sf::Text m_txtNomsJ;
    sf::Text m_txtScoresJ;
    sf::Text m_txtInfoJeu;
    sf::Text m_txtNomAEnreg;

    sf::Font m_fntNoms;
    sf::Font m_fntChiffres;

    std::ostringstream m_streamNomsJ,m_streamScoresJ,m_streamInfoJeu;

    int m_score;
    int m_niveau;
    int m_nombrLignes;
    std::vector<std::string> m_vecNoms;
    std::vector<std::string> m_vecScores;

    std::string m_nomAENreg;

};
#endif // DEF_INFO
