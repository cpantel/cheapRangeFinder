#ifndef PLAYER_H
#define PLAYER_H

#include "Screens.hpp"
#include "Mixer.hpp"
#include "Calibrator.hpp"
#include "View.hpp"
#include "Controller.hpp"
#include "Model.hpp"

#include "symbols.hpp"

class Player
{

private:
    Screens * screens;
    Mixer * mixer;
    Calibrator * calibrator;
    View * view;
    Model * model;
    Controller * controller;

public:
    Player();
    ~Player();
    void play(QString sourceLeft, QString sourceRight);
    void resize(int x,int y);
    void show();
};
#endif