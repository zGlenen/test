#include "employee.h"
#include <sstream>

Employee::Employee(const std::string& data) {
    std::istringstream iss(data);
    std::string field;
    int i = 0;
    while (std::getline(iss, field, '\t')) {
        switch (i) {
            case 0: employee_id = field; break;
            case 1: last_name = field; break;
            case 2: first_name = field; break;
            case 3: address = field; break;
            case 4: city = field; break;
            case 5: province = field; break;
            case 6: postal_code = field; break;
            case 7: phone_number = field; break;
            case 8: gender = field[0]; break;
            case 9: age = std::stoi(field); break;
            case 10: num_of_dependants = std::stoi(field); break;
            case 11: department_category = field; break;
            case 12: union_member = field[0]; break;
            case 13: hourly_rate = std::stof(field); break;
            default: break;
        }
        i++;
    }
}
Employee::Employee(const Employee& other) {
    employee_id = other.employee_id;
    last_name = other.last_name;
    first_name = other.first_name;
    address = other.address;
    city = other.city;
    province = other.province;
    postal_code = other.postal_code;
    phone_number = other.phone_number;
    gender = other.gender;
    age = other.age;
    num_of_dependants = other.num_of_dependants;
    department_category = other.department_category;
    union_member = other.union_member;
    hourly_rate = other.hourly_rate;
}


std::string Employee::getField(int field) {
    std::string value;
    //case 3 broken
    //case 5 broken
    //case 8 broken
    //case 9 broken
    //case 10 and up broken

    switch (field) {
        case 0: value = employee_id; break;
        case 1: value = last_name; break;
        case 2: value = first_name; break;
        case 3: value = address; break;
        case 4: value = city; break;
        case 5: value = province; break;
        case 6: value = postal_code; break;
        case 7: value = phone_number; break;
        case 8: value = gender; break;
        case 9: value = std::to_string(age); break;
        case 10: value = std::to_string(num_of_dependants); break;
        case 11: value = department_category; break;
        case 12: value = union_member; break;
        case 13: value = std::to_string(hourly_rate); break;
        default: break;
    }
    return value;
}

std::ostream &operator<<(std::ostream &output, Employee &e) {
    output << e.employee_id << "\t\t";
    output << e.last_name << "\t\t";
    output << e.first_name << "\t\t";
    output << e.address << "\t\t";
    output << e.city << "\t\t";
    output << e.province << "\t\t";
    output << e.postal_code << "\t\t";
    output << e.phone_number << "\t\t";
    output << e.gender << "\t\t";
    output << e.age << "\t\t";
    output << e.num_of_dependants << "\t\t";
    output << e.department_category << "\t\t";
    output << e.union_member << "\t\t";
    output << e.hourly_rate;

    return output;
}
