from __future__ import print_function
from point import Point
from ray import Ray
from plate import Plate

p0 = Point(0, 0, 0)
d = Point(1, 1, 1)

centroChapa = Point(0, 0, -4)
tamanhoChapa = 4
numeroDeFuros = 100

chapa = Plate(centroChapa, tamanhoChapa, numeroDeFuros)
print(chapa.point(0, 99).toList())
print(chapa.point(50, 50).toList())
