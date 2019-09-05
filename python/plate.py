from coordinate import Coordinate

class Plate:
  # Construtor padrão
  def __init__(self, size, number_of_holes, distance):
    self.size = size
    self.number_of_holes = number_of_holes
    self.distance = distance
    self.buffer = [[(255, 255, 255) for x in range(self.number_of_holes)] for y in range(self.number_of_holes)]

  def point(self, line, column):
    delta_x = self.size/self.number_of_holes
    delta_y = self.size/self.number_of_holes

    x = -self.size/2 + delta_x/2 + column*delta_x
    y = self.size/2 - delta_y/2 - line*delta_y
    z = -self.distance

    return Coordinate(x, y, z, 1)
