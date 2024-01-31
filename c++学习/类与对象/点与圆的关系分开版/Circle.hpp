#pragma once//防止头文件重复包含
#include<iostream>
#include"point.hpp"
using namespace std;//头文件只留声明
class Circle
{
public:
	void setr(double r);
	double getr();
	void setcenter(Point center);
	Point getcenter(); 
private:
	double m_radius;
	Point m_center;
};