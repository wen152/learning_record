#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;//ͷ�ļ�ֻ������
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