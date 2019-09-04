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
    triangles.append(Triangle(self.vertices[0], self.vertices[4], self.vertices[5]))
    triangles.append(Triangle(self.vertices[0], self.vertices[5], self.vertices[1]))
    triangles.append(Triangle(self.vertices[1], self.vertices[5], self.vertices[6]))
    triangles.append(Triangle(self.vertices[1], self.vertices[6], self.vertices[2]))
    triangles.append(Triangle(self.vertices[2], self.vertices[6], self.vertices[7]))
    triangles.append(Triangle(self.vertices[2], self.vertices[7], self.vertices[3]))
    triangles.append(Triangle(self.vertices[3], self.vertices[7], self.vertices[4]))
    triangles.append(Triangle(self.vertices[3], self.vertices[4], self.vertices[0]))
    triangles.append(Triangle(self.vertices[3], self.vertices[0], self.vertices[1]))
    triangles.append(Triangle(self.vertices[3], self.vertices[1], self.vertices[2]))
    triangles.append(Triangle(self.vertices[7], self.vertices[4], self.vertices[5]))
    triangles.append(Triangle(self.vertices[7], self.vertices[5], self.vertices[6]))

    for triangle in triangles:
      colision = triangle.verify_colision(ray)
      
      if colision is not None:
        P = ray.point(colision)
        colision_list.append({
          "color": self.color,
          "point": P,
          "t": colision
        })

    return colision_list
