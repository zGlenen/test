#include "employee.h"
#include <sstream>

Employee::Employee(const std::string& data) {
    std::istringstream iss(data);
    std::string field;
    int i = 0;
    while (std::getline(iss, field, '\t')) {
        switch (i) {
            case 0: m_employee_id = field; break;
            case 1: m_last_name = field; break;
            case 2: m_first_name = field; break;
            case 3: m_address = field; break;
            case 4: m_city = field; break;
            case 5: m_province = field; break;
            case 6: m_postal_code = field; break;
            case 7: m_phone_number = field; break;
            case 8: m_gender = field[0]; break;
            case 9: m_age = std::stoi(field); break;
            case 10: m_num_of_dependants = std::stoi(field); break;
            case 11: m_department_category = field; break;
            case 12: m_union_member = field[0]; break;
            case 13: m_hourly_rate = std::stof(field); break;
            default: break;
        }
        i++;
    }
    m_sorting_field = 0;
}

Employee::Employee(const Employee& other) {
    m_employee_id = other.m_employee_id;
    m_last_name = other.m_last_name;
    m_first_name = other.m_first_name;
    m_address = other.m_address;
    m_city = other.m_city;
    m_province = other.m_province;
    m_postal_code = other.m_postal_code;
    m_phone_number = other.m_phone_number;
    m_gender = other.m_gender;
    m_age = other.m_age;
    m_num_of_dependants = other.m_num_of_dependants;
    m_department_category = other.m_department_category;
    m_union_member = other.m_union_member;
    m_hourly_rate = other.m_hourly_rate;
    m_sorting_field = other.m_sorting_field;
}

int Employee::get_address() const {
    std::string address_num;
    for (char c : m_address) {
        if (std::isdigit(c)) {
            address_num += c;
        } else {
            break;
        }
    }
    return address_num.empty() ? 0 : std::stoi(address_num.substr(0, address_num.length()));
}

bool operator>(const Employee& left,const Employee& right){
    bool isGreaterThan = false;
    switch (left.m_sorting_field) {
        case 0:
            isGreaterThan = left.m_employee_id > right.m_employee_id;break;
        case 1:
            isGreaterThan = left.m_last_name > right.m_last_name;break;
        case 2:
            isGreaterThan = left.m_first_name > right.m_first_name;break;
        case 3:
            isGreaterThan = left.get_address() > right.get_address(); break;
        case 4:
            isGreaterThan = left.m_city > right.m_city; break;
        case 5:
            isGreaterThan = left.m_province > right.m_province;break;
        case 6:
            isGreaterThan = left.m_postal_code > right.m_postal_code;break;
        case 7:
            isGreaterThan = left.m_phone_number > right.m_phone_number;break;
        case 8:
            isGreaterThan = left.m_gender > right.m_gender;break;
        case 9:
            isGreaterThan = left.m_age > right.m_age;break;
        case 10:
            isGreaterThan = left.m_num_of_dependants > right.m_num_of_dependants;break;
        case 11:
            isGreaterThan = left.m_department_category > right.m_department_category;break;
        case 12:
            isGreaterThan = left.m_union_member > right.m_union_member;break;
        case 13:
            isGreaterThan = left.m_hourly_rate > right.m_hourly_rate;break;
        default:break;
    }
    return isGreaterThan;
}
bool operator<(const Employee& left,const Employee& right){
    bool isLessThan = false;
    switch (left.m_sorting_field) {
        case 0:
            isLessThan = left.m_employee_id < right.m_employee_id;break;
        case 1:
            isLessThan = left.m_last_name < right.m_last_name;break;
        case 2:
            isLessThan = left.m_first_name < right.m_first_name;break;
        case 3:
            isLessThan = left.get_address() < right.get_address();break;
        case 4:
            isLessThan = left.m_city < right.m_city;break;
        case 5:
            isLessThan = left.m_province < right.m_province;break;
        case 6:
            isLessThan = left.m_postal_code < right.m_postal_code;break;
        case 7:
            isLessThan = left.m_phone_number < right.m_phone_number;break;
        case 8:
            isLessThan = left.m_gender < right.m_gender;break;
        case 9:
            isLessThan = left.m_age < right.m_age;break;
        case 10:
            isLessThan = left.m_num_of_dependants < right.m_num_of_dependants;break;
        case 11:
            isLessThan = left.m_department_category < right.m_department_category;
            break;
        case 12:
            isLessThan = left.m_union_member < right.m_union_member;break;
        case 13:
            isLessThan = left.m_hourly_rate < right.m_hourly_rate;break;
        default:break;
    }
    return isLessThan;
}
bool operator>=(const Employee& left,const Employee& right){
    bool isLessThan = false;
    switch (left.m_sorting_field) {
        case 0:
            isLessThan = left.m_employee_id >= right.m_employee_id;break;
        case 1:
            isLessThan = left.m_last_name >= right.m_last_name;break;
        case 2:
            isLessThan = left.m_first_name >= right.m_first_name;break;
        case 3:
            isLessThan = left.get_address() >= right.get_address();break;
        case 4:
            isLessThan = left.m_city >= right.m_city;break;
        case 5:
            isLessThan = left.m_province >= right.m_province;break;
        case 6:
            isLessThan = left.m_postal_code >= right.m_postal_code;break;
        case 7:
            isLessThan = left.m_phone_number >= right.m_phone_number;break;
        case 8:
            isLessThan = left.m_gender >= right.m_gender;break;
        case 9:
            isLessThan = left.m_age >= right.m_age;break;
        case 10:
            isLessThan = left.m_num_of_dependants >= right.m_num_of_dependants;break;
        case 11:
            isLessThan = left.m_department_category >= right.m_department_category;break;
        case 12:
            isLessThan = left.m_union_member >= right.m_union_member;break;
        case 13:
            isLessThan = left.m_hourly_rate >= right.m_hourly_rate;break;
        default:break;
    }
    return isLessThan;
}
bool operator<=(const Employee& left,const Employee& right){
    bool isLessThan = false;
    switch (left.m_sorting_field) {
        case 0:
            isLessThan = left.m_employee_id <= right.m_employee_id;break;
        case 1:
            isLessThan = left.m_last_name <= right.m_last_name;break;
        case 2:
            isLessThan = left.m_first_name <= right.m_first_name;break;
        case 3:
            isLessThan = left.get_address() <= right.get_address();break;
        case 4:
            isLessThan = left.m_city <= right.m_city;break;
        case 5:
            isLessThan = left.m_province <= right.m_province;break;
        case 6:
            isLessThan = left.m_postal_code <= right.m_postal_code;break;
        case 7:
            isLessThan = left.m_phone_number <= right.m_phone_number;break;
        case 8:
            isLessThan = left.m_gender <= right.m_gender;break;
        case 9:
            isLessThan = left.m_age <= right.m_age;break;
        case 10:
            isLessThan = left.m_num_of_dependants <= right.m_num_of_dependants;break;
        case 11:
            isLessThan = left.m_department_category <= right.m_department_category;break;
        case 12:
            isLessThan = left.m_union_member <= right.m_union_member;break;
        case 13:
            isLessThan = left.m_hourly_rate <= right.m_hourly_rate;break;
        default:break;
    }
    return isLessThan;
}
std::ostream &operator<<(std::ostream &output, Employee &e) {
    output << e.m_employee_id << "\t";
    output << e.m_last_name << "\t";
    output << e.m_first_name << "\t";
    output << e.m_address << "\t";
    output << e.m_city << "\t";
    output << e.m_province << "\t";
    output << e.m_postal_code << "\t";
    output << e.m_phone_number << "\t";
    output << e.m_gender << "\t";
    output << e.m_age << "\t";
    output << e.m_num_of_dependants << "\t";
    output << e.m_department_category << "\t";
    output << e.m_union_member << "\t";
    output << e.m_hourly_rate;
    return output;
}