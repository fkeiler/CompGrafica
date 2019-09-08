from coordinate import Coordinate

class Sphere:
    #Construtor Padrão
    def __init__(self, center, radius):
        self.center = center
        self.radius = radius

    #Verificando colisão com um raio
    def verify_colision(self, ray):
        a = ray.d.dot_product(ray.d)
        b = 2 * ((ray.p0 - self.center).dot_product(ray.d))
        c = (ray.p0 - self.center).dot_product(ray.p0 - self.center) - radius**2

        delta = b**2 - 4*a*c

        #Delta menor que 0, sem colisão
        if delta < 0:
            return []

        #Delta igual a 0, raio é tangente à esfera
        elif delta == 0:
            colision_list = []

            t = -b/(2*a)

            P = ray.point(t)

            colision_list.append({
                "point": P,
                "t": t
            })

        #Delta maior que 0, raio atravessa a esfera, com 2 pontos de colisão
        else:
            colision_list = []

            t = (-b + delta)/(2*a)
            P = ray.point(t)
            
            colision_list.append({
                "point": P,
                "t": t
            })

            t = (-b - delta)/(2*a)
            P = ray.point(t)

            colision_list.append({
                "point": P,
                "t": t
            })

    #Calcula o vetor normal à superfície da esfera
    def normal_vector(self, P):
        n = (P - self.center)/self.radius
        return n


