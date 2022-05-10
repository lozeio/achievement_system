
#include<cstring>
#include<cstdio>
#include<iomanip>
#include<iostream>
#include"student.h"

using namespace std;


Student::Student(long long schoo, string namee, bool sexx, int agee, string depar, string nationa, int* gradess)
    : school_number(schoo), name(namee), sex(sexx), age(agee), department(depar), nationality(nationa) {
    for (int i = 0; i <= 6; i++) {
        grades[i] = gradess[i];
    }
}

void Student::set_name(const string& nameee) {
    name = nameee;
}

void Student::set_sex(const bool& sexxx) {
    sex = sexxx;
}

void Student::set_department(const string& depar) {
    department = depar;
}

void Student::set_age(const int& ageee) {
    age = ageee;
}

void Student::set_nationgality(const string& nation) {
    nationality = nation;
}

void Student::set_grades(const int& num, const int& grade) {
    grades[0] -= grades[num];
    grades[num] = grade;
    grades[0] += grade;
}

void Student::set_school_number(const long long& num) {
    school_number = num;
}

void Student::set_ranking(const int& rankk) {
    ranking = rankk;
}

void Student::print_student() {
    cout << setw(3) << get_ranking();
    cout << setw(12) << get_school_number();
    cout << setw(10) << get_name();
    if (get_sex() == 0) {
        cout << setw(6) << "woman";
    } else {
        cout << setw(6) << "man";
    }
    cout << setw(5) << get_age();
    cout << setw(20) << get_department();
    cout << setw(10) << get_nationgality();
    for (int j = 1; j <= 6; j++) {
        cout << setw(4) << get_grades()[j];
    }
    puts("");
}