#include <iostream>
#include "CommandParser.h"

int main(int argc, char* argv[]) {
    CommandParser parser;
    parser.parse(argc, argv);
    return 0;
}