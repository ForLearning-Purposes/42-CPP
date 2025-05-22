#include "serializer.hpp"

int main() {
    Data employee_data = {123342, "Monika Simic"};

    std::cout << "Original Data: " << employee_data.employee_ID << ", " << employee_data.employee_name << std::endl;
}