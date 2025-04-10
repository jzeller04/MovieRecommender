#include "include/movie.hpp"
#include "include/algorithms.hpp"
#include <iostream>
#include <random>
#include <ctime>
#include <string>
int main()
{

    // NOTE for Douglas and Parth, everything in this main function is just for testing. But look at the functions I have created to guide how you do user input/file input. User preferences should be stored in a hash set. Movies for now can be in a vector.

    srand(time(NULL));
    std::string ex = "Movie ";
    std::vector<Movie> actionMovies;

    for(int i = 0; i < 500; i++)
    {
        std::unordered_set<Genre> copyGenres;
        for(int j = 0; j < 5; j++)
        {
            int random = rand() % 18;
            copyGenres.insert(intToGenre(random));
        }
        std::string ex2 = "Movie " + std::to_string(i);
        actionMovies.push_back(Movie(i, ex2, copyGenres));
    }

    std::unordered_set<Genre> userGenres;
    for(int j = 0; j < 10; j++)
    {
        int random = rand() % 18;
        userGenres.insert(intToGenre(random));
    }

    std::cout << "User prefs: \n";
    for(Genre i : userGenres)
    {
        std::string mark = (debugFindGenre(static_cast<Genre>(i), userGenres) ? "*" : "");
        std::cout << genreToString(i) << mark << std::endl;
    }

    std::vector<Movie> recMovies;
    recMovies = recommendMovie(actionMovies, userGenres);
    std::cout << "Recommended Movies: " << recMovies.size() << "/" << actionMovies.size() << std::endl;
    for(auto i : recMovies)
    {
        i.debugPrintStar(userGenres);
    }

    std::cout << "NOTE: All movies right now are just randomly generated test movies." << std::endl;


}