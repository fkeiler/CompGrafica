from math import sqrt
from coordinate import Coordinate

class Cone:
  # Construtor padrão
  def __init__(self, base_center, unitary_vector, height, radius):
    self.base_center = base_center
    self.unitary_vector = unitary_vector
    self.height = height
    self.radius = radius
    self.vertice = self.base_center + self.unitary_vector * self.height
    self.cos_theta = self.height/sqrt(self.height**2 + self.radius**2)
    self.color = (57, 220, 20)

  def verify_colision(self, ray):
    # Variavel criada para simplificar os calculos
    v = self.vertice - ray.p0

    # a, b e c calculados
    a = ray.d.dot_product(self.unitary_vector)**2 - ray.d.dot_product(ray.d)*(self.cos_theta**2)
    b = 2*(v.dot_product(ray.d)*(self.cos_theta**2) - v.dot_product(self.unitary_vector)*ray.d.dot_product(self.unitary_vector))
    c = v.dot_product(self.unitary_vector)**2 - v.dot_product(v)*(self.cos_theta**2)

    # Caso o a seja igual a 0 nao precisamos calcular o delta
    if a == 0:
      colision_list = []
      t = -c/b
      P = ray.point(t)
      colision_list.append({
        "color": self.color,
        "point": P,
        "t": t
      })
      return colision_list

    # delta calculado
    delta = b**2 - 4*a*c

    # Verificar se houve uma, duas ou se nao houveram colisoes
    # Se o valor delta for menor que 0 nao ocorre nenhuma colisao
    # Se o valor delta for igual a 0 pode ter ocorrido uma colisao dependendo da altura
    # Se o valor delta for maior que 0 podem ter ocorrido duas colisoes dependendo da altura
    if delta < 0:
      return []
    elif delta == 0:
      colision_list = []
      t = (-b/(2*a))
      
      # Ponto de colisao com o cone
      P = ray.point(t)
      # Altura da colisao
      point_height = (self.vertice - P).dot_product(self.unitary_vector)

      # Verifica se o valor t encontrado resulta em um ponto dentro da altura do cone
      if point_height >= 0 and point_height <= self.height:
        colision_list.append({
          "color": self.color,
          "point": P,
          "t": t
        })

      return colision_list
    else:
      colision_list = []
      # Primeiro t encontrado
      t = ((-b-sqrt(delta))/(2*a))
      
      # Ponto de colisao com o cone
      P = ray.point(t)
      # Altura da colisao
      point_height = (self.vertice - P).dot_product(self.unitary_vector)

      # Verifica se o valor t encontrado resulta em um ponto dentro da altura do cone
      if point_height >= 0 and point_height <= self.height:
        colision_list.append({
          "color": self.color,
          "point": P,
          "t": t
        })

      # Segundo t encontrado
      t = ((-b+sqrt(delta))/(2*a))
      
      # Ponto de colisao com o cone
      P = ray.point(t)
      # Altura da colisao
      point_height = (self.vertice - P).dot_product(self.unitary_vector)

      # Verifica se o valor t encontrado resulta em um ponto dentro da altura do cone
      if point_height >= 0 and point_height <= self.height:
        colision_list.append({
          "color": self.color,
          "point": P,
          "t": t
        })
      
      return colision_list
