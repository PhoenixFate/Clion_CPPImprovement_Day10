#include <iostream>
#include <vector>
using namespace std;



//迭代器，遍历功能

void test101()
{
    int arr[5]={1,2,4,6,7};
    int *p=arr;
    for(int i=0;i<5;++i)
    {
        cout<<arr[i]<<"  "<<*(p+i)<<endl;
    }
}

void test102()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(8);

    //1.
    vector<int>::iterator itBegin=v.begin();
    vector<int>::iterator itEnd=v.end();

    while(itBegin!=itEnd)
    {
        cout<<*itBegin<<endl;
        itBegin++;
    }
}

int main() {
    test101();
    test102();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}