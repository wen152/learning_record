#include<iostream>
using namespace std;
#include<string>
//抽象类
class AbstrctDrinking
{
    public:
        //烧水
        virtual void Boil() = 0;
        //冲泡
        virtual void Brew() = 0;
        //倒入杯中
        virtual void PourIntoCup() = 0;
        //加入辅料
        virtual void PutSomething() = 0;

        //制作饮品
        void makeDrink()
        {
            Boil();
            Brew();
            PourIntoCup();
            PutSomething();
        }

    private:
};

class Coffee:public AbstrctDrinking
{
    public:
        //烧水
        virtual void Boil()
        {
            cout << "烧农夫山泉" << endl;
        }
        //冲泡
        virtual void Brew()
        {
            cout << "冲泡咖啡" << endl;
        }
        //倒入杯中
        virtual void PourIntoCup()
        {
            cout << "倒入杯中" << endl;
        }
        //加入辅料
        virtual void PutSomething()
        {
            cout << "加入糖和牛奶" << endl;
        }
};

class Tea:public AbstrctDrinking
{
    public:
        //烧水
        virtual void Boil()
        {
            cout << "烧矿泉水" << endl;
        }
        //冲泡
        virtual void Brew()
        {
            cout << "冲泡茶叶" << endl;
        }
        //倒入杯中
        virtual void PourIntoCup()
        {
            cout << "倒入杯中" << endl;
        }
        //加入辅料
        virtual void PutSomething()
        {
            cout << "加入枸杞" << endl;
        }
};

void doWork(AbstrctDrinking *abs) // AbstractDrinking *abs=new Coffee;
{
        abs->makeDrink();
        delete abs;
}

void test()
{
        doWork(new Coffee);
        cout << "————————————————————" << endl;
        doWork(new Tea);
        cout << "————————————————————" << endl;
}

int main()
{
        test();
        system("pause");
        return 0;
}