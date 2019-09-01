#include "Polygon.hpp"

Polygon::Polygon(Point p, Point q, Point r){
    p1 = p;
    p2 = q;
    p3 = r;
}
double Polygon::colisionPoints(Ray R){
    Vector v1 = Vector(p1, p2);
    Vector v2 = Vector(p1, p3);
    Vector norma = v1.crossProduct(v2);
    if(R.d.dotProduct(norma) == 0) return -1; //Se a projeção for 0, o raio é paralelo ou interno ao plano
    double tint = Vector(R.p0, p1).dotProduct(norma) / R.d.dotProduct(norma);
    Point Pint = R.p0 + Point(R.d.x*tint, R.d.y*tint, R.d.z*tint);
    if((Vector(p1, p2).crossProduct(Vector(p1, Pint))).dotProduct(norma) < 0) return -1;
    if((Vector(p2, p3).crossProduct(Vector(p2, Pint))).dotProduct(norma) < 0) return -1;
    if((Vector(p3, p1).crossProduct(Vector(p3, Pint))).dotProduct(norma) < 0) return -1;
    return tint;
}