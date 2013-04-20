#include "Calibrator.hpp"
#include "symbols.hpp"
Calibrator::Calibrator(QWidget *parent2) {
    parent = parent2;

    functionSelector = new QButtonGroup(parent);

    modeSelectorBox[WORKING] = new QCheckBox("Ready", parent);
    modeSelectorBox[NEAR]    = new QCheckBox("Near", parent);
    modeSelectorBox[MIDDLE]  = new QCheckBox("Middle", parent);
    modeSelectorBox[FAR]     = new QCheckBox("Far", parent);

    for(int pos = WORKING; pos<OPMODE_END; ++pos) {
        ticksValue[pos] = new QLabel("?",parent);
        distanceValue[pos] = new QLineEdit("0",parent);
        functionSelector->addButton(modeSelectorBox[pos]);
    }

    modeSelectorBox[NEAR]->setChecked(true);
    functionSelector->setExclusive(true);

    for(int pos = WORKING; pos<OPMODE_END; ++pos) {
        distanceValue[pos]->setMinimumHeight(28);
        distanceValue[pos]->setMaximumHeight(28);
        distanceValue[pos]->setMinimumWidth(90);
        distanceValue[pos]->setMaximumWidth(90);
        distanceValue[pos]->setMaxLength(12);
        distanceValue[pos]->setReadOnly(true);
    }
}

void Calibrator::setTicksValue(OpMode pos, QString value){
    ticksValue[pos]->setText(value);
}

void Calibrator::setDistanceValue(OpMode pos, QString value){
    distanceValue[pos]->setText(value);
}

QWidget * Calibrator::getModeSelectorBoxWidget(OpMode pos) {
    return modeSelectorBox[pos];
}

QWidget * Calibrator::getTicksWidget(OpMode pos) {
    return ticksValue[pos];
}

QWidget * Calibrator::getDistanceWidget(OpMode pos){
    return distanceValue[pos];
}

QString Calibrator::getTicksValue(OpMode pos){
    return ticksValue[pos]->text();
}

QString Calibrator::getDistanceValue(OpMode pos){
    return distanceValue[pos]->text();
}

void Calibrator::setAllReadOnlyBut(int mode) {
    for(int pos = WORKING;pos<OPMODE_END; ++pos) {
        if (pos == mode ) {
            distanceValue[mode]->setReadOnly(false);
            modeSelectorBox[mode]->setChecked(true);
        } else {
            distanceValue[pos]->setReadOnly(true);
        }
    }
}

Calibrator::~Calibrator() {
    delete(functionSelector);
    for(int pos = WORKING; pos<OPMODE_END; ++pos) {
       delete(ticksValue[pos]);
       delete(modeSelectorBox[pos]);
    }
}
