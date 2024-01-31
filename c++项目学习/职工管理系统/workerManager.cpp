#include <iostream>
using namespace std;
#include "workerManager.hpp"
#include <string>

WorkerManager::WorkerManager()
{
    //this->m_EmpNum = 0;
    //this->m_EmpArray = NULL;
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    //初始时刻文件是否存在
    if(!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;//这里的return的作用是结束构造函数
    }
    //文件存在，并且没有记录
    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        cout << "文件为空!" << endl;
        this->m_EmpNum = 0;
        this->m_FileIsEmpty = true;
        this->m_EmpArray = NULL;
        ifs.close();
        return;//这里的return的作用是结束构造函数
    }
    //文件不为空，初始化职工表
    this->m_EmpArray = new Worker *[this->m_EmpNum];//创建在堆区
    init_Emp();
    //测试代码
    for (int i = 0; i < m_EmpNum; i++)
    {
        cout << "职工号： " << this->m_EmpArray[i]->m_Id
            << " 职工姓名： " << this->m_EmpArray[i]->m_Name
            << " 部门编号： " << this->m_EmpArray[i]->m_DeptId << endl;
    }
}

WorkerManager::~WorkerManager()
{
    if(this->m_EmpArray != NULL)
    {
        delete[] this->m_EmpArray;//释放堆区数据
    }
}

void WorkerManager::show_menu()
{
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);//运行正常，退出程序
}

void WorkerManager::Add_Emp()
{
    cout << "请输入增加的职工数量" << endl;
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0)
    {
        //计算新空间大小
        int newSize = this->m_EmpNum + addNum;
        //开辟新空间
        Worker ** newSpace = new Worker *[newSize];
        //将原空间下内容存放在新空间下
        if(this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        //输入新数据
        for (int i = 0; i < addNum; i++)
            {
                int id;
                string name;
                int did;
                cout << "请输入第" << i + 1 << "个新职员的编号:" << endl;
                cin >> id;
                cout << "请输入第" << i + 1 << "个新职员的姓名:" << endl;
                cin >> name;
                cout << "请选择该新职员的岗位:" << endl;
                cout << "1、普通职工" << endl;
                cout << "2、经理" << endl;
                cout << "3、老板" << endl; 
                cin >> did;
                Worker * worker = NULL;
                switch (did)
                {
                case 1:
                    worker = new Employee(id, name, 1);
                    break;
                case 2:
                    worker = new Manager(id, name, 2);
                    break;
                case 3:
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
                }
                newSpace[this->m_EmpNum + i] = worker;
            }
            //释放原有空间
        delete[] this->m_EmpArray;
        //更改新空间指向
        this->m_EmpArray = newSpace;
        //更新职员数量
        this->m_EmpNum = newSize;
        //更新职员信息不为空标志
        this->m_FileIsEmpty = false;
        //提示信息
        cout << "成功添加" << addNum << "名新职员！" << endl;
        //保存到文件中
        this->save();
        }
    else
    {
        cout << "输入有误" << endl;
    }
    system("pause");
    system("cls");//清屏操作
}

void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << ""
            << this->m_EmpArray[i]->m_Name << ""
            << this->m_EmpArray[i]->m_DeptId << "" << endl;
    }
    ofs.close();
}

int WorkerManager::get_EmpNum()
{
    ifstream ifs;//是否要判断isfile_empty，如何处理这个问题
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int did;
    int num = 0;
    while(ifs>>id && ifs>>name && ifs>>did)
    {
        num++;
    }
    ifs.close();
    return num;
}

void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int did;
    int index = 0;
    while(ifs>>id && ifs>>name && ifs>>did)
    {
        Worker *worker = NULL;
        if(did == 1)
        {
            worker = new Employee(id, name, did);
        }
        else if(did == 2)
        {
            worker = new Manager(id, name, did);
        }
        else
        {
            worker = new Boss(id, name, did);
        }
        //存放在数组中
        this->m_EmpArray[index] = worker;
        index++;
    }
}

void WorkerManager::Show_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else 
    {
        for (int i = 0; i < m_EmpNum; i++)
        {
            //利用多态调用接口
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

int WorkerManager::IsExist(int id)
{
    int index = -1;
    for (int i = 0; i < m_EmpNum; i++)
    {
        if(this->m_EmpArray[i]->m_Id == id)
        {
            index = i;
            break;
        }//重复Id,录入错误
    }
    return index;
}

void WorkerManager::Del_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空!" << endl;
    }
    else
    {
        //按职工编号删除
        cout << "请输入想要删除的职工编号:" << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);

        if (index != -1)
        {
            for (int i = index; i < this->m_EmpNum - 1; i++)
            {
                    this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;

            this->save();//删除后数据同步到文件中
            cout << "删除成功!" << endl;
        }
        else
        {
            cout << "删除失败,未找到该员工" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::Mod_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空!" << endl;
    }
    else
    {
        cout << "请输入想要修改的职工编号:" << endl;
        int id = 0;
        cin >> id;

        int ret = this->IsExist(id);
        if(ret != -1)
        {
            {
                delete this->m_EmpArray[ret];
            }
            int newid = 0;
            string newname = "";
            int newdid = 0;
            cout << "查到： " << id << "号职工，请输入新职工编号： " << endl;
            cin >> newid;
            cout << "请输入新姓名： " << endl;
            cin >> newname;
            cout << "请输入岗位： " << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> newdid;
            Worker *worker = NULL;
            switch (newdid)
            {
            case 1:
                worker = new Employee(newid, newname, newdid);
                break;
            case 2:
                worker = new Manager(newid, newname, newdid);
                break;
            case 3:
                worker = new Boss(newid, newname, newdid);
                break;
            default:
                break;
            }
            //更改数据到数组中
            this->m_EmpArray[ret] = worker;
            cout << "修改成功!" << endl;
            //保存到文件中
            this->save();
        }
        else
        {
            cout << "修改失败,查无此人" << endl;
        }
    }
    //按任意键 清屏
    system("pause");
    system("cls");
}

void WorkerManager::Find_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空!" << endl;
    }
    else
    {
        cout << "请输入查找的方式：" << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按姓名查找" << endl;
        int select_way = 0;
        cin >> select_way;
        if (select_way == 1)
        {
            int id;
            cout << "请输入查找的职工编号：" << endl;
            cin >> id;
            int ret = this->IsExist(id);
            if(ret != -1)
            {
                cout << "请输入查找的职工编号：" << endl;
                this->m_EmpArray[ret]->showInfo();
            }
        }
        else if(select_way == 2)
        {
            string name;
            cout << "请输入查找的姓名：" << endl;
            cin >> name;

            bool flag = false;//查找到的标志
            for (int i = 0; i < m_EmpNum; i++)
            {
                if(m_EmpArray[i]->m_Name == name)
                {
                    cout << "查找成功,职工编号为: " 
                         << m_EmpArray[i]->m_Id
                         << " 号的信息如下: " << endl;
                    flag = true;
                    this->m_EmpArray[i]->showInfo();
                }
            }
            if(flag == false)
            {
                //查无此人
                cout << "查找失败，查无此人" << endl;
            }
        }
        else
        {
            cout << "输入选项有误" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::Sort_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "请选择排序方式： " << endl;
        cout << "1、按职工编号进行升序" << endl;
        cout << "2、按职工编号进行降序" << endl;

        int select_way = 0;
        cin >> select_way;
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            int minOrmax = i;
            for (int j = i + 1; j < this->m_EmpNum; j++)
            {
                if(select_way == 1)
                {
                    if(this->m_EmpArray[minOrmax]->m_Id > this->m_EmpArray[minOrmax]->m_Id)
                    {
                        minOrmax = j;
                    }
                }
                else
                {
                    if(this->m_EmpArray[minOrmax]->m_Id < this->m_EmpArray[minOrmax]->m_Id)
                    {
                        minOrmax = j;
                    }
                }
            }
            if(i != minOrmax)
            {
                Worker *temp = m_EmpArray[i];
                m_EmpArray[i] = m_EmpArray[minOrmax];
                m_EmpArray[minOrmax] = temp;
            }
        }
        cout << "排序成功,排序后结果为：" << endl;
        this->save();
        this->Show_Emp();//全部显示
    }
}

void WorkerManager::Clean_File()
{
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;

    if(select == 1)
    {
        //打开模式ios::trunc 如果存在删除文件并重新创建
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if(this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                if(this->m_EmpArray[i] != NULL)
                {
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum = 0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_FileIsEmpty = true;
        }
        cout << "清空成功!" << endl;
    }
    system("pause");
    system("cls");
}