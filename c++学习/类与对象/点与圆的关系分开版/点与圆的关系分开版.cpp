#include<iostream>
#include<math.h>
#include"point.hpp"
#include"Circle.hpp"
using namespace std;
//����Բ��
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