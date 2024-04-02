#include "student.h"

Student::Student() : name(""), age(0) {}

Student::Student(const std::string& name, int age) : name(name), age(age) {}

bool Student::operator>(const Student& S) const
{
    return age > S.age;
}

bool Student::operator<(const Student& S) const
{
    return age < S.age;
}

bool Student::operator==(const Student& S) const
{
    return age == S.age && name == S.name;
}

std::ostream& operator<<(std::ostream& os, const Student& student)
{
    os << "Name: " << student.name << ", Age: " << student.age;
    return os;
}


