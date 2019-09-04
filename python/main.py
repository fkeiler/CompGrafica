from __future__ import print_function
from PIL import Image

from coordinate import Coordinate
from ray import Ray

from cone import Cone
from cube import Cube
from cylinder import Cylinder
from camera import Camera

# Observador
p0 = Coordinate(7.5, 2, 15, 0)

# "Chapa"
altura_chapa = 4
largura_chapa = 4
numero_furos_vertical = 100
numero_furos_horizontal = 100

# Local que ele observa
look_at = Coordinate(5, 2, 5, 0)
view_up = Coordinate(5, 6, 5, 0)

# Informações dos cubos
aresta_cubo = 3
centro_base_cubo1 = Coordinate(5, 0, 5, 0)
centro_base_cubo2 = Coordinate(5, 3, 5, 0)
centro_base_cubo3 = Coordinate(5, 6, 5, 0)

# Informações dos cilindros
altura_cilindo = 2
raio_cilindro = 0.5
vetor_unitario_cilindro = Coordinate(0, 1, 0, 1)
centro_base_cilindro1 = Coordinate( 5, 0, 10, 0)
centro_base_cilindro2 = Coordinate(10, 0, 10, 0)

# Informações dos cones
altura_cone = 5
raio_cone = 1
vetor_unitario_cone = Coordinate(0, 1, 0, 1)
centro_base_cone1 = Coordinate( 5, 2, 10, 0)
centro_base_cone2 = Coordinate(10, 2, 10, 0)

# Inicializando objetos
cilindro1 = Cylinder(centro_base_cilindro1, vetor_unitario_cilindro, altura_cilindo, raio_cilindro)
cilindro2 = Cylinder(centro_base_cilindro2, vetor_unitario_cilindro, altura_cilindo, raio_cilindro)
cone1 = Cone(centro_base_cone1, vetor_unitario_cone, altura_cone, raio_cone)
cone2 = Cone(centro_base_cone2, vetor_unitario_cone, altura_cone, raio_cone)
cubo1 = Cube(centro_base_cubo1, aresta_cubo)
cubo2 = Cube(centro_base_cubo2, aresta_cubo)
cubo3 = Cube(centro_base_cubo3, aresta_cubo)

# Inicializar camera
camera = Camera(p0, look_at, view_up)

# Conversão de coordenadas de mundo para coordenadas de camera
print(camera.Matrix)
