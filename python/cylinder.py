from math import sqrt
from point import Point

class Cylinder:
  # Construtor padrão
  def __init__(self, baseCenter, uCylinder, cylinderHeight, cylinderRadius):
    self.B = baseCenter
    self.u = uCylinder
    self.H = cylinderHeight
    self.R = cylinderRadius
    self.color = (101, 67, 33)

  def verifyColision(self, ray):
    v = (ray.p0 - self.B) - self.u*((ray.p0 - self.B).dotProduct(self.u))
    w = ray.d - self.u*ray.d.dotProduct(self.u)
    
    a = w.dotProduct(w)
    b = 2*v.dotProduct(w)
    c = v.dotProduct(v) - self.R**2

    delta = b**2 - 4*a*c

    if delta < 0:
      return []
    elif delta == 0:
      tInt = []
      t = (-b/(2*a))
      P = ray.pointT(t)
      verify = (P - self.B).dotProduct(self.u)

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
      verify = (P - self.B).dotProduct(self.u)
      
      # Verifica se o valor t encontrado resulta em um ponto dentro da altura do cilindro
      if verify >= 0 and verify <= self.H:
        tInt.append({
          "color":self.color,
          "t": t
        })

      # Segundo t
      t = ((-b+sqrt(delta))/(2*a))
      P = ray.pointT(t)
      verify = (P - self.B).dotProduct(self.u)

      # Verifica se o valor t encontrado resulta em um ponto dentro da altura do cilindro
      if verify >= 0 and verify <= self.H:
        tInt.append({
          "color":self.color,
          "t": t
        })
      
      return tInt
