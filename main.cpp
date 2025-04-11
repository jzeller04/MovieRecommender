#include "include/movie.hpp"
#include "include/algorithms.hpp"
#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include "movieDatabase.hpp"
int main()
{

    // NOTE for Douglas and Parth, everything in this main function is just for testing. But look at the functions I have created to guide how you do user input/file input. User preferences should be stored in a hash set. Movies for now can be in a vector.

    srand(time(NULL));

    // generating random test dataset (basically a test file) of 1000 movies

    Movie dataSet[1000];
    for(int i = 0; i < 1000; i++)
    {
        std::unordered_set<Genre> copyGenres;
        for(int j = 0; j < 5; j++)
        {
            int random = rand() % 18;
            copyGenres.insert(intToGenre(random));
        }
        std::string title = "Movie " + std::to_string(i);
        dataSet[i] = Movie(i, title, copyGenres);
    }

    // storing sample into movie storage class
    MovieStorage storage;
    for(int i = 0; i < 1000; i++)
    {
        storage.store(&dataSet[i]);
    }

    std::unordered_set<Genre> userGenres; // create random user preferences
    for(int j = 0; j < 10; j++)
    {
        int random = rand() % 18;
        userGenres.insert(intToGenre(random));
    }

    std::cout << "User prefs: \n"; // display user prefs
    for(Genre i : userGenres)
    {
        std::cout << genreToString(i) << std::endl;
    }
    std::unordered_set<Movie*> actionMovies = storage.getSet(Genre::Action); // testing only looking thru action movies
    std::set<Movie> recMovies;
    recMovies = recommendMovie(actionMovies, userGenres);
    std::cout << "Recommended Movies: " << recMovies.size() << "/" << "1000";
    for(auto i : recMovies)
    {
        i.debugPrintStar(userGenres);
    }

    std::cout << "NOTE: All movies right now are just randomly generated test movies." << std::endl;


}