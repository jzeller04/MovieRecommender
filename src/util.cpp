#include "util.hpp"


std::string genreToString(Genre genre)
{
    switch(genre)
    {
        case Genre::Action: return "Action";
        case Genre::Adventure: return "Adventure";
        case Genre::Animation: return "Animation";
        case Genre::Children_s: return "Children's";
        case Genre::Comedy: return "Comedy";
        case Genre::Crime: return "Crime";
        case Genre::Documentary: return "Documentary";
        case Genre::Drama: return "Drama";
        case Genre::Fantasy: return "Fantasy";
        case Genre::Film_Noir: return "Film-Noir";
        case Genre::Horror: return "Horror";
        case Genre::Musical: return "Musical";
        case Genre::Mystery: return "Mystery";
        case Genre::Romance: return "Romance";
        case Genre::Sci_Fi: return "Sci-Fi";
        case Genre::Thriller: return "Thriller";
        case Genre::War: return "War";
        case Genre::Western: return "Western";
        case Genre::None: return "None";
        default: return "Unknown";
    }
}

