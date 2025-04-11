#include "movieDatabase.hpp"

MovieStorage::MovieStorage()
{
}

MovieStorage::~MovieStorage()
{
}

void MovieStorage::store(Movie *movie)
{
    for(auto i : movie->getGenres())
    {
        m_Movies[i].insert(movie); // inserts movie into correct set based on genre
    }
}

std::unordered_set<Movie*>& MovieStorage::getSet(Genre genre)
{
    return m_Movies[genre];
}
