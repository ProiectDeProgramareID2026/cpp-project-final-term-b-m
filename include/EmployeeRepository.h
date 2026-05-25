#pragma once
#include <string>
#include <vector>
#include "Angajat.h"

class EmployeeRepository {
private:
    std::string filePath;

public:
    explicit EmployeeRepository(const std::string& filePath);
    ~EmployeeRepository();

    std::vector<Angajat> load() const;
    void save(const std::vector<Angajat>& angajati) const;
    bool fileExists() const;
};