#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<map>
#include<ctime>
// 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
// 员工信息有: 姓名 工资组成；部门分为：策划、美术、研发
// 随机给10名员工分配部门和工资
// 通过multimap进行信息的插入 key(部门编号) value(员工)
// 分部门显示员工信息
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
            worker.m_Name = "员工";
            worker.m_Name += nameSeed[i];//+=重载

            worker.m_Salary = rand() % 10000 + 10000;//10000~19999
            v.push_back(worker);
        }
}

void setGroup(vector<Worker>&v, multimap<int,Worker>&m)
{
        for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
        {
            int deptId = rand() % 3;// 0 1 2 部门编号
            m.insert(make_pair(deptId, *it));//key部门编号，value具体员工
        }
}

void showWorkerByGroup(multimap<int,Worker>&m)
{
        cout << "策划部门: " << endl;
        multimap<int, Worker>::iterator pos = m.find(CEHUA);
        int count = m.count(CEHUA);//统计具体人数
        
}