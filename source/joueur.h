#ifndef DEF_JOUEUR
#define DEF_JOUEUR

#include <SFML/Graphics.hpp>
#include "enums.h"
#include "varG.h"
#include "constantes.h"

class Joueur
{
public:
    Joueur(sf::RenderWindow& fenetre);

    void mouvementTetromino();
    void mouvementTetrominos();

    void ajouteTetromino();
    void ajouteTetroFileSuiv();
    void ajouteTetroFileDeGarde();

    Tetromino nouvelTetromino();

    int choixTetromino();
    void rotationTetromino();

    void collisionsGlobales();
    bool collisionsFond();
    bool collisionsBords();
    bool collisionsTetrominos();

    bool rangeePleine();
    void effacementRangee();

    void afficheTetrominos();

    ~Joueur();

private:
    sf::RenderWindow* m_fenetre;

    sf::Texture m_tBlocs;

    float m_dMouv_x,m_dMouv_y;

    std::vector<Tetromino> m_vecTetrominos;
    std::vector<Tetromino> m_vecFileSuiv;
    std::vector<Tetromino> m_vecFileDeGarde;
    std::vector<int> m_vecRangeeASupp;
    Tetromino m_tetroFantome;



};

#endif // DEF_JOUEUR
