#include <iostream>

using namespace std;



class CostEstimate{
public:
    int data;
    int count;
    CostEstimate(void);
    CostEstimate(const int, const int);
    CostEstimate& operator=(const CostEstimate&);
};

CostEstimate::CostEstimate(void)
    : data(0), count(0){}
CostEstimate::CostEstimate(const int Ldata, const int Lcount)
    : data(Ldata), count(Lcount){}
CostEstimate& CostEstimate::operator=(const CostEstimate& rts) {
        this->data = rts.data;
        this->count = rts.count;
        cout << "using self-defined operator!" << endl;
    return *this;
}

int main()
{
    CostEstimate temp;
    temp.data = 1;
    temp.count = 2;

    CostEstimate temp2;
    temp2 = temp;
    cout << temp2.data << "\t" <<temp2.count <<endl;

    temp2.count = 4;
    cout << temp2.data << "\t" <<temp2.count <<endl;
    cout << temp.data << "\t" <<temp.count <<endl;

    return 0;
}
