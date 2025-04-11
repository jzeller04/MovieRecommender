#include "movie.hpp"


Movie::Movie()
{
    this->m_id = -1;
    this->m_movieTitle = "";
    // this->m_genres = Genre::None;
    // this->m_tags = tags;
}
Movie::Movie(unsigned int id, const std::string &title, const std::unordered_set<Genre> &movieGenre/*, const std::vector<std::string> &tags*/)
{
    this->m_id = id;
    this->m_movieTitle = title;
    this->m_genres = movieGenre;
    // this->m_tags = tags;
}
unsigned int Movie::getID() const
{
    return m_id;
}

std::vector<std::string> Movie::getTags() const
{
    return m_tags;
}

std::string Movie::getTitle() const
{
    return m_movieTitle;
}

std::unordered_set<Genre> Movie::getGenres() const
{
    return m_genres;
}

bool Movie::operator<(const Movie& other) const {
    return m_id < other.m_id;
}

bool Movie::operator==(const Movie& other) const {
return m_movieTitle == other.m_movieTitle && m_id == other.m_id && m_genres == other.m_genres;
}


void Movie::debugPrint()
{
    std::cerr << "Movie info: \n";
    std::cerr << m_id << std::endl;
    std::cerr << m_movieTitle << std::endl;
    for(auto i : m_genres)
        std::cerr << genreToString(i) << std::endl;
}

void Movie::debugPrintStar(std::unordered_set<Genre> userPrefs)
{
    std::cerr << "===============\n";
    std::cerr << "Movie info: \n";
    //std::cerr << m_id << std::endl;
    std::cerr << m_movieTitle << std::endl;
    for(auto i : m_genres)
        std::cerr << genreToString(i) << (debugFindGenre(i, userPrefs) ? "*" : "") << std::endl;
    std::cerr << "===============\n";
}