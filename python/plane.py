import numpy as np

class Plane:
  # Construtor padrão
  def __init__(self, point1, point2, point3, point4, unitaryVector):
    self.points = []
    self.points.append(point1)
    self.points.append(point2)
    self.points.append(point3)
    self.points.append(point4)
    self.n = np.copy(unitaryVector)

  def verifyColision(self, ray):
    tInt = (self.points[0] - ray.p0).dot(self.n)/ray.d.dot(self.n)
    maxDistance = np.linalg.norm(self.points[3] - self.points[0])
    pInt = ray.point(tInt)

    for point in self.points:
      if np.linalg.norm(pInt - point) > maxDistance:
        return []

    return [pInt]
