#pragma once

#include <string>
#include "enum/genre.hpp"
#include "movie.hpp"

float jaccardSimilarity(const std::unordered_set<Genre> &a, const std::unordered_set<Genre> &b);

std::vector<Movie> recommendMovie(const std::vector<Movie> &movieDatabase, const std::unordered_set<Genre> &userPrefs);