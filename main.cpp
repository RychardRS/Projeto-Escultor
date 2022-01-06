#ifndef ESCULTOR_H
#define ESCULTOR_H

using namespace std;

struct Voxel {
  float r,g,b;
  float a;
  bool isOn;
  /*r indica o parâmetro da cor vermelha
    g indica o parâmetro da cor verde
    b indica o parâmetro da cor azul
    a indica o parâmetro de transparência*/
};

int main()
{
    class Escultor { //construtor da classe escultor
protected:
  Voxel ***v; // para a Matriz 3D
  int nx,ny,nz; // dimensões da matriz no eixo X, Y e Z
  float r,g,b,a; // coloração no sistema RGB(red, green, blue) com o parâmetro de transparência

public: /*local onde vai o código desenvolvido para montagem da figura 3D, com formas geométricas
          que permite o desenvolvedor manipular sua figura */
  Escultor(int _nx, int _ny, int _nz);
  ~Escultor(); // a negação do Escultor, ou seja, serve como um "destrutor"
  void setColor(float r, float g, float b, float alpha); /*define a cor do desenho, vale lembrar que a tonalidade
  de cada parâmetro do sistema RGB varia de 0 a 255, enquanto a transparência(alpha) varia de 0 a 1)*/

  void putVoxel(int x, int y, int z);/* irá habilitar o Voxel, fazendo isOn = true para operar nas cores definidas
                                        no setColor*/

  void cutVoxel(int x, int y, int z);/*desativa o Voxel, fazendo isOn = false e consequentemente parando de operar
                                       nas cores definidas*/

  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);/*ativa todos os Voxels em um intervalo pré determinado
                                                                com o início e fim da construção em cada eixo X, Y e Z
                                                                assim como atribui a cor atual do desenho*/

  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);//desativa todos os Voxels no intervalo definido

  void putSphere(int xcenter, int ycenter, int zcenter, int radius);/*ativa os voxels que satisfazem a equação da esfera
                                                                      no plano do desenho, assim como atribui a cor já definida*/

  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);//desativa os voxels que satisfazem a equação da esfera


  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);/*ativa os Voxels que satisfazem a equação
  do elipsóide, possuindo as coordenadas de centro(xcenter, ycenter, zcenter) e as coordenadas em cada eixo(rx,ry,rz)*/

  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);/*desativa os Voxels que satisfazem a equação
  do elipsóide*/

  void writeOFF(const char* filename);//responsável por gravar a escultura no formato OFF no arquivo filename
};

}

#endif // ESCULTOR_H
