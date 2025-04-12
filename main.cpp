#include "include/movie.hpp"
#include "include/algorithms.hpp"
#include "include/movieDatabase.hpp"
#include "include/dataParser.hpp"
#include <iostream>
#include <random>
#include <ctime>
#include <string>



int main(){

    srand(time(NULL));
    int userinput = 0;

    std::vector<Movie> movieCentralStorage;
    movieCentralStorage.reserve(10000);

    std::string filename = "assets\\ml-latest-small\\movies.csv";
    MovieStorage storage = readMoviesFromCSV(filename, movieCentralStorage);

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

    std::cout << "Here's what we recommend you to watch!\n";

    if(recMovies.size() != 0){

        for(auto i : recMovies)
        {
            i.printInfo();
        }
        std::cout << "Recommended Movies: " << recMovies.size() << "/" << "9743\n";
    }
    else{
        std::cout << "No movies found for those genres!" << std::endl;
    }

}
