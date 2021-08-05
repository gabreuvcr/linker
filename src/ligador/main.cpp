#include <iostream>
#include <vector>
#include <map>

#include "ligador.h"

int main(int argc, char *argv[]) {
    int ILC = 0;
    std::vector<std::string> commands;
    std::map<std::string, int> labels = {};

    for(int i = 1; i < argc; i++) {
        update_table(argv[i], labels, commands, ILC);
    }
    update_code(labels, commands);

    int size = commands.size();
    int program_start = 100;
    int stack_start = 1000 + program_start + size;
    int entry_point = program_start + labels["main"] - 1;

    std::cout << "MV-EXE" << std::endl << std::endl;

    std::cout << size << " ";
    std::cout << program_start << " ";
    std::cout << stack_start << " ";
    std::cout << entry_point << std::endl << std::endl;

    for (int i = 0; i < size; i++) {
        std::cout << commands[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
