import numpy as np
from plane import Plane
from sphere import Sphere

class Cube:
  # Construtor padrão
  def __init__(self, baseCenter, cubeEdge, colision, visibility):
    # Informações do cubo
    self.baseCenter = np.copy(baseCenter)
    self.edge = cubeEdge
    
    # Faces do cubo
    self.faces = []

    A = np.array([self.baseCenter[0] - self.edge/2, self.baseCenter[1] + self.edge, self.baseCenter[2] + self.edge/2, 1])
    B = np.array([self.baseCenter[0] + self.edge/2, self.baseCenter[1] + self.edge, self.baseCenter[2] + self.edge/2, 1])
    C = np.array([self.baseCenter[0] - self.edge/2, self.baseCenter[1], self.baseCenter[2] + self.edge/2, 1])
    D = np.array([self.baseCenter[0] + self.edge/2, self.baseCenter[1], self.baseCenter[2] + self.edge/2, 1])
    E = np.array([self.baseCenter[0] - self.edge/2, self.baseCenter[1] + self.edge, self.baseCenter[2] - self.edge/2, 1])
    F = np.array([self.baseCenter[0] + self.edge/2, self.baseCenter[1] + self.edge, self.baseCenter[2] - self.edge/2, 1])
    G = np.array([self.baseCenter[0] - self.edge/2, self.baseCenter[1], self.baseCenter[2] - self.edge/2, 1])
    H = np.array([self.baseCenter[0] + self.edge/2, self.baseCenter[1], self.baseCenter[2] - self.edge/2, 1])

    self.faces.append(Plane(A, B, C, D, np.array([0.0, 0.0, 1.0, 0.0])))
    self.faces.append(Plane(B, F, D, H, np.array([1.0, 0.0, 0.0, 0.0])))
    self.faces.append(Plane(F, E, H, G, np.array([0.0, 0.0, -1.0, 0.0])))
    self.faces.append(Plane(E, A, C, G, np.array([-1.0, 0.0, 0.0, 0.0])))
    self.faces.append(Plane(E, F, A, B, np.array([0.0, 1.0, 0.0, 0.0])))
    self.faces.append(Plane(G, H, C, D, np.array([0.0, -1.0, 0.0, 0.0])))

    # Esfera de contato
    cubeCenter = np.copy(self.baseCenter)
    cubeCenter[1] += self.edge/2
    contactSphereRadius = np.linalg.norm(A - cubeCenter)
    self.contactSphere = Sphere(cubeCenter, contactSphereRadius, True, False)
    
    #self.material = material
    self.colision = colision
    self.visibility = visibility

  def verifyColision(self, ray):
    # Verificando se o objeto recebe colisões
    if not self.colision:
      return []
    
    
    
