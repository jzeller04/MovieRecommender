#pragma once

#include <string>
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
    std::vector<Genre> m_genres;
public:
    Movie();
    Movie(unsigned int id, const std::string &title, const std::vector<Genre> &movieGenres/*,const std::vector<std::string> &tags*/);
    unsigned int getID();
    std::vector<std::string> getTags();
    std::string getTitle();
    std::vector<Genre> getGenre();

    void debugPrint();
};