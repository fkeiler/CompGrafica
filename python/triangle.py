from point import Point

class Triangle:
  #Construtor padrão
  def __init__(self, p, q, r):
    self.p1 = p
    self.p2 = q
    self.p3 = r

  def verifyColision(self, ray):
    v1 = self.p2 - self.p1
    v2 = self.p3 - self.p1
    norma = v1.crossProduct(v2)
    
    if ray.d.dotProduct(norma) == 0:
      return None
    
    tint = (self.p1 - ray.p0).dotProduct(norma) / ray.d.dotProduct(norma)
    Pint = ray.pointT(tint)
    
    if ((self.p2-self.p1).crossProduct(Pint - self.p1)).dotProduct(norma) < 0 or ((self.p3-self.p2).crossProduct(Pint - self.p2)).dotProduct(norma) < 0 or ((self.p1-self.p3).crossProduct(Pint - self.p3)).dotProduct(norma) < 0:
      return None
    
    return tint
 