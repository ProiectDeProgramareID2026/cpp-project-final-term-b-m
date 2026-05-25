#include "../include/DataCalendaristica.h"
#include <sstream>
#include <iomanip>
#include <cctype>

DataCalendaristica::DataCalendaristica() : zi(1), luna(1), an(1970) {}

DataCalendaristica::DataCalendaristica(int zi, int luna, int an) : zi(zi), luna(luna), an(an) {}

DataCalendaristica::~DataCalendaristica() {}

bool DataCalendaristica::isValidDateString(const std::string& date) {
    // Verificăm lungimea și poziția delimitatorilor
    if (date.length() != 10) return false;
    if (date[2] != '/' || date[5] != '/') return false;

    // Verificăm ca restul caracterelor să fie cifre
    for (int i = 0; i < 10; ++i) {
        if (i == 2 || i == 5) continue;
        if (!std::isdigit(date[i])) return false;
    }

    int z = std::stoi(date.substr(0, 2));
    int l = std::stoi(date.substr(3, 2));
    int a = std::stoi(date.substr(6, 4));

    if (l < 1 || l > 12) return false;
    if (z < 1 || z > 31) return false;

    // Verificare număr zile din lună
    if ((l == 4 || l == 6 || l == 9 || l == 11) && z > 30) return false;
    if (l == 2) {
        bool isLeap = (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
        if (z > (isLeap ? 29 : 28)) return false;
    }

    return true;
}

DataCalendaristica DataCalendaristica::fromString(const std::string& date) {
    if (!isValidDateString(date)) {
        return DataCalendaristica(); // Returnează valoarea default pentru formate incorecte
    }
    int z = std::stoi(date.substr(0, 2));
    int l = std::stoi(date.substr(3, 2));
    int a = std::stoi(date.substr(6, 4));
    return DataCalendaristica(z, l, a);
}

std::string DataCalendaristica::toString() const {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << zi << "/"
        << std::setfill('0') << std::setw(2) << luna << "/"
        << std::setfill('0') << std::setw(4) << an;
    return oss.str();
}