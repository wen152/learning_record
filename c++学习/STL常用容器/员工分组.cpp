#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<map>
#include<ctime>
// ��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
// Ա����Ϣ��: ���� ������ɣ����ŷ�Ϊ���߻����������з�
// �����10��Ա�����䲿�ź͹���
// ͨ��multimap������Ϣ�Ĳ��� key(���ű��) value(Ա��)
// �ֲ�����ʾԱ����Ϣ
#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
    public:
        string m_Name;
        int m_Salary;
};

void createWorker(vector<Worker>&v)
{
        string nameSeed = "ABCDEFGHIJ";
        for (int i = 0; i < 10; i++)
        {
            Worker worker;
            worker.m_Name = "Ա��";
            worker.m_Name += nameSeed[i];//+=����

            worker.m_Salary = rand() % 10000 + 10000;//10000~19999
            v.push_back(worker);
        }
}

void setGroup(vector<Worker>&v, multimap<int,Worker>&m)
{
        for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
        {
            int deptId = rand() % 3;// 0 1 2 ���ű��
            m.insert(make_pair(deptId, *it));//key���ű�ţ�value����Ա��
        }
}

void showWorkerByGroup(multimap<int,Worker>&m)
{
        cout << "�߻�����: " << endl;
        multimap<int, Worker>::iterator pos = m.find(CEHUA);
        int count = m.count(CEHUA);//ͳ�ƾ�������
        
}