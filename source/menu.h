#ifndef DEF_MENU
#define DEF_MENU

#include <SFML/Graphics.hpp>
#include "constantes.h"
#include "varG.h"
#include "enums.h"


class Menu
{
public:
    Menu(sf::RenderWindow &fenetre);
    ~Menu();
    void initMenuP();
    void initMenuI();
    void initMenuI1();
    void initMenuI2();
    void initMenuI3();
    void initMenuPause();
    void initMenuFinPart();
    void initMenuEnregScore();

    void setTypeMenu(int menuActuel);
    TypeMenu getTypeMenu();

    void afficheMenuP();
    void afficheMenuI();
    void afficheMenuI1();
    void afficheMenuI2();
    void afficheMenuI3();
    void afficheMenuPause();
    void afficheMenuFinPart();
    void afficheMenuEnregScore();
    void afficheMenu();

    void retourMenuP();

    void elementActif();
    void selectionElActif();

    bool collisionTS(sf::FloatRect elem);

    void quitterJeu();



private:
    sf::RenderWindow* m_fenetre;

    TypeMenu m_typeMenu;
    sf::Font m_font;
    sf::Font m_font2;
    sf::Font m_font3;

    int m_elementActif;

    //pour menu principal
    sf::Texture m_tMenuP;
    sf::Sprite m_sMenuP;


    //pour menu instructions
    sf::Texture m_tMenuI;
    sf::Sprite m_sMenuI;


    //pour menu instructions 1
    sf::Texture m_tMenuI1;
    sf::Sprite m_sMenuI1;


    //pour menu instructions 2
    sf::Texture m_tMenuI2;
    sf::Sprite m_sMenuI2;


    //pour menu instructions 3
    sf::Texture m_tMenuI3;
    sf::Sprite m_sMenuI3;

    //pour menu pause
    sf::Texture m_tMenuPause;
    sf::Sprite m_sMenuPause;

    //pour menu fin partie
    sf::Texture m_tMenuFinP;
    sf::Sprite m_sMenuFinP;

    //pour menu enregistre score
    sf::Texture m_tMenuEnregScore;
    sf::Sprite m_sMenuEnregScore;

    //boites engl des boutons
    sf::FloatRect boiteEBJ,boiteEBI,boiteEBQ,boiteEBPr,boiteEBSuiv,boiteEBOk,boiteEBPR,boiteEBPI,boiteEBPQ,boiteEBFQ,boiteEBFR,boiteEBESOk;


};
#endif // DEF_MENU
