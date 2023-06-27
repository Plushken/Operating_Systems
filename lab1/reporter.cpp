#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
#include "Employee.h"

int main(int argc, char *argv[]) {
    std::string input_file, output_file;
    double pay_per_hour;

    if (argc < 4) {
        std::cerr
                << "Usage: reporter <input_binary_file> <Output_text_file> <pay_per_hour>";
        return 1;
    }
    input_file = argv[1];
    output_file = argv[2];
    pay_per_hour = atof(argv[3]);

    std::string inDirPath = "../binFiles";

    std::ifstream ifs(inDirPath + "/" + input_file, std::ios::binary);
    if (!ifs) {
        std::cerr << "Can't open input file " << input_file << std::endl;
        return 1;
    }

    if (output_file.length() < 5
        || output_file.substr(output_file.length() - 4) != ".txt") {
        output_file += ".txt";
    }

    std::string outDirPath = "../reports";
    if (access(outDirPath.c_str(), F_OK) == -1) {
        if (mkdir(outDirPath.c_str(), 0777) == -1) {
            std::cout << "Error creating directory " << outDirPath << std::endl;
            return 1;
        }
    }

    std::ofstream ofs((outDirPath + "/" + output_file).c_str());
    if (!ofs) {
        std::cerr << "Can't open output file " << output_file << std::endl;
        return 1;
    }

    int count = 0;
    employee e;
    while (ifs.read((char *) &e, sizeof(e))) {
        double salary = e.hours * pay_per_hour;
        ofs << e.num << " " << e.name << " " << e.hours << " " << salary
            << std::endl;
        ++count;
    }

    std::cout << "Report for " << input_file << " (" << count
              << " employees) saved to " << output_file << std::endl;

    ifs.close();
    ofs.close();
    return 0;
}