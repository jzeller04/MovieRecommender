#pragma once

#include <string>
#include <unordered_set>
#include "enum/genre.hpp"
#include "movie.hpp"
#include <set>
#include "movieDatabase.hpp"

float jaccardSimilarity(const std::unordered_set<Genre> &a, const std::unordered_set<Genre> &b);

std::set<Movie> recommendMovie(const MovieStorage& movieDatabase, const std::unordered_set<Genre>& userPrefs);