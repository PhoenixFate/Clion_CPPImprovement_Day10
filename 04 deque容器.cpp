//
// Created by phoenix on 3/20/2019.
//
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

/*
deque构造函数
deque<T> deqT;//默认构造形式
deque(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身。
deque(n, elem);//构造函数将n个elem拷贝给本身。
deque(const deque &deq);//拷贝构造函数。

3.3.3.2 deque赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
deque& operator=(const deque &deq); //重载等号操作符
swap(deq);// 将deq与本身的元素互换

3.3.3.3 deque大小操作
deque.size();//返回容器中元素的个数
deque.empty();//判断容器是否为空
deque.resize(num);//重新指定容器的长度为num,若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置,如果容器变短，则末尾超出容器长度的元素被删除。
*/

void printDeque(const deque<int>&d)
{
    cout<<"--------------------printDeque--------------------"<<endl;
    //const_iterator只读迭代器        reverse_iterator 逆序迭代器
    for(deque<int>::const_iterator it=d.begin();it!=d.end();++it)
    {
        cout<<*it<<endl;
    }
}

void test401()
{
    deque<int> d;//默认构造
    d.push_back(1);
    d.push_back(4);
    d.push_back(6);
    d.push_back(8);
    d.push_back(9);
    d.push_back(3);

    deque<int> d2(d.begin()+1,d.begin()+3);
    d2.push_back(22);
    d2.swap(d);
    printDeque(d2);
    cout<<"d2.size(): "<<d2.size()<<endl;
    cout<<d2.empty()<<endl;
}


/*
deque双端插入和删除操作
push_back(elem);//在容器尾部添加一个数据
push_front(elem);//在容器头部插入一个数据
pop_back();//删除容器最后一个数据
pop_front();//删除容器第一个数据

3.3.3.5 deque数据存取
at(idx);//返回索引idx所指的数据，如果idx越界，抛出out_of_range。
operator[];//返回索引idx所指的数据，如果idx越界，不抛出异常，直接出错。
front();//返回第一个数据。
back();//返回最后一个数据
3.3.3.6 deque插入操作
insert(pos,elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
3.3.3.7 deque删除操作
clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。

*/

void test402()
{
    cout<<"----------------------02----------------------"<<endl;
    deque<int> d;
    d.push_back(99);
    d.push_front(1);
    d.push_back(100);
    d.push_front(5);
    d.push_front(10);
    printDeque(d);


    //头删 尾删
    d.pop_back();
    d.pop_front();
    printDeque(d);

    cout<<"front: "<<d.front()<<endl;
    cout<<"back: "<<d.back()<<endl;


    //插入
    deque<int> d2;
    d2.push_back(50);
    d2.push_back(60);
    d2.insert(d2.begin()+1,d.begin(),d.end());
    printDeque(d2);
}

//排序规则 --回调函数
bool myCompare(int v1,int v2)
{
    return v1>v2;
}

//排序 sort
void test403()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(5);
    d.push_back(15);
    d.push_back(2);
    d.push_back(99);
    printDeque(d);

    //排序算法
    std::sort(d.begin(),d.end());
    printDeque(d);

    //从大到小
    sort(d.begin(),d.end(),myCompare);
    printDeque(d);
}

int main()
{
    test401();
    test402();
    test403();
    return 0;
}
