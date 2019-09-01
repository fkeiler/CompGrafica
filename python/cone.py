from math import sqrt
from point import Point

class Cone:
  # Construtor padrão
  def __init__(self, baseCenter, uCone, coneHeight, coneRadius):
    self.C = baseCenter
    self.u = uCone
    self.H = coneHeight
    self.R = coneRadius
    self.V = self.C + self.u*self.H
    self.cosTheta = self.H/sqrt(self.H**2 + self.R**2)
    self.color = (57, 220, 20)

  def verifyColision(self, ray):
    v = self.V - ray.p0

    a = ray.d.dotProduct(self.u)**2 - ray.d.dotProduct(ray.d)*(self.cosTheta**2)
    b = 2*(v.dotProduct(ray.d)*(self.cosTheta**2) - v.dotProduct(self.u)*ray.d.dotProduct(self.u))
    c = v.dotProduct(self.u)**2 - v.dotProduct(v)*(self.cosTheta**2)

    # Verificando o caso de que a = 0
    if a == 0:
      tInt = []
      t = -c/b
      tInt.append({
        "color":self.color,
        "t": t
      })
      return tInt

    delta = b**2 - 4*a*c

    if delta < 0:
      return []
    elif delta == 0:
      tInt = []
      t = (-b/(2*a))
      P = ray.pointT(t)
      verify = (self.V - P).dotProduct(self.u)

      # Verifica se o valor t encontrado resulta em um ponto dentro da altura do cilindro
      if verify >= 0 and verify <= self.H:
        tInt.append({
          "color":self.color,
          "t": t
        })

      return tInt
    else:
      tInt = []
      # Primeiro t
      t = ((-b-sqrt(delta))/(2*a))
      P = ray.pointT(t)
      verify = (self.V - P).dotProduct(self.u)
      
      # Verifica se o valor t encontrado resulta em um ponto dentro da altura do cilindro
      if verify >= 0 and verify <= self.H:
        tInt.append({
          "color":self.color,
          "t": t
        })

      # Segundo t
      t = ((-b+sqrt(delta))/(2*a))
      P = ray.pointT(t)
      verify = (self.V - P).dotProduct(self.u)

      # Verifica se o valor t encontrado resulta em um ponto dentro da altura do cilindro
      if verify >= 0 and verify <= self.H:
        tInt.append({
          "color":self.color,
          "t": t
        })
      
      return tInt
