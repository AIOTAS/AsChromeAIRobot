#include <iostream>
using namespace std;
#include "chrome_robot_page.h"

int main()
{
    AsChromePageRobot * chrome_page_robot = new AsChromePageRobot();
    chrome_page_robot->connect_browser();

    delete chrome_page_robot;
    return 0;
}