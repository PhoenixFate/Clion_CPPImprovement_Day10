//
// Created by phoenix on 3/19/2019.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void test301()
{
    vector<int> v;
    for(int i=0;i<10;++i)
    {
        v.push_back(i);
        cout<<v.capacity()<<endl;
    }
    for(vector<int>::iterator it=v.begin();it!=v.end();++it)
    {
        cout<<*it<<endl;
    }
}

/*
vector构造函数
vector<T> v; //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem);//构造函数将n个elem拷贝给本身。
vector(const vector &vec);//拷贝构造函数。

//例子 使用第二个构造函数 我们可以...
int arr[] = {2,3,4,1,9};
vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

3.2.4.2 vector常用赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
vector& operator=(const vector  &vec);//重载等号操作符
swap(vec);// 将vec与本身的元素互换。

3.2.4.3 vector大小操作
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
capacity();//容器的容量
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。

*/
void printVector(vector<int> v)
{
    cout<<"-------------------printVector-----------------------"<<endl;
    for(vector<int>::iterator it=v.begin();it!=v.end();++it)
    {
        cout<<*it<<endl;
    }
}

void test302()
{
    cout<<"-----------------------------------02------------------------------"<<endl;
    vector<int> v;
    int arr[]={1,2,3,4,5};
    vector<int> v1(arr, arr+sizeof(arr)/ sizeof(int));
    vector<int> v2(v1.begin(),v1.end());
    printVector(v2);
    vector<int> v3(3,10);
    printVector(v3);

    //assign
    vector<int> v4;
    v4.push_back(100);
    v4.assign(v3.begin(),v3.end());
    printVector(v4);

    v4.swap(v2);
    cout<<"swap:"<<endl;
    printVector(v4);
    printVector(v2);
    cout<<"v4.size(): "<<v4.size()<<endl;
    cout<<"v4.empty(): "<<v4.empty()<<endl;

    v4.resize(8,-1);//第二个参数为默认值
    cout<<"v4.resize(n)"<<endl;
    printVector(v4);
    v4.resize(3);
    cout<<"v4.resize(n)"<<endl;
    printVector(v4);

    v4.reserve(10);
    cout<<"v4.size():"<<v4.size()<<endl;
    cout<<"v4.capacity():"<<v4.capacity()<<endl;
}

//巧用swap来收缩空间
void test303()
{

    cout<<"----------------------------03----------------------------"<<endl;
    vector<int> v;
    for(int i=0;i<100000;++i)
    {
        v.push_back(i);
    }
    cout<<"v.size():"<<v.size()<<endl;
    cout<<"v.capacity():"<<v.capacity()<<endl;

    v.resize(3);
    cout<<"v.size():"<<v.size()<<endl;
    cout<<"v.capacity():"<<v.capacity()<<endl;

    //swap
    vector<int>(v).swap(v);//匿名对象当前行结束后自动释放
    cout<<"v.size():"<<v.size()<<endl;
    cout<<"v.capacity():"<<v.capacity()<<endl;
}


//reserve()
void test304()
{
    cout<<"-------------------------04----------------------"<<endl;
    vector<int> v;
    v.reserve(100000);
    int *p=NULL;
    int num=0;
    for(int i=0;i<100000;i++)
    {
        v.push_back(i);
        if(p!=&v[0])
        {
            p=&v[0];
            num++;
        }
    }
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    cout<<num<<endl;
}

/*
vector数据存取操作
at(int idx); //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
operator[];//返回索引idx所指的数据，越界时，运行直接报错
front();//返回容器中第一个数据元素
back();//返回容器中最后一个数据元素

3.2.4.5 vector插入和删除操作
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele.
push_back(ele); //尾部插入元素ele
pop_back();//删除最后一个元素
erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
erase(const_iterator pos);//删除迭代器指向的元素
clear();//删除容器中所有元素

*/

void test305()
{
    cout<<"-----------------------05-------------------"<<endl;
    vector<int> v;
    v.push_back(10);
    v.push_back(5);
    v.push_back(20);
    v.push_back(30);
    cout<<"v.front():"<<v.front()<<endl;
    cout<<"v.back():"<<v.back()<<endl;
    cout<<"v.at():"<<v.at(3)<<endl;
    cout<<"v[]:"<<v[2]<<endl;
    v.insert(v.begin(),100);
    printVector(v);
    v.pop_back();//尾删
    printVector(v);

    v.erase(v.begin());
    printVector(v);
    v.erase(v.begin()+1,v.begin()+3);
    cout<<v.empty()<<endl;
    v.push_back(1);
    v.clear();//清空所有的数据
}

void test306()
{
    cout<<"---------------------06---------------------"<<endl;
    //逆序遍历
    vector<int> v;
    for(int i=0;i<10;++i)
    {
        v.push_back(i);
    }
    //reverse_iterator 逆序迭代器
    for(vector<int>::reverse_iterator it=v.rbegin();it!=v.rend();++it)
    {
        cout<<*it<<endl;
    }

    //vector迭代器是随机访问的迭代器  支持跳跃访问
    vector<int>::iterator itBegin=v.begin();
    itBegin+=3;
}

int main3()
{
    test301();
    test302();
    test303();
    test304();
    test305();
    test306();
    return 0;
}