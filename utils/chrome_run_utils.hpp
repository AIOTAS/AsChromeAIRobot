#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <cstdlib>

void run_cmd_using_system(std::vector<std::string> &cmd_strs_list)
{
    if (cmd_strs_list.empty())
    {
        std::cout << "cmd args vector is empty, please check your program is in success use the function." << std::endl;
    }

    std::string cmd_string = "";
    for (std::vector<std::string>::iterator begin = cmd_strs_list.begin(); begin != cmd_strs_list.end(); begin++)
    {
        cmd_string += (std::string(begin->c_str()) + " ");
    }

    std::cout << cmd_string << std::endl;

    int result = system(cmd_string.c_str());
    std::cout << result << std::endl;
}

// 开启一个线程去执行系统调用，启动chrome浏览器实例
void run_cmd_using_system_with_thread(std::vector<std::string> &cmd_strs_list)
{
    std::thread run_browser_thread(run_cmd_using_system, cmd_strs_list);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    run_browser_thread.detach();
}