#ifndef DEF_CONTROLEUR
#define DEF_CONTROLEUR

#include <SFML/Graphics.hpp>
#include "decor.h"


class Controleur
{
public:
    Controleur(sf::RenderWindow &fenetre);
    ~Controleur();
    void debutJeu();
    void finJeu();
    void pauseJeu();

    void afficheFondEc();
    void afficheJeu();
    void afficheInfo();
    void afficheMenu();

    void retourMenu();

    void gestionDplSouris();
    void gestionSelecSouris();

    void gestMajDonnees();
    void mouvementTetro(int dir);

    void stockerTetroActif();



private:
    sf::RenderWindow* m_fenetre;
    Decor* m_decor;
    float delai;
    sf::Clock horloge;
    float timer;


};

#endif // DEF_CONTROLEUR
