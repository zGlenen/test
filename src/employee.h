#ifndef ASSIGNMENT4_EMPLOYEE_H
#define ASSIGNMENT4_EMPLOYEE_H
#include "iostream"
class Employee{
private:
    std::string m_employee_id;
    std::string m_last_name;
    std::string m_first_name;
    std::string m_address;
    std::string m_city;
    std::string m_province;
    std::string m_postal_code;
    std::string m_phone_number;
    char m_gender{-1};
    int m_num_of_dependants{-1};
    std::string m_department_category;
    char m_union_member{-1};
    float m_hourly_rate{-1.00};
    int m_age{-1};
    int m_sorting_field{-1};
    [[nodiscard]] int get_address() const;
public:
    Employee() = default;
    explicit Employee(const std::string& data);
    Employee(const Employee& other);
    friend bool operator>(const Employee& left,const Employee& right);
    friend bool operator<(const Employee& left,const Employee& right);
    friend bool operator<=(const Employee& left,const Employee& right);
    friend bool operator>=(const Employee& left,const Employee& right);
    friend std::ostream& operator<<(std::ostream& output,Employee &e);
};

#endif //ASSIGNMENT4_EMPLOYEE_H