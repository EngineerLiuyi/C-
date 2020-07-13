#include <iostream>
#include <vector>

using namespace std;
/**************************************
2020/06/25
STL之一：vector的Iterator Category是Random access:
Random access - constant O(1)
Insertion or removal of elements at the end - amortized constant O(1)
Insertion or removal of elements - linear in the distance to the end of the vector O(n)
***************************************/
int main()
{
    //Initialization
    //svector<int> data(5, 0);
    vector<int> data = {0, 1, 2, 3, 4};
    //insertion 插入
    {
        // 尾部插入
        data.push_back(5);
        // 随机插入
        data.insert(data.begin() + 6, 6);
    }

    // deletion 删除元素,注意这里删除的是第四个元素
    data.erase(data.begin() + 3);

    //visit elements 访问元素
    cout << "the first element of the vector is "
         << data[0] << endl;

    //iteration 遍历
    for(auto& it : data)
        cout << it << endl;

    //size
    cout << "data size is " << data.size() << endl;

    //clear
    data.clear();

    return 0;
}
