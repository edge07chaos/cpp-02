#include "Point.hpp"

static Fixed crossProduct(Point const &m, Point const &n, Point const &p) {
    return (n.getX() - m.getX()) * (p.getY() - m.getY()) 
         - (n.getY() - m.getY()) * (p.getX() - m.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed cp1 = crossProduct(a, b, point);
	Fixed cp2 = crossProduct(b, c, point);
	Fixed cp3 = crossProduct(c, a, point);

	return ((cp1 > 0 && cp2 > 0 && cp3 > 0) || (cp1 < 0 && cp2 < 0 && cp3 < 0));
}