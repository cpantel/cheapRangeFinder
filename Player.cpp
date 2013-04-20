#include "Player.hpp"

#define COMMANDBUTTON_SWITCHMIXMODE 0

Player::Player()
{
    controller = new Controller();

    screens = new Screens(controller);
    mixer = new Mixer(controller);
    calibrator = new Calibrator(controller);
    model = new Model();
    view = new View(mixer, screens, calibrator);
    controller->set(mixer,screens,calibrator, model);
    controller->setLayout(view->getLayout());
}

void Player::resize(int x, int y) {
    controller->resize(x,y);
}

void Player::show(){
    controller->show();
}

Player::~Player(){
    delete(screens);
    delete(mixer);
    delete(calibrator);
    delete(view);
    delete(model);
    delete(controller);
}

void Player::play(QString sourceLeft, QString sourceRight)
{
    screens->play(sourceLeft, sourceRight);
}


