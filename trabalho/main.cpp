#include <GL/glew.h>
#include <GL/glut.h>

#include "Sphere.hpp"
#include "Cylinder.hpp"
#include "Camera.hpp"
#include "Luzes.hpp"

const int WIDTH = 600, HEIGHT = 400;
const int BUFFER_SIZE = WIDTH*HEIGHT*3;

LinearAlgebra::Vector4Df P0{1, 4, 1, 1};
LinearAlgebra::Vector4Df LA{10, 4, 10, 1};
LinearAlgebra::Vector4Df VU{10, 6, 10, 1};

void display(){
    LinearAlgebra::Vector4Df sphereCenter{10, 4, 10, 1};
    float radius = 2;

    Camera camera(P0, LA, VU, HEIGHT, WIDTH);
    std::vector<Cluster*> objetos;

    sphereCenter = camera.convert(sphereCenter);

    Sphere *sphere = new Sphere(sphereCenter, radius, CG::sRedMaterial(), "Test Sphere");
    objetos.push_back(sphere);

    camera.renderScenery(objetos);

    float *data;
    data = new float[BUFFER_SIZE]; // Buffer de pixels

    std::vector<Luz::Luz*> luzes;

    Luz::Remota *teste = new Luz::Remota();
    teste->Ia = {0.1, 0.1, 0.1};
    teste->Id = {1, 1, 1};
    teste->Is = {10, 10, 10};
    teste->direcao = {0, 1, 0, 0};
    luzes.push_back(teste);

    Luz::Remota *teste2 = new Luz::Remota();
    teste2->Ia = {0.1, 0.1, 0.1};
    teste2->Id = {2, 2, 2};
    teste2->Is = {5, 5, 5};
    teste2->direcao = {0, -1, 0, 0};
    luzes.push_back(teste);

    for(int i = 0; i < camera.buffer.size(); i++){
        LinearAlgebra::Vector3Df *cor = new LinearAlgebra::Vector3Df{0, 0, 0};
        for (Luz::Luz *l : luzes){
            *cor += (l->iluminar(&(camera.buffer[i]), camera.P0));
        }
        data[i*3 + 0] = cor->x;
        data[i*3 + 1] = cor->y;
        data[i*3 + 2] = cor->z;
    }

    glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_FLOAT, data); // Função que exibe o buffer de pixels na tela
    glutSwapBuffers(); // Troca de buffer
}

void movimentoTeclado(unsigned char Key, int x, int y)
{
    switch(Key)
    {
        case 'w': P0 = P0 + LinearAlgebra::Vector4Df{1, 0, 0, 1}; break;
        case 'a': P0 = P0 + LinearAlgebra::Vector4Df{0, 0, 1, 1}; break;
        case 's': P0 = P0 + LinearAlgebra::Vector4Df{-1, 0, 0, 1};break;
        case 'd': P0 = P0 + LinearAlgebra::Vector4Df{0, 0, -1, 1};break;
        case ' ': P0 = P0 + LinearAlgebra::Vector4Df{0, 1, 0, 1}; break;
        case 27: exit(1);
    }
    display();
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
    glutKeyboardFunc(movimentoTeclado);

    glutMainLoop(); // Loop do programa

    return 0;
}
