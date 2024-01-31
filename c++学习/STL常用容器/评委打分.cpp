//有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

//选手类
class Person
{
    public:
        Person(string name, int score)//构造函数
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
            string name = "选手";
            name += nameSeed[i];//+=重载
            int score = 0;
            Person p(name, score);//构造函数
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
            //排序
            sort(d.begin(), d.end());
            //去除最低分和最高分
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
			cout << "姓名:" << it->m_Name << " 平均分:" << it->m_Score << endl;
        }
}

int main()
{
        //随机数种子
        srand((unsigned int)time(NULL));
        vector<Person> v;
        createPerson(v);
        setScore(v);
        showScore(v);
        system("pause");
        return 0;
}