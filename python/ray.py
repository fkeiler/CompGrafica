from coordinate import Coordinate

class Ray:
  # Construtor padrão
  def __init__(self, p0):
    self.p0 = p0
    self.d = Coordinate(0, 0, 0, 0)

  # Retorna o ponto P(t) com t sendo um escalar
  def point(self, t):
    return self.p0 + self.d*t
