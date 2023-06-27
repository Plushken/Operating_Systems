#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/stat.h>
#include "Employee.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cout << "Usage: Creator <filename> <num_records>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    int num_records = atoi(argv[2]);

    std::string dirpath = "../binFiles";
    if (access(dirpath.c_str(), F_OK) == -1) {
        if (mkdir(dirpath.c_str(), 0777) == -1) {
            std::cout << "Error creating directory " << dirpath << std::endl;
            return 1;
        }
    }

    std::ofstream outfile((dirpath + "/" + filename).c_str(), std::ios::binary);
    if (!outfile.is_open()) {
        std::cout << "Error opening file " << filename << std::endl;
        return 1;
    }

    employee emp{};
    for (int i = 0; i < num_records; i++) {
        std::cout << "Record " << i + 1 << std::endl;

        std::cout << "Enter employee number: \r";
        std::cin >> emp.num;

        std::cout << "Enter employee name: \r";
        std::cin >> emp.name;

        std::cout << "Enter hours worked: \r";
        std::cin >> emp.hours;

        outfile.write((char *) &emp, sizeof(emp));
    }

    outfile.close();

    std::cout << "File created successfully." << std::endl;

    return 0;
}