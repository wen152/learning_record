#include"Circle.hpp"
void Circle::setr(double r)
{
	m_radius = r;
}
double Circle::getr()
{
	return m_radius;
}
void Circle::setcenter(Point center)
{
	m_center = center;
}
Point Circle::getcenter()
{
	return m_center;
}