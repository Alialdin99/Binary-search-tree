#include <iostream>
#include "BST.h"

int main() {
    BST students;
    students.insert(20, "ahmed", "CS", 3.4);
    students.insert(15, "ali", "IS", 3.9);
    students.insert(30, "mosatafa", "DS", 4);
    students.insert(1, "rady", "BI", 3);
    students.insert(21, "rawny", "CS", 2);
    students.insert(12, "gemy", "CS", 2.5);
    students.print();

}