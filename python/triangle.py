class Triangle:
  #Construtor padrão
  def __init__(self, p, q, r):
    self.p1 = p
    self.p2 = q
    self.p3 = r

  def verify_colision(self, ray):
    v1 = self.p2 - self.p1
    v2 = self.p3 - self.p1
    norma = v1.cross_product(v2)
    
    if ray.d.dot_product(norma) == 0:
      return None
    
    t_int = (self.p1 - ray.p0).dot_product(norma) / ray.d.dot_product(norma)
    p_int = ray.point(t_int)
    
    if ((self.p2-self.p1).cross_product(p_int - self.p1)).dot_product(norma) < 0 or ((self.p3-self.p2).cross_product(p_int - self.p2)).dot_product(norma) < 0 or ((self.p1-self.p3).cross_product(p_int - self.p3)).dot_product(norma) < 0:
      return None
    
    return t_int
  
  def normal_vector(self):
    v1 = self.p2 - self.p1
    v2 = self.p3 - self.p1

    N = v1.cross_product(v2)

    n_vector = N * (1/N.norm())

    return n_vector