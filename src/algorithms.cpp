#include "algorithms.hpp"

// jaccard coefficient is the intersection of two sets divided by the union
float jaccardSimilarity(const std::unordered_set<Genre> &a, const std::unordered_set<Genre> &b) // the genres in the movies use hash sets in order to make this algorithm run at O(n), instead of O(n^2)
{
    int intersection = 0;
    int unionSize = a.size() + b.size();


    // find size of the intersection:

    if(a.empty() || b.empty()) // if one set is empty, no need to run the O(n) operation
        return 0;

    for(const auto &genre : a)
    {
        if(b.count(genre))
        {
            intersection++;
            unionSize--;
        }
    }

    return static_cast<float>(intersection)/unionSize;

}
// have this take in a MovieStorage instead
std::set<Movie> recommendMovie(std::unordered_set<Movie*> &movieDatabase, const std::unordered_set<Genre> &userPrefs)
{
    std::set<Movie> returnMovies;

    for(auto *i : movieDatabase)
    {
        if(jaccardSimilarity(i->getGenres(), userPrefs) > 0.4) // tweak this number
        {
            returnMovies.insert(*i);
        }
    }
    
    return returnMovies;
}

