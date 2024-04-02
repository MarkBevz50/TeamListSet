#include <iostream>
#include "set.h" // Assuming Set class is defined in Set.h

int main() {

        Set<int> set1;
        set1.Add(1);
        set1.Add(2);
        set1.Add(3);

        Set<int> set2;
        set2.Add(2);
        set2.Add(3);
        set2.Add(4);
        std::cout << "Set 1: ";
            set1.Print();
            std::cout << "Set 2: ";
            set2.Print();
        Set<int> intersectionSet = set1.Intersection(set2);
        std::cout << "Intersection: ";
        intersectionSet.Print();
        std::cout << "Set 1: ";
        set1.Print();
        std::cout << "Set 2: ";
        set2.Print();
        Set<int> differenceSet = set1.Difference(set2);
        std::cout << "Difference: ";
        differenceSet.Print();
        std::cout << "Set 1: ";
        set1.Print();
        std::cout << "Set 2: ";
        set2.Print();
        Set<std::string> set4;
        set4.Add("Hi");
        set4.Add("I");
        set4.Add("love");
        set4.Add("you");
        set4.Print();
    return 0;
}