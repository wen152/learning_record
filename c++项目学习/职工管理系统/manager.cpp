#include <iostream>
using namespace std;
#include "manager.hpp"

Manager::Manager(int id, string name, int did)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = did;
}

void Manager::showInfo()
{
    cout << "ְ����ţ� " << this->m_Id
        << " \tְ�������� " << this->m_Name
        << " \t��λ��" << this->getDeptName()
        << " \t��λְ������ϰ彻��������,���·������Ա��" << endl;//\tˮƽ�Ʊ�������һ��TABλ��
}

string Manager::getDeptName()
{
    return string("����");
}
