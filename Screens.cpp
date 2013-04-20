

#include "Screens.hpp"

#define SCREEN_HEIGHT 240
#define SCREEN_WIDTH 320


Screens::Screens(QWidget * p)
{
    parent = p;
    const char * const vlc_args[] = {
              "--extraintf=logger",
              "--verbose=2",
              "--no-audio"
              
    };

    screen[LEFT]=new QFrame(parent);
    screen[RIGHT]=new QFrame(parent);


    screenMixer = new QLabel(parent);
    
    for(int pos = LEFT; pos<=RIGHT; ++pos) {
        vlcInstance[pos] = libvlc_new(sizeof(vlc_args) / sizeof(vlc_args[0]), vlc_args);
        mediaPlayer[pos] = libvlc_media_player_new (vlcInstance[pos]);
    }
    
    screenMixer->setMinimumHeight(SCREEN_HEIGHT);
    screenMixer->setMaximumHeight(SCREEN_HEIGHT);
    screenMixer->setMinimumWidth(SCREEN_WIDTH);
    screenMixer->setMaximumWidth(SCREEN_WIDTH);   
    screenMixer->resize(SCREEN_WIDTH, SCREEN_HEIGHT); 

    for(int pos = LEFT; pos<=RIGHT; ++pos) {
        screen[pos]->setMinimumHeight(SCREEN_HEIGHT);
        screen[pos]->setMaximumHeight(SCREEN_HEIGHT);
        screen[pos]->setMinimumWidth(SCREEN_WIDTH);
        screen[pos]->setMaximumWidth(SCREEN_WIDTH);  
        screen[pos]->resize(SCREEN_WIDTH, SCREEN_HEIGHT);
    }
    
    imageMixer = QImage(screen[LEFT]->size(), QImage::Format_ARGB32_Premultiplied);
    painter = new QPainter(&imageMixer);
    painter->setOpacity(0.5);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
}

void Screens::play(QString sourceLeft, QString sourceRight) {

    QString source[2] = { sourceLeft, sourceRight };
    for(int pos = LEFT; pos<=RIGHT; ++pos) {
        media[pos] = libvlc_media_new_path(vlcInstance[pos], source[pos].toAscii());
        libvlc_media_player_set_media (mediaPlayer[pos], media[pos]);
        libvlc_media_player_set_xwindow (mediaPlayer[pos], screen[pos]->winId() );
        libvlc_media_player_play (mediaPlayer[pos]);
    }
}
void Screens::grabWindows(){
    pixmap[LEFT] = QPixmap::grabWindow(screen[LEFT]->winId());
    pixmap[RIGHT] = QPixmap::grabWindow(screen[RIGHT]->winId());
}

void Screens::mix(int value){
    painter->drawImage(- value,0,pixmap[LEFT].toImage());
    painter->drawImage( value,0,pixmap[RIGHT].toImage());
    
    screenMixer->setPixmap(QPixmap::fromImage(imageMixer));    
}

QLabel * Screens::getScreenMixerWidget(){
    return screenMixer;
}

void Screens::resize(){
    screenMixer->resize(screen[LEFT]->size());
}

QWidget * Screens::getScreenWidget(Positions pos){
    return screen[pos];
}

Screens::~Screens()
{
    painter->end();
    delete(painter);
    for(int pos = LEFT; pos<=RIGHT; ++pos) {
        libvlc_media_player_stop (mediaPlayer[pos]);
        libvlc_media_player_release (mediaPlayer[pos]);
        libvlc_release (vlcInstance[pos]);    
    }
    delete(screenMixer);
    
    for(int pos = LEFT; pos<=RIGHT; ++pos) {
        delete(screen[pos]);    
    }
}