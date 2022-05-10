#include<cstdio>
#include<map>
#include<cstring>
#include<iostream>
#include"MD5.h"

using namespace std;

// 返回值：
// 0： 用户名或密码错误
// 1： 管理员
// 2： 学生

std::map<string, string> admin;
std::map<string, string> student;

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
    if (admin.find(user_name) != admin.end()) {
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