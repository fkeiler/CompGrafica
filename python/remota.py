class Remota:
  def __init__(self, r, g, b, direct):
    self.intensidade = [r, g, b];
    self.direcao = direct;

  def aplicar(self, material, ponto, objeto):
    normal = objeto.normal_vector(ponto)
    fatorDifuso = max(normal.dot_product(self.direcao), 0)
    return [self.intensidade[0]*material.diffuse[0]*fatorDifuso, self.intensidade[1]*material.diffuse[1]*fatorDifuso, self.intensidade[2]*material.diffuse[2]*fatorDifuso]

