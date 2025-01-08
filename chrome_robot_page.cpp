#include "chrome_robot_page.h"
#include "chrome_run_utils.hpp"

bool AsChromePageRobot::connect_browser()
{
    std::string chrome_exec_path = this->get_chrome_path_from_env();
    std::cout << chrome_exec_path << std::endl;

    std::vector<std::string> run_browser_args;
    run_browser_args.push_back("\"" + chrome_exec_path + "\"");
    run_browser_args.push_back("--remote-debugging-port=" + this->remote_debugging_port);
    run_browser_args.push_back("--disable-suggestions-ui");
    run_browser_args.push_back("--hide-crash-restore-bubble");
    run_browser_args.push_back("--disable-infobars");
    run_browser_args.push_back("--no-first-run");
    run_browser_args.push_back("--disable-features=PrivacySandboxSettings4");
    run_browser_args.push_back("--user-data-dir=C:\\Users\\10501\\AppData\\Local\\Temp\\AsChromePageRobot\\userData\\9333");

    run_cmd_using_system_with_thread(run_browser_args);
    return true;
}

std::string AsChromePageRobot::get_chrome_path_from_env()
{
#if defined(_WIN32) || defined(_WIN64)
    HKEY hKey;
    const char *subKey = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\chrome.exe";
    char chromePath[MAX_PATH];
    DWORD bufferSize = sizeof(chromePath);

    // 打开注册表项
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, subKey, 0, KEY_READ, &hKey) == ERROR_SUCCESS)
    {
        // 查询 "Default" 值
        if (RegQueryValueExA(hKey, nullptr, nullptr, nullptr, (LPBYTE)chromePath, &bufferSize) == ERROR_SUCCESS)
        {
            RegCloseKey(hKey);
            return std::string(chromePath);
        }
        RegCloseKey(hKey);
    }
#endif
    return "";
}