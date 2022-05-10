#pragma once

#include<vector>
#include<cstring>
#include"student.h"

using namespace std;


class Students {
   private:
    vector<Student> student;

   public:
    void creat_student();
    vector<Student>::iterator find_student(const int type, const string str, const long long num);
    void list_student();
    void delete_student(vector<Student>::iterator);
    vector<Student>::iterator get_students_end();
    void sort_student();
};