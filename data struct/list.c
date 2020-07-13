#include <iostream>
#include <list>
#include <algorithm> //std::find()

using namespace std;
/**************************************
2020/06/26
STL之二list,又称双向链表容器，即该容器的底层是以双向链表的形式实现的。
这意味着，list 容器中的元素可以分散存储在内存空间里
list插入，删除容易
***************************************/
int main()
{
    //Initialization
    int arr[] = {1, 2, 3, 4, 5};
    list<int> data(arr, arr+5);

    //insertion 插入
    {
        // 尾部插入
        data.push_back(5);
        // 头部插入
        data.push_front(-1);
        // 随机插入
        auto it = std::find(data.begin(), data.end(), 5);
        if (it != data.end())
            data.insert(it, 6);
    }

    // deletion 删除元素,注意这里删除的是第四个元素
    data.erase(data.begin());
    //data.pop_front();
    data.pop_back();



    //iteration 遍历 C++11
    for(auto& it : data)
        cout << it << endl;

    //size
    //cout << "data max size is " << data.max_size() << endl;
    cout << "data size is " << data.size() << endl;

    //clear
    data.clear();

    return 0;
}
