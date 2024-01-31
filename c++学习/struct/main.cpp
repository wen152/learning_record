#include<iostream>
using namespace std;
int * func()
{
	int * p = new int(10);
	//堆区的数据由程序员开辟和释放
	return p;
}
void test()
{
	int * arr = new int[10];//创建10整型数据的数组，在堆区
	for (int i = 0; i < 10; i++)
	{
		arr[i] = 100 + i;
		cout << arr[i] << endl;
	}
	delete[] arr;//释放堆区数组
	//释放数组的时候，需要加[]
}
int main()
{
	int * p = func();
	cout << p << endl;
	cout << *p << endl;
	delete p;//内存已经被释放，再次访问就是非法操作
	test();
	system("pause");
	return 0;
}