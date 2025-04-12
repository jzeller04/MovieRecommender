#include "dataParser.hpp"


// Function to split a string by a delimiter
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to read movies from CSV
MovieStorage readMoviesFromCSV(const std::string& filename, std::vector<Movie> &centralDB) {
    MovieStorage movieDB;
    
    std::ifstream file(filename);
    std::string line;
    
    // Skip header line
    std::getline(file, line);

    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return movieDB;
    }
    int i = 0;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string movieId, title, genreStr;
        
        std::getline(ss, movieId, ',');
        std::getline(ss, title, ',');
        std::getline(ss, genreStr, ',');

        // Parse genres
        std::vector<std::string> genreStrings = split(genreStr, '|');
        std::unordered_set<Genre> movieGenres;
        
        for (const auto& genreStr : genreStrings) {
            Genre genre = stringToGenre(genreStr);
            if (genre != Genre::None) {
                movieGenres.insert(genre);
            }
        }

        // Create new movie object and store it
        Movie newMovie(std::stoi(movieId), title, movieGenres);
        centralDB.emplace_back(newMovie);
        movieDB.store(&centralDB[i]);
        i++;
    }

    file.close();
    return movieDB;
}

/*int main() {
    std::string filename = "assets\\ml-latest-small\\movies.csv";
    auto movieDB = readMoviesFromCSV(filename);

    // Print movies by genre
    for (int i = 0; i < static_cast<int>(Genre::None); ++i) {
        Genre genre = static_cast<Genre>(i);
        const auto& movies = movieDB.getSet(genre);

        std::cout << "Genre: " << genreToString(genre) << " (" << movies.size() << " movies)" << std::endl;
        for (const auto& movie : movies) {
            std::cout << "  ID: " << movie->getID() << ", Title: " << movie->getTitle() << ", Genres: ";
            for (const auto& movieGenre : movie->getGenres()) {
                std::cout << genreToString(movieGenre) << ", ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}*/