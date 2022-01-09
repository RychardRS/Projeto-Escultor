#include "escultor.h"
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>

int main(void){

    Escultor *vox;
    int a = 150, b= 150, c = 150;

    vox = new Escultor(a,b,c);

    vox->setColor(100,100,50,1);
    vox->putBox(0,50,0,1,0,30); // piso

    vox->setColor(255,0,0,1);
    // A SEGUIR TEMOS OS BURACOS NA MESA DE SINUCA
    vox->cutBox(1,1,0,0,1,1);
    vox->cutBox(1,1,1,1,1,1);
    vox->cutBox(1,1,0,0,29,29);
    vox->cutBox(1,1,1,1,29,29);
    vox->cutBox(49,49,0,0,29,29);
    vox->cutBox(49,49,1,1,29,29);
    vox->cutBox(49,49,0,0,1,1);
    vox->cutBox(49,49,1,1,1,1);
    vox->cutBox(24,26,0,0,1,1);
    vox->cutBox(25,25,1,1,1,1);
    vox->cutBox(24,26,0,0,29,29);
    vox->cutBox(25,25,1,1,29,29);
    vox->cutBox(25,25,0,0,1,1);
    // A SEGUIR TEMOS OS AJUSTES PARA A BOLA ENTRAR NO BURACO DAS MESAS
    vox->cutBox(2,2,0,0,1,1);
    vox->cutBox(1,1,0,0,2,2);
    vox->cutBox(1,1,0,0,28,28);
    vox->cutBox(2,2,0,0,29,29);
    vox->cutBox(48,48,0,0,1,1);
    vox->cutBox(49,49,0,0,2,2);
    vox->cutBox(49,49,0,0,28,28);
    vox->cutBox(48,48,0,0,29,29);

    vox->setColor(150,150,120,1);
    // A SEGUIR TEMOS AS PERNAS DA MESA DE SINUCA
    vox->putBox(3,4,2,15,0,1);
    vox->putBox(3,4,2,15,29,30);
    vox->putBox(46,47,2,15,0,1);
    vox->putBox(46,47,2,15,29,30);
    // A SEGUIR TEMOS O CONTROLE DO PISO PRA FAZER A MESA DA BOLA
    vox->cutBox(2,48,0,0,2,28);
    // A SEGUIR TEMOS A COLORAÇÃO DA MESA DA BOLA
    vox->setColor(0,160,0,1);
    vox->putBox(2,48,1,1,2,28);
    // A SEGUIR TEMOS A BOLA DA SINUCA
    vox->setColor(0,0,0,1);
    vox->putEllipsoid(25,0,15,1,1,0);
    vox->cutEllipsoid(24,0,15,0,0,0);


    vox->writeOFF((char*)"mesadesinuca.off");


}
