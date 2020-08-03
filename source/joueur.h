#ifndef DEF_JOUEUR
#define DEF_JOUEUR

#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "enums.h"
#include "varG.h"
#include "constantes.h"

class Joueur
{
public:
    Joueur(sf::RenderWindow& fenetre);
    void initJoueur();
    void mouvementTetromino();
    void mouvementTetrominos();
    void bougerTetromino(int dir);

    void gestionTetroFantome();

    void initFileSuiv();

    void ajouteTetromino();
    void ajouteTetroFileSuiv();
    void ajouteTetroFileDeGarde();

    Tetromino nouvelTetromino();

    int choixTetromino();
    void rotationTetromino(int sensR);

    bool collisionsGlobales();
    bool collisionsFond(int typeTetro);
    bool collisionsBords();
    bool collisionsTetrominos(int typeTetro);
    void changerDirTetro(int dir);

    bool rangeePleine();
    void effacementRangee();

    void afficheG();

    void finJeu();
    void effacementDonnees();

    ~Joueur();

private:
    sf::RenderWindow* m_fenetre;

    sf::Texture m_tBlocs, m_tGrille,m_tBFant;
    sf::Sprite m_sGrille;

    bool m_dirG,m_dirD,m_dirB;

    float m_dMouv_x,m_dMouv_y;

    std::vector<Tetromino> m_vecTetrominos;
    std::vector<Tetromino> m_vecFileSuiv;
    std::vector<Tetromino> m_vecFileDeGarde;
    std::vector<int> m_vecRangeeASupp;
    std::vector<Tetromino> m_vecTetroFantome;
    std::vector<sf::Vector2f> m_posInitTetro;




};

#endif // DEF_JOUEUR
