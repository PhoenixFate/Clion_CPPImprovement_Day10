#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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


void myFun(int v)
{
    cout<<"myFun"<<endl;
    cout<<v<<endl;
}

void test102()
{
    cout<<"------------------------------test02---------------------------"<<endl;
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(8);

    //1.
    vector<int>::iterator itBegin=v.begin();
    vector<int>::iterator itEnd=v.end();//v.end指向最后一个元素的末尾

    //第一种遍历方式
    cout<<"----------------------------the first method to traverse an array------------------------"<<endl;
    while(itBegin!=itEnd)
    {
        cout<<*itBegin<<endl;
        itBegin++;
    }

    cout<<"------------------------the second method to traverse an array-----------------"<<endl;
    //第二种遍历方式
    for(vector<int>::iterator it=v.begin();it!=v.end();++it)
    {
        cout<<*it<<endl;
    }



    //第三种方式
    for_each(v.begin(),v.end(),myFun);

}

//操作自定义的类型
class Person1
{
public:
    Person1(string name,int age):name(name),age(age)
    {

    }
    string name;
    int age;
};

void test103()
{
    Person1 p1(" \b王大锤",88);
    Person1 p2(" \b隔壁老王",11);
    Person1 p3(" \b大头儿子",28);
    vector<Person1> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    for(vector<Person1>::iterator it=v.begin();it!=v.end();++it)
    {
        cout<<(*it).name<<"  "<<(*it).age<<endl;
    }
}

void test104()
{
    Person1 p1(" \b王大锤",88);
    Person1 p2(" \b隔壁老王",11);
    Person1 p3(" \b大头儿子",28);
    vector<Person1*> v;
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);

    for(vector<Person1*>::iterator it=v.begin();it!=v.end();++it)
    {
        cout<<(*it)->name<<"  "<<(*it)->age<<endl;
    }
}


//容器嵌套容器
void test105()
{
    vector<vector<int>> v;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    vector<int> v2;
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);
    vector<int> v3;
    v3.push_back(7);
    v3.push_back(8);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);


    for(vector<vector<int>>::iterator it=v.begin();it!=v.end();++it)
    {
        for(vector<int>::iterator it2=(*it).begin();it2!=(*it).end();++it2)
        {
            cout<<*it2<<endl;
        }
    }
}

int main1() {
    test101();
    test102();
    test103();
    test104();
    test105();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}