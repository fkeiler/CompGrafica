class Camera:
  def __init__(self, p0, look_at, view_up):
    self.K = (p0 - look_at).normalize()
    self.I = ((view_up - p0).cross_product(self.K)).normalize()
    self.J = self.K.cross_product(self.I)
    
    self.Matrix = [[0 for x in range(4)] for y in range(4)]
    
    for i in range(len(self.Matrix[0])-1):
      self.Matrix[0][i] = self.K.to_list()[i]
    for i in range(len(self.Matrix[0])-1):
      self.Matrix[1][i] = self.I.to_list()[i]
    for i in range(len(self.Matrix[0])-1):
      self.Matrix[2][i] = self.J.to_list()[i]

    self.Matrix[3][0] = -p0.dot_product(self.I)
    self.Matrix[3][1] = -p0.dot_product(self.J)
    self.Matrix[3][2] = -p0.dot_product(self.K)
    self.Matrix[3][3] = 1

  def convert_to_camera(self, coordinate):
    pass
