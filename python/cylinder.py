from math import sqrt

class Cylinder:
  # Construtor padrão
  def __init__(self, base_center, unitary_vector, height, radius):
    self.base_center = base_center
    self.unitary_vector = unitary_vector
    self.height = height
    self.radius = radius
    self.color = (101, 67, 33)

  def verify_colision(self, ray):
    # Variaveis criadas para simplificar os calculos
    v = (ray.p0 - self.base_center) - self.unitary_vector * ((ray.p0 - self.base_center).dot_product(self.unitary_vector))
    w = ray.d - self.unitary_vector * ray.d.dot_product(self.unitary_vector)
    
    # a, b e c calculados
    a = w.dot_product(w)
    b = 2*v.dot_product(w)
    c = v.dot_product(v) - self.radius**2

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
      
      # Ponto de colisao com o cilindro
      P = ray.point(t)
      # Altura da colisao
      point_height = (P - self.base_center).dot_product(self.unitary_vector)

      # Verifica se o valor t encontrado resulta em um ponto dentro da altura do cilindro
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
      
      # Ponto de colisao com o cilindro
      P = ray.point(t)
      # Altura da colisao
      point_height = (P - self.base_center).dot_product(self.unitary_vector)
      
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
      # Altura da colisao
      point_height = (P - self.base_center).dot_product(self.unitary_vector)
      
      # Verifica se o valor t encontrado resulta em um ponto dentro da altura do cilindro
      if point_height >= 0 and point_height <= self.height:
        colision_list.append({
          "color": self.color,
          "point": P,
          "t": t
        })
      
      return colision_list
