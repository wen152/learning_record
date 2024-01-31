#include<iostream>
using namespace std;
#include<fstream>

void test()
{
    ofstream ofs;
    ofs.open("test.txt", ios::out);
    ofs << "姓名：张三" << endl
        << "性别：男" << endl
        << "年龄：18" << endl;
    ofs.close();
}
int main()
{
    test();
    system("pause");
    return 0;
}