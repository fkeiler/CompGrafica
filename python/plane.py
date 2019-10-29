from numpy import copy

class Plane:
  # Construtor padrão
  def __init__(self, point, unitary_vector):
    self.point_pl = copy(point)
    self.unitary_vector = copy(unitary_vector)

  def verify_colision(self, ray):
    t = (self.point_pl - ray.p0).dot(self.unitary_vector)/ray.d.dot(self.unitary_vector)
    P = ray.point(t)

    return t,P

