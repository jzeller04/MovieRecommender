#include "movieDatabase.hpp"

MovieStorage::MovieStorage()
{
    // Debugging: Output to make sure constructor runs
    std::cout << "Initializing genres...\n";

    // Manually initialize each genre with an empty set
    for (int genre = static_cast<int>(Genre::Action); genre <= static_cast<int>(Genre::Western); ++genre) {
        Genre g = intToGenre(genre);
        m_Movies[g] = std::unordered_set<Movie*>();

        // Debugging: Ensure each genre is being initialized
        std::cout << "Initialized genre: " << genreToString(g) << "\n"; // Prints genre index
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
