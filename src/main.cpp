#include <iostream>
#include <span>
#include <iomanip>
#include <queue>
#include "merge_sort.h"
#include "employee.h"

void dump_array(std::span<int> array) {
    for (int i : array) {
        std::cout << std::setw(3) << i;
    }
    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& output, std::queue<Employee> queue) {
    while (queue.size() > 1) {
        auto num = queue.front();
        queue.pop();
        output << num << std::endl;
    }
    output << queue.front();
    return output;
}

std::ostream& operator<<(std::ostream& output, std::span<int> array) {
    if (array.empty()) return output;
    int i = 0;
    for (; i < array.size() - 1; i++) {
        output << array[i] << ",";
    }
    output << array[i];
    return output;
}

void open_file(std::queue<Employee>& e,std::string file_name){
    std::fstream file;
    file.open(file_name,std::ios::in);
    std::string line;
    while(std::getline(file,line)){
        Employee emp(line);
        e.push(emp);
    }
}

int main() {

    Merge_Sort ms;

    std::queue<Employee> employees;
    open_file(employees,"../src/assign4.txt");


    auto nums = std::to_array({3, 6, 8, 10, 5, 9, 4, 1, 2, 7});

    std::cout << "Before Sorting ..." << std::endl;
    std::cout << employees << std::endl;

    ms.merge_sort(employees);

    std::cout << "After Sorting ..." << std::endl;
    std::cout << employees << std::endl;

    return 0;
}
