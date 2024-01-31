#include<iostream>
#include<string>
using namespace std;

//抽象类，虚基类
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
        Computer(CPU * cpu,GPU * gpu,Memory * mem)//构造函数
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
                cout << "释放m_cpu" << endl;
                m_cpu = NULL;
            }
            if (m_gpu!=NULL)
            {
                delete m_gpu;
                cout << "释放m_gpu" << endl;
                m_gpu = NULL;
            }
            if (m_mem!=NULL)
            {
                delete m_mem;
                cout << "释放m_mem" << endl;
                m_mem = NULL;
            }
        }
    private:
        CPU *m_cpu;
        GPU *m_gpu;
        Memory *m_mem;
};

//子类
class InterCpu:public CPU
{
    public:
        virtual void calculate()
        {
			cout << "Inter的CPU开始计算" << endl;
        }        
};

class InterGpu:public GPU
{
    public:
        virtual void display()
        {
            cout << "Inter的GPU开始显示" << endl;
        }        
};

class InterMemory:public Memory
{
    public:
        virtual void storage()
        {
			cout << "Inter的内存条开始存储" << endl;
        }        
};

class LenovoCpu:public CPU
{
    public:
        virtual void calculate()
        {
            cout << "Lenovo的CPU开始计算" << endl;
        }        
};

class LenovoGpu:public GPU
{
    public:
        virtual void display()
        {
			cout << "Lenovo的GPU开始显示" << endl;
        }        
};
class LenovoMemory:public Memory
{
    public:
        virtual void storage()
        {
            cout << "Lenovo的内存条开始存储" << endl;
        }        
};

void test()
{
        CPU *intercpu = new InterCpu;
        GPU *intergpu = new InterGpu;
        Memory *intermem = new InterMemory;
        Computer *com1 = new Computer(intercpu, intergpu, intermem);
        cout << "第一台电脑" << endl;
        com1->work();
        delete com1;
        cout << "———————————————————————" << endl;
        cout << "第二台电脑" << endl;
        Computer *com2 = new Computer(new LenovoCpu, new LenovoGpu, new LenovoMemory);
        com2->work();
        delete com2;
}

int main()
{
		cout << "你好" << endl;
		test();
        system("pause");
        return 0;
}