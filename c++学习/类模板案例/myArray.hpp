// ��������: ʵ��һ��ͨ�õ������࣬Ҫ�����£�

// ���Զ��������������Լ��Զ����������͵����ݽ��д洢
// �������е����ݴ洢������
// ���캯���п��Դ������������
// �ṩ��Ӧ�Ŀ������캯���Լ�operator=��ֹǳ��������
// �ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
// ����ͨ���±�ķ�ʽ���������е�Ԫ��
// ���Ի�ȡ�����е�ǰԪ�ظ��������������
#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray 
{
    public:
        //���캯��
        MyArray(int capacity)
        {
            this->m_Capacity = capacity;
            this->m_Size = 0;
            pAddress = new T[this->m_Capacity];//�ڶ���������ô���ڴ�
        }//���ṩĬ���޲ι���

        //��������
        MyArray(const MyArray & arr)
        {
            this->m_Capacity = arr.m_Capacity;
            this->m_Size = arr.m_Size;
            this->pAddress = new T[this->m_Capacity];
            for (int i = 0; i < this->m_Size; i++)
            {
                //��TΪ���󣬰���ָ�룬��Ҫ����=�����
                //T��Ϊ��ͨ���Ϳ���ֱ��= ��ָ��������Ҫ���
                this->pAddress[i] = arr.pAddress[i];
            }
        }//ǳ����ֻ����ָ�룬����ͬһ���ڴ�
        
        //����= ����� ��ֹǳ��������
        MyArray& operator=(const MyArray& myarray)
        {
            if(this->pAddress != NULL)
            {
                delete[] this->pAddress;
                this->m_Capacity = 0;
                this->m_Size = 0;
            }
            this->m_Capacity = myarray.m_Capacity;
            this->m_Size = myarray.m_Size;
            this->pAddress = new T[this->m_Capacity];
            for (int i = 0; i < this->m_Size; i++)
            {
                this->pAddress[i] = myarray[i];
            }
            return *this;
        }

        //����[]������ arr[0]
        T& operator[](int index)
        {
            return this->pAddress[index];
        }

        //β�巨
        void Push_back(const T & val)
        {
            if(this->m_Capacity == this->m_Size)
            {
                return;
            }
            this->pAddress[this->m_Size] = val;
            this->m_Size++;
        }

        //βɾ��
        void Pop_back()
        {
            if(this->m_Size == 0)
            {
                return;
            }
            this->m_Size--;
        }

        //��ȡ��������
        int getCapacity()
        {
            return this->m_Capacity;
        }

        //��ȡ�����С
        int getSize()
        {
            return this->m_Size;
        }

        //����
        ~MyArray()
        {
            if(this->pAddress != NULL)
            {
                delete[] this->pAddress;
                this->pAddress = NULL;
                this->m_Capacity = 0;
                this->m_Size = 0;
            }
        }

    private:
        T * pAddress;//ָ��һ���ѿռ䣬�洢����������
        int m_Capacity;//����
        int m_Size;//��С
};