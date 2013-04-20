#ifndef SYMBOLS_HPP
#define SYMBOLS_HPP

    enum OpMode {
        WORKING=0,
        NEAR=1,
        MIDDLE=2,
        FAR=3,
        OPMODE_END=4
    };
    enum MixMode {
        MIXMODE_STILL=0,
        MIXMODE_CONTINUOUS=1,
        MIXMODE_LIVE=2,
        MIXMODE_END=3
    };

    enum Positions {
        LEFT=0,
        RIGHT=1,
        CENTER=2
    };

#endif // SYMBOLS_HPP