cmake_minimum_required(VERSION 3.10)
project(EmployeeManagementCpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Definim executabilul pentru aplicația 2
add_executable(app_2
    src/main_app_2.cpp
    src/Angajat.cpp
    src/DataCalendaristica.cpp
    src/EmployeeRepository.cpp
    src/SearchService.cpp
    src/ReportService.cpp
    src/CommandParser.cpp
    include/Angajat.h
        include/CommandParser.h
    include/DataCalendaristica.h
    include/EmployeeRepository.h
    include/ReportService.h
    include/SearchService.h
)

# Specificăm directorul cu headere (.h) pentru target-ul app_2
target_include_directories(app_2 PRIVATE include)