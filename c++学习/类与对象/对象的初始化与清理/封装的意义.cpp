#include<iostream>
using namespace std;
/*
���Բ�࣬��Բ���ܳ�
*/
#define PI 3.14

class Circle
{
	//����Ȩ��
	//����Ȩ��
public:
	//����
	//�뾶
	int m_r;
	//��Ϊ
	//��ȡԲ���ܳ�
	double calculateZC()
	{
		return 2 * PI* m_r;
	}
};

int main()
{
	Circle c1;
	//ͨ��Բ�� ���������Բ(����)
	c1.m_r = 10;
	cout << "Բ���ܳ�Ϊ��" << c1.calculateZC() << endl;
}