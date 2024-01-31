#pragma once
#include <iostream>
using namespace std;
#include "worker.hpp"
#include "employee.hpp"
#include "manager.hpp"
#include "boss.hpp"
#include <fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
    public:
        WorkerManager();

        ~WorkerManager();

        void show_menu();

        void exitSystem();

        void Add_Emp();//添加新职员

        void save();//保存文件

        int get_EmpNum();//统计人数

        void init_Emp();//初始化员工

        void Show_Emp();//显示职工

        void Del_Emp();//删除职工

        int IsExist(int id);//判断职工是否存在

        void Mod_Emp();//修改职工信息

        void Find_Emp();//查找职工

        void Sort_Emp();//排序

        void Clean_File();//清空记录数据

        //记录文件中的人数个数
        int m_EmpNum;
        //员工数组的指针
        Worker **m_EmpArray;
        //判断文件是否为空
        bool m_FileIsEmpty;
};