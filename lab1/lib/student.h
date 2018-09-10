#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
using namespace std;


class student
{
public:
    char* name;
    int math, phys, prog;

    student(const char* name, int math, int phys, int prog)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->phys = phys;
        this->math = math;
        this->prog = prog;
    }

    double avg() {
        return (math + phys + prog) / 3;
    }

    void print()
    {
         cout << name << " " << math << " "<< phys << " "  << prog <<  endl;
    }
};


#endif // STUDENT_H
