//
// Created by phoenix on 3/14/2019.
//
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

/*
    string 构造函数
    string();//创建一个空的字符串 例如: string str;
    string(const string& str);//使用一个string对象初始化另一个string对象
    string(const char* s);//使用字符串s初始化
    string(int n, char c);//使用n个字符c初始化

    3.1.2.2 string基本赋值操作
    string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
    string& operator=(const string &s);//把字符串s赋给当前的字符串
    string& operator=(char c);//字符赋值给当前的字符串
    string& assign(const char *s);//把字符串s赋给当前的字符串
    string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
    string& assign(const string &s);//把字符串s赋给当前字符串
    string& assign(int n, char c);//用n个字符c赋给当前字符串
    string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
*/

void test201()
{
    string str;
    string str1("abc");
    string str2(str1);
    string str3=str1;
    string str4(10,'a');
    cout<<"str2:"<<str2<<endl;
    cout<<"str3:"<<str3<<endl;
    cout<<"str4:"<<str4<<endl;

    //基本赋值
    str="hello";
    str4=str;
    cout<<"str:"<<str<<endl;
    cout<<"str4:"<<str4<<endl;

    str3.assign("abcdefg",4);
    cout<<str3<<endl;
    str3.assign("abcdefg",1,3);
    cout<<str3<<endl;
}

/*
    string存取字符操作
    char& operator[](int n);//通过[]方式取字符
    char& at(int n);//通过at方法获取字符
*/
void test202()
{
    string str="abcefgh";
    cout<<str[2]<<endl;
    cout<<str.at(2)<<endl;

    try {
       // str.at(10);
    }
    catch (out_of_range &e)
    {
        cout<<e.what()<<endl;
    }
    catch (exception &e)
    {
        cout<<e.what()<<endl;
    }

}


/*
    string拼接操作
    string& operator+=(const string& str);//重载+=操作符
    string& operator+=(const char* str);//重载+=操作符
    string& operator+=(const char c);//重载+=操作符
    string& append(const char *s);//把字符串s连接到当前字符串结尾
    string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
    string& append(const string &s);//同operator+=()
    string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
    string& append(int n, char c);//在当前字符串结尾添加n个字符c

    3.1.2.5 string查找和替换
    int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
    int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
    int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
    int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
    int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
    int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
    int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
    int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
    string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
    string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s

*/
void test203()
{
    string str=" \b我";
    str+="爱北京";
    cout<<str<<endl;
    str.append("非常");
    cout<<str<<endl;
    str.append("abcedfg",2,3);
    cout<<str<<endl;
    string s="abcdefgbc";
    int pos=s.find("bc");//找不到返回-1
    cout<<pos<<endl;
    int pos2=s.rfind("bc");
    cout<<pos2<<endl;

    //replace
    string str4="hello world";
    str4.replace(1,3,"aaab");//替换从pos开始n个字符为字符串str
    cout<<str4<<endl;
}

/*
    string比较操作
    compare函数在>时返回 1，<时返回 -1，==时返回 0。
    比较区分大小写，比较时参考字典顺序，排越前面的越小。
    大写的A比小写的a小。

    int compare(const string &s) const;//与字符串s比较
    int compare(const char *s) const;//与字符串s比较
*/
void test204()
{
    string str1="abc";
    string str2="bcd";
    cout<<str1.compare(str2)<<endl;
    cout<<str2.compare(str1)<<endl;
}


/*
    string子串
    string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串
*/
void test205()
{
    string s1="abcedfg";
    string s2=s1.substr(0,3);
    cout<<s2<<endl;
    string email="slfjaslsjfdlk@163.com";
    int pos=email.find("@");
    string name=email.substr(0,pos);
    cout<<name<<endl;
}

/*
    string插入和删除操作
    string& insert(int pos, const char* s); //插入字符串
    string& insert(int pos, const string& str); //插入字符串
    string& insert(int pos, int n, char c);//在指定位置插入n个字符c
    string& erase(int pos, int n = npos);//删除从Pos开始的n个字符
*/

void test206()
{
    cout<<"-----------------------------------06------------------------------------"<<endl;
    string str="hello";
    str.insert(1,"insert");
    cout<<str<<endl;
    str.erase(1,6);
    cout<<str<<endl;
}

/*
string和c-style字符串转换
*/
void test207()
{
    cout<<"---------------------------07--------------------------------"<<endl;
    string str="hello";
    const char* c=str.c_str();
    cout<<c<<endl;
}

void test208()
{
    cout<<"---------------------------08---------------------------"<<endl;
    string str="abcdefg";
    char& c1=str[2];
    char& c2=str[3];
    c1='1';
    c2='2';
    cout<<str<<endl;
    cout<<(int*)str.c_str()<<endl;

    str="ppppppppppppppppppp";
    c1='a';
    c2='b';
    cout<<str<<endl;
    cout<<(int*)str.c_str()<<endl;
}

void test209()
{
    cout<<"--------------------------09----------------------------"<<endl;
    string str="abDEcssg";
    for(int i=0;i<str.size();++i)
    {
        str[i]=tolower(str[i]);
    }
    cout<<str<<endl;
    for(int i=0;i<str.size();++i)
    {
        str[i]=toupper(str[i]);
    }
    cout<<str<<endl;
}

int main2()
{
    test201();
    test202();
    test203();
    test204();
    test205();
    test206();
    test207();
    test208();
    test209();
    return 0;
}
