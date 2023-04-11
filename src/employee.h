#ifndef ASSIGNMENT4_EMPLOYEE_H
#define ASSIGNMENT4_EMPLOYEE_H
#include "iostream"
class Employee{
private:
    std::string employee_id;
    std::string last_name;
    std::string first_name;
    std::string address;
    std::string city;
    std::string province;
    std::string postal_code;
    std::string phone_number;
    char gender{-1};
    int num_of_dependants{-1};
    std::string department_category;
    char union_member{-1};
    float hourly_rate{-1.00};
    int age{-1};
public:
    Employee() = default;
    explicit Employee(const std::string& data);
    Employee(const Employee& other);
    std::string getField(int field);
    friend std::ostream& operator<<(std::ostream& output,Employee &e);
};

#endif //ASSIGNMENT4_EMPLOYEE_H