#include<iostream>
using namespace std;
#include<string>
//������
class AbstrctDrinking
{
    public:
        //��ˮ
        virtual void Boil() = 0;
        //����
        virtual void Brew() = 0;
        //���뱭��
        virtual void PourIntoCup() = 0;
        //���븨��
        virtual void PutSomething() = 0;

        //������Ʒ
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
        //��ˮ
        virtual void Boil()
        {
            cout << "��ũ��ɽȪ" << endl;
        }
        //����
        virtual void Brew()
        {
            cout << "���ݿ���" << endl;
        }
        //���뱭��
        virtual void PourIntoCup()
        {
            cout << "���뱭��" << endl;
        }
        //���븨��
        virtual void PutSomething()
        {
            cout << "�����Ǻ�ţ��" << endl;
        }
};

class Tea:public AbstrctDrinking
{
    public:
        //��ˮ
        virtual void Boil()
        {
            cout << "�տ�Ȫˮ" << endl;
        }
        //����
        virtual void Brew()
        {
            cout << "���ݲ�Ҷ" << endl;
        }
        //���뱭��
        virtual void PourIntoCup()
        {
            cout << "���뱭��" << endl;
        }
        //���븨��
        virtual void PutSomething()
        {
            cout << "�������" << endl;
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
        cout << "����������������������������������������" << endl;
        doWork(new Tea);
        cout << "����������������������������������������" << endl;
}

int main()
{
        test();
        system("pause");
        return 0;
}