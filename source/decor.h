#ifndef DEF_DECOR
#define DEF_DECOR

#include <SFML/Graphics.hpp>
#include "menu.h"
#include "info.h"
#include "son.h"
#include "joueur.h"


class Decor
{
public:
    Decor(sf::RenderWindow& fenetre);
    ~Decor();

    Joueur& getJoueur();
    Menu& getMenu();
    Info& getInfo();
    Son& getSon();

    void afficheFondEc();




private:
    sf::RenderWindow* m_fenetre;
    Joueur* m_joueur;
    Son* m_son;
    Info*  m_info;
    Menu* m_menu;

    sf::Texture m_tFondG;
    sf::Sprite m_sFondG;

};

#endif // DEF_DECOR
