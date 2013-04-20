#include "Controller.hpp"
#include <iostream>

Controller::Controller():QWidget() {
}
void Controller::set(Mixer * m, Screens * s, Calibrator * c, Model * md) {
    mixer = m;
    screens = s;
    calibrator = c;
    model = md;

    mode = WORKING;
    mixValue = 0;
   // mixer->updateMixModeLabel();
    connectItems();
    calibrateNear();
    poller=new QTimer(this);
    connect(poller, SIGNAL(timeout()), this, SLOT(updateInterface()));
    poller->start(100);
}

Controller::~Controller() {
    poller->stop();
    delete(poller);
}

void Controller::connectItems() {
    connect(mixer->getModeSelectorBoxWidget(MIXMODE_STILL),SIGNAL(clicked()),this,SLOT(mixmodeStill()));
    connect(mixer->getModeSelectorBoxWidget(MIXMODE_CONTINUOUS),SIGNAL(clicked()),this,SLOT(mixmodeContinuous()));
    connect(mixer->getModeSelectorBoxWidget(MIXMODE_LIVE),SIGNAL(clicked()),this,SLOT(mixmodeLive()));    
    connect(mixer->getControlWidget(),SIGNAL(sliderMoved(int)),this,SLOT(mix(int)));    
    connect(mixer->getControlWidget(),SIGNAL(valueChanged(int)),this,SLOT(mix(int)));    
    connect(mixer->getRangeWidget(),SIGNAL(sliderMoved(int)),this,SLOT(updateRange(int)));
    connect(mixer->getRangeWidget(),SIGNAL(valueChanged(int)),this,SLOT(updateRange(int)));
    connect(calibrator->getModeSelectorBoxWidget(WORKING),SIGNAL(clicked()),this,SLOT(calibrateWorking()));
    connect(calibrator->getModeSelectorBoxWidget(NEAR),SIGNAL(clicked()),this,SLOT(calibrateNear()));
    connect(calibrator->getModeSelectorBoxWidget(MIDDLE),SIGNAL(clicked()),this,SLOT(calibrateMiddle()));    
    connect(calibrator->getModeSelectorBoxWidget(FAR),SIGNAL(clicked()),this,SLOT(calibrateFar()));
    
}

// todo esto y los connect se pueden ir, ya que mixer puede preguntarle a sus boxes, no?
void Controller::mixmodeStill(){
    mixer->setStill();
}

void Controller::mixmodeContinuous(){
    mixer->setContinuous();
}

void Controller::mixmodeLive(){
    mixer->setLive();
}

int Controller::convert(QString s) {
    bool ok;
    double i =s.toDouble(&ok);
    if (! ok) throw 1;
    return i;
}
void Controller::calibrateWorking() {
    try {
        model->setNear(
            convert(calibrator->getDistanceValue(NEAR)),
            convert(calibrator->getTicksValue(NEAR))
        );
    } catch (int e) {
        calibrateNear();
        return;
    }
    try {
        model->setMiddle(
            convert(calibrator->getDistanceValue(MIDDLE)),
            convert(calibrator->getTicksValue(MIDDLE))
        );
    } catch (int e) {
        calibrateMiddle();
        return;
    }
    try {
        model->setFar(
            convert(calibrator->getDistanceValue(FAR)),
            convert(calibrator->getTicksValue(FAR))
        );
    } catch (int e) {
        calibrateFar();
        return;
    }

    mode= WORKING;
    calibrator->setAllReadOnlyBut(WORKING);
    
    model->prepare();
//     std::cout  << "A: " << model->a[0][0]  << "   " << model->a[0][1] << "   " << model->a[0][2] << std::endl;
//     std::cout  << "A: " << model->a[1][0]  << "   " << model->a[1][1] << "   " << model->a[1][2] << std::endl;
//     std::cout  << "A: " << model->a[2][0]  << "   " << model->a[2][1] << "   " << model->a[2][2] << std::endl;
//     std::cout  << "B: " << model->b[0]  << "   " << model->b[1] << "   " << model->b[2] << std::endl;
// 
//     std::cout  << "a: " << model->r[0]  << "b: " << model->r[1] << "c: " << model->r[2] << std::endl;
}

void Controller::calibrateNear() {
    mode= NEAR;
    calibrator->setAllReadOnlyBut(mode);
}

void Controller::calibrateMiddle() {
    mode= MIDDLE;
    calibrator->setAllReadOnlyBut(mode);
}

void Controller::calibrateFar() {
    mode= FAR;
    calibrator->setAllReadOnlyBut(mode);
}



void Controller::updateRange(int value) {
    mixer->updateRange(value);
}

void Controller::mix(int value){
    mixValue=value;
    
    if (mixer->isLive() || ! mixer->isSampled()) {
        screens->grabWindows();
        mixer->setSampled(true); 
    }
    screens->mix(value);
    
    calibrator->setTicksValue((OpMode)mode,(QString::number(value)));
    calibrator->setDistanceValue(WORKING,QString::number(model->calculate(value)));
}
void Controller::updateInterface()
{
    screens->resize();
    if (mixer->isLive()) {
        mix(mixValue);   
    }
}
