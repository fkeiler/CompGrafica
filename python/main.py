from __future__ import print_function
import numpy as np

from coordinate import Coordinate
from ray import Ray
from plate import Plate

from cone import Cone
from cube import Cube
from cylinder import Cylinder
from camera import Camera

# Observador
p0 = np.array([0.0, 2.0, 0.0, 1.0])

# Informações Chapa
largura_chapa = 8
altura_chapa = 6
distancia_chapa = 4
numero_furos_largura = 640
numero_furos_altura = 480

# Local que ele observa
look_at = np.array([10.0, 2.0, 10.0, 1.0])
view_up = np.array([10.0, 8.0, 10.0, 1.0])

# Informações dos cubos
aresta_cubo = 3
centro_base_cubo1 = np.array([10.0, 0.0, 5.0, 1.0])
centro_base_cubo2 = np.array([10.0, 3.0, 5.0, 1.0])
centro_base_cubo3 = np.array([10.0, 6.0, 5.0, 1.0])

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

# Inicializando Objetos da Cena
cubo = Cube(centro_base_cubo1, aresta_cubo, True)

# Inicializando Camera
camera = Camera(p0, look_at, view_up)

# Conversão de coordenadas de mundo para coordenadas de camera
p0 = camera.convert_to_camera_coord(p0)

#print(p0)
