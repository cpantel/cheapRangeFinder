#include <QtGui/QApplication>
#include "Player.hpp"
#include <iostream>

using namespace std;

void showHelp(char * name) {
    cout << "Usage: " << name << " left_source right_source"<< endl;
    cout << endl;
    cout << "    v4l2:///dev/video0" << endl;
    cout << "    [file://]filename              Plain media file" << endl;
    cout << "    http://ip:port/file            HTTP URL" << endl;
    cout << "    ftp://ip:port/file             FTP URL" << endl;
    cout << "    mms://ip:port/file             MMS URL" << endl;
    cout << "    [dvd://][device][@raw_device]  DVD device" << endl;
    cout << "    [vcd://][device]               VCD device" << endl;
    cout << "    [cdda://][device]              Audio CD device" << endl;
    cout << "    udp:[[<source address>]@[<bind address>][:<bind port>]]" << endl;

}
int main(int argc, char *argv[]) {
    if (argc == 1) {
        showHelp(argv[0]);
        return 255;
    }

    if (argc != 3 ) {
        cout << "Bad arguments" << endl;
        return 1;
    }

    QApplication app(argc,argv);
    Player player;
    player.resize(960,720);
    player.play(argv[1],argv[2]);
    player.show();
    return app.exec();
}


