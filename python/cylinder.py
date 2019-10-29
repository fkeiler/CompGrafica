from math import sqrt
from numpy import copy
from numpy.linalg import norm

from plane import Plane

class Cylinder:
  # Construtor padrão
  def __init__(self, base_center, unitary_vector, height, radius):
    self.base_center = copy(base_center)
    self.unitary_vector = copy(unitary_vector)
    self.height = height
    self.radius = radius
    self.base = Plane(self.base_center, self.unitary_vector*-1)
    self.top = Plane(self.base_center + self.unitary_vector*height, self.unitary_vector)
    self.color = (101, 67, 33)
    # Depois alterar o material

  def verify_colision(self, ray):
    # Variaveis criadas para simplificar os calculos
    v = (ray.p0 - self.base_center) - self.unitary_vector * ((ray.p0 - self.base_center).dot(self.unitary_vector))
    w = ray.d - self.unitary_vector * ray.d.dot(self.unitary_vector)
    
    # a, b e c calculados
    a = w.dot(w)
    b = 2*v.dot(w)
    c = v.dot(v) - self.radius**2

    colision_list = []

    # Verificar colisão com o topo e a base do cilindro
    # Verificando colisão com a base
    t,P = self.base.verify_colision(ray)
    print(P)
    print(norm(P - self.base.point_pl))
    if norm(P - self.base.point_pl) <= self.radius:
      colision_list.append({
        "color": self.color,
        "point": P,
        "t": t
      })

    # Verificando colisão com o topo
    t,P = self.top.verify_colision(ray)
    if norm(P - self.top.point_pl) <= self.radius:
      colision_list.append({
        "color": self.color,
        "point": P,
        "t": t
      })

    # Caso a igual à zero d é paralelo ao vetor unitário do cilindro
    if a == 0:
      print(colision_list)
      return colision_list

    # delta calculado
    delta = b**2 - 4*a*c
    print(delta)

    # Verificar se houve uma, duas ou se nao houveram colisoes
    # Se o valor delta for menor que 0 nao ocorre nenhuma colisao
    # Se o valor delta for igual a 0 pode ter ocorrido uma colisao dependendo da altura
    # Se o valor delta for maior que 0 podem ter ocorrido duas colisoes dependendo da altura
    if delta < 0:
      return []
    elif delta == 0:
      t = (-b/(2*a))
      
      # Ponto de colisao com o cilindro
      P = ray.point(t)
      # Altura da colisao
      point_height = (P - self.base_center).dot(self.unitary_vector)

      # Verifica se o valor t encontrado resulta em um ponto dentro da altura do cilindro
      if point_height >= 0 and point_height <= self.height:
        colision_list.append({
          "color": self.color,
          "point": P,
          "t": t
        })

      print(colision_list)
      return colision_list
    else:
      # Primeiro t encontrado
      t = ((-b-sqrt(delta))/(2*a))
      
      # Ponto de colisao com o cilindro
      P = ray.point(t)
      print(P)
      # Altura da colisao
      point_height = (P - self.base_center).dot(self.unitary_vector)
      
      # Verifica se o valor t encontrado resulta em um ponto dentro da altura do cilindro
      if point_height >= 0 and point_height <= self.height:
        colision_list.append({
          "color": self.color,
          "point": P,
          "t": t
        })

      # Segundo t encontrado
      t = ((-b+sqrt(delta))/(2*a))
      
      # Ponto de colisao com o cilindro
      P = ray.point(t)
      print(P)
      # Altura da colisao
      point_height = (P - self.base_center).dot(self.unitary_vector)
      
      # Verifica se o valor t encontrado resulta em um ponto dentro da altura do cilindro
      if point_height >= 0 and point_height <= self.height:
        colision_list.append({
          "color": self.color,
          "point": P,
          "t": t
        })
      
      print(colision_list)
      return colision_list
