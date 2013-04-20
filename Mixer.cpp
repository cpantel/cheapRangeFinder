#include "Mixer.hpp"

Mixer::Mixer(QWidget * parent2) {
    parent = parent2;
    rangeDisplay = new QLabel(parent);
    functionSelector = new QButtonGroup(parent);

    modeSelectorBox[MIXMODE_STILL] = new QCheckBox("Still", parent);
    modeSelectorBox[MIXMODE_CONTINUOUS]    = new QCheckBox("Continuous", parent);
    modeSelectorBox[MIXMODE_LIVE]  = new QCheckBox("Live", parent);

    for(int pos = MIXMODE_STILL; pos<MIXMODE_END; ++pos) {
        functionSelector->addButton(modeSelectorBox[pos]);
    }
    
    modeSelectorBox[MIXMODE_STILL]->setChecked(true);
    functionSelector->setExclusive(true);

    range = new QSlider(Qt::Horizontal,parent);
    control = new QDial(parent);

    mixMode = MIXMODE_LIVE;
    sampled = false;     

    range->setMinimum(50);
    range->setMaximum(300);
    range->setValue(50);
    
    rangeSpan = 50;
    control->setMinimum(- rangeSpan);
    control->setMaximum(rangeSpan);
    
    control->setValue(0);
}

Mixer::~Mixer(){
    delete(rangeDisplay);
//     for(int pos = MIXMODE_STILL; pos<MIXMODE_END; ++pos) {
//         delete(modeSelectorBox);
//     }
    delete(range);
    delete(control);
}

void Mixer::setStill(){
    mixMode = MIXMODE_STILL;
}
void Mixer::setContinuous(){
    mixMode = MIXMODE_CONTINUOUS;
}
void Mixer::setLive(){
    mixMode = MIXMODE_LIVE;
}

bool Mixer::isLive() {
   return (mixMode == MIXMODE_LIVE);
}

bool Mixer::isStill() {
   return (mixMode == MIXMODE_STILL);
}

bool Mixer::isContinuous() {
   return (mixMode == MIXMODE_CONTINUOUS);
}



void Mixer::updateRange(int value) {
    control->setMinimum(-value);
    control->setMaximum(value);
    rangeDisplay->setText(QString::number(value));
}
    
QWidget *  Mixer::getRangeDisplayWidget(){
    return rangeDisplay;
}

QWidget *  Mixer::getRangeWidget(){
    return range;
}

QWidget *  Mixer::getControlWidget(){
    return control;
}

QWidget * Mixer::getModeSelectorBoxWidget(MixMode pos) {
    return modeSelectorBox[pos];
}

void Mixer::setSampled(bool s){
    sampled = s;
}
bool Mixer::isSampled(){
    return sampled;
}