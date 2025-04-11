#include "include/movie.hpp"
#include "algorithms.hpp"
#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include "movieDatabase.hpp"


int main(){

    srand(time(NULL));
    int userinput = 0;

    // generating random test dataset (basically a test file) of 1000 movies

    Movie dataSet[1000];
    for(int i = 0; i < 1000; i++)
    {
        std::unordered_set<Genre> copyGenres;
        for(int j = 0; j < 5; j++)
        {
            int random = rand() % 17 + 1;
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

    std::unordered_set<Genre> userGenres; //store user preferences
    
    //main menu to prompt users for input
    while(userinput != -1){
        std::cout << "Enter your movie preferences!(-1 to quit):" << std::endl;
        std::cout << "1:Action\n2:Adventure\n3:Animation\n4:Childrens'\n5:Comedy\n6:Crime\n7:Documentary\n8:Drama\n9:Fantasy\n10:Film Noir\n11:Horror\n12:Musical\n13:Mystery\n14:Romance\n15:Sci-Fi\n16:Thriller\n17:War\n18:Western\n";
        std::cout << "Input: ";
        std::cin >> userinput;
        if(userinput > 0 && userinput < 19)
            userGenres.insert(intToGenre(userinput));
        std::cout << "Entered: " << genreToString(intToGenre(userinput)) << "\n" << std::endl;
    }
    std::cout << "\n\n";

    std::cout << "User prefs: \n"; // display user prefs
    for(Genre i : userGenres)
    {
        std::cout << genreToString(i) << std::endl;
    }

    std::cout << "\n\n";
    std::set<Movie> recMovies;
    recMovies = recommendMovie(storage, userGenres);

    if(recMovies.size() != 0){

        for(auto i : recMovies)
        {
            i.debugPrintStar(userGenres);
        }
        std::cout << "Recommended Movies: " << recMovies.size() << "/" << "1000\n";
    }
    else{
        std::cout << "No movies found for those genres!" << std::endl;
    }

    std::cout << "NOTE: All movies right now are just randomly generated test movies." << std::endl;

}
