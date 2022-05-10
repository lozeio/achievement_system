
#include <windows.h>
#include <cstring>
#include <iostream>
#include <vector>
#include "MD5.h"
#include "functions.h"
#include "student.h"
#include "students.h"

using namespace std;

int op;
Students students;

int main() {
    while (1) {
        system("cls");
        string user_name;
        int type = login(user_name);
        system("cls");

        if (type == 1) {
            printf("%s", admin_options_1);
            scanf("%d", &op);

            if (op == 0) {
                break;
            } else if (op == 1) {
                students.creat_student();
            } else if (op == 2) {
                while (1) {
                    printf("%s", admin_options_2);
                    scanf("%d", &op);
                    system("cls");
                    string str;
                    long long num;

                    if (op == 0) {
                        break;
                    } else if (op == 1) {
                        puts("Please enter the name:");
                        cin>>str;
                    } else if (op == 2) {
                        puts("Please enter the school number:");
                        scanf("%lld", &num);
                    } else if (op == 3) {
                        puts("Please enter the ranking:");
                        scanf("%lld", &num);
                    }
                    auto student = students.find_student(op, str, num);

                    if (student != students.get_students_end()) {
                        while (1) {
                            printf("%s", admin_options_3);
                            scanf("%d", &op);
                            system("cls");
                            if (op == 0) {
                                break;
                            } else if (op == 1) {
                                students.delete_student(student);
                            } else if (op == 2) {
                                while (1) {
                                    printf("%s", admin_options_4);
                                    scanf("%d", &op);
                                    system("cls");
                                    if (op == 0) {
                                        break;
                                    } else if (op == 1) {
                                        puts("Please enter new name");
                                        string name;
                                        cin >> name;
                                        student->set_name(name);
                                    } else if (op == 2) {
                                        puts("Please enter new gender(0 for woman and 1 for man)");
                                        int sex;
                                        cin >> sex;
                                        student->set_sex(sex);
                                    } else if (op == 3) {
                                        puts("Please enter new department");
                                        string department;
                                        cin >> department;
                                        student->set_department(department);
                                    } else if (op == 4) {
                                        puts("Please enter new age");
                                        int age;
                                        cin >> age;
                                        student->set_age(age);
                                    } else if (op == 5) {
                                        puts("Please enter new nationality");
                                        string nationality;
                                        cin >> nationality;
                                        student->set_nationgality(nationality);
                                    } else if (op == 6) {
                                        puts("Please enter new school number");
                                        long long nnum;
                                        cin >> nnum;
                                        student->set_school_number(nnum);
                                    } else if (op == 7) {
                                        while (1) {
                                            printf("%s", admin_options_5);
                                            scanf("%d", &op);
                                            system("cls");
                                            if (op == 0) {
                                                break;
                                            } else if (op >= 1 && op <= 6) {
                                                puts("Please enter the grade");
                                                int nnum;
                                                scanf("%d", nnum);
                                                student->set_grades(op, nnum);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        puts("Student do not exist");
                    }

                }
                students.sort_student();
            } else if (op == 3) {
                students.list_student();
            }

        } else if (type == 2) {
            long long num = stoll(user_name);
            students.find_student(2, "", num)->print_student();
        } else {
            puts("Wrong user name or password please retry");
            puts("enter \"fuck\" to exit");
            string x;
            cin>>x;
            if(x=="fuck")break;
            system("pause");
        }
    }
    return 0;
}