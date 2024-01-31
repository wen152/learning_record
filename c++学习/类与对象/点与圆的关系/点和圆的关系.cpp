#include<iostream>
#include<math.h>
using namespace std;
//��������
class Point
{
public:
	void setX(double x)
	{
		m_X = x;
	}
	void setY(double y)
	{
		m_Y = y;
	}
	double getX()
	{
		return m_X;
	}
	double getY()
	{
		return m_Y;
	}
private:
	double m_X;
	double m_Y;
};
//����Բ��
class Circle
{
public:
	void setr(double r)
	{
		m_radius = r;
	}
	double getr()
	{
		return m_radius;
	}
	void setcenter(Point center)
	{
		m_center = center;
	}
	Point getcenter()
	{
		return m_center;
	}
private:
	double m_radius;
	Point m_center;
};
void isIncircle(Circle& c, Point& p)
{
	double dis = pow((c.getcenter().getX() - p.getX()), 2) + pow((c.getcenter().getY() - p.getY()), 2);
	double r_dis = pow(c.getr(), 2);
	if (dis > r_dis)
		cout << "����Բ��" << endl;
	else if (dis == r_dis)
		cout << "����Բ��" << endl;
	else
		cout << "����Բ��" << endl;
}
int main()
{
	Point center;
	Circle circle;
	cout << "����һ�������ֱ�߹�ϵ�ĳ���" << endl;
	//cout << "�����������꣺" << endl;
	center.setX(10);
	center.setY(10);
	circle.setr(10);
	circle.setcenter(center);
	Point p;
	p.setX(0);
	p.setY(0);
	isIncircle(circle, p);
	system("pause");
	return 0;
}