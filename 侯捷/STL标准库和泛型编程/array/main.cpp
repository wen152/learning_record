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
        std::cout << "产生数组的时间:" << (clock() - timeStart) << std::cout << "ms" << std::endl;
        std::cout << "数组的大小:" << c.size() << std::endl;
        std::cout << "数组第一个元素:" << c.front() << std::endl;
        std::cout << "数组最后一个元素:" << c.end() << std::endl;
        std::cout << "数组的首地址:" << c.data() << std::endl;
    }
    //qsort()
    //bsearch()
}