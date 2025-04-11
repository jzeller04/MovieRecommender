#include "movieDatabase.hpp"

MovieStorage::MovieStorage()
{
    std::cout << "Initializing genres...\n";

    // Manually initialize each genre with an empty set
    for (int genre = static_cast<int>(Genre::Action); genre <= static_cast<int>(Genre::Western); ++genre) {
        Genre g = intToGenre(genre);
        m_Movies[g] = std::unordered_set<Movie*>();

        std::cout << "Initialized genre: " << genreToString(g) << "\n";
    }
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

const std::unordered_set<Movie*>& MovieStorage::getSet(Genre genre) const
{
    return m_Movies.at(genre);
}
