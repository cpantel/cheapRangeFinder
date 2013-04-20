#ifndef VIEW_HPP
#define VIEW_HPP

#include <QGroupBox>

#include <QVBoxLayout>

#include "Calibrator.hpp"
#include "Mixer.hpp"
#include "Screens.hpp"

class View
{
private:
    Mixer * mixer;
    Screens * screens;
    Calibrator * calibrator;

    QGroupBox * displayBox;
    QGroupBox * commandBox;
    QGroupBox * calibrationBox;
    QGroupBox * mixerModeBox;
    QHBoxLayout * commandBoxLayout;
    QHBoxLayout * displayBoxLayout;
    QGridLayout * calibrationBoxLayout;
    QGridLayout * mixerBoxLayout;
    QVBoxLayout * layout;

public:
    View(Mixer * m, Screens * s, Calibrator * c);
    QVBoxLayout * getLayout();
    ~View();

};
#endif // VIEW_HPP
