#include<iostream>
using namespace std;
int * func()
{
	int * p = new int(10);
	//�����������ɳ���Ա���ٺ��ͷ�
	return p;
}
void test()
{
	int * arr = new int[10];//����10�������ݵ����飬�ڶ���
	for (int i = 0; i < 10; i++)
	{
		arr[i] = 100 + i;
		cout << arr[i] << endl;
	}
	delete[] arr;//�ͷŶ�������
	//�ͷ������ʱ����Ҫ��[]
}
int main()
{
	int * p = func();
	cout << p << endl;
	cout << *p << endl;
	delete p;//�ڴ��Ѿ����ͷţ��ٴη��ʾ��ǷǷ�����
	test();
	system("pause");
	return 0;
}