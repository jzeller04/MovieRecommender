#include "include/movie.hpp"
#include "include/algorithms.hpp"
#include <iostream>

int main()
{
    std::unordered_set<Genre> genres;
    genres.insert(Genre::Action);
    genres.insert(Genre::Adventure);


    std::unordered_set<Genre> genres2;
    genres2.insert(Genre::Action);
    genres2.insert(Genre::Horror);

    
    std::string ex = "Example";
    Movie movie1(1, "Title1", genres);
    Movie movie2(2, "Example2", genres2);

    movie1.debugPrint();
    movie2.debugPrint();

    std::cerr << jaccardSimilarity(movie1.getGenres(), movie2.getGenres()); // this works!

}