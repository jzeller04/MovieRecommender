#pragma once

#include <string>
#include <unordered_set>
#include <vector>
#include "enum/genre.hpp"
#include "util.hpp"
#include <iostream>
#include <functional>

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
    unsigned int getID() const;
    std::vector<std::string> getTags() const;
    std::string getTitle() const;
    std::unordered_set<Genre> getGenres() const;

    bool operator<(const Movie& other) const {
        return m_id < other.m_id; // Or use a more complex comparison logic here
    }

    void debugPrint();
    void debugPrintStar(std::unordered_set<Genre> userPrefs);
};

  // Required for std::hash

