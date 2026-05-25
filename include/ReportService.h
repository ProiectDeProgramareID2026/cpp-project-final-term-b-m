#pragma once
#include <vector>
#include <string>
#include <map>
#include "Angajat.h"

class ReportService {
public:
    ReportService();
    ~ReportService();

    int countEmployees(const std::vector<Angajat>& angajati) const;
    std::map<std::string, int> countByJob(const std::vector<Angajat>& angajati) const;
    double averageSalary(const std::vector<Angajat>& angajati) const;
    std::string generateAllEmployeesReport(const std::vector<Angajat>& angajati) const;
    std::string generateJobsReport(const std::vector<Angajat>& angajati) const;
    std::string generateAverageSalaryReport(const std::vector<Angajat>& angajati) const;
    void exportReport(const std::string& content, const std::string& outputPath) const;
};