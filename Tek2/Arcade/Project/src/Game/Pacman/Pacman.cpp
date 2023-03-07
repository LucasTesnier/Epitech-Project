/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include <iostream>
#include <unistd.h>


extern "C" arcade::game::IGame *entryPointGame(void)
{
    arcade::game::IGame *newGame = new arcade::game::Pacman();

    return newGame;
}


/**
 * @brief It loads the map.
 */
arcade::game::Pacman::Pacman()
{
    _timeToBeInvicible = 0;
    _points = 0;
    _life = 3;
    _animation = 0;
    _opeeeen = 40;
    _temp = ' ';
    loadMap("./src/Game/Pacman/map.txt");
}


/**
 * @brief It destroys the game
 */
arcade::game::Pacman::~Pacman()
{
    destroyGame();
}


/**
 * @brief It makes the pacman move and the ghosts move
 */
void arcade::game::Pacman::simulate()
{
    makeMoovPac(_posEntityPac);
    arcade::vector2i_t temp[3];
    int count = 0;

    for (int y = 0; y != 21; y++) {
        for (int i = 0; i != 33; i++) {
            if (_map[y][i] == 'G') {
                temp[count] = arcade::vector2i_t {
                    (std::size_t)i,
                    (std::size_t)y
                };
                count += 1;
            }
        }
    }
    for (int i = 0; i < count; i++) {
        makeMoovGhost(temp[i]);
    }
    _animation += 1;
    usleep(100000);
}

/**
 * @brief It returns a vector of game_object_t, which is a struct containing the position, size, orientation,
 * color and path of the object
 * 
 * @return a vector of game_object_t.
 */
const std::vector<arcade::game_object_t> arcade::game::Pacman::getPendingItems() const
{
    std::vector<arcade::game_object_t> entitys;
    arcade::game_object_t entity;
    size_t size = 1;

     for (int y = 0; y != 21 ; y++) {
         for (int i = 0; i != 33; i++) {
             if (_map[y][i] == 'W') { 
                 entity.color = "0000FF";
                 entity.orientation = ELEFT;
                 entity.path = "./assets/pacman/wall.bmp";
                 entity.pos.x = i + 8;
                 entity.pos.y = y + 14;
                 entity.size.x = size;
                 entity.size.y = size;
             }
             if (_map[y][i] == 'P') { 
                 entity.color = (_timeToBeInvicible != 0) ? "FFFF00" : "F0FF00";
                 entity.orientation = ELEFT;
                 entity.path = "./assets/pacman/pacman" + ((_direction == ELEFT) ? std::string("_left") : ((_direction == ERIGHT) ? std::string("_right") : ((_direction == EUP) ? std::string("_down") : std::string("_up")))) + ((_animation % 2 == 1) ? std::string("_two") : std::string("_one")) + ((_timeToBeInvicible != 0) ? std::string("_i") : std::string("")) + ".bmp";
                 entity.pos.x = i + 8;
                 entity.pos.y = y + 14;
                 entity.size.x = size;
                 entity.size.y = size;
             }
             if (_map[y][i] == 'G') { 
                 entity.color = (_timeToBeInvicible != 0) ? "00FF36" : "001AD2";
                 entity.orientation = ELEFT;
                 entity.path = "./assets/pacman/ghost" + ((_direction == ELEFT) ? std::string("_left") : ((_direction == ERIGHT) ? std::string("_right") : ((_direction == EUP) ? std::string("_down") : std::string("_up")))) + ((_animation % 2 == 0) ? std::string("_two") : std::string("")) + ((_timeToBeInvicible != 0) ? std::string("_i") : std::string("")) + ".bmp";
                 entity.pos.x = i + 8;
                 entity.pos.y = y + 14;
                 entity.size.x = size;
                 entity.size.y = size;
             } entity.size.y = size;
             if (_map[y][i] == '.') { 
                 entity.color = "FFFFFF";
                 entity.orientation = EUP;
                 entity.path = "./assets/pacman/coin.bmp";
                 entity.pos.x = i + 8;
                 entity.pos.y = y + 14;
                 entity.size.x = size;
                 entity.size.y = size;
             }
             if (_map[y][i] == 'C') {  
                 entity.color = "FF0000";
                 entity.orientation = EUP;
                 entity.path = "./assets/pacman/cherry.bmp";
                 entity.pos.x = i + 8;
                 entity.pos.y = y + 14;
                 entity.size.x = size;
                 entity.size.y = size;
             }
            entitys.push_back(entity);
         }
     }
     return entitys;
}


/**
 * @brief It takes a vector of events and does the appropriate action for each event
 * 
 * @param events A vector of events that have been triggered since the last call to doPendingEvent.
 */
void arcade::game::Pacman::doPendingEvent(std::vector<arcade::event_t> &events)
{
    for (auto &ev : events) {
        switch (ev) {
            case UP:
                    _direction = EDOWN;
                break;
            case DOWN:
                    _direction = EUP;
                break;
            case RIGHT:
                    _direction = ERIGHT;
                break;
            case LEFT:
                    _direction = ELEFT;
                break;
            case RESTART:
                reset();
                break;
            default:
                break;
        }
    }
}

/**
 * @brief It returns a game_object_t struct with the path to the background image, the position of the image
 * (0,0), the color of the image (black) and the orientation of the image (up)
 * 
 * @return The background of the game
 */
const arcade::game_object_t arcade::game::Pacman::getBackground() const
{
    arcade::vector2i_t v {v.x = 0, v.y = 0};
    arcade::game_object_t bg;

    bg.path = "./assets/snake_backgrund.bmp";
    bg.pos = v;
    bg.color = "000000";
    bg.orientation = EUP;

    return bg;
}


/**
 * @brief It deletes the map and then loads it again
 */
void arcade::game::Pacman::reset()
{
    deleteMap();
    loadMap("./src/Game/Pacman/map.txt");
}

/**
 * @brief If the player is dead, return LOSE, if the player has won, return WIN, otherwise return IN_PROGRESS.
 * 
 * @return The game status.
 */
arcade::game_status_t arcade::game::Pacman::getGameStatus() const
{
    if (!isAlive())
        return (LOSE);
    if (isWin())
        return (WIN);
    return (IN_PROGRESS);
}

/**
 * @brief It returns a vector of text_object_t, which is a struct containing the text to display, the font to
 * use, the position, the color of the text, the color of the background, and the size of the text
 * 
 * @return A vector of text_object_t
 */
const std::vector<arcade::text_object_t> arcade::game::Pacman::getPendingTexts() const
{
    std::vector<arcade::text_object_t> vect;
    arcade::text_object_t score;

    score.message = "SCORE: " + std::to_string(_points);
    score.fontPath = "./assets/font/arial.ttf";
    score.pos = arcade::vector2i_t {
        40,
        2
    };
    score.textColor = "f22b2b";
    score.backgroundColor = "000000";
    score.size = 50;
    vect.push_back(score);
    arcade::text_object_t live;

    live.message = "Remaining Lifes: " + std::to_string(_life);
    live.fontPath = "./assets/font/arial.ttf";
    live.pos = arcade::vector2i_t {
        40,
        6
    };
    live.textColor = "f22b2b";
    live.backgroundColor = "000000";
    live.size = 40;
    vect.push_back(live);
    vect.push_back(arcade::text_object_t {
            std::to_string(_points),
            "Score",
            0,
            arcade::vector2i_t {
                0,
                0
            },
            "FF1493",
            "000000"
        });
    return (vect);
}

/**
 * @brief It checks if the next position of the entity is a point
 * 
 * @param posNextentity The position of the entity in the next frame.
 * 
 * @return A boolean
 */
bool arcade::game::Pacman::isAPoint(vector2i_s posNextentity)
{
    if (_map[posNextentity.y][posNextentity.x] == '.')
        return (true);
    return (false);
}

/**
 * @brief It checks if the next case is empty
 * 
 * @param posNextentity the position of the entity in the next frame
 * 
 * @return A boolean
 */
bool arcade::game::Pacman::isEmptyCase(vector2i_s posNextentity)
{
    if (_map[posNextentity.y][posNextentity.x] == ' ')
        return (true);
    return (false);
}

/**
 * @brief It checks if the next position of the entity is a cherry
 * 
 * @param posNextentity the position of the entity in the next frame
 * 
 * @return A boolean
 */
bool arcade::game::Pacman::isACherry(vector2i_s posNextentity)
{
    if (_map[posNextentity.y][posNextentity.x] == 'C')
        return (true);
    return (false);
}


/**
 * @brief It returns true if the player is invincible, false otherwise
 * 
 * @return A boolean.
 */
bool arcade::game::Pacman::isInvincible()
{
    if (_timeToBeInvicible > 0)
        return (true);
    return (false);
}


/**
 * @brief It checks if the next position of the entity is a ghost
 * 
 * @param posNextentity the position of the entity that is going to move
 * 
 * @return A boolean
 */
bool arcade::game::Pacman::isAGhost(vector2i_s posNextentity)
{
    if (_map[posNextentity.y][posNextentity.x] == 'G')
        return (true);
    return (false);
}


/**
 * @brief It checks if the next position of the entity is a teleport
 * 
 * @param posNextentity the position of the entity in the next frame
 * 
 * @return A boolean
 */
bool arcade::game::Pacman::isATp(vector2i_s posNextentity)
{
    if (_map[posNextentity.y][posNextentity.x] == 'T')
        return (true);
    return (false);
}


/**
 * @brief It checks if the next position of the entity is a wall
 * 
 * @param posNextentity the position of the entity in the next frame
 * 
 * @return A boolean
 */
bool arcade::game::Pacman::isAWall(vector2i_s posNextentity)
{
    if (_map[posNextentity.y][posNextentity.x] == 'W')
        return (true);
    return (false);
}

/**
 * @brief It checks if the next position of the player is a ghost and if the player is not invicible
 * 
 * @param posNextentity the position of the entity in the next frame
 * 
 * @return A boolean
 */
bool arcade::game::Pacman::isEatbyGhost(vector2i_s posNextentity)
{
    if (_map[posNextentity.y][posNextentity.x] == 'G' && _timeToBeInvicible == 0)
        return (true);
    return (false);
}

/**
 * @brief It checks if the next position of the player is a ghost and if the player is invicible
 * 
 * @param posNextentity The position of the entity in the next frame.
 * 
 * @return It returns a boolean.
 */
bool arcade::game::Pacman::isEataGhost(vector2i_s posNextentity)
{
    if (_map[posNextentity.y][posNextentity.x] == 'G' && _timeToBeInvicible > 0)
        return (true);
    return (false);
}

/**
 * @brief It returns true if the player is alive, false otherwise
 * 
 * @return The function isAlive returns a boolean value.
 */
bool arcade::game::Pacman::isAlive() const
{
    if (_life > 0)
        return (true);
    return (false);
}

/**
 * @brief It checks if the player has won the game
 * 
 * @return The function isWin() returns a boolean value.
 */
bool arcade::game::Pacman::isWin() const
{
    for (int y = 0; y != 24; y++) {
        for (int i = 0; i != 34; i++)
            if (_map[y][i] == '.' || _map[y][i] == 'C') {
               return (false);
            }
    }
    return (true);
}

/**
 * @brief It opens the map file, reads it line by line, and stores it in a 2D array
 * 
 * @param path The path to the map file
 */
void arcade::game::Pacman::loadMap(char const *path)
{ 
    arcade::game_object_t entity;
    std::ifstream map;
    std::string line;
    map.open(path);
    for (int y = 0; std::getline(map, line); y++) {
        for (int i = 0; i != 34; i++) {
            _map[y][i] = line.c_str()[i];
        }
    }
    map.close();
    for (int y = 0; y != 21; y++) {
        for (int i = 0; i != 34; i++)
            if (_map[y][i] == 'P') {
                _posEntityPac.y = y;
                _posEntityPac.x = i;
            }
    }
}

/**
 * @brief Delete the map
 */
void arcade::game::Pacman::deleteMap()
{
    _timeToBeInvicible = 0;
    _points = 0;
    _life = 3;
    _opeeeen = 40;
    //todo delete vecter
}

/**
 * @brief It initializes the game
 */
void arcade::game::Pacman::initGame()
{

}

/**
 * @brief This function is called when the game is destroyed.
 */
void arcade::game::Pacman::destroyGame()
{

}

/**
 * @brief It returns the next position of an entity, given its current position and its orientation
 * 
 * @param entity The position of the entity
 * @param orientation the orientation of the entity
 * 
 * @return The next position of the entity
 */
arcade::vector2i_t arcade::game::Pacman::getNextEntity(vector2i_t entity, orientation_t orientation)
{
    vector2i_t nextPos;

    nextPos.x = entity.x;
    nextPos.y = entity.y;
    switch (orientation) {
        case 0:
            nextPos.x += 0;
            nextPos.y += 1; 
            break;
        case 90:
            nextPos.x += 1;
            nextPos.y += 0; 
            break;
        case 180:
            nextPos.x += 0;
            nextPos.y += -1; 
            break;
        case 270:
            nextPos.x += -1;
            nextPos.y += 0; 
            break;
    default:
        break;
    }
    return (nextPos);
}

/**
 * @brief It checks if the next move is possible
 * 
 * @param entity the entity's position
 * @param orientation the orientation of the entity
 * 
 * @return A boolean
 */
bool arcade::game::Pacman::checkNextMoove(vector2i_t &entity, orientation_t orientation)
{
    vector2i_t nextEntity = getNextEntity(entity, orientation);

    if (isAWall(nextEntity))
        return (false);
    return (true);
}

/**
 * @brief It moves the pacman
 * 
 * @param entity the position of the entity
 */
void arcade::game::Pacman::makeMoovPac(vector2i_t &entity)
{
    vector2i_s posNextEntity = getNextEntity(entity, _direction);

    
    _opeeeen -= 1;
    if (_opeeeen == 0) {
        _map[8][12] = ' ';
        _map[8][13] = ' ';
        _map[8][14] = ' ';
        _map[8][15] = ' ';
        _map[8][16] = ' ';
        _map[8][17] = ' ';
        _map[8][18] = ' ';
        _map[8][19] = ' ';
        _map[8][20] = ' ';
    }
    if (_timeToBeInvicible > 0)
        _timeToBeInvicible -= 1;
    if (isACherry(posNextEntity)) {
        moove(entity, _direction);
        addPoints('C');
        _timeToBeInvicible += BEINVINIBLE;
    }
    if (isEmptyCase(posNextEntity))
        moove(entity, _direction);
    if (isAPoint(posNextEntity)) {
        moove(entity, _direction);
        addPoints('.');
    }
    if (isAGhost(posNextEntity) && isInvincible()) {
        killGhost(posNextEntity);
        addPoints('G');
        moove(entity, _direction);
    }
    if (isAGhost(posNextEntity) && !isInvincible()) {
        //kill pacman
        //lose life
        _map[_posEntityPac.y][_posEntityPac.x] = ' ';
        _map[13][16] = 'P';
        _posEntityPac.y = 13;
        _posEntityPac.x = 16;
        _opeeeen = 30;
        _life -= 1;
        //moove(entity, _direction);
    }
    if (isATp(posNextEntity))
        TPEntity(entity, _direction);
}

/**
 * @brief It does nothing
 * 
 * @param entity The position of the entity that is being killed.
 */
void arcade::game::Pacman::killGhost(vector2i_t &entity)
{
    (void) entity;
    // nextEntity.pos.x = 18;
    // nextEntity.pos.y = 11;
}


/**
 * @brief It adds points to the player's score
 * 
 * @param c The character to add points for.
 */
void arcade::game::Pacman::addPoints(char c)
{
    if (c == 'G')
        _points += 5;
    if (c == 'C')
        _points += 2;
    if (c == '.')
        _points += 1;
}

/**
 * @brief It does nothing
 * 
 * @param entity The entity to move
 */
void arcade::game::Pacman::makeMoovGhost(vector2i_t entity)
{
    vector2i_s posNextEntity = getNextEntity(entity, _direction);
    orientation_t hey[4] = {
        EUP,
        ERIGHT,
        EDOWN,
        ELEFT
    };
    if (isAGhost(posNextEntity))
        return;
    if (isACherry(posNextEntity)) {
        moove(entity, hey[rand() % 4]);
        return;
    }
    if (isEmptyCase(posNextEntity)) {
        moove(entity, hey[rand() % 4]);
        return;
    }
    if (isAPoint(posNextEntity)) {
        moove(entity, hey[rand() % 4]);
        return;
    }
    // if (isATp(posNextEntity))
    //     TPEntity(entity, _direction);
}

/**
 * @brief It moves the entity in the direction of the orientation
 * 
 * @param entity the entity to move
 * @param orientation the direction the entity is going to move
 */
void arcade::game::Pacman::moove(vector2i_t entity, orientation_t orientation)
{
    if (orientation == EUP)
        mooveUp(entity);
    if (orientation == EDOWN)
        mooveDown(entity);
    if (orientation == ELEFT)
        mooveLeft(entity);
    if (orientation == ERIGHT)
        mooveRight(entity);
}

/**
 * @brief It moves the player to the left
 * 
 * @param entity The entity that is moving.
 */
void arcade::game::Pacman::mooveLeft(vector2i_t entity)
{
    if (_map[entity.y][entity.x] == 'P') {
        _map[_posEntityPac.y][_posEntityPac.x] = ' ';
        _posEntityPac.x += -1;
        _posEntityPac.y += 0;
        _map[_posEntityPac.y][_posEntityPac.x] = 'P';
    } else {
        if (_map[entity.y][entity.x - 1] != 'W' && _map[entity.y][entity.x - 1] != 'G') {
            if (_map[entity.y][entity.x - 1] == ' ') {
                _map[entity.y][entity.x] = ' ';
                _map[entity.y][entity.x - 1] = 'G';
                _temp = ' ';
            } else {
                char a = _temp;
                _map[entity.y][entity.x] = a;
                _temp = _map[entity.y][entity.x - 1];
                _map[entity.y][entity.x - 1] = 'G';
            }
        }
    }
}

/**
 * @brief It moves the entity to the right
 * 
 * @param entity The entity to move
 */
void arcade::game::Pacman::mooveRight(vector2i_t entity)
{
    if (_map[entity.y][entity.x] == 'P') {
        _map[_posEntityPac.y][_posEntityPac.x] = ' ';
        _posEntityPac.x += 1;
        _posEntityPac.y += 0;
        _map[_posEntityPac.y][_posEntityPac.x] = 'P';
    } else {
        if (_map[entity.y][entity.x + 1] != 'W' && _map[entity.y][entity.x + 1] != 'G') {
            if (_map[entity.y][entity.x + 1] == ' ') {
                _map[entity.y][entity.x] = ' ';
                _map[entity.y][entity.x + 1] = 'G';
            } else {
                char a = _temp;
                _map[entity.y][entity.x] = a;
                _temp = _map[entity.y][entity.x + 1];
                _map[entity.y][entity.x + 1] = 'G';
            }
        }
    }
    
}

/**
 * @brief It moves the player up
 * 
 * @param entity the entity to move
 */
void arcade::game::Pacman::mooveUp(vector2i_t entity)
{
    if (_map[entity.y][entity.x] == 'P') {
        _map[_posEntityPac.y][_posEntityPac.x] = ' ';
        _posEntityPac.x += 0;
        _posEntityPac.y += 1;
        _map[_posEntityPac.y][_posEntityPac.x] = 'P';
    } else {
        if (_map[entity.y + 1][entity.x] != 'W' && _map[entity.y + 1][entity.x] != 'G') {
            if (_map[entity.y + 1][entity.x] == ' ') {
                _map[entity.y][entity.x] = ' ';
                _map[entity.y + 1][entity.x] = 'G';
            } else {
                char a = _temp;
                _map[entity.y][entity.x] = a;
                _temp = _map[entity.y + 1][entity.x];
                _map[entity.y + 1][entity.x] = 'G';
            }
        }
    }
    
}

/**
 * @brief It moves the player down
 * 
 * @param entity the entity to move
 */
void arcade::game::Pacman::mooveDown(vector2i_t entity)
{
    if (_map[entity.y][entity.x] == 'P') {
        _map[_posEntityPac.y][_posEntityPac.x] = ' ';
        _posEntityPac.x += 0;
        _posEntityPac.y += -1;
        _map[_posEntityPac.y][_posEntityPac.x] = 'P';
    } else {
        if (_map[entity.y - 1][entity.x] != 'W' && _map[entity.y - 1][entity.x] != 'G') {
            if (_map[entity.y - 1][entity.x] == ' ') {
                _map[entity.y][entity.x] = ' ';
                _map[entity.y - 1][entity.x] = 'G';
            } else {
                char a = _temp;
                _map[entity.y][entity.x] = a;
                _temp = _map[entity.y - 1][entity.x];
                _map[entity.y - 1][entity.x] = 'G';
            }
        }
    }
     
}

/**
 * @brief It teleports the player from one side of the map to the other
 * 
 * @param entity The position of the entity on the map.
 * @param orientation the direction the entity is moving in
 */
void arcade::game::Pacman::TPEntity(vector2i_t entity, orientation_t orientation)
{
    (void) entity;
    if (_posEntityPac.x == 1 && _posEntityPac.y == 9 && orientation == ELEFT) {
        _map[9][1] = ' ';
        _map[9][31] = 'P';
        _posEntityPac.x = 31;
        _posEntityPac.y = 9;
    }
    if (_posEntityPac.x == 31 && _posEntityPac.y == 9 && orientation == ERIGHT) {
        _map[9][1] = 'P';
        _map[9][31] = ' ';
        _posEntityPac.x = 1;
        _posEntityPac.y = 9;
    }
}