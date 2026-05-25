#pragma once
#include <vector>
#include <string>
#include "Angajat.h"

class SearchService {
public:
    SearchService();
    ~SearchService();

    std::vector<Angajat> searchByName(const std::vector<Angajat>& angajati, const std::string& nameFragment) const;
    std::vector<Angajat> searchByJob(const std::vector<Angajat>& angajati, const std::string& jobFragment) const;
    std::vector<Angajat> searchByNameAndJob(const std::vector<Angajat>& angajati, const std::string& nameFragment, const std::string& jobFragment) const;
    std::vector<Angajat> filterBySalary(const std::vector<Angajat>& angajati, double minSalary, double maxSalary) const;
private:
    bool containsIgnoreCase(const std::string& str, const std::string& fragment) const;
};