#pragma once

#include<cstring>

using namespace std;

class Student {
   private:
    string name;
    bool sex;  // woman is 0 && man is 1
    string department;
    int age;
    string nationality;
    int grades[10];
    long long school_number;
    int ranking;

   public:
    string get_name() { return name; }
    bool get_sex() { return sex; }
    string get_department() { return department; }
    int get_age() { return age; }
    string get_nationgality() { return nationality; }
    int* get_grades() { return grades; }
    long long get_school_number() { return school_number; }
    int get_ranking() { return ranking; }

    void set_name(const string&);
    void set_sex(const bool&);
    void set_department(const string&);
    void set_age(const int&);
    void set_nationgality(const string&);
    void set_grades(const int& num, const int& grade);
    void set_school_number(const long long&);
    void set_ranking(const int&);

    Student(long long, string, bool, int, string, string, int*);
    ~Student(){}

    bool operator<(const Student& b) const { return grades[0] < b.grades[0]; }
    void print_student();
};
