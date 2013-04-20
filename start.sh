#!/bin/sh
FPS=5
#FPS=10
#FPS=15
#FPS=30
#WIDTH=160; HEIGHT=120;
WIDTH=176; HEIGHT=144;
#WIDTH=320; HEIGHT=240;
#WIDTH=352; HEIGHT=288;
#WIDTH=640; HEIGHT=480;

CHROMA=":chroma=MJPG"

OPTIONS=":width=${WIDTH}:height=${HEIGHT}${CHROMA}:fps=${FPS}"
DEVICE1=1
DEVICE2=2
#./cheapDistanceMeteringSystem "v4l2:///dev/video${DEVICE1}${OPTIONS}" "v4l2:///dev/video${DEVICE2}${OPTIONS}"
./cheapDistanceMeteringSystem "samples/left1.mp4"  "samples/right1.mp4"

#     ./cheapDistanceMeteringSystem "http://192.168.1.105"  "http://192.168.1.109"
