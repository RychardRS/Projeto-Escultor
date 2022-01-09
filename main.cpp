#include "escultor.h"
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>

int main(void){

    Escultor *v3;
    int a = 150, b= 150, c = 150;

    v3 = new Escultor(a,b,c);

    v3->setColor(80,40,10,1);
    v3->putBox(0,50,0,1,0,30); // piso

    v3->setColor(255,0,0,1);
    // A SEGUIR TEMOS OS BURACOS NA MESA DE SINUCA
    v3->cutBox(1,1,0,0,1,1);
    v3->cutBox(1,1,1,1,1,1);
    v3->cutBox(1,1,0,0,29,29);
    v3->cutBox(1,1,1,1,29,29);
    v3->cutBox(49,49,0,0,29,29);
    v3->cutBox(49,49,1,1,29,29);
    v3->cutBox(49,49,0,0,1,1);
    v3->cutBox(49,49,1,1,1,1);
    v3->cutBox(24,26,0,0,1,1);
    v3->cutBox(25,25,1,1,1,1);
    v3->cutBox(24,26,0,0,29,29);
    v3->cutBox(25,25,1,1,29,29);
    v3->cutBox(25,25,0,0,1,1);
    // A SEGUIR TEMOS OS AJUSTES PARA A BOLA ENTRAR NO BURACO DAS MESAS
    v3->cutBox(2,2,0,0,1,1);
    v3->cutBox(1,1,0,0,2,2);
    v3->cutBox(1,1,0,0,28,28);
    v3->cutBox(2,2,0,0,29,29);
    v3->cutBox(48,48,0,0,1,1);
    v3->cutBox(49,49,0,0,2,2);
    v3->cutBox(49,49,0,0,28,28);
    v3->cutBox(48,48,0,0,29,29);

    v3->setColor(0,0,0,1);
    // A SEGUIR TEMOS AS PERNAS DA MESA DE SINUCA
    v3->putBox(3,4,2,15,0,1);
    v3->putBox(3,4,2,15,29,30);
    v3->putBox(46,47,2,15,0,1);
    v3->putBox(46,47,2,15,29,30);
    // A SEGUIR TEMOS O CONTROLE DO PISO PRA FAZER A MESA DA BOLA
    v3->cutBox(2,48,0,0,2,28);
    // A SEGUIR TEMOS A COLORAÇÃO DA MESA DA BOLA
    v3->setColor(0,70,0,1);
    v3->putBox(2,48,1,1,2,28);

    v3->writeOFF((char*)"mesadesinuca.off");


}
