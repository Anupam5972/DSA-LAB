#include <iostream>
using namespace std;
class ABC
{
    int i;

public:
    void fun(int j)
    {
        i = j;
        cout << this;
        cout << *this;
    }
};
int main()
{
    ABC a;
    a.fun(5);
}