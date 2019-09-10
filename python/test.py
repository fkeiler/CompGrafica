from __future__ import print_function
from PIL import Image

from coordinate import Coordinate
from ray import Ray
from plate import Plate

from cone import Cone
from cube import Cube
from cylinder import Cylinder

from material import Material
from ambiente import Ambiente
from remota import Remota


# Observador
p0 = Coordinate(0, 0, 0, 1)

# Informações Chapa
tamanho_chapa = 6
numero_furos_chapa = 300
distancia_chapa = 3

# Informações dos cubos
aresta_cubo = 3
centro_base_cubo1 = Coordinate(-3.5355339059327378, -2.0, -10.606601717798211, 1)
centro_base_cubo2 = Coordinate(-3.5355339059327378, 1, -10.606601717798211, 1)
centro_base_cubo3 = Coordinate(-3.5355339059327378, 4, -10.606601717798211, 1)

# Informações dos cilindros
altura_cilindo = 2
raio_cilindro = 0.5
vetor_unitario_cilindro = Coordinate(0, 1, 0, 0)
centro_base_cilindro1 = Coordinate(1.4142, -2, -11.3137, 1)
centro_base_cilindro2 = Coordinate(-2.8284, -2, -15.5563, 1)

# Informações dos cones
altura_cone = 8
raio_cone = 2
vetor_unitario_cone = Coordinate(0, 1, 0, 0)
centro_base_cone1 = Coordinate(1.4142, 0, -11.3137, 1)
centro_base_cone2 = Coordinate(-2.8284, 0, -15.5563, 1)

# Inicializando raio e chapa
raio = Ray(p0)
chapa = Plate(tamanho_chapa, numero_furos_chapa, distancia_chapa)

# Inicializando objetos
cubo1 = Cube(centro_base_cubo1, aresta_cubo)
cubo2 = Cube(centro_base_cubo2, aresta_cubo)
cubo3 = Cube(centro_base_cubo3, aresta_cubo)
cilindro1 = Cylinder(centro_base_cilindro1, vetor_unitario_cilindro, altura_cilindo, raio_cilindro)
cone1 = Cone(centro_base_cone1, vetor_unitario_cone, altura_cone, raio_cone)
cilindro2 = Cylinder(centro_base_cilindro2, vetor_unitario_cilindro, altura_cilindo, raio_cilindro)
cone2 = Cone(centro_base_cone2, vetor_unitario_cone, altura_cone, raio_cone)

# materialindo objetos para facilitar identificacao
cubo1.material = Material([0.18, 0.46, 0.73], [0.18, 0.46, 0.73], [0.18, 0.46, 0.73], 0.5)
cubo2.material = Material([0.18, 0.46, 0.73], [0.18, 0.46, 0.73], [0.18, 0.46, 0.73], 0.5)
cubo3.material = Material([0.18, 0.46, 0.73], [0.18, 0.46, 0.73], [0.18, 0.46, 0.73], 0.5)

luzAmbiente = Ambiente(0.5, 0.5, 0.5)
luzRemota = Remota(1, 1, 1, Coordinate(1, 1, 1, 0))

imagem = Image.new('RGB', (numero_furos_chapa, numero_furos_chapa))

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
      cor_primeira_colisao = [sum(x) for x in zip(luzAmbiente.aplicar(colisoes[0]["material"]),luzRemota.aplicar(colisoes[0]["material"], raio.point(colisoes[0]["t"]), cone1))]
      menor_t = colisoes[0]["t"]

    for colisao in colisoes:
      if(colisao["t"] < menor_t):
        menor_t = colisao["t"]
        cor_primeira_colisao = [sum(x) for x in zip(luzAmbiente.aplicar(colisao["material"]), luzRemota.aplicar(colisao["material"], raio.point(colisao["t"]), cone1))]

    # Desenhando na imagem
    chapa.buffer[l][c] = cor_primeira_colisao
    imagem.putpixel( (c, l), tuple(int(c*255) for c in chapa.buffer[l][c]) )

imagem.save('saida_teste.png')
