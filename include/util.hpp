#pragma once

#include <string>
#include "enum/genre.hpp"
#include "movie.hpp"
#include <functional> // For std::hash
#include <string>



std::string genreToString(Genre genre);

Genre intToGenre(int i);

Genre stringToGenre(std::string genre);

bool debugFindGenre(Genre a, const std::unordered_set<Genre> &genreSet);
