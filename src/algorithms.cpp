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

std::vector<Movie> recommendMovie(const std::vector<Movie> &movieDatabase, const std::unordered_set<Genre> &userPrefs)
{
    std::vector<Movie> returnMovies;

    for(auto i : movieDatabase /*add rating shit later?*/)
    {
        if(jaccardSimilarity(i.getGenres(), userPrefs) > 0.45) // tweak this number
        {
            returnMovies.push_back(i);
        }
    }
    
    return returnMovies;
}