#include<iostream>
using namespace std;
/*
设计圆类，求圆的周长
*/
#define PI 3.14

class Circle
{
	//访问权限
	//公共权限
public:
	//属性
	//半径
	int m_r;
	//行为
	//获取圆的周长
	double calculateZC()
	{
		return 2 * PI* m_r;
	}
};

int main()
{
	Circle c1;
	//通过圆类 创建具体的圆(对象)
	c1.m_r = 10;
	cout << "圆的周长为：" << c1.calculateZC() << endl;
}