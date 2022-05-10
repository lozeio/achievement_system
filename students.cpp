
#include<cstring>
#include<cstdio>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include"students.h"

using namespace std;

void Students::creat_student() {
    long long schoo;
    string namee;
    bool sexx;  // woman is 0 && man is 1
    int agee;
    string depar;
    string nationa;
    int gradess[10];
    puts("Please enter the school number");
    cin >> schoo;
    puts("Please enter the name:");
    cin >> namee;
    puts("Please enter the gender(0 for woman and 1 for man):");
    cin >> sexx;
    puts("Please enter the agee:");
    cin >> agee;
    puts("Please enter the department:");
    cin >> depar;
    puts("Please enter the nationality:");
    cin >> nationa;
    puts("Please enter the grades(Chinese Mathematics English Physical Chemical Biology):");
    gradess[0] = 0;
    for (int i = 1; i <= 6; i++) {
        cin >> gradess[i];
        gradess[0] += gradess[i];
    }
}

vector<Student>::iterator Students::find_student(const int type, const string str, const long long num) {
    if (type == 1) {
        for (auto i = student.begin(); i != student.end(); i++) {
            if (i->get_name() == str)
                return i;
        }
    } else if (type == 2) {
        for (auto i = student.begin(); i != student.end(); i++) {
            if (i->get_school_number() == num)
                return i;
        }

    } else if (type == 3) {
        for (auto i = student.begin(); i != student.end(); i++) {
            if (i->get_ranking() == num)
                return i;
        }
    }
    return student.end();
}

void Students::list_student() {
    for (auto i = student.begin(); i != student.end(); i++) {
        cout << setw(3) << i->get_ranking();
        cout << setw(12) << i->get_school_number();
        cout << setw(10) << i->get_name();
        if (i->get_sex() == 0) {
            cout << setw(6) << "woman";
        } else {
            cout << setw(6) << "man";
        }
        cout << setw(5) << i->get_age();
        cout << setw(20) << i->get_department();
        cout << setw(10) << i->get_nationgality();
        for (int j = 1; j <= 6; j++) {
            cout << setw(4) << i->get_grades()[j];
        }
        puts("");
    }
}

void Students::delete_student(vector<Student>::iterator x) {
    student.erase(x);
}

vector<Student>::iterator Students::get_students_end() {
    return student.end();
}

void Students::sort_student() {
    sort(student.begin(), student.end());
    int j = 1;
    for (auto i = student.begin(); i != student.end(); i++, j++) {
        i->set_ranking(j);
        if (i != student.begin()) {
            if (i->get_grades()[0] == (i - 1)->get_grades()[0]) {
                i->set_ranking((i - 1)->get_ranking());
            }
        }
    }
}