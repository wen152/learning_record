//��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

//ѡ����
class Person
{
    public:
        Person(string name, int score)//���캯��
        {
            this->m_Name = name;
            this->m_Score = score;
        }

    public:
        string m_Name;
        int m_Score;
};

void createPerson(vector<Person>&v)
{
        string nameSeed = "ABCDE";
        for (int i = 0; i < 5; i++)
        {
            string name = "ѡ��";
            name += nameSeed[i];//+=����
            int score = 0;
            Person p(name, score);//���캯��
            v.push_back(p);
        }
}

void setScore(vector<Person>&v)
{
        for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
        {
            deque<int> d;
            for (int i = 0; i < 10; i++)
            {
                int score = rand() % 41 + 60;// 60~100
                d.push_back(score);
            }
            //����
            sort(d.begin(), d.end());
            //ȥ����ͷֺ���߷�
            d.pop_front();
            d.pop_back();
            int sum = 0;
            for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
            {
                sum += *dit;
            }
            int avg = sum / d.size();
            it->m_Score = avg;
        }
}

void showScore(vector<Person>&v)
{
        for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
        {
			cout << "����:" << it->m_Name << " ƽ����:" << it->m_Score << endl;
        }
}

int main()
{
        //���������
        srand((unsigned int)time(NULL));
        vector<Person> v;
        createPerson(v);
        setScore(v);
        showScore(v);
        system("pause");
        return 0;
}