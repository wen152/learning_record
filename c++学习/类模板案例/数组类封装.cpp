// ��������: ʵ��һ��ͨ�õ������࣬Ҫ�����£�

// ���Զ��������������Լ��Զ����������͵����ݽ��д洢
// �������е����ݴ洢������
// ���캯���п��Դ������������
// �ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ��������
// �ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
// ����ͨ���±�ķ�ʽ���������е�Ԫ��
// ���Ի�ȡ�����е�ǰԪ�ظ��������������
#include<iostream>
#include<string>
#include"myArray.hpp"

void printIntArray(MyArray<int>& arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//�������ú�������
void test01()
{
    MyArray<int> array1(10);
    for (int i = 0; i < 10; i++)
    {
        array1.Push_back(i);
    }//m_Size��ʼ��Ϊ0
    cout << "array1��ӡ���" << endl;
    printIntArray(array1);
    cout << "array1�Ĵ�С" << array1.getSize() << endl;
    cout << "array1������" << array1.getCapacity() << endl;
    cout << "-------------------------------" << endl;

    MyArray<int> array2(array1);
    array2.Pop_back();
    cout << "array2�Ĵ�С" << array1.getSize() << endl;
    cout << "array2������" << array1.getCapacity() << endl;
}

//�����Զ�����������
class Person
{
    public:
        Person()
        {

        }
        Person(string name, int age)
        {
            this->m_Name = name;
            this->m_Age = age;
        }
    public:
        string m_Name;
        int m_Age;
};

void printPersonArray(MyArray<Person> & personArr)
{
        for (int i = 0; i < personArr.getSize(); i++)
        {
            cout << "����:" << personArr[i].m_Name << " ����:" << personArr[i].m_Age << endl;
        }
}

void test02()
{
    //��������
    MyArray<Person> pArray(10);
	Person p1("�����", 30);
	Person p2("����", 20);
	Person p3("槼�", 18);
	Person p4("���Ѿ�", 15);
	Person p5("����", 24);
    //��������
	pArray.Push_back(p1);
	pArray.Push_back(p2);
	pArray.Push_back(p3);
	pArray.Push_back(p4);
	pArray.Push_back(p5);
    printPersonArray(pArray);

	cout << "pArray�Ĵ�С��" << pArray.getSize() << endl;
	cout << "pArray��������" << pArray.getCapacity() << endl;
}

int main() {

	//test01();

	test02();

	system("pause");

    return 0;
}