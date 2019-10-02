import numpy as np

class Plate:
  # Construtor padrão
  def __init__(self, size, plate_size_horizontal, plate_size_vertical, distance, size_x, size_y):
    self.plate_size_horizontal = plate_size_horizontal
    self.plate_size_vertical = plate_size_vertical
    self.distance = distance
    self.width = size_x
    self.height = size_y
    self.buffer = [[(255, 255, 255) for x in range(self.width)] for y in range(self.height)]

  def point(self, line, column):
    delta_x = self.plate_size_horizontal/self.width
    delta_y = self.plate_size_vertical/self.height

    x = -self.plate_size_horizontal/2 + delta_x/2 + column*delta_x
    y =  self.plate_size_vertical/2 - delta_y/2 - line*delta_y
    z = -self.distance

    return np.array([x, y, z, 1])

