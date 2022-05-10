#include<cstdio>
#include<map>
#include<string>
#include<iostream>
#include"MD5.h"

using namespace std;

// 返回值：
// 0： 用户名或密码错误
// 1： 管理员
// 2： 学生

map<string, string> admin;
map<string, string> student;

int login(string user_name) {
    //学号
    
    string password;
    puts("Please enter user name:");
    cin>>user_name;
    puts("Please enter password:");
    cin>>password;
    md5::MD5 md5;
    char* passwrd=new char[110];
    strcpy(passwrd,password.c_str());
    password = md5.digestString(passwrd);
    if (admin.find(user_name) != admin.end()) //用find函数来定位数据出现位置，它返回的一个迭代器，当数据出现时，它返回数据所在位置的迭代器，如果map中没有要查找的数据，它返回的迭代器等于end函数返回的迭代器
    {
        if (admin[user_name] == password) {
            return 1;
        }
    } else if (student.find(user_name) != student.end()) {
        if (student[user_name] == password) {
            return 2;
        }
    }
    return 0;
}