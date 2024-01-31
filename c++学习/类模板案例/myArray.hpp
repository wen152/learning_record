// 案例描述: 实现一个通用的数组类，要求如下：

// 可以对内置数据类型以及自定义数据类型的数据进行存储
// 将数组中的数据存储到堆区
// 构造函数中可以传入数组的容量
// 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
// 提供尾插法和尾删法对数组中的数据进行增加和删除
// 可以通过下标的方式访问数组中的元素
// 可以获取数组中当前元素个数和数组的容量
#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray 
{
    public:
        //构造函数
        MyArray(int capacity)
        {
            this->m_Capacity = capacity;
            this->m_Size = 0;
            pAddress = new T[this->m_Capacity];//在堆区分配这么多内存
        }//不提供默认无参构造

        //拷贝函数
        MyArray(const MyArray & arr)
        {
            this->m_Capacity = arr.m_Capacity;
            this->m_Size = arr.m_Size;
            this->pAddress = new T[this->m_Capacity];
            for (int i = 0; i < this->m_Size; i++)
            {
                //若T为对象，包含指针，需要重载=运算符
                //T若为普通类型可以直接= 但指针类型需要深拷贝
                this->pAddress[i] = arr.pAddress[i];
            }
        }//浅拷贝只拷贝指针，共享同一块内存
        
        //重载= 运算符 防止浅拷贝问题
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

        //重载[]操作符 arr[0]
        T& operator[](int index)
        {
            return this->pAddress[index];
        }

        //尾插法
        void Push_back(const T & val)
        {
            if(this->m_Capacity == this->m_Size)
            {
                return;
            }
            this->pAddress[this->m_Size] = val;
            this->m_Size++;
        }

        //尾删法
        void Pop_back()
        {
            if(this->m_Size == 0)
            {
                return;
            }
            this->m_Size--;
        }

        //获取数组容量
        int getCapacity()
        {
            return this->m_Capacity;
        }

        //获取数组大小
        int getSize()
        {
            return this->m_Size;
        }

        //析构
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
        T * pAddress;//指向一个堆空间，存储真正的数据
        int m_Capacity;//容量
        int m_Size;//大小
};