#include <iostream>
#include "set.h" // Assuming Set class is defined in Set.h

int main() {
    // Testing Set of integers
    Set<int> set1;
    set1.Add(3);
    set1.Add(2);
   /* set1.Add(1);*/

    Set<int> set2;
    /*set2.Add(2);*/
    set2.Add(4);
    set2.Add(5);
    std::cout << "Set 1: ";
    set1.Print();
    std::cout << "Set 2: ";
    set2.Print();

   Set<int> intersectionSet = set1.Intersection(set2);
    std::cout << "Intersection of Set 1 and Set 2: ";
    intersectionSet.Print();
    Set<int> differenceSet = set1.Difference(set2);
    std::cout << "Difference of Set 1 and Set 2: ";
    differenceSet.Print();

    

    return 0;
}