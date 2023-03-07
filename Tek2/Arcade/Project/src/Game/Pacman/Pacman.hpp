/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Pacman
*/

#ifndef PACMAN_HPP
#define PACMAN_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include "AGame.hpp"
#include "game_object.hpp"

namespace arcade {
    namespace game { 

        typedef enum entity_s {
            BEINVINIBLE = 20
        } entity_t;

        class Pacman : public AGame {
            public:
                Pacman();
                ~Pacman();
                const std::vector<arcade::game_object_t> getPendingItems() const;
                void simulate();
                void doPendingEvent(std::vector<arcade::event_t> &);
                const arcade::game_object_t getBackground() const;
                void reset();
                arcade::game_status_t getGameStatus() const;
                const std::vector<arcade::text_object_t> getPendingTexts() const;
                void initGame();
                void destroyGame();

            protected:
                bool isGameOver(bool _isGameOver);

                void loadMap(char const *path);
                void deleteMap();
                arcade::game_object_t makeEntity();

                std::vector<arcade::game_object_t> loadEntity(std::vector<arcade::game_object_t> &);


                bool isAPoint(vector2i_t posNextentity);
                bool isACherry(vector2i_t posNextentity);
                bool isInvincible();
                bool isAGhost(vector2i_t posNextentity);
                bool isATp(vector2i_t posNextentity);
                bool isAWall(vector2i_t posNextentity);
                bool isEatbyGhost(vector2i_t posNextentity);
                bool isEataGhost(vector2i_t posNextentity);
                bool isAlive() const;
                bool isWin() const;
                bool isEmptyCase(vector2i_s posNextentity);

                vector2i_t getNextEntity(vector2i_t entity, orientation_t orientation);

                void upgradePoints();

                bool checkNextMoove(vector2i_t &entity, orientation_t orientation);

                void makeMoovPac(vector2i_t &entity);
                void makeMoovGhost(vector2i_t entity);
                void moove(vector2i_t entity, orientation_t orientation);

                void mooveLeft(vector2i_t posEntity);
                void mooveRight(vector2i_t posEntity);
                void mooveUp(vector2i_t posEntity);
                void mooveDown(vector2i_t posEntity);
                
                void TPEntity(vector2i_t posEntity, orientation_t orientation);

                void addPoints(char c);
                void killGhost(vector2i_t &entity);



            private:
                bool _isGameOver;

                char _map[21][34];

                int _timeToBeInvicible;
                int _opeeeen;
                int _points;
                int _life;
                arcade::orientation_t _direction;
                std::size_t _animation;
                std::vector<arcade::game_object_t> _mapVector;
                vector2i_t _posEntityPac;
                char _temp;

        };
    };
};

#endif /* !PACMAN_HPP */
