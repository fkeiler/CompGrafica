from numpy import copy, zeros

class Ray:
  # Construtor padrão
  def __init__(self, p0):
    self.p0 = copy(p0)
    self.d = zeros(4)

  # Retorna o ponto P(t) com t sendo um escalar
  def point(self, t):
    return self.p0 + self.d*t
