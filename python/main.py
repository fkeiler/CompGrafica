from __future__ import print_function
from PIL import Image

from coordinate import Coordinate
from ray import Ray
from plate import Plate

from cone import Cone
from cube import Cube
from cylinder import Cylinder
from camera import Camera

# Observador
p0 = Coordinate(0, 2, 0, 1)

# Informações Chapa
tamanho_chapa = 6
numero_furos_chapa = 200
distancia_chapa = 3

# Local que ele observa
look_at = Coordinate(10, 2, 10, 1)
view_up = Coordinate(10, 8, 10, 1)

# Informações dos cubos
aresta_cubo = 3
centro_base_cubo1 = Coordinate(10, 0, 5, 1)
centro_base_cubo2 = Coordinate(10, 3, 5, 1)
centro_base_cubo3 = Coordinate(10, 6, 5, 1)

# Informações dos cilindros
altura_cilindo = 2
raio_cilindro = 0.5
vetor_unitario_cilindro = Coordinate(0, 1, 0, 0)
centro_base_cilindro1 = Coordinate(7, 0, 9, 1)
centro_base_cilindro2 = Coordinate(13, 0, 9, 1)

# Informações dos cones
altura_cone = 8
raio_cone = 2
vetor_unitario_cone = Coordinate(0, 1, 0, 0)
centro_base_cone1 = Coordinate(7, 2, 9, 1)
centro_base_cone2 = Coordinate(13, 2, 9, 1)

# Inicializando raio e chapa
raio = Ray(p0)
chapa = Plate(tamanho_chapa, numero_furos_chapa, distancia_chapa)

# Inicializar camera
camera = Camera(p0, look_at, view_up)

# Inicializando objetos
cubo1 = Cube(centro_base_cubo1, aresta_cubo)
cubo2 = Cube(centro_base_cubo2, aresta_cubo)
cubo3 = Cube(centro_base_cubo3, aresta_cubo)
cilindro1 = Cylinder(centro_base_cilindro1, vetor_unitario_cilindro, altura_cilindo, raio_cilindro)
cilindro2 = Cylinder(centro_base_cilindro2, vetor_unitario_cilindro, altura_cilindo, raio_cilindro)
cone1 = Cone(centro_base_cone1, vetor_unitario_cone, altura_cone, raio_cone)
cone2 = Cone(centro_base_cone2, vetor_unitario_cone, altura_cone, raio_cone)

# materialindo objetos para facilitar identificacao
cubo1.material = (46, 119, 187)
cubo2.material = (29, 131, 195)
cubo3.material = (39, 174, 227)

# Conversão de coordenadas de mundo para coordenadas de camera
p0 = camera.convert_to_camera_coord(p0)
raio.p0 = p0

cubo1.base_center = camera.convert_to_camera_coord(cubo1.base_center)
for i in range(len(cubo1.vertices)):
  cubo1.vertices[i] = camera.convert_to_camera_coord(cubo1.vertices[i])

cubo2.base_center = camera.convert_to_camera_coord(cubo2.base_center)
for i in range(len(cubo2.vertices)):
  cubo2.vertices[i] = camera.convert_to_camera_coord(cubo2.vertices[i])

cubo3.base_center = camera.convert_to_camera_coord(cubo3.base_center)
for i in range(len(cubo3.vertices)):
  cubo3.vertices[i] = camera.convert_to_camera_coord(cubo3.vertices[i])

cilindro1.base_center = camera.convert_to_camera_coord(cilindro1.base_center)
cilindro1.unitary_vector = camera.convert_to_camera_coord(cilindro1.unitary_vector)
cilindro2.base_center = camera.convert_to_camera_coord(cilindro2.base_center)
cilindro2.unitary_vector = camera.convert_to_camera_coord(cilindro2.unitary_vector)

cone1.base_center = camera.convert_to_camera_coord(cone1.base_center)
cone1.unitary_vector = camera.convert_to_camera_coord(cone1.unitary_vector)
cone1.vertice = camera.convert_to_camera_coord(cone1.vertice)
cone2.base_center = camera.convert_to_camera_coord(cone2.base_center)
cone2.unitary_vector = camera.convert_to_camera_coord(cone2.unitary_vector)
cone2.vertice = camera.convert_to_camera_coord(cone2.vertice)

imagem = Image.new('RGB', (numero_furos_chapa, numero_furos_chapa))

print("p0:", p0.to_list())
print("C cone 1:", cone1.base_center.to_list())
print("C cone 2:", cone2.base_center.to_list())
print("C cilindro 1:", cilindro1.base_center.to_list())
print("C cilindro 2:", cilindro2.base_center.to_list())
print("C cubo 1:", cubo1.base_center.to_list())

for l in range(chapa.number_of_holes):
  for c in range(chapa.number_of_holes):
    colisoes = []
    cor_primeira_colisao = (255, 255, 255)
    menor_t = 0

    # Definindo o valor d do raio com base no ponto da chapa
    raio.d = Coordinate.given_two_points(p0, chapa.point(l, c))
    
    # Calculando colisões
    colisoes += cilindro1.verify_colision(raio)
    colisoes += cone1.verify_colision(raio)
    colisoes += cilindro2.verify_colision(raio)
    colisoes += cone2.verify_colision(raio)
    colisoes += cubo1.verify_colision(raio)
    colisoes += cubo2.verify_colision(raio)
    colisoes += cubo3.verify_colision(raio)

    # Verificando quem foi atigindo primeiro
    if len(colisoes) > 0:
      cor_primeira_colisao = colisoes[0]["material"]
      menor_t = colisoes[0]["t"]

    for colisao in colisoes:
      if(colisao["t"] < menor_t):
        menor_t = colisao["t"]
        cor_primeira_colisao = colisao["material"]
    
    del colisoes

    # Desenhando na imagem
    chapa.buffer[l][c] = cor_primeira_colisao
    imagem.putpixel( (c, l), chapa.buffer[l][c] )

imagem.save('saida.png')


