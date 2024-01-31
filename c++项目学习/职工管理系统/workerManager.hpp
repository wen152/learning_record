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

        void Add_Emp();//�����ְԱ

        void save();//�����ļ�

        int get_EmpNum();//ͳ������

        void init_Emp();//��ʼ��Ա��

        void Show_Emp();//��ʾְ��

        void Del_Emp();//ɾ��ְ��

        int IsExist(int id);//�ж�ְ���Ƿ����

        void Mod_Emp();//�޸�ְ����Ϣ

        void Find_Emp();//����ְ��

        void Sort_Emp();//����

        void Clean_File();//��ռ�¼����

        //��¼�ļ��е���������
        int m_EmpNum;
        //Ա�������ָ��
        Worker **m_EmpArray;
        //�ж��ļ��Ƿ�Ϊ��
        bool m_FileIsEmpty;
};