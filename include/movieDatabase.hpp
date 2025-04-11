#pragma once

#include <unordered_set>
#include <unordered_map>
#include "movie.hpp"
#include "enum/genre.hpp"
#include "util.hpp"
#include <iostream>
#include <string>

class MovieStorage // store movies with references. Copying movies is just space inefficient
{
private:
    std::unordered_map<Genre, std::unordered_set<Movie*>> m_Movies;

    
public:
    MovieStorage();
    ~MovieStorage();
    void store(Movie* movie);
    std::unordered_set<Movie*>& getSet(Genre genre);
};