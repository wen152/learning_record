#include<iostream>
using namespace std;
#include <string>
//��ģ��
template<class NameType, class AgeType = int>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
public:
	NameType mName;
	AgeType mAge;
};

//1��ָ�����������
void printPerson1(Person<string, int> &p)
{
	p.showPerson();
}
void test01()
{
	Person <string, int >p("�����", 100);
	printPerson1(p);
}

//2������ģ�廯
template <class T1, class T2>
void printPerson2(Person<T1, T2>&p)
{
	p.showPerson();
	cout << "T1������Ϊ�� " << typeid(T1).name() << endl;
	cout << "T2������Ϊ�� " << typeid(T2).name() << endl;
}
void test02()
{
	Person <string, int >p("��˽�", 90);
	printPerson2(p);
}

//3��������ģ�廯
template<class T>
void printPerson3(T & p)
{
	cout << "T������Ϊ�� " << typeid(T).name() << endl;
	p.showPerson();

}
void test03()
{
	Person <string, int >p("��ɮ", 30);
	printPerson3(p);
}

int main() {

	test01();
	test02();
	test03();

	system("pause");

	return 0;
}