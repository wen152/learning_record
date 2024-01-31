#include<iostream>
#include<math.h>
#include"point.hpp"
#include"Circle.hpp"
using namespace std;
//创建圆类
void isIncircle(Circle& c, Point& p)
{
	double dis = pow((c.getcenter().getX() - p.getX()), 2) + pow((c.getcenter().getY() - p.getY()), 2);
	double r_dis = pow(c.getr(), 2);
	if (dis > r_dis)
		cout << "点在圆外" << endl;
	else if (dis == r_dis)
		cout << "点在圆上" << endl;
	else
		cout << "点在圆内" << endl;
}
int main()
{
	Point center;
	Circle circle;
	cout << "这是一个求点与直线关系的程序" << endl;
	//cout << "请输入点的坐标：" << endl;
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