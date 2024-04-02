#pragma once
#include <iostream>

class Student
{
private:
    std::string name;
    int age;

public:
    Student();
    Student(const std::string& name, int age);
    bool operator>(const Student& S) const;
    bool operator<(const Student& S) const;
    bool operator==(const Student& S) const;
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};
