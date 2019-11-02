class Ambiente:
  def __init__(self, r, g, b):
    self.intensidade = [r, g, b]

  def aplicar(self, material):
    return [self.intensidade[0] * material.ambient[0], self.intensidade[1] * material.ambient[1], self.intensidade[2] * material.ambient[2]]
