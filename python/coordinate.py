from math import sqrt

class Coordinate:
  # Construtor padrão
  def __init__(self, xi, yi, zi, ti):
    self.x = xi 
    self.y = yi
    self.z = zi
    self.t = ti

  # Construtor utilizando 2 pontos
  @classmethod
  def given_two_points(cls, p1, p2):
    x = p2.x - p1.x
    y = p2.y - p1.y
    z = p2.z - p1.z
    t = 1

    return cls(x, y, z, t)

  # Sobrecarga do operador de adição
  def __add__(self, other):
    if type(other) == Coordinate:
      return Coordinate(self.x + other.x, self.y + other.y, self.z + other.z, self.t)
    else:
      return Coordinate(self.x + other, self.y + other, self.z + other, self.t)

  # Sobrecarga do operador de subtração
  def __sub__(self, other):
    if type(other) == Coordinate:
      return Coordinate(self.x - other.x, self.y - other.y, self.z - other.z, self.t)
    else:
      return Coordinate(self.x - other, self.y - other, self.z - other, self.t)

  # Sobrecarga do operador de multiplicação
  def __mul__(self, other):
    if type(other) != Coordinate:
      return Coordinate(self.x * other, self.y * other, self.z * other, self.t)

  # Retorna os valores de x, y, z, t em uma lista
  def to_list(self):
    return [self.x, self.y, self.z, self.t]
  
  # Retorna a norma do vetor
  def norm(self):
    return sqrt(self.x**2 + self.y**2 + self.z**2)

  # Retorna o vetor normalizado
  def normalize(self):
    return Coordinate(self.x/self.norm(), self.y/self.norm(), self.z/self.norm(), 1)

  # Produto escalar
  def dot_product(self, coordinate):
    return self.x*coordinate.x + self.y*coordinate.y + self.z*coordinate.z

  # Cross Product
  def cross_product(self, coordinate):
    return Coordinate((self.y*coordinate.z - self.z*coordinate.y), (self.z*coordinate.x - self.x*coordinate.z), (self.x*coordinate.y - self.y*coordinate.x), self.t)
