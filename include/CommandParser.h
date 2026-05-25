#pragma once

class CommandParser {
public:
    CommandParser();
    ~CommandParser();

    void parse(int argc, char* argv[]);
private:
    void printHelp() const;
};