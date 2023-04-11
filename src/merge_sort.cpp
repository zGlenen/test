#include "merge_sort.h"
#include <span>
#include <queue>

void Merge_Sort::split(std::queue<Employee>& inarray, std::queue<Employee>& out1, std::queue<Employee>& out2) {

    int num_subfiles = 0;

    std::string prev;
    while (!inarray.empty()) {

        // read a "record"
        Employee curr = inarray.front();
        inarray.pop();

        // when the previous number is greater than the current, we are starting a new subfile
        if (curr.getField(0) < prev) num_subfiles++;

        // put records in order into temp files
        if (num_subfiles % 2 == 0) {
            out2.push(curr);
        } else {
            out1.push(curr);
        }

        prev = curr.getField(0);
    }

}

bool Merge_Sort::elements_in_file(std::queue<Employee>& first, std::queue<Employee>& second, Employee& last) {
    return !first.empty() && (first.front().getField(0) > last.getField(0)) &&
           (second.empty() || (second.front().getField(0) < last.getField(0)) || (first.front().getField(0) < second.front().getField(0)));
}

bool Merge_Sort::elements_in_sublist(std::queue<Employee>& first, std::queue<Employee>& second, Employee& last) {
    return !first.empty() && (first.front().getField(0) > last.getField(0));
}

int Merge_Sort::merge(std::queue<Employee>& out, std::queue<Employee>& in1, std::queue<Employee>& in2) {

    int num_subfiles = 0;

    // who starts the process??
    auto& first = in2.empty() || (in1.front().getField(0) < in2.front().getField(0)) ? in1 : in2;
    auto& second = &first == &in1 ? in2 : in1;

    // keep merging while there are records to read
    while (!in1.empty() || !in2.empty()) {

        // keep taking in order elements until the end of a sublist
        Employee last;
        while (elements_in_sublist(first, second, last)) {
            // take elements from the same file while in order
            do {
                last = first.front();
                first.pop();
                out.push(last);
            } while (elements_in_file(first, second, last));

            // move to other file
            if (!second.empty()) {
                std::swap(first, second);
            }
        }

        num_subfiles++;

    }

    return num_subfiles;
}

void Merge_Sort::merge_sort(std::queue<Employee>&  array) {
    int num_subfiles = 0;

    std::queue<Employee> split1, split2;
    do {
        split(array, split1, split2);

        num_subfiles = merge(array, split1, split2);

    } while (num_subfiles != 1);

}

void Merge_Sort::alter_field(std::string &field, int field_num) {
    //case 3 address

    //case 8 & case 12 char

    // case 9 & 10 int

    //case 13 float;;

    if (field_num > 3){

    }

}


