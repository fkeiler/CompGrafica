from __future__ import print_function
from PIL import Image

from point import Point
from ray import Ray
from plate import Plate
from cylinder import Cylinder
from cone import Cone

p0 = Point(0, 0, 0)
d = Point(1, 1, 1)

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

raio = Ray(p0, d)
chapa = Plate(centroChapa, tamanhoChapa, numeroDeFuros)
cilindro = Cylinder(centroBaseCilindro, uCilindro, alturaCilindro, raioCilindro)
cone = Cone(centroBaseCone, uCone, alturaCone, raioCone)

# Calcular colisões
for x in range(chapa.n):
  for y in range(chapa.n):
    colisoes = []
    corPrimeiraColisao = (255, 255, 255)
    menor = 0

    # Calculando o novo d para o ponto da chapa
    raio.d = Point.usingTwoPoints(p0, chapa.point(x, y))
    
    colisoes += cilindro.verifyColision(raio)
    colisoes += cone.verifyColision(raio)

    # Verificar qual é a primeira colisão
    if len(colisoes) > 0: 
      corPrimeiraColisao = colisoes[0]["color"]
      menor = colisoes[0]["t"]

    for colisao in colisoes:
      if(colisao["t"] < menor):
        menor = colisao["t"]
        corPrimeiraColisao = colisao["color"]

    chapa.matrix[x][y] = corPrimeiraColisao

# Pintar imagem
imagem = Image.new('RGB', (numeroDeFuros, numeroDeFuros))

for x in range(chapa.n):
  for y in range(chapa.n):
    imagem.putpixel( (x,y), chapa.matrix[x][y] )

imagem.save('saida.png')
