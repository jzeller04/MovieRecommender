#include "include/algorithms.hpp"


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
// recommends movies with MovieStorage input, and userPrefs
std::set<Movie> recommendMovie(const MovieStorage &movieDatabase, const std::unordered_set<Genre> &userPrefs) // side note, jaccard similarity only works well if the sets have a similar length. If the user only has one preference, it thinks NO movies are similar (which is true, but still)
{
    std::set<Movie> returnMovies;

    

    for(auto genreList : userPrefs) // go thru each set of movies that is the same genre as user prefs
    {
        for(auto *movieSet : movieDatabase.getSet(genreList))
        {
            if(userPrefs.size() < 3)
            {
                if(jaccardSimilarity(movieSet->getGenres(), userPrefs) > 0.3) // tweak this number
                {
                    returnMovies.insert(*movieSet);
                } 
            }
            else if(jaccardSimilarity(movieSet->getGenres(), userPrefs) > 0.4) // tweak this number
            {
                returnMovies.insert(*movieSet);
            }
        } 
    }

    
    return returnMovies;
}

