#ifndef DEF_INFO
#define DEF_INFO

#include <SFML/Graphics.hpp>
#include "enums.h"
#include "varG.h"
#include "constantes.h"

class Info
{
public:
    Info(sf::RenderWindow& fenetre);
    void initInfo();
    void reinitInfo();
    void gestTableauScore();
    void gestInfoPartEnCours(int action);
    void gestMeilleurJ();
    void afficheInfo();
    ~Info();


private:
    sf::RenderWindow *m_fenetre;

    sf::Text m_txtNiveau;
    sf::Text m_txtNomsJ;
    sf::Text m_txtScoresJ;
    sf::Text m_txtInfoJeu;

    sf::Font m_fntNoms;
    sf::Font m_fntChiffres;

    int m_score;
    int m_niveau;
    int m_nombrLignes;

};
#endif // DEF_INFO
