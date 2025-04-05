#pragma once

#include <string>
#include "enum/genre.hpp"
#include "movie.hpp"

float jaccardSimilarity(const std::unordered_set<Genre> &a, const std::unordered_set<Genre> &b);