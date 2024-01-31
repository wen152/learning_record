#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::vector;
int main()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while(cin >> grade)
    {
        if (grade <= 100)
        {
            ++scores[grade / 10];
        }
    }
    for (auto c : scores)
    {
        cout << c << " ";
    }
    cout << std::endl;
    system("pause");
}