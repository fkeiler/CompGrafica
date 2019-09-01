from point import Point

class Polygon:
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
            return NULL
        tint = (p1 - R.p0).dotProduct(norma) / R.d.dotProduct(norma)
        Pint = R.pointT(tint);
        if ((p2-p1).crossProduct(Pint - p1)).dotProduct(norma) < 0 or ((p3-p2).crossProduct(Pint - p2)).dotProduct(norma) < 0 or ((p1-p3).crossProduct(Pint - p3)).dotProduct(norma) < 0:
            return NULL
        return tint
