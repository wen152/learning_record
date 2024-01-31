#include"point.hpp"
//只留成员函数，必须加作用域，Point作用域下的成员函数
void Point::setX(double x)
{
	m_X = x;
}
void Point::setY(double y)
{
	m_Y = y;
}
double Point::getX()
{
	return m_X;
}
double Point::getY()
{
	return m_Y;
}