#ifndef DEF_ENUMS
#define DEF_ENUMS

#include <SFML/Graphics.hpp>

struct Blocs
{
    std::vector<sf::Sprite>v_blocs;
};

struct Tetromino
{
    bool tetr_en_mouv;
    bool dir_m_b;
    bool dir_m_g;
    bool dir_m_d;

    Blocs forme;
    int nb_blocs;
};

enum{
    mouv_b,
    mouv_g,
    mouv_d
};

enum TypeMenu
{
    MenuPrincipal,
    MenuInstructions1,
    MenuInstructions2,
    MenuInstructions3,
    MenuPause,
    MenuFinPartie

};

enum
{
    AUCUN_EL_ACT,
    JOUER_ACTIF,
    INSTRUCTIONS_ACTIF,
    QUITTER_ACTIF,
    OK_ACTIF,
    PRECEDENT_ACTIF,
    SUIVANT_ACTIF,
    RETOUR_ACTIF,
    PAUSER_ACTIF,
    PAUSEI_ACTIF,
    PAUSEQ_ACTIF,
    FINPQ_ACTIF,
    FINPR_ACTIF

};

enum
{
    FORME_J,
    FORME_T,
    FORME_L,
    FORME_S,
    FORME_I,
    FORME_Z,
    FORME_O
};


#endif // DEF_ENUMS
