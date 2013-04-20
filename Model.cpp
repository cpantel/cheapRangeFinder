#include "Model.hpp"

void Model::setNear(double distance, double ticks){
    a[0][0] = ticks * ticks;
    a[0][1] = ticks;
    a[0][2]=1;
    
    b[0] = distance;
}

void Model::setMiddle(double distance, double ticks){
    a[1][0] = ticks * ticks;
    a[1][1] = ticks;
    a[1][2] = 1;
    
    b[1] = distance;
}
void Model::setFar(double distance, double ticks){
    a[2][0] = ticks * ticks;
    a[2][1] = ticks;
    a[2][2] = 1;
    
    b[2] = distance;
}

double Model::calculate(double ticks) {
    return ticks*ticks*r[0] + ticks * r[1] + r[2];
}

/*
DET  =  a00(a22a11-a21a12)
       -a10(a22a01-a21a02)
       +a20(a12a01-a11a02)

|a00 a01 a02|-1  |  a22a11-a21a12 -(a22a01-a21a02)  a12a01-a11a02 |
|a10 a11 a12|  = |-(a22a10-a20a12)  a22a00-a20a02 -(a12a00-a10a02)|/DET
|a20 a21 a22|    |  a21a10-a20a11 -(a21a00-a20a01)  a11a00-a10a01 |
*/
void Model::prepare(){
   det = a[0][0] * (a[2][2] * a[1][1] - a[2][1] * a[1][2])
       - a[1][0] * (a[2][2] * a[0][1] - a[2][1] * a[0][2])
       + a[2][0] * (a[1][2] * a[0][1] - a[1][1] * a[0][2]);
       
   i[0][0] =   (a[2][2]*a[1][1] -a[2][1]*a[1][2]) / det;
   i[0][1] = - (a[2][2]*a[0][1] -a[2][1]*a[0][2]) / det;
   i[0][2] =   (a[1][2]*a[0][1] -a[1][1]*a[0][2]) / det;
      
   i[1][0] = - (a[2][2]*a[1][0] -a[2][0]*a[1][2]) / det;
   i[1][1] =   (a[2][2]*a[0][0] -a[2][0]*a[0][2]) / det;
   i[1][2] = - (a[1][2]*a[0][0] -a[1][0]*a[0][2]) / det;

   i[2][0] =   (a[2][1]*a[1][0] -a[2][0]*a[1][1]) / det;
   i[2][1] = - (a[2][1]*a[0][0] -a[2][0]*a[0][1]) / det;
   i[2][2] =   (a[1][1]*a[0][0] -a[1][0]*a[0][1]) / det;
                     
   r[0] = i[0][0] * b[0] + i[0][1] * b[1] + i[0][2] * b[2];
   r[1] = i[1][0] * b[0] + i[1][1] * b[1] + i[1][2] * b[2];
   r[2] = i[2][0] * b[0] + i[2][1] * b[1] + i[2][2] * b[2];
}