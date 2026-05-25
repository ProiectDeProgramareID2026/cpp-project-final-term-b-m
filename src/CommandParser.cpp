#include "CommandParser.h"
#include "EmployeeRepository.h"
#include "SearchService.h"
#include "ReportService.h"
#include <iostream>
#include <string>
#include <stdexcept>

CommandParser::CommandParser() {}

CommandParser::~CommandParser() {}

void CommandParser::printHelp() const {
    std::cout << "Comenzi disponibile pentru app_2.exe:\n"
              << "  help\n"
              << "  afisare_angajati\n"
              << "  cautare_nume \"<fragment_nume>\"\n"
              << "  cautare_post \"<fragment_post>\"\n"
              << "  cautare_nume_post \"<fragment_nume>\" \"<fragment_post>\"\n"
              << "  filtrare_salariu <salariu_minim> <salariu_maxim>\n"
              << "  raport_posturi\n"
              << "  raport_salariu_mediu\n"
              << "  export_raport <tip_raport> \"<fisier_output>\"\n"
              << "    (tip_raport acceptate: toti, posturi, salariu_mediu)\n";
}

void CommandParser::parse(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Eroare: Lipsesc argumentele. Folositi 'help' pentru lista comenzilor.\n";
        return;
    }

    std::string command = argv[1];

    if (command == "help") {
        printHelp();
        return;
    }

    EmployeeRepository repo("../data/angajati.csv");
    SearchService search;
    ReportService report;
    auto angajati = repo.load();

    if (command == "afisare_angajati") {
        if (argc != 2) { std::cerr << "Eroare: Comanda 'afisare_angajati' nu primeste argumente.\n"; return; }
        std::cout << report.generateAllEmployeesReport(angajati);
        
    } else if (command == "cautare_nume") {
        if (argc != 3) { std::cerr << "Eroare: Argumente invalide. Utilizare: cautare_nume \"<fragment_nume>\"\n"; return; }
        auto results = search.searchByName(angajati, argv[2]);
        if(results.empty()) std::cout << "Nu a fost gasit niciun angajat.\n";
        else for(const auto& a : results) std::cout << a.toDisplayString() << "\n";

    } else if (command == "cautare_post") {
        if (argc != 3) { std::cerr << "Eroare: Argumente invalide. Utilizare: cautare_post \"<fragment_post>\"\n"; return; }
        auto results = search.searchByJob(angajati, argv[2]);
        if(results.empty()) std::cout << "Nu a fost gasit niciun angajat.\n";
        else for(const auto& a : results) std::cout << a.toDisplayString() << "\n";

    } else if (command == "cautare_nume_post") {
        if (argc != 4) { std::cerr << "Eroare: Argumente invalide. Utilizare: cautare_nume_post \"<fragment_nume>\" \"<fragment_post>\"\n"; return; }
        auto results = search.searchByNameAndJob(angajati, argv[2], argv[3]);
        if(results.empty()) std::cout << "Nu a fost gasit niciun angajat.\n";
        else for(const auto& a : results) std::cout << a.toDisplayString() << "\n";

    } else if (command == "filtrare_salariu") {
        if (argc != 4) { std::cerr << "Eroare: Argumente invalide. Utilizare: filtrare_salariu <salariu_minim> <salariu_maxim>\n"; return; }
        try {
            double minSal = std::stod(argv[2]);
            double maxSal = std::stod(argv[3]);
            auto results = search.filterBySalary(angajati, minSal, maxSal);
            if(results.empty()) std::cout << "Nu a fost gasit niciun angajat in intervalul salarial.\n";
            else for(const auto& a : results) std::cout << a.toDisplayString() << "\n";
        } catch (const std::exception&) {
            std::cerr << "Eroare: Salariile trebuie sa fie numere valide.\n";
        }

    } else if (command == "raport_posturi") {
        if (argc != 2) { std::cerr << "Eroare: Comanda 'raport_posturi' nu primeste argumente.\n"; return; }
        std::cout << report.generateJobsReport(angajati);

    } else if (command == "raport_salariu_mediu") {
        if (argc != 2) { std::cerr << "Eroare: Comanda 'raport_salariu_mediu' nu primeste argumente.\n"; return; }
        std::cout << report.generateAverageSalaryReport(angajati);

    } else if (command == "export_raport") {
        if (argc != 4) { std::cerr << "Eroare: Argumente invalide. Utilizare: export_raport <tip_raport> \"<fisier_output>\"\n"; return; }
        std::string tip = argv[2];
        std::string outFile = argv[3];
        std::string content = "";
        if (tip == "toti") content = report.generateAllEmployeesReport(angajati);
        else if (tip == "posturi") content = report.generateJobsReport(angajati);
        else if (tip == "salariu_mediu") content = report.generateAverageSalaryReport(angajati);
        else {
            std::cerr << "Eroare: Tip raport invalid. Optiuni: toti, posturi, salariu_mediu\n";
            return;
        }
        report.exportReport(content, outFile);
        std::cout << "Raport exportat cu succes in " << outFile << "\n";
    } else {
        std::cerr << "Eroare: Comanda necunoscuta: " << command << "\n";
        std::cerr << "Folositi 'help' pentru a vedea lista comenzilor disponibile.\n";
    }
}