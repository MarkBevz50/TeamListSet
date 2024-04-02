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

        //Set<int> intersectionSet = set1.Intersection(set2);
        //std::cout << "Intersection: ";
        //intersectionSet.Print();

        Set<int> differenceSet = set1.Difference(set2);
        std::cout << "Difference: ";
        differenceSet.Print();
    return 0;
}