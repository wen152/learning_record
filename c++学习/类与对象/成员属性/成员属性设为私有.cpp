#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	void setname(string name)
	{
		m_name = name;
	}
	string getname()
	{
		return m_name;
	}

private:
	string m_name;
	int m_age;
	string m_lover;
};

int main()
{
	Person p;
	p.setname("уехЩ");
	cout << p.getname() << endl;
	system("pause");
	return 0;
}