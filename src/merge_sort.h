#ifndef ASSIGNMENT4_MERGE_SORT_H
#define ASSIGNMENT4_MERGE_SORT_H

#include "iostream"
#include <fstream>
#include <queue>
#include <span>
#include "employee.h"

class Merge_Sort{
public:
    void merge_sort(std::queue<Employee>& array);
    int merge(std::queue<Employee>& out, std::queue<Employee>& in1, std::queue<Employee>& in2);
    void split(std::queue<Employee>& inarray, std::queue<Employee>& out1, std::queue<Employee>& out2);
    bool elements_in_file(std::queue<Employee>& first, std::queue<Employee>& second, Employee& last);
    void alter_field(std::string& field, int field_num);

    bool elements_in_sublist(std::queue<Employee>& first, std::queue<Employee>& second, Employee& last);
};

#endif //ASSIGNMENT4_MERGE_SORT_H