from __future__ import print_function

from point import Point
from ray import Ray
from plate import Plate
from cylinder import Cylinder
from cone import Cone

p0 = Point(0, 0, 0)

centroChapa = Point(0, 0, -4)
tamanhoChapa = 4
numeroDeFuros = 100

centroBaseCilindro = Point(0, -2, -10)
uCilindro = Point(0, 1, 0)
alturaCilindro = 2
raioCilindro = 0.5

centroBaseCone = Point(0, 0, -10)
uCone = Point(0, 1, 0)
alturaCone = 8
raioCone = 3

arestaCubo = 6
uCubo = Point(0, 1, 0)
centroCubo1 = Point(0, -2, -20)
centroCubo2 = Point(0, 4, -20)
centroCubo3 = Point(0, 10, -20)

chapa = Plate(centroChapa, tamanhoChapa, numeroDeFuros)
#raio = Ray(p0, d)
cilindro = Cylinder(centroBaseCilindro, uCilindro, alturaCilindro, raioCilindro)
cone = Cone(centroBaseCone, uCone, alturaCone, raioCone)

print(chapa.point(50, 49).toList())
