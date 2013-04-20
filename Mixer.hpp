#ifndef MIXER_HPP
#define MIXER_HPP

#include <QSlider>
#include <QDial>
#include <QCheckBox>
#include <QLabel>
#include <QToolButton>
#include <QButtonGroup> 
#include "symbols.hpp"

class Mixer {
private:
    QWidget * parent;
    bool sampled;
    QLabel   * rangeDisplay;
    QButtonGroup * functionSelector;

    QCheckBox * modeSelectorBox[MIXMODE_END];
    QSlider * range;
    QDial * control;
    int rangeSpan;
    MixMode mixMode;

public:
    Mixer(QWidget * parent);
    ~Mixer();
    void setStill();
    void setContinuous();
    void setLive();
    void setSampled(bool);
    bool isSampled();
    QWidget * getRangeDisplayWidget();
    QWidget * getRangeWidget();
    QWidget * getControlWidget();
    QWidget * getModeSelectorBoxWidget(MixMode pos);
    void updateRange(int);
    bool isLive();
    bool isStill();
    bool isContinuous();
};

#endif // MIXER_HPP