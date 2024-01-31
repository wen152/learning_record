#include<iostream>
#include<string>
using namespace std;

//�����࣬�����
class CPU
{
    public:
        virtual void calculate() = 0;
};

class GPU
{
    public:
        virtual void display() = 0;
};

class Memory
{
    public:
        virtual void storage() = 0;
};

class Computer
{
    public:
        Computer(CPU * cpu,GPU * gpu,Memory * mem)//���캯��
        {
            m_cpu = cpu;
            m_gpu = gpu;
            m_mem = mem;
        }
        void work()
        {
            m_cpu->calculate();
            m_gpu->display();
            m_mem->storage();
        }
        ~Computer()
        {
            if (m_cpu!=NULL)
            {
                delete m_cpu;
                cout << "�ͷ�m_cpu" << endl;
                m_cpu = NULL;
            }
            if (m_gpu!=NULL)
            {
                delete m_gpu;
                cout << "�ͷ�m_gpu" << endl;
                m_gpu = NULL;
            }
            if (m_mem!=NULL)
            {
                delete m_mem;
                cout << "�ͷ�m_mem" << endl;
                m_mem = NULL;
            }
        }
    private:
        CPU *m_cpu;
        GPU *m_gpu;
        Memory *m_mem;
};

//����
class InterCpu:public CPU
{
    public:
        virtual void calculate()
        {
			cout << "Inter��CPU��ʼ����" << endl;
        }        
};

class InterGpu:public GPU
{
    public:
        virtual void display()
        {
            cout << "Inter��GPU��ʼ��ʾ" << endl;
        }        
};

class InterMemory:public Memory
{
    public:
        virtual void storage()
        {
			cout << "Inter���ڴ�����ʼ�洢" << endl;
        }        
};

class LenovoCpu:public CPU
{
    public:
        virtual void calculate()
        {
            cout << "Lenovo��CPU��ʼ����" << endl;
        }        
};

class LenovoGpu:public GPU
{
    public:
        virtual void display()
        {
			cout << "Lenovo��GPU��ʼ��ʾ" << endl;
        }        
};
class LenovoMemory:public Memory
{
    public:
        virtual void storage()
        {
            cout << "Lenovo���ڴ�����ʼ�洢" << endl;
        }        
};

void test()
{
        CPU *intercpu = new InterCpu;
        GPU *intergpu = new InterGpu;
        Memory *intermem = new InterMemory;
        Computer *com1 = new Computer(intercpu, intergpu, intermem);
        cout << "��һ̨����" << endl;
        com1->work();
        delete com1;
        cout << "����������������������������������������������" << endl;
        cout << "�ڶ�̨����" << endl;
        Computer *com2 = new Computer(new LenovoCpu, new LenovoGpu, new LenovoMemory);
        com2->work();
        delete com2;
}

int main()
{
		cout << "���" << endl;
		test();
        system("pause");
        return 0;
}