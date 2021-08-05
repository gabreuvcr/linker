#include "ligador.h"

std::vector<std::string> get_input(const std::string& file_name) {
	std::ifstream f;
    f.open(file_name);

    std::vector<std::string> inputs;
	std::string line;
	while (std::getline(f, line)) {
        std::stringstream ss(line);
        std::string command;
        while(getline(ss, command, ' ')) {
            if(command.size() == 0) continue;
            inputs.push_back(command);
        }
	}
    f.close();
    return inputs;
}

void update_table(const std::string& file_name, std::map<std::string, int>& labels, std::vector<std::string>& commands, int& ILC) {
    std::vector<std::string> input = get_input(file_name);
    int size = input.size();
    bool is_table = true;
    int header_i = 0;

    for (auto i = 0; i < size; i++) {
        if (is_table) {
            if (input[i] == "#endtable#") {
                header_i = i;
                is_table = false;
                continue;
            }
            labels[input[i]] = std::stoi(input[i + 1]) + ILC;
            i++;
        }
        else if (i <= header_i + 4) {
            //ignore header (temporary)
            continue;
        }
        else {
            ILC++;
            commands.push_back(input[i]);
        }
    }
}

bool is_num(std::string &str) {
    return std::all_of(std::begin(str), std::end(str), ::isdigit) || str[0] == '-';
}

void update_code(std::map<std::string, int> labels, std::vector<std::string>& commands) {
    int ILC = 0;
    int size = commands.size();

    for (int i = 0; i < size; i++) {
        ILC++;
        if (!is_num(commands[i])) {
            commands[i] = std::to_string(labels[commands[i]] - ILC - 1);
        }
    }
}
