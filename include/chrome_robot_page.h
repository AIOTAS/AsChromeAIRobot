#pragma once

#include <cstdlib>
#include <iostream>
#include <map>
#include <any>
#include <vector>
#include <cstdlib>
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

class AsChromePageRobot
{
public:
    AsChromePageRobot() = default;
    ~AsChromePageRobot() = default;

    bool connect_browser();
    std::string get_chrome_path_from_env();

private:
    // std::map<std::string, std::any> options;
    std::string remote_debugging_ip = "127.0.0.1";
    int remote_debugging_port = 9222;
};