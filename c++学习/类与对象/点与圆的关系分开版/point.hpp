#pragma once//防止头文件重复包含
#include<iostream>
using namespace std;//头文件只留声明
class Point
{
public:
	void setX(double x);
	void setY(double y);
	double getX();
	double getY();
private:
	double m_X;
	double m_Y;
};