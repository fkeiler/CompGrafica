from math import sqrt
from coordinate import Coordinate
from triangle import Triangle

class Cube:
  # Construtor padrão
  def __init__(self, base_center, cube_edge):
    self.base_center = base_center
    self.edge = cube_edge
    # Vertices do Cubo
    self.vertices = []
    self.vertices.append(Coordinate(base_center.x - cube_edge/2, base_center.y + cube_edge, base_center.z + cube_edge/2, 0))
    self.vertices.append(Coordinate(base_center.x + cube_edge/2, base_center.y + cube_edge, base_center.z + cube_edge/2, 0))
    self.vertices.append(Coordinate(base_center.x + cube_edge/2, base_center.y + cube_edge, base_center.z - cube_edge/2, 0))
    self.vertices.append(Coordinate(base_center.x - cube_edge/2, base_center.y + cube_edge, base_center.z - cube_edge/2, 0))
    self.vertices.append(Coordinate(base_center.x - cube_edge/2, base_center.y, base_center.z + cube_edge/2, 0))
    self.vertices.append(Coordinate(base_center.x + cube_edge/2, base_center.y, base_center.z + cube_edge/2, 0))
    self.vertices.append(Coordinate(base_center.x + cube_edge/2, base_center.y, base_center.z - cube_edge/2, 0))
    self.vertices.append(Coordinate(base_center.x - cube_edge/2, base_center.y, base_center.z - cube_edge/2, 0))
    self.color = (0, 139, 204)
  
  def verify_colision(self, ray):
    colision_list = []

    # Triangulos da face
    triangles = []
    triangles.append(Triangle(self.v1, self.v5, self.v6))
    triangles.append(Triangle(self.v1, self.v6, self.v2))
    triangles.append(Triangle(self.v2, self.v6, self.v7))
    triangles.append(Triangle(self.v2, self.v7, self.v3))
    triangles.append(Triangle(self.v3, self.v7, self.v8))
    triangles.append(Triangle(self.v3, self.v8, self.v4))
    triangles.append(Triangle(self.v4, self.v8, self.v5))
    triangles.append(Triangle(self.v4, self.v5, self.v1))
    triangles.append(Triangle(self.v4, self.v1, self.v2))
    triangles.append(Triangle(self.v4, self.v2, self.v3))
    triangles.append(Triangle(self.v8, self.v5, self.v6))
    triangles.append(Triangle(self.v8, self.v6, self.v7))

    for triangle in triangles:
      colision = triangle.verify_colision(ray)
      
      if colision is not None:
        P = ray.pointT(colision)
        colision_list.append({
          "color": self.color,
          "point": P,
          "t": colision
        })

    return colision_list
