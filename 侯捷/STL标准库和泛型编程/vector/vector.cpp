#include<vector>
#include<algorithm>
#include<functional>
#include<iostream>
using namespace std;

int main()
{
    int arr[6] = {309, 239, 2938, 4039, 489, 230};
    //container
    vector<int, allocator<int>> vi(arr, arr + 6);//allocator�����ڴ�
    cout << "vector��sizeΪ" << vi.size() << endl;
    cout << count_if(vi.begin(), vi.end(), not1(bind2nd(less<int>(), 500)));//����
    return 0;
}
