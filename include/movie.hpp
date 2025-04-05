#pragma once

#include <string>
#include <unordered_set>
#include <vector>
#include "enum/genre.hpp"
#include "util.hpp"
#include <iostream>

class Movie
{
private:
    unsigned int m_id;
    std::vector<std::string> m_tags;
    std::string m_movieTitle;
    std::unordered_set<Genre> m_genres;
public:
    Movie();
    Movie(unsigned int id, const std::string &title, const std::unordered_set<Genre> &movieGenres/*,const std::vector<std::string> &tags*/);
    unsigned int getID();
    std::vector<std::string> getTags();
    std::string getTitle();
    std::unordered_set<Genre> getGenres();

    void debugPrint();
};