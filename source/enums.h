#ifndef DEF_ENUMS
#define DEF_ENUMS

#include <SFML/Graphics.hpp>

struct Blocs
{
    std::vector<sf::Sprite>v_blocs;
};

struct Tetromino
{
    Blocs forme;
    int nb_blocs;
    int formeTetromino;
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
    MenuFinPartie,
    MenuEnregScore

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
    FINPR_ACTIF,
    ESOk_ACTIF

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

enum
{
    TETRO_FANTOME,
    TETRO_NORMAL
};

enum
{
    ROTATION_G,
    ROTATION_D
};

enum
{
    ACTION_AUGM_SCORES,
    ACTION_AUGM_LIGNES,
    ACTION_AUGM_NIVEAU
};


#endif // DEF_ENUMS
