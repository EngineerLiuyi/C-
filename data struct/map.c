#include <iostream>
#include <string>
#include <map>
#include <unordered_map>


using namespace std;
/**************************************
2020/06/26
STL之四map(sorted)
std :: map是一个排序的关联容器，其中包含具有唯一键的键/值对。
使用比较功能“比较”对键进行排序。 搜索，删除和插入操作具有对数
复杂性。 地图通常以红黑树的形式实现。

STL之五set，与map基本一样但是key = value
定义一个元素为整数的集合a，可以用
set<int> a;
基本操作：
对集合a中元素的有
插入元素：a.insert(1);
删除元素（如果存在）：a.erase(1);
判断元素是否属于集合：if (a.find(1) != a.end()) ...
返回集合元素的个数：a.size()
将集合清为空集：a.clear()
————————————————
版权声明：本文为CSDN博主「wu_lai_314」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/wu_lai_314/java/article/details/8440550
***************************************/
int main()
{
    //Initialization
    map<string, int> data;

    //insertion 插入
    {
        data.insert(data.begin(),pair<string, int>("Louie", 1));
        data.insert(data.begin(),pair<string, int>("Anna", 2));
        data.insert(data.begin(),pair<string, int>("Bei", 3));
        data.insert(data.begin(),pair<string, int>("Logan", 2));
        data.insert(data.begin(),pair<string, int>("Jeff", 4));
    }

    // deletion 删除元素,注意这里删除的是第四个元素
    data.erase(data.begin());

    //iteration 遍历 C++11
//    for(auto& pair : data) //c++ 17
//        cout << pair.first << " : " << pair.second << endl;
    for(auto& [key, value] : data) //c++ 17
        cout << "map:" << key << " : " << value << endl;

    //size
    //cout << "data max size is " << data.max_size() << endl;
    cout << "data size is " << data.size() << endl;


    unordered_map<string, int> data_unordered;

    data_unordered.insert(data_unordered.begin(),pair<string, int>("Louie", 1));
    data_unordered.insert(data_unordered.begin(),pair<string, int>("Anna", 2));
    data_unordered.insert(data_unordered.begin(),pair<string, int>("Bei", 3));
    data_unordered.insert(data_unordered.begin(),pair<string, int>("Logan", 2));
    data_unordered.insert(data_unordered.begin(),pair<string, int>("Jeff", 4));

    data_unordered.erase(data_unordered.begin());

    for(auto& [key, value] : data_unordered) //c++ 17
        cout << "unordered_map" << key << " : " << value << endl;

    data_unordered.clear();

    //clear
    data.clear();

    return 0;
}
