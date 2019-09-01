from math import sqrt

class Point:
  # Construtor padrão
  def __init__(self, xi, yi, zi):
    self.x = xi 
    self.y = yi
    self.z = zi 

  # Sobrecarga do operador de adição
  def __add__(self, other):
    if type(other) == Point:
      return Point(self.x + other.x, self.y + other.y, self.z + other.z)
    else:
      return Point(self.x + other, self.y + other, self.z + other)

  # Sobrecarga do operador de subtração
  def __sub__(self, other):
    if type(other) == Point:
      return Point(self.x - other.x, self.y - other.y, self.z - other.z)
    else:
      return Point(self.x - other, self.y - other, self.z - other)

  # Sobrecarga do operador de multiplicação
  def __mul__(self, other):
    if type(other) != Point:
      return Point(self.x * other, self.y * other, self.z * other)

  # Construtor utilizando 2 pontos
  @classmethod
  def usingTwoPoints(cls, p1, p2):
    x = p2.x - p1.x
    y = p2.y - p1.y
    z = p2.z - p1.z

    return cls(x, y, z)

  # Retorna os valores de x, y, z em uma lista
  def toList(self):
    return [self.x, self.y, self.z]
  
  # Retorna a norma do vetor
  def norm(self):
    return sqrt(self.x**2 + self.y**2 + self.z**2)

  # Retorna o vetor normalizado
  def normalize(self, cls):
    return cls(self.x/self.norm(), self.y/self.norm(), self.z/self.norm())

  # Produto escalar
  def dotProduct(self, pointVector):
    return self.x*pointVector.x + self.y*pointVector.y + self.z*pointVector.z

  def crossProduct(self, pointVector):
    return Point((y*w.z - z*w.y), (z*w.x - x*w.z), (x*w.y - y*w.x))
