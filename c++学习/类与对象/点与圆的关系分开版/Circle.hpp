#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
#include"point.hpp"
using namespace std;//ͷ�ļ�ֻ������
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