#include "serializer.hpp"

int main() {
    Data employee_data = {123342, "Monika Simic"};

    std::cout << "Original Data: " << employee_data.employee_ID << ", " << employee_data.employee_name << std::endl;

    uintptr_t ser_data = Serializer::serialize(&employee_data);
    std::cout << "Serialized Data: " << ser_data << std::endl; //
    Data* des_data = Serializer::deserialize(ser_data);
    std::cout << "Deserialized Data: " << des_data->employee_ID << ", " << des_data->employee_name << std::endl;
}