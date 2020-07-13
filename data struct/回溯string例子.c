#include <iostream>
#include <map>
#include <vector>
#include <functional>

using namespace std;

//时间是线性的
vector<int> splitIntoFibonacci(string s) {
    const int n = s.length();
    vector<int> nums;
    function<bool(int)> dfs = [&](int pos) {
        if(pos == n) return nums.size() >= 3;
        int max_len = s[pos] == '0' ? 1 : 10;
        long num = 0;
        for(int i = pos; i < min(pos + max_len, n); ++i) {
            num = 10*num + (s[i] - '0');
            if(num > INT_MAX) break;
            if(nums.size() >= 2) {
                long sum = nums.rbegin()[0];
                sum += nums.rbegin()[1];
                if(num > sum) break;
                else if(num < sum) continue;
                // num must equal to sum
            }
            nums.push_back(num);
            if(dfs(i+1)) return true;
            nums.pop_back();
        }
        return false;
    };
    dfs(0);
    return nums;
}

int main()
{
    vector<int> ans = splitIntoFibonacci("1123");
    for(vector<int>::iterator it = ans.begin(); it!=ans.end(); ++it)
        cout << *it << endl;
    return 0;
}
