#ifndef SCREENS_HPP
#define SCREENS_HPP

#include <vlc/vlc.h>

#include <QLabel>
#include <QFrame>
#include <QString>
#include <QWidget>

#include <QPainter>

#include "symbols.hpp"

class Screens
{

private:

    QPainter * painter;
    QPixmap pixmap[2];
    QWidget * parent;
    libvlc_instance_t *vlcInstance[2];
    libvlc_media_player_t *mediaPlayer[2];
    libvlc_media_t *media[2];
    QImage imageMixer;
    QLabel   *screenMixer;

    QFrame *screen[2];



public:
    void play(QString sourceLeft, QString sourceRight);
    void grabWindows();
    void mix(int value);
    void resize();
    QLabel * getScreenMixerWidget();
    QWidget * getScreenWidget(Positions pos);
    Screens(QWidget * parent);

    ~Screens();

};

#endif // SCREENS_HPP