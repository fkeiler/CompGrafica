from point import Point

class Plate:
  # Construtor padrão
  def __init__(self, plateCenter, plateSize, numberOfHoles):
    self.C = plateCenter
    self.S = plateSize
    self.n = numberOfHoles
    self.matrix = [[(255, 255, 255) for x in range(numberOfHoles)] for y in range(numberOfHoles)]

  def point(self, i, j):
    z = self.C.z

    # Calculando x do ponto
    if i < self.n/2:
      x = self.C.x - (self.S/self.n)*(49-i) - (self.S/(2*self.n))
    else:
      x = self.C.x + (self.S/self.n)*(i-50) + (self.S/(2*self.n))

    # Calculando y do ponto
    if j < self.n/2:
      y = self.C.x + (self.S/self.n)*(49-j) + (self.S/(2*self.n))
    else:
      y = self.C.x - (self.S/self.n)*(j-50) - (self.S/(2*self.n))

    return Point(x, y, z)
