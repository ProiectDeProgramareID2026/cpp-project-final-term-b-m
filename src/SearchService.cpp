#include "SearchService.h"
#include <algorithm>
#include <cctype>

SearchService::SearchService() {}

SearchService::~SearchService() {}

bool SearchService::containsIgnoreCase(const std::string& str, const std::string& fragment) const {
    auto it = std::search(
        str.begin(), str.end(),
        fragment.begin(), fragment.end(),
        [](unsigned char ch1, unsigned char ch2) { return std::tolower(ch1) == std::tolower(ch2); }
    );
    return (it != str.end());
}

std::vector<Angajat> SearchService::searchByName(const std::vector<Angajat>& angajati, const std::string& nameFragment) const {
    std::vector<Angajat> result;
    for (const auto& angajat : angajati) {
        if (containsIgnoreCase(angajat.getNume(), nameFragment)) {
            result.push_back(angajat);
        }
    }
    return result;
}

std::vector<Angajat> SearchService::searchByJob(const std::vector<Angajat>& angajati, const std::string& jobFragment) const {
    std::vector<Angajat> result;
    for (const auto& angajat : angajati) {
        if (containsIgnoreCase(angajat.getPost(), jobFragment)) {
            result.push_back(angajat);
        }
    }
    return result;
}

std::vector<Angajat> SearchService::searchByNameAndJob(const std::vector<Angajat>& angajati, const std::string& nameFragment, const std::string& jobFragment) const {
    std::vector<Angajat> result;
    for (const auto& angajat : angajati) {
        if (containsIgnoreCase(angajat.getNume(), nameFragment) && containsIgnoreCase(angajat.getPost(), jobFragment)) {
            result.push_back(angajat);
        }
    }
    return result;
}

std::vector<Angajat> SearchService::filterBySalary(const std::vector<Angajat>& angajati, double minSalary, double maxSalary) const {
    std::vector<Angajat> result;
    for (const auto& angajat : angajati) {
        if (angajat.getSalariu() >= minSalary && std::abs(angajat.getSalariu() - maxSalary) <= 1e-9 || angajat.getSalariu() <= maxSalary) { // Am folosit strict verificare dublă ca standard, dar o comparație directă simplifică. Refac:
            if (angajat.getSalariu() >= minSalary && angajat.getSalariu() <= maxSalary) {
                result.push_back(angajat);
            }
        }
        return result;
    }
}