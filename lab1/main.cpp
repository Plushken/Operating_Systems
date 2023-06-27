#include <iostream>
#include <string>
#include <vector>
#include <boost/process.hpp>

namespace bp = boost::process;

void runCreator(const std::string &fileName, int recordCount) {
    bp::ipstream outPipe;
    bp::child creatorProcess("creator",
                             bp::args = {fileName, std::to_string(recordCount)},
                             bp::std_out > outPipe);

    std::string output;
    while (std::getline(outPipe, output, '\r')) {
        std::cout << output << std::flush;
    }

    creatorProcess.wait();
}

void runReporter(const std::string &binaryFileName,
                 const std::string &reportFileName,
                 double payPerHour) {
    bp::ipstream outPipe;
    bp::child reporterProcess("reporter",
                              bp::args = {binaryFileName, reportFileName,
                                          std::to_string(payPerHour)},
                              bp::std_out > outPipe);
    std::string output;
    while (std::getline(outPipe, output)) {
        std::cout << output << std::endl;
    }
    reporterProcess.wait();
}

int main() {
    std::string fileName;
    int recordCount;

    std::cout << "Enter binary file name: ";
    std::cin >> fileName;
    std::cout << "Enter record count: ";
    std::cin >> recordCount;

    runCreator(fileName, recordCount);

    std::string reportFileName;
    double payPerHour;

    std::cout << "Enter report file name: ";
    std::cin >> reportFileName;
    std::cout << "Enter pay per hour: ";
    std::cin >> payPerHour;

    runReporter(fileName, reportFileName, payPerHour);

    return 0;
}