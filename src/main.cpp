#include <iostream>
#include <queue>
#include "merge_sort.h"
#include "employee.h"

std::ostream& operator<<(std::ostream& output, std::queue<Employee> queue) {
    while (queue.size() > 1) {
        auto num = queue.front();
        queue.pop();
        output << num << std::endl;
    }
    output << queue.front();
    return output;
}

void open_file(std::queue<Employee>& e,const std::string& file_name){
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

    std::cout << "Before Sorting ..." << std::endl;
    std::cout << employees << std::endl;

    ms.merge_sort(employees);

    std::cout << "After Sorting ..." << std::endl;
    std::cout << employees << std::endl;

    return 0;
}
