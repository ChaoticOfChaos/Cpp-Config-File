#ifndef CONFIG_FETCH_HPP
#define CONFIG_FETCH_HPP

#include <map>
#include <string>
#include <vector>

#include <iostream>

#include "txtmanipull.hpp"

std::map<std::string, std::string> config_fetch(std::string ConfigFilePath="./.config.conf", char commentary='#') {
    std::map<std::string, std::string> configContent;
    std::vector<std::string> exit;
    TXTManipulation::ReadFile configFile(ConfigFilePath);
    std::vector<std::string> token_exit;
    if (configFile.read() == 1) {
        return {{"NONE", "NONE"}};
    }

    for (std::string line : configFile.getValue()) {
        if (line[0] != commentary && line.size() > 0) {
            exit.push_back(line);
        }
    }

    for (std::string token : exit) {
        token_exit = TXTManipulation::split(token, '=');

        configContent[token_exit[0]] = token_exit[1];
    }

    return configContent;
}

#endif