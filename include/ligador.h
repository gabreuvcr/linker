#ifndef LIGADOR_H
#define LIGADOR_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctype.h>

std::vector<std::string> get_input(const std::string &file_name);
void update_table(const std::string& file_name, std::map<std::string, int>& labels, std::vector<std::string>& commands, int& ILC);
void update_code(std::map<std::string, int> labels, std::vector<std::string>& commands);

#endif
