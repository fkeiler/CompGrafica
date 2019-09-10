class Material:
  def __init__(self, ambient, diffuse, specular, shininess):
    self.ambient = ambient      # Vetor [R, G, B]
    self.diffuse = diffuse      # Vetor [R, G, B]
    self.specular = specular    # Vetor [R, G, B]
    self.shininess = shininess  # Constante alpha
