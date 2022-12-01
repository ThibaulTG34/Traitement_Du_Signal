#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include "Wave.cpp"

/*
x_n = a*e_n + b
-1 = a*0 + b --> b = -1
1 = a*255 + b --> a = 1/255

double x, f = 2/255;
char e;
x = ((double)e*f) - 1
e = (unsigned char)floor((x-1.0) - 127.5)

LA (440Hz):
T = 1/440 s
Tau = 1/f_e , f_e = 44100 Hz
x_k = sin(2PI*f_la*k*Tau) = sin(2PI*(f_la/f_e)*k)
s(t) = sin(2PI*f_la*t)
*/

double char_vers_double(unsigned char e){
    double f = 1.0/127.5;
    return ((double)e*f) - 1.0;
}

unsigned char double_vers_char(double x){
    x = (x + 1.0)*127.5;
    x = x<0.0 ? 0.0 : x;
    x = x>255.0 ? 255.0 : x;
    return (unsigned char)std::floor(x);
}

void creation_note(double f_note, int nbEchantillon, double f_e, double* echant) {
    
    double T = 1/f_note;
    double Tau = 1/f_e;
    double k = t*f_e;
    
    for(size_t i=0; i<k; i++) {
        echant[i] = sin(2*M_PI*(f_note/f_e)*i);
    }

}


int main () {
    
	double* echantillon = new double[1000];
    creation_note(440, 1000, 44100, echantillon);

}