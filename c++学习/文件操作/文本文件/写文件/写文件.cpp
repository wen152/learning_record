#include<iostream>
using namespace std;
#include<fstream>

void test()
{
    ofstream ofs;
    ofs.open("test.txt", ios::out);
    ofs << "����������" << endl
        << "�Ա���" << endl
        << "���䣺18" << endl;
    ofs.close();
}
int main()
{
    test();
    system("pause");
    return 0;
}