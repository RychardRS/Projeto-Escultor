#include "escultor.h"
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

// AQUI TEMOS A PARTE MAIS IMPORTANTE DO C�DIGO

using namespace std;

Escultor::Escultor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny; // come�amos criando a classe construtor do escultor
    nz = _nz;


    v= new Voxel**[nz]; // cria��o do Voxel na forma ponteiro para ponteiro

    v[0] = new Voxel*[nz*nx]; // aloca��o de linhas para o Voxel

    for(int k=1;k<nz;k++){
        v[k]=v[k-1]+nx; // adicionando linhas aos planos
    }

    v[0][0] = new Voxel[nz*nx*ny]; // aloca��o dos Voxel na matriz 3D


    int contador=0;
    // cria��o de colunas para ficar entre as linhas e planos da matriz 3D
    for(int k=0;k<nz;k++){
        for(int i=0;i<nx;i++){
            v[k][i] = v[0][0] + contador*ny;
            contador++;
        }
    }

}

Escultor::~Escultor(){
    // o destrutor
    delete [] v[0][0]; // libera��o do Voxel a partir do comando delete
    delete [] v[0]; // libera��o das linhas
    delete [] v; // libera��o da figura desenhada

}

void Escultor::setColor(float vermelho, float verde, float azul, float alpha){
    // utilizado para definir a cor do desenho
    r = vermelho; // cor vermelha
    g = verde; // cor verde
    b = azul; // cor azul
    a = alpha; // transpar�ncia da pe�a
};
void Escultor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    /* m�todo respons�vel por gerar a representa��o de uma esfera no plano x, y, z.
     esse m�todo insere a esfera de acordo com as coordenadas da esfera (x,y,z) e o raio da esfera (radius).*/
    float d;

    for(int k=0;k<=nz;k++){
        for(int j=0; j<=ny; j++){ // an�lise de planos, linhas e colunas da matriz.
            for(int i=0; i<=nx; i++){
                d = pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2);
                if(d <= pow(radius, 2)){
                    putVoxel(i,j,k); // insere a esfera de acordo com as coordenadas formadas na sa�da.
                }
            }
        }
    }
}

void Escultor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    // m�todo respons�vel por desabilitar a representa��o da esfera no plano x, y, z de acordo com as coordenadas definidas.
    // esse m�todo apaga a esfera de acordo com as coordenadas da esfera (x,y,z) e o raio da esfera (radius).
    float d;

    for(int k=0;k<=nz;k++){
        for(int j=0;j<=ny;j++){  // an�lise de planos, linhas e colunas da matriz.
            for(int i=0;i<=nx;i++){
                d = pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2);
                if(d <= pow(radius, 2)){
                    cutVoxel(i,j,k); // desabilita o Voxel em uma determinada �rea do plano x, y, z.
                }
            }
        }
    }
}

void Escultor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    /* insere um Voxel com as coordenadas correspondentes aos eixos, levando em conta
       o in�cio e o fim em cada eixo, gerando uma caixa.*/
    for(int k=z0;k<=z1;k++){
        for(int j=y0;j<=y1;j++){
            for(int i=x0;i<=x1;i++){
                putVoxel(i,j,k); // ativa o Voxel nas coordenadas especifidadas
            }
        }
    }
}

void Escultor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    // desativa os Voxels em um determinado espa�o atribuido pelas coordenadas do plano x, y, z.
    for (int k=z0;k<=z1;k++){
        for(int i=x0;i<=x1;i++){ // 3 "for" para an�lise de linhas, colunas e planos da matriz
            for(int j=y0;j<=y1;j++){
                cutVoxel(i,j,k); // desativa o Voxel de acordo com as coordenadas determinadas.
            }
        }

    }
}

// ativa o Voxel na posi��o (x,y,z), atribuindo assim isOn = true

void Escultor::putVoxel(int x, int y, int z){

    v[x][y][z].isOn = true; // ativa��o do isOn, fazendo o voxel aparecer
    v[x][y][z].r = r;
    v[x][y][z].g = g; // implementa��o das cores do sistema RGB e da transpar�ncia.
    v[x][y][z].b = b;
    v[x][y][z].a = a;

};

void Escultor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false; // desativa o Voxel, fazendo isOn = false
};




void Escultor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    float d;
    if(rx ==0){
        for(int k=0;k<=nz;k++){  // an�lise de planos, linhas e colunas da matriz.
            for(int j=0;j<=ny;j++){
                d = pow(j - ycenter, 2)/pow(ry,2) + pow(k - zcenter, 2)/pow(rz,2);
                if(d <= 1){
                    putVoxel(xcenter,j,k); // Habilita o Voxel em uma determinada �rea do plano x, y, z.
                }
            }
        }
    }
    else if(ry==0){
        for(int k=0; k<=nz; k++){  // an�lise de planos, linhas e colunas da matriz.
            for(int i=0;i<=nx;i++){
                d = pow(i - xcenter,2)/pow(rx,2) + pow(k - zcenter, 2)/pow(rz,2);
                if(d <= 1){
                    putVoxel(i,ycenter,k); // Habilita o Voxel em uma determinada �rea do plano x, y, z.

                }
            }
        }
    }
    else if(rz==0){
        for(int i=0;i<=nx;i++){  // an�lise de planos, linhas e colunas da matriz.
            for(int j=0;j<=ny;j++){
                d = pow(i - xcenter, 2)/pow(rx,2) + pow(j-ycenter, 2)/pow(ry,2);
                if(d <= 1){
                    putVoxel(i,j,zcenter); // Habilita o Voxel em uma determinada �rea do plano x, y, z.
                }
            }
        }
    }
    else{
        for(int k=0;k<=nz;k++){
            for(int j=0;j<=ny;j++){  // an�lise de planos, linhas e colunas da matriz.
                for(int i=0;i<=nx;i++){
                    d = pow(i-xcenter,2)/pow(rx,2) + pow(j-ycenter,2)/pow(ry, 2) + pow(k-zcenter,2)/pow(rz,2);
                    if(d <=1){
                        putVoxel(i,j,k); // Habilita o Voxel em uma determinada �rea do plano x, y, z.
                    }
                }
            }
        }
    }
}

void Escultor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    float d;

    if(rx ==0){
        for(int k=0;k<=nz;k++){  // an�lise de planos, linhas e colunas da matriz.
            for(int j=0;j<=ny;j++){
                d = pow(j - ycenter, 2)/pow(ry,2) + pow(k - zcenter, 2)/pow(rz,2);
                if(d <= 1){
                    cutVoxel(xcenter,j,k); // desabilita o Voxel em uma determinada �rea do plano x, y, z.
                }
            }
        }
    }
    else if(ry==0){
        for(int k=0; k<=nz; k++){
            for(int i=0;i<=nx;i++){
                d = pow(i - xcenter,2)/pow(rx,2) + pow(k - zcenter, 2)/pow(rz,2);
                if(d <= 1){
                    cutVoxel(i,ycenter,k); // desabilita o Voxel em uma determinada �rea do plano x, y, z.
                }
            }
        }
    }
    else if(rz==0){
        for(int i=0;i<=nx;i++){
            for(int j=0;j<=ny;j++){
                d = pow(i - xcenter, 2)/pow(rx,2) + pow(j-ycenter, 2)/pow(ry,2);
                if(d <= 1){
                    cutVoxel(i,j,zcenter); // desabilita o Voxel em uma determinada �rea do plano x, y, z.
                }
            }
        }
    }
    else{
        for(int k=0;k<=nz;k++){
            for(int j=0;j<=ny;j++){
                for(int i=0;i<=nx;i++){
                    d = pow(i-xcenter,2)/pow(rx,2) + pow(j-ycenter,2)/pow(ry, 2) + pow(k-zcenter,2)/pow(rz,2);
                    if(d <=1){
                        cutVoxel(i,j,k); // desabilita o Voxel em uma determinada �rea do plano x, y, z.
                    }
                }
            }
        }
    }
}


void Escultor::writeOFF(char* filename){
    ofstream fout;

    fixed(fout);

    int vertices = 0;
    int faces = 0;
    int aux = 0;

    fout.open(filename); // abertura do arquivo .OFF para escrita

    if(fout.is_open()){
        cout << "O arquivo OFF esta sendo gravado, aguarde um momento..." << endl;
    }
    else {
        cout << "Ocorreu um erro no arquivo OFF";
        exit(1);
    }
    fout << "OFF" << endl;

    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].isOn){
                    vertices = vertices+8;
                    faces = faces+6;

                }
            }
        }

    }

   fout << vertices <<" "<< faces << " "<< 0 << endl;

   for(int i=0;i<nx;i++){
       for(int j=0;j<ny;j++){
           for(int k=0;k<nz;k++){
               if(v[i][j][k].isOn){

                   fout<<i-0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                   fout<<i-0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                   fout<<i+0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                   fout<<i+0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                   fout<<i-0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                   fout<<i-0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                   fout<<i+0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                   fout<<i+0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
               }
           }
       }
   }

   for(int i=0;i<nx;i++){
       for(int j=0;j<ny;j++){
           for(int k=0;k<nz;k++){
               if(v[i][j][k].isOn){
                fout<<4<<" "<<aux+0<<" "<<aux+3<<" "<<aux+2<<" "<<aux+1<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                fout<<4<<" "<<aux+4<<" "<<aux+5<<" "<<aux+6<<" "<<aux+7<<" "<<v[i][j][k].r<<" " <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                fout<<4<<" "<<aux+0<<" "<<aux+1<<" "<<aux+5<<" "<<aux+4<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                fout<<4<<" "<<aux+0<<" "<<aux+4<<" "<<aux+7<<" "<<aux+3<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                fout<<4<<" "<<aux+3<<" "<<aux+7<<" "<<aux+6<<" "<<aux+2<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                fout<<4<<" "<<aux+1<<" "<<aux+2<<" "<<aux+6<<" "<<aux+5<<" "<<v[i][j][k].r<<" "<<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                aux=aux+8;
           }
       }
   }
}

   if(fout.is_open()){
        cout<<"O arquivo OFF foi salvo, verifique o caminho de saida na pasta do seu projeto" << endl;  // finaliza��o da grava��o do arquivo .OFF
   }
}
