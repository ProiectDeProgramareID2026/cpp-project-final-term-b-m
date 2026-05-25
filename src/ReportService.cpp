#include "../include/ReportService.h"
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iostream>

ReportService::ReportService() {}

ReportService::~ReportService() {}

int ReportService::countEmployees(const std::vector<Angajat>& angajati) const {
    return static_cast<int>(angajati.size());
}

std::map<std::string, int> ReportService::countByJob(const std::vector<Angajat>& angajati) const {
    std::map<std::string, int> jobCounts;
    for (const auto& angajat : angajati) {
        jobCounts[angajat.getPost()]++;
    }
    return jobCounts;
}

double ReportService::averageSalary(const std::vector<Angajat>& angajati) const {
    if (angajati.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    for (const auto& angajat : angajati) {
        sum += angajat.getSalariu();
    }
    return sum / angajati.size();
}

std::string ReportService::generateAllEmployeesReport(const std::vector<Angajat>& angajati) const {
    std::ostringstream oss;
    oss << "SISTEM MANAGEMENT ANGAJATI - RAPORT\n";
    oss << "Tip raport: Toti angajatii\n";
    oss << "Numar total angajati: " << countEmployees(angajati) << "\n\n";
    for (const auto& angajat : angajati) {
        oss << angajat.toDisplayString() << "\n";
    }
    return oss.str();
}

std::string ReportService::generateJobsReport(const std::vector<Angajat>& angajati) const {
    std::ostringstream oss;
    oss << "SISTEM MANAGEMENT ANGAJATI - RAPORT\n";
    oss << "Tip raport: Angajati grupati pe posturi\n\n";
    auto jobCounts = countByJob(angajati);
    for (const auto& pair : jobCounts) {
        oss << "Post: " << pair.first << " | Numar angajati: " << pair.second << "\n";
    }
    return oss.str();
}

std::string ReportService::generateAverageSalaryReport(const std::vector<Angajat>& angajati) const {
    std::ostringstream oss;
    oss << "SISTEM MANAGEMENT ANGAJATI - RAPORT\n";
    oss << "Tip raport: Salariu mediu\n\n";
    oss << "Salariul mediu al tuturor angajatilor este: " 
        << std::fixed << std::setprecision(2) << averageSalary(angajati) << "\n";
    return oss.str();
}

void ReportService::exportReport(const std::string& content, const std::string& outputPath) const {
    std::ofstream file(outputPath);
    if (file.is_open()) {
        file << content;
        file.close();
    } else {
        std::cerr << "Eroare: Nu s-a putut deschide sau crea fisierul " << outputPath << " pentru export!\n";
    }
}