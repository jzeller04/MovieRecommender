#include "include/movie.hpp"
#include "include/algorithms.hpp"
#include <iostream>

int main()
{
    std::vector<Genre> genres;
    genres.push_back(Genre::Children_s);
    genres.push_back(Genre::Adventure);

    std::vector<Genre> genres2;
    genres2.push_back(Genre::Adventure);
    genres2.push_back(Genre::Animation);
    std::string ex = "Example";
    Movie movie1(1, "Title1", genres);
    Movie movie2(2, "Example2", genres2);

    movie1.debugPrint();
    movie2.debugPrint();

    std::cerr << jaccardSimilarity(movie1, movie2);

}