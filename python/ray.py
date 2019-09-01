from point import Point

class Ray:
  # Construtor padrão
  def __init__(self, p0Entrada, dEntrada):
    self.p0 = p0Entrada
    self.d = dEntrada

  # Retorna o ponto P(t) com t sendo um escalar
  def pointT(self, t):
    return self.p0 + self.d*t
