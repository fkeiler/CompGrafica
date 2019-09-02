from math import sqrt
from point import Point
from triangle import Triangle

class Cube:
  # Construtor padrão
  def __init__(self, cubeCenter, cubeEdge):
    self.C = cubeCenter
    self.e = cubeEdge
    # Vertices do Cubo
    self.v1 = Point(cubeCenter.x - cubeEdge/2, cubeCenter.y + cubeEdge, cubeCenter.z + cubeEdge/2)
    self.v2 = Point(cubeCenter.x + cubeEdge/2, cubeCenter.y + cubeEdge, cubeCenter.z + cubeEdge/2)
    self.v3 = Point(cubeCenter.x + cubeEdge/2, cubeCenter.y + cubeEdge, cubeCenter.z - cubeEdge/2)
    self.v4 = Point(cubeCenter.x - cubeEdge/2, cubeCenter.y + cubeEdge, cubeCenter.z - cubeEdge/2)
    self.v5 = Point(cubeCenter.x - cubeEdge/2, cubeCenter.y, cubeCenter.z + cubeEdge/2)
    self.v6 = Point(cubeCenter.x + cubeEdge/2, cubeCenter.y, cubeCenter.z + cubeEdge/2)
    self.v7 = Point(cubeCenter.x + cubeEdge/2, cubeCenter.y, cubeCenter.z - cubeEdge/2)
    self.v8 = Point(cubeCenter.x - cubeEdge/2, cubeCenter.y, cubeCenter.z - cubeEdge/2)
    # Triangulos da face
    self.triangles = []
    self.triangles.append(Triangle(self.v1, self.v5, self.v6))
    self.triangles.append(Triangle(self.v1, self.v6, self.v2))
    self.triangles.append(Triangle(self.v2, self.v6, self.v7))
    self.triangles.append(Triangle(self.v2, self.v7, self.v3))
    self.triangles.append(Triangle(self.v3, self.v7, self.v8))
    self.triangles.append(Triangle(self.v3, self.v8, self.v4))
    self.triangles.append(Triangle(self.v4, self.v8, self.v5))
    self.triangles.append(Triangle(self.v4, self.v5, self.v1))
    self.triangles.append(Triangle(self.v4, self.v1, self.v2))
    self.triangles.append(Triangle(self.v4, self.v2, self.v3))
    self.triangles.append(Triangle(self.v8, self.v5, self.v6))
    self.triangles.append(Triangle(self.v8, self.v6, self.v7))
    self.color = (0, 139, 204)
  
  def verifyColision(self, ray):
    colisions = []

    for triangle in self.triangles:
      colision = triangle.verifyColision(ray)
      
      if colision is not None:
        colisions.append({
          "color": self.color,
          "t": colision
        })

    return colisions
