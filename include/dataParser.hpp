#pragma once

#include "movie.hpp"
#include "util.hpp"
#include "movieDatabase.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

std::vector<std::string> split(const std::string& str, char delimiter);

MovieStorage readMoviesFromCSV(const std::string& filename);