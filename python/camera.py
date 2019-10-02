import numpy as np

class Camera:
  def __init__(self, p0, look_at, view_up):
    self.K = (p0[:3] - look_at[:3])/np.linalg.norm(p0[:3] - look_at[:3])
    self.I = np.cross((view_up[:3] - p0[:3]), self.K)/np.linalg.norm(np.cross((view_up[:3] - p0[:3]), self.K))
    self.J = np.cross(self.K, self.I)
    self.Matrix = np.zeros(shape=(4,4))
    
    for i in range(len(self.Matrix[0])-1):
      self.Matrix[0][i] = self.I[i]
      self.Matrix[1][i] = self.J[i]
      self.Matrix[2][i] = self.K[i]
 
    self.Matrix[0][3] = -p0[:3].dot(self.I)
    self.Matrix[1][3] = -p0[:3].dot(self.J)
    self.Matrix[2][3] = -p0[:3].dot(self.K)
    self.Matrix[3][3] = 1

  def convert_to_camera_coord(self, value):
    return value.dot(np.transpose(self.Matrix))
