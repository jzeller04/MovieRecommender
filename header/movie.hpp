#pragma once

#include <string>
#include <vector>
#include "./enum/genre.hpp"

class Movie
{
private:
    unsigned int m_id;
    std::vector<std::string> m_tags;
    std::string m_movieTitle;
    Genre m_genre;
public:
    Movie(unsigned int id, const std::string &title, Genre movieGenre, const std::vector<std::string> &tags);
};