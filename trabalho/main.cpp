#include <GL/glew.h>
#include <GL/glut.h>

#include "Ray.hpp"
#include "Sphere.hpp"
#include "Cylinder.hpp"

#include "CG.hpp"

const int WIDTH = 640, HEIGHT = 480;
const int BUFFER_SIZE = WIDTH*HEIGHT*3;

/*
void display(){
    int mod;

    float *data;
    data = new float[BUFFER_SIZE]; // Buffer de pixels

    Coordinate p0({6,8,0,1});

    Coordinate sphereCenter({6,2,0,1});
    double sphereRadius = 1;

    Coordinate d = (sphereCenter - p0).normalize();

    std::vector<Coordinate> world;

    world.push_back(p0);
    world.push_back(sphereCenter);
    world.push_back(d);

    for(auto &c : world) {
        std::cout << c << std::endl;
    }

    Ray raio(p0);
    raio.d = d;

    Sphere esfera(sphereCenter, sphereRadius);

    esfera.verifyColision(raio);

    // glClear( GL_COLOR_BUFFER_BIT ); // Função que limpa o buffer

    // Calcular Buffer de pixels
    for (int i = 0; i < BUFFER_SIZE; i++){
        mod = i%3;

        switch (mod)
        {
            case 0:
                data[i] = 0.8;
                break;
            case 1:
                data[i] = 0.8;
                break;
            case 2:
                data[i] = 0.8;
                break;
            default:
                data[i] = 0.8;
                break;
        }
    }

    glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_FLOAT, data); // Função que exibe o buffer de pixels na tela
    glutSwapBuffers(); // Troca de buffer
}
*/

int main(int argc, char **argv) {
    // Criação da Janela
    /*
    glutInit(&argc, argv); // Inicializa o GLUT
    glutInitDisplayMode(GLUT_RGB); // Configurando o modo do display
    glutInitWindowPosition(400,400); // Posição inicial da janela
    glutInitWindowSize(WIDTH, HEIGHT); // Configura o tamanho da janela utilizando as váriaveis globais
    glutCreateWindow("Scene"); // Configura o titulo da janela

    // Exibindo coisas na janela
    glutDisplayFunc(display); // Função que vai exibir os desenhos na janela

    glutMainLoop(); // Loop do programa
    */

/*
    LinearAlgebra::Vector4Df P0{7.5, 2, 15, 1};
    LinearAlgebra::Vector4Df LA{5, 2, 5, 1};
    LinearAlgebra::Vector4Df VU{5, 6, 5, 1};

    // Creating the transform Matrix of camera
    LinearAlgebra::Vector4Df Kc = (P0-LA).normalize();
    LinearAlgebra::Vector4Df Ic = (VU-P0).cross_product(Kc).normalize();
    LinearAlgebra::Vector4Df Jc = Kc.cross_product(Ic);

    LinearAlgebra::Matrix4Df transformMatrix = LinearAlgebra::indentityMatrix();

    for(int i = 0; i < 3; i++){
        transformMatrix._matrix[0][i] = Ic.value[i];
        transformMatrix._matrix[1][i] = Jc.value[i];
        transformMatrix._matrix[2][i] = Kc.value[i];
    };

    transformMatrix._matrix[0][3] = -P0.dot_product(Ic);
    transformMatrix._matrix[1][3] = -P0.dot_product(Jc);
    transformMatrix._matrix[2][3] = -P0.dot_product(Kc);

    for(int i = 0; i < 4; i++){
        std::cout << transformMatrix.row[i] << std::endl;
    }
*/



    return 0;
}
