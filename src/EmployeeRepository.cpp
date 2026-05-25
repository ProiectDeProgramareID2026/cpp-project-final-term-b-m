#include "EmployeeRepository.h"
#include <fstream>
#include <iostream>

EmployeeRepository::EmployeeRepository(const std::string& filePath) : filePath(filePath) {}

EmployeeRepository::~EmployeeRepository() {}

bool EmployeeRepository::fileExists() const {
    std::ifstream file(filePath);
    return file.good();
}

std::vector<Angajat> EmployeeRepository::load() const {
    std::vector<Angajat> angajati;
    if (!fileExists()) {
        return angajati;
    }

    std::ifstream file(filePath);
    if (!file.is_open()) {
        return angajati;
    }

    std::string line;
    if (std::getline(file, line)) {
        try {
            int count = std::stoi(line);
            for (int i = 0; i < count; ++i) {
                if (std::getline(file, line)) {
                    angajati.push_back(Angajat::fromCsvLine(line));
                }
            }
        } catch (...) {
            // Ignorăm erorile de parsare dacă fișierul nu respectă structura pe prima linie
        }
    }
    
    return angajati;
}

void EmployeeRepository::save(const std::vector<Angajat>& angajati) const {
    std::ofstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Eroare: Nu s-a putut deschide fisierul pentru salvare: " << filePath << "\n";
        return;
    }

    file << angajati.size() << "\n";
    for (const auto& angajat : angajati) {
        file << angajat.toCsvLine() << "\n";
    }
}