import numpy as np

class Sphere:
  # Construtor Padrão
  def __init__(self, centerSphere, radius, colision, visibility):
    self.center = np.copy(centerSphere)
    self.radius = radius
    self.colision = colision
    self.visibility = visibility

  def verifyColision(self, ray):
    # Caso a colisão esteja desligada
    if not self.colision:
      return []

    a = ray.d.dot(d)
    b = 2*(ray.p0 - self.center).dot(d)
    c = (ray.p0 - self.center).dot(ray.p0 - self.center) - self.radius**2

    delta = b**2 - 4*a*c

