#include<iostream>
#include<array>
#include<ctime>
#include<cstdlib>
namespace test
{
    void test_array()
    {
        std::cout << "\ntest_array()--------\n";
        std::array<long, ASIZE> c;
        clock_t timeStart = clock();
        for (long i = 0; i < ASIZE; ++i)
        {
            c[i] = rand();
        }
        std::cout << "���������ʱ��:" << (clock() - timeStart) << std::cout << "ms" << std::endl;
        std::cout << "����Ĵ�С:" << c.size() << std::endl;
        std::cout << "�����һ��Ԫ��:" << c.front() << std::endl;
        std::cout << "�������һ��Ԫ��:" << c.end() << std::endl;
        std::cout << "������׵�ַ:" << c.data() << std::endl;
    }
    //qsort()
    //bsearch()
}