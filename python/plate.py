from point import Point

class Plate:
  # Construtor padrão
  def __init__(self, plateCenter, plateSize, numberOfHoles):
    self.C = plateCenter
    self.S = plateSize
    self.n = numberOfHoles
    self.matrix = [[(255, 255, 255) for x in range(numberOfHoles)] for y in range(numberOfHoles)]

  def point(self, line, column):
    z = self.C.z

    # Calculando x do ponto
    if column < self.n/2:
      x = self.C.x - (self.S/self.n)*((self.n/2 -1) -column) - (self.S/(2*self.n))
    else:
      x = self.C.x + (self.S/self.n)*(column-(self.n/2)) + (self.S/(2*self.n))

    # Calculando y do ponto
    if line < self.n/2:
      y = self.C.y + (self.S/self.n)*((self.n/2 -1) -line) + (self.S/(2*self.n))
    else:
      y = self.C.y - (self.S/self.n)*(line-(self.n/2)) - (self.S/(2*self.n))

    return Point(x, y, z)
