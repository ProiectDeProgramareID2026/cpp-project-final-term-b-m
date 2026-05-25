cmake_minimum_required(VERSION 3.10)
project(EmployeeManagementCpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specificăm directorul cu headere (.h)
include_directories(include)

# Definim executabilul pentru aplicația 2
add_executable(app_2
    src/main_app_2.cpp
    src/Angajat.cpp
    src/DataCalendaristica.cpp
    src/EmployeeRepository.cpp
    src/SearchService.cpp
    src/ReportService.cpp
    src/CommandParser.cpp
        src/main_app_2.cpp
)