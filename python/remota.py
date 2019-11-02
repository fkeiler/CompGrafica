import numpy as np

class Remota:
  def __init__(self, r, g, b, direct):
    self.intensidade = [r, g, b]
    self.direcao = direct

  def aplicar(self, material, ponto, objeto):
    normal = np.linalg.norm(objeto)
    fatorDifuso = max(np.dot(normal,self.direcao), 0)
    return [self.intensidade[0]*material.diffuse[0]*fatorDifuso, self.intensidade[1]*material.diffuse[1]*fatorDifuso, self.intensidade[2]*material.diffuse[2]*fatorDifuso]
