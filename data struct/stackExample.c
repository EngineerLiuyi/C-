#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int evalRPN(vector<string>& tokens){
    stack<int> s;
    for(const string& token: tokens){
        if(isdigit(token.back()))
            s.push(stoi(token));
        else {
            int n2 = s.top(); s.pop();
            int n1 = s.top(); s.pop();
            int n = 0;
            switch(token[0]) {
                case '+' : n = n1 + n2; break;
                case '-' : n = n1 - n2; break;
                case '*' : n = n1 * n2; break;
                case '/' : n = n1 / n2; break;
            }
            s.push(n);
        }
    }
    return s.top();
}


int main()
{
    vector<string> tokens{"2", "3", "*", "1", "+", "2", "/"};
    cout << evalRPN(tokens) <<endl;

 	return 0;
}
