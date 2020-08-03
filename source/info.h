#ifndef DEF_INFO
#define DEF_INFO

#include <SFML/Graphics.hpp>
#include "enums.h"
#include "varG.h"
#include "constantes.h"
#include "sstream"

class Info
{
public:
    Info(sf::RenderWindow& fenetre);
    void initInfo();
    void reinitInfo();
    void chargementDonnees();
    void gestTableauScore();
    void gestInfoPartEnCours(int action);
    void gestMeilleurJ();
    void maj_Info();
    void afficheInfo();

    template <class T> std::string nbEnString(T nb);
    ~Info();


private:
    sf::RenderWindow *m_fenetre;
    sf::Text m_txtNiveau;
    sf::Text m_txtNomsJ;
    sf::Text m_txtScoresJ;
    sf::Text m_txtInfoJeu;

    sf::Font m_fntNoms;
    sf::Font m_fntChiffres;

    std::ostringstream m_streamNomsJ,m_streamScoresJ,m_streamInfoJeu;

    int m_score;
    int m_niveau;
    int m_nombrLignes;

};
#endif // DEF_INFO
