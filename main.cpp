#include <iostream>
#include <string>
#include <map>

#include "config_fetch.hpp"

int main() {
    std::map<std::string, std::string> confs;
    confs = config_fetch(".config.conf");

    std::cout << confs["var1"] << std::endl;

    return 0;
}