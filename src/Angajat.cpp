#include "Angajat.h"
#include <sstream>
#include <iomanip>
#include <vector>

Angajat::Angajat() : id(0), salariu(0.0) {}

Angajat::Angajat(int id, const std::string& nume, const std::string& adresa, const std::string& post, const DataCalendaristica& dataAngajare, double salariu)
    : id(id), nume(nume), adresa(adresa), post(post), dataAngajare(dataAngajare), salariu(salariu) {}

Angajat::~Angajat() {}

int Angajat::getId() const {
    return id;
}

std::string Angajat::getNume() const {
    return nume;
}

std::string Angajat::getAdresa() const {
    return adresa;
}

std::string Angajat::getPost() const {
    return post;
}

DataCalendaristica Angajat::getDataAngajare() const {
    return dataAngajare;
}

double Angajat::getSalariu() const {
    return salariu;
}

std::string Angajat::toCsvLine() const {
    std::ostringstream oss;
    oss << id << ";" << nume << ";" << adresa << ";" << post << ";"
        << dataAngajare.toString() << ";" 
        << std::fixed << std::setprecision(2) << salariu;
    return oss.str();
}

Angajat Angajat::fromCsvLine(const std::string& line) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(line);
    
    // Extragem fiecare element delimitat de ';'
    while (std::getline(tokenStream, token, ';')) {
        tokens.push_back(token);
    }

    if (tokens.size() < 6) {
        return Angajat(); 
    }

    return Angajat(std::stoi(tokens[0]), tokens[1], tokens[2], tokens[3], DataCalendaristica::fromString(tokens[4]), std::stod(tokens[5]));
}

std::string Angajat::toDisplayString() const {
    std::ostringstream oss;
    oss << "ID: " << id << " | Nume: " << nume << " | Adresa: " << adresa 
        << " | Post: " << post << " | Data Angajare: " << dataAngajare.toString() 
        << " | Salariu: " << std::fixed << std::setprecision(2) << salariu;
    return oss.str();
}