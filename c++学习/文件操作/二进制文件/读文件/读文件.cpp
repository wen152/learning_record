#include <iostream>
using namespace std;
#include <fstream>
#include <string>

class Person
{
public:
	char m_Name[64];
	int m_Age;
};

void test()
{
	ifstream ifs("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}

	Person p;
	ifs.read((char *)&p, sizeof(p));

	cout << "������ " << p.m_Name << " ���䣺 " << p.m_Age << endl;
    ifs.close();
}

int main() {

	test();

	system("pause");

	return 0;
}
