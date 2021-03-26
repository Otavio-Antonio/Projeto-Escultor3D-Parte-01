#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cmath>

using namespace std;
/**
 * @brief The Voxel struct
 * @details Testando descrição
 */
struct Voxel{
    float r, g, b, a;
    bool isOn;
};

/**
 * @brief Classe sculptor
 * @details
 */
class sculptor
{
protected:

    int nx, ny, nz;
    float r,g,b,a;
    Voxel ***imagemVox;

public:

    /**
     * @brief sculptor
     * @details É o contrutor da classe sculptor, que recebe 3 inteiros referentes a uma matriz de três dimensões e faz a alocação dinâmica na memoria.
     * @param _nx
     * @param _ny
     * @param _nz
     */
    sculptor(int _nx, int _ny, int _nz);
    ~sculptor();

    /**
     * @brief putVoxel
     * @details Recebe 3 inteiros referentes a uma posição da matriz que indica que esse Voxel deverá ser DESENHADO na imagem gerada pelo programa.
     * @param x
     * @param y
     * @param z
     */
    void putVoxel(int x, int y, int z);

    /**
     * @brief cutVoxel
     * @details Recebe 3 inteiros referentes a uma posição da matriz que indica que esse Voxel deverá ser APAGADO da imagem gerada pelo programa.
     * @param x
     * @param y
     * @param z
     */
    void cutVoxel(int x, int y, int z);

    /**
     * @brief putBox
     * @details Recebe 6 inteiros referentes aos limites de um Cubo, indicando que esse Cubo deverá ser DENSHADO na imagem que será gerada pelo programa (a posição do cubo na imagem é delimitado pelos interios recebidos).
     * @param x0 Início do intervalo em X.
     * @param x1 Fim do intervalo em X.
     * @param y0 Início do intervalo em Y.
     * @param y1 Fim do intervalo em Y.
     * @param z0 Início do intervalo em Z.
     * @param z1 Fim do intervalo em Z.
     */
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);

    /**
     * @brief cutBox
     * @details Recebe 6 inteiros referentes aos limites de um Cubo, indicando que esse Cubo, formado por voxels, deverá ser APAGADO da imagem que sera gerada pelo programa (a posição do cubo na imagem é delimitado pelos interios recebidos).
     * @param x0 Início do intervalo em X.
     * @param x1 Fim do intervalo em X.
     * @param y0 Início do intervalo em Y.
     * @param y1 Fim do intervalo em Y.
     * @param z0 Início do intervalo em Z.
     * @param z1 Fim do intervalo em Z.
     */
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

    /**
     * @brief putSphere
     * @details Recebe 4 inteiros referentes ao centro de uma Esfera e seu raio, indicando que uma Esfera formada por voxels deverá ser DESENHADA na imagem que será gerada pelo programa (a posição da esfera na imagem é delimitada pelo seu centro).
     * @param xcenter Posição do centro da esfera no eixo X.
     * @param ycenter Posição do centro da esfera no eixo Y.
     * @param zcenter Posição do centro da esfera no eixo Z.
     * @param radius Tamanho do raio.
     */
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);

    /**
     * @brief cutSphere
     * @details Recebe 4 inteiros referentes ao centro de uma Esfera e seu raio, indicando que uma Esfera formada por voxels deverá ser APAGADA da imagem que será gerada pelo programa (sua posição na imagem é delimitada pelo seu centro).
     * @param xcenter Posição do centro da esfera no eixo X.
     * @param ycenter Posição do centro da esfera no eixo Y.
     * @param zcenter Posição do centro da esfera no eixo Z.
     * @param radius Tamanho do raio.
     */
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

    /**
     * @brief putEllipsoid
     * @details Recebe 3 inteiros referentes ao centro de um Elipsóide e 3 inteiros referente aos seus raios, indicando que um Elipsóide formado por voxels deverá ser DESENHADO na imagem que será gerada pelo programa (sua posição na imagem é delimitada pelo seu centro).
     * @param xcenter Posição do centro da elipsóide no eixo X.
     * @param ycenter Posição do centro da elipsóide no eixo Y.
     * @param zcenter Posição do centro da elipsóide no eixo Z.
     * @param rx Tamanho do raio no eixo X.
     * @param ry Tamanho do raio no eixo Y.
     * @param rz Tamanho do raio no eixo Z.
     */
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    /**
     * @brief cutEllipsoid
     * @details Recebe 3 inteiros referentes ao centro de um Elipsóide e 3 inteiros referente aos seus raios, indicando que um Elipsóide formado por voxels deverá ser APAGADO da imagem que será gerada pelo programa (sua posição na imagem é delimitada pelo seu centro).
     * @param xcenter Posição do centro da elipsóide no eixo X.
     * @param ycenter Posição do centro da elipsóide no eixo Y.
     * @param zcenter Posição do centro da elipsóide no eixo Z.
     * @param rx Tamanho do raio no eixo X.
     * @param ry Tamanho do raio no eixo Y.
     * @param rz Tamanho do raio no eixo Z.
     */
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

    /**
     * @brief setColor
     * @details Recebe 4 floats referentes a cor que o usuario deseja utilizar para cada figura ou voxel que desejar.
     * @param r Valor variante de 0 a 1 que indica a quantidade de vermelho na cor desejada.
     * @param g Valor variante de 0 a 1 que indica a quantidade de verde na cor desejada.
     * @param b Valor variante de 0 a 1 que indica a quantidade de azul na cor desejada.
     * @param alpha Valor variante de 0 a 1 que indica a transparência.
     */
    void setColor(float r, float g, float b, float alpha);

    /**
     * @brief writeOFF
     * @details Gera um aqrquivo do tipo ".off" para ser visualizado em um visualizador de imagens, como por exemplo o MeshLab.
     * @param filename
     */
    void writeOFF(char* filename);
};
#endif // SCULPTOR_H
