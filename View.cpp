#include <QToolButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QGridLayout>

#include "View.hpp"
#include "symbols.hpp"

View::View(Mixer * m, Screens * s, Calibrator * c){
    mixer = m;
    screens = s;
    calibrator = c;
}

QVBoxLayout * View::getLayout(){
    displayBox = new QGroupBox;
    commandBox = new QGroupBox;
    calibrationBox = new QGroupBox;
    mixerModeBox = new QGroupBox;

    commandBoxLayout = new QHBoxLayout;
    displayBoxLayout = new QHBoxLayout;
    calibrationBoxLayout = new QGridLayout;
    layout = new QVBoxLayout;

    calibrationBoxLayout->addWidget(calibrator->getDistanceWidget(WORKING),0,0);
    calibrationBoxLayout->addWidget(calibrator->getDistanceWidget(NEAR),1,0);
    calibrationBoxLayout->addWidget(calibrator->getDistanceWidget(MIDDLE),2,0);
    calibrationBoxLayout->addWidget(calibrator->getDistanceWidget(FAR),3,0);
    calibrationBoxLayout->addWidget(calibrator->getTicksWidget(WORKING),0,1);
    calibrationBoxLayout->addWidget(calibrator->getTicksWidget(NEAR),1,1);
    calibrationBoxLayout->addWidget(calibrator->getTicksWidget(MIDDLE),2,1);
    calibrationBoxLayout->addWidget(calibrator->getTicksWidget(FAR),3,1);
    calibrationBoxLayout->addWidget(calibrator->getModeSelectorBoxWidget(WORKING),0,2);       
    calibrationBoxLayout->addWidget(calibrator->getModeSelectorBoxWidget(NEAR),1,2);        
    calibrationBoxLayout->addWidget(calibrator->getModeSelectorBoxWidget(MIDDLE),2,2);
    calibrationBoxLayout->addWidget(calibrator->getModeSelectorBoxWidget(FAR),3,2);
        
    mixerBoxLayout = new QGridLayout;

    mixerBoxLayout->addWidget(mixer->getModeSelectorBoxWidget(MIXMODE_STILL),0,0);
    mixerBoxLayout->addWidget(mixer->getModeSelectorBoxWidget(MIXMODE_CONTINUOUS),1,0);
    mixerBoxLayout->addWidget(mixer->getModeSelectorBoxWidget(MIXMODE_LIVE),2,0);
    
    displayBoxLayout->addWidget(screens->getScreenWidget(LEFT));
    displayBoxLayout->addWidget(screens->getScreenMixerWidget());
    displayBoxLayout->addWidget(screens->getScreenWidget(RIGHT));
    
    commandBox->setLayout(commandBoxLayout);
    displayBox->setLayout(displayBoxLayout);
    calibrationBox->setLayout(calibrationBoxLayout);
    mixerModeBox->setLayout(mixerBoxLayout);
    
    commandBoxLayout->addWidget(mixerModeBox);
    commandBoxLayout->addWidget(mixer->getRangeWidget());
    commandBoxLayout->addWidget(mixer->getRangeDisplayWidget());
    commandBoxLayout->addWidget(mixer->getControlWidget());

    commandBoxLayout->addWidget(calibrationBox);
    
    layout->addWidget(displayBox);

    layout->addWidget(commandBox);
    return layout;
}

View::~View(){
    delete(displayBox);
    delete(commandBox);
//    delete(calibrationBox);
//     delete(commandBoxLayout);
//     delete(displayBoxLayout);
//    delete(calibrationBoxLayout);
//    delete(layout);

}