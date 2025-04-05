#include "algorithms.hpp"


float jaccardSimilarity(Movie a, Movie b) // the genres in the movies are a vector on purpose, because "brute forcing" is faster with smaller input samples. Movies rearely have more than 3 or 4 genres, so by using an O(n^2), its actually faster.
{
    int intersection = 0;
    int unionSize = a.getGenre().size() + b.getGenre().size();


    // find size of the intersection:

    for(auto i : a.getGenre())
    {
        for(auto j : b.getGenre())
        {
            if(i == j)
            {
                intersection++;
                unionSize--;
            }
        }
    }
    return static_cast<float>(intersection)/unionSize;

}