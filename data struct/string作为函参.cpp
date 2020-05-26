#include <iostream>
using namespace std;

void fun(const string& s) {
    cout << s << " " << reinterpret_cast<uintptr_t>(s.data()) << endl;
}
int main()
{
    constexpr char data1[] = "very long string ...";
    char *data = "very long string ...";
    string data2{"very long string ..."};
    cout << data1 << " " << reinterpret_cast<uintptr_t>(data1) << endl;
    cout << data << " " << reinterpret_cast<uintptr_t>(data) << endl;
    cout << data2 << " " << reinterpret_cast<uintptr_t>(data2.data()) << endl;
    fun(data1);
    fun(data);
    fun(data2);

 	return 0;
}
