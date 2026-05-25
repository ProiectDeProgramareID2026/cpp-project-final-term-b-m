#pragma once
#include <string>

class DataCalendaristica {
private:
    int zi;
    int luna;
    int an;

public:
    DataCalendaristica();
    DataCalendaristica(int zi, int luna, int an);
    ~DataCalendaristica();

    static bool isValidDateString(const std::string& date);
    static DataCalendaristica fromString(const std::string& date);
    std::string toString() const;
};