#ifndef DEF_CONTROLEUR
#define DEF_CONTROLEUR

#include <SFML/Graphics.hpp>
#include "decor.h"


class Controleur
{
public:
    Controleur(sf::RenderWindow &fenetre);
    ~Controleur();
    void afficheFondEc();
    void afficheJeu();
    void afficheInfo();
    void afficheMenu();

    void retourMenu();

    void gestionDplSouris();
    void gestionSelecSouris();

    void gestMajDonnees();



private:
    sf::RenderWindow* m_fenetre;
    Decor* m_decor;

};

#endif // DEF_CONTROLEUR
