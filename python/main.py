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
p0 = np.array([0, 2, 0, 1])

# Informações Chapa
larguraChapa = 8
alturaChapa = 6
numeroFurosLargura = 640
numeroFurosAltura = 480
distancia_chapa = 4

# Local que ele observa
lookAt = np.array([10, 2, 10, 1])
viewUp = np.array([10, 8, 10, 1])

# Informações dos cubos
arestaCubo = 3
centroBaseCubo1 = np.array([10, 0, 5, 1])
centroBaseCubo2 = np.array([10, 3, 5, 1])
centroBaseCubo3 = np.array([10, 6, 5, 1])

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

# Conversão de coordenadas de mundo para coordenadas de camera
