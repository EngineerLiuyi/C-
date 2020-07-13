#include <iostream>
#include <deque>

using namespace std;
/**************************************
2020/06/26
STL之二deque的Iterator Category是Random access，用法基本与vector相同,
但是与std :: vector相反，双端队列的元素不是连续存储的。扩展双端队列比扩展
std :: vector便宜，因为它不涉及将现有元素复制到新的内存位置。
Random access - constant O(1)
Insertion or removal of elements at the end or beginning - constant O(1)
Insertion or removal of elements - linear O(n)
***************************************/
int main()
{
    //Initialization
    deque<int> data = {0, 1, 2, 3, 4};
    //insertion 插入
    {
        // 尾部插入
        data.push_back(5);
        // 头部插入
        data.push_front(-1);
        // 随机插入
        data.insert(data.cbegin() + 7, 2, 6); //插入n个constN，2个6
    }

    // deletion 删除元素,注意这里删除的是第四个元素
    data.erase(data.begin() + 4);
    //data.pop_front();
    data.pop_back();

    //visit elements 访问元素
    cout << "the first element of the deque is "
         << data[0] << endl;    //data.at(0)

    //iteration 遍历 C++11
    for(auto& it : data)
        cout << it << endl;

    //size
    cout << "data max size is " << data.max_size() << endl;
    cout << "data size is " << data.size() << endl;

    //clear
    data.clear();

    return 0;
}
