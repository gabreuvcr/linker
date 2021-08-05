#include <iostream>
#include <vector>
#include <map>

#include "ligador.h"

int main(int argc, char *argv[]) {
    int ILC = 0;
    std::vector<std::string> commands;
    std::map<std::string, int> labels = {};

    update_table(argv[1], labels, commands, ILC);
    update_table(argv[2], labels, commands, ILC);
    update_code(labels, commands);

    int size = commands.size();
    for (int i = 0; i < size; i++) {
        std::cout << commands[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
