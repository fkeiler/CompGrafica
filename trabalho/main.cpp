#include <GL/glew.h>
#include <GL/glut.h>

#include "Sphere.hpp"
#include "Cylinder.hpp"
#include "Camera.hpp"

const int WIDTH = 640, HEIGHT = 480;
const int BUFFER_SIZE = WIDTH*HEIGHT*3;


void display(){
    LinearAlgebra::Vector4Df sphereCenter{10, 4, 10, 1};
    float radius = 2;

    LinearAlgebra::Vector4Df planePoint{0, 0, 0, 1};
    LinearAlgebra::Vector4Df planeUnitary{0, 1, 0, 0};

    LinearAlgebra::Vector4Df P0{1, 4, 1, 1};
    LinearAlgebra::Vector4Df LA{10, 4, 10, 1};
    LinearAlgebra::Vector4Df VU{10, 6, 10, 1};

    Camera camera(P0, LA, VU, HEIGHT, WIDTH);

    sphereCenter = camera.convert(sphereCenter);
    planePoint = camera.convert(planePoint);
    planeUnitary = camera.convert(planeUnitary);

    Sphere sphere(sphereCenter, radius, CG::sRedMaterial(),"Test Sphere");
    Plane plane(planePoint, planeUnitary, CG::sGrayMaterial(), "Test Plane");

    camera.renderScenary(sphere, plane);

    float *data;
    data = new float[BUFFER_SIZE]; // Buffer de pixels

    for(int i = 0; i < camera.buffer.size(); i++){
        data[i*3 + 0] = camera.buffer[i].objectMaterial.Ia.value[0];
        data[i*3 + 1] = camera.buffer[i].objectMaterial.Ia.value[1];
        data[i*3 + 2] = camera.buffer[i].objectMaterial.Ia.value[2];
    }

    glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_FLOAT, data); // Função que exibe o buffer de pixels na tela
    glutSwapBuffers(); // Troca de buffer
}


int main(int argc, char **argv) {
    // Criação da Janela
    glutInit(&argc, argv); // Inicializa o GLUT
    glutInitDisplayMode(GLUT_RGB); // Configurando o modo do display
    glutInitWindowPosition(400,400); // Posição inicial da janela
    glutInitWindowSize(WIDTH, HEIGHT); // Configura o tamanho da janela utilizando as váriaveis globais
    glutCreateWindow("Scene"); // Configura o titulo da janela

    // Exibindo coisas na janela
    glutDisplayFunc(display); // Função que vai exibir os desenhos na janela

    glutMainLoop(); // Loop do programa

    return 0;
}
