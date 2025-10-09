#include "Point.hpp"

// Calcule le produit vectoriel entre AB et AP
static Fixed cross(Point const& a, Point const& b, Point const& p)
{
	Fixed abx = b.getX() - a.getX();
	Fixed aby = b.getY() - a.getY();
	Fixed apx = p.getX() - a.getX();
	Fixed apy = p.getY() - a.getY();
	return abx * apy - aby * apx;
}

// Vérifie si un point est à l'intérieur d'un triangle
bool bsp(Point const& a, Point const& b, Point const& c, Point const& p)
{
	Fixed c1 = cross(a, b, p);
	Fixed c2 = cross(b, c, p);
	Fixed c3 = cross(c, a, p);

	if (abs(c1.toFloat()) < 0.0001 || abs(c2.toFloat()) < 0.0001 || abs(c3.toFloat()) < 0.0001)
 	   return false;

	bool pos = (c1 > Fixed(0)) && (c2 > Fixed(0)) && (c3 > Fixed(0));
	bool neg = (c1 < Fixed(0)) && (c2 < Fixed(0)) && (c3 < Fixed(0));
	return pos || neg;
}
