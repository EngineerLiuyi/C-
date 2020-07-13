#include <iostream>
#include <vector>

using namespace std;

/*
* FenwickTree -> partical update
*   update O(logn)
*   query O(logn)
*
* DP -> update every elements
*   update O(n)
*   query O(1)
*/
class FenwickTree{
public:
    FenwickTree(size_t n): sums_(n+1, 0) {}
    /*
    FenwickTree(int n) {
        for (int i=0;i<=n;i++) sums_.push_back(0);
    }*/

    void update(int i, int delta) {
        while(i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }

    int query(int i) const {
        int sum = 0;
        while (i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }
private:
    static inline int lowbit(int x) {return x & (-x);}
    vector<int> sums_;
};

int main()
{
    FenwickTree data(8);
    for(int i = 1; i < 9; i ++)     //cannot start from 0
        data.update(i,i);
    for(int i = 1; i < 9; i++)
        cout << i << ": " << data.query(i) << endl;
    return 0;
}
