// TH 2021
#pragma once

#include <string>
#include <vector>

std::vector<std::string> readFileLines(std::string path);

std::vector<int> vecStringToInt(const std::vector<std::string>& string_vec);

void extractIntsFromString(const std::string& str, std::vector<int>* out);

void extractIntsFromCommaString(const std::string& str, std::vector<int>* out);
