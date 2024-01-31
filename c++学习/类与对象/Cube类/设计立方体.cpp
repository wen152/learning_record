#include<iostream>
#include<string>
using namespace std;
//提供公共接口
class Cube
{
public:
	//设置属性
	void setL(int l)
	{
		m_L = l;

	}
	void setW(int w)
	{
		m_W = w;

	}
	void setH(int h)
	{
		m_H = h;

	}
	//获取属性
	int getL()
	{
		return m_L;
	}
	int getW()
	{
		return m_W;
	}
	int getH()
	{
		return m_H;
	}
	//其他
	int calculateSquare()
	{
		return 2 * (m_L*m_W + m_L*m_H + m_W*m_H);
	}
	int calculateV()
	{
		return m_L*m_W*m_H;
	}
	bool isSameByClass(Cube &c)
	{
		return 1;
	}
private://成员属性一般设置为私有权限
	int m_L;
	int m_W;
	int m_H;
};
bool isSame(Cube &c1,Cube &c2)
{

}
int main()
{
	Cube c1, c2;
	c1.isSameByClass(c2);
	return 0;
}