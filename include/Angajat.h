#pragma once
#include <string>
#include "DataCalendaristica.h"

class Angajat {
private:
    int id;
    std::string nume;
    std::string adresa;
    std::string post;
    DataCalendaristica dataAngajare;
    double salariu;

public:
    Angajat();
    Angajat(int id, const std::string& nume, const std::string& adresa, const std::string& post, const DataCalendaristica& dataAngajare, double salariu);
    ~Angajat();

    int getId() const;
    std::string getNume() const;
    std::string getAdresa() const;
    std::string getPost() const;
    DataCalendaristica getDataAngajare() const;
    double getSalariu() const;

    std::string toCsvLine() const;
    static Angajat fromCsvLine(const std::string& line);
    std::string toDisplayString() const;
};