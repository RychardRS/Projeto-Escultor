#ifndef ESCULTOR_H
#define ESCULTOR_H

using namespace std;

struct Voxel {
  float r,g,b;
  float a;
  bool isOn;
  /*r indica o par�metro da cor vermelha
    g indica o par�metro da cor verde
    b indica o par�metro da cor azul
    a indica o par�metro de transpar�ncia*/
};

int main()
{
    class Escultor { //construtor da classe escultor
protected:
  Voxel ***v; // para a Matriz 3D
  int nx,ny,nz; // dimens�es da matriz no eixo X, Y e Z
  float r,g,b,a; // colora��o no sistema RGB(red, green, blue) com o par�metro de transpar�ncia

public: /*local onde vai o c�digo desenvolvido para montagem da figura 3D, com formas geom�tricas
          que permite o desenvolvedor manipular sua figura */
  Escultor(int _nx, int _ny, int _nz);
  ~Escultor(); // a nega��o do Escultor, ou seja, serve como um "destrutor"
  void setColor(float r, float g, float b, float alpha); /*define a cor do desenho, vale lembrar que a tonalidade
  de cada par�metro do sistema RGB varia de 0 a 255, enquanto a transpar�ncia(alpha) varia de 0 a 1)*/

  void putVoxel(int x, int y, int z);/* ir� habilitar o Voxel, fazendo isOn = true para operar nas cores definidas
                                        no setColor*/

  void cutVoxel(int x, int y, int z);/*desativa o Voxel, fazendo isOn = false e consequentemente parando de operar
                                       nas cores definidas*/

  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);/*ativa todos os Voxels em um intervalo pr� determinado
                                                                com o in�cio e fim da constru��o em cada eixo X, Y e Z
                                                                assim como atribui a cor atual do desenho*/

  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);//desativa todos os Voxels no intervalo definido

  void putSphere(int xcenter, int ycenter, int zcenter, int radius);/*ativa os voxels que satisfazem a equa��o da esfera
                                                                      no plano do desenho, assim como atribui a cor j� definida*/

  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);//desativa os voxels que satisfazem a equa��o da esfera


  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);/*ativa os Voxels que satisfazem a equa��o
  do elips�ide, possuindo as coordenadas de centro(xcenter, ycenter, zcenter) e as coordenadas em cada eixo(rx,ry,rz)*/

  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);/*desativa os Voxels que satisfazem a equa��o
  do elips�ide*/

  void writeOFF(const char* filename);//respons�vel por gravar a escultura no formato OFF no arquivo filename
};

}

#endif // ESCULTOR_H
