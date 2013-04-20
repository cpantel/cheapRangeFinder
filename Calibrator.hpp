#ifndef CALIBRATOR_HPP
#define CALIBRATOR_HPP

#include <QButtonGroup>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>

#include "symbols.hpp"

class Calibrator {
private:
    QWidget * parent;
    QButtonGroup * functionSelector;
    QCheckBox * modeSelectorBox[OPMODE_END];
    QLabel * ticksValue[OPMODE_END];
    QLineEdit * distanceValue[OPMODE_END];

public:
    Calibrator(QWidget *parent);
    ~Calibrator();
    QWidget * getModeSelectorBoxWidget(OpMode pos);
    QString getTicksValue(OpMode pos);
    QString getDistanceValue(OpMode pos);
    QWidget * getTicksWidget(OpMode pos);
    QWidget * getDistanceWidget(OpMode pos);
    void setTicksValue(OpMode pos, QString value);
    void setDistanceValue(OpMode pos, QString value);
    void setAllReadOnlyBut(int mode);
};

#endif // CALIBRATOR_HPP