#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <QTimer>
#include <QString>
#include <QWidget>
#include "Calibrator.hpp"
#include "Mixer.hpp"
#include "Screens.hpp"
#include "Model.hpp"

class Controller: public QWidget {
    Q_OBJECT
private:
    Mixer * mixer;
    Screens * screens;
    Calibrator * calibrator;
    QTimer *poller;
    Model * model;
    int mode;
    int convert(QString s);
    int mixValue;
public:
    void set(Mixer * m, Screens * s, Calibrator * c, Model * md);
    Controller();
    ~Controller();
    void connectItems();
;

public slots:
    void updateInterface();
    void mix(int);
    void updateRange(int);
    void calibrateWorking();
    void calibrateNear();
    void calibrateMiddle();
    void calibrateFar();
    void mixmodeStill();
    void mixmodeContinuous();
    void mixmodeLive();
};

#endif // CONTROLLER_HPP