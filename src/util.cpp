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
Genre intToGenre(int i)
{
    switch(i)
    {
        case 1: return Genre::Action;
        case 2: return Genre::Adventure;
        case 3: return Genre::Animation;
        case 4: return Genre::Children_s;
        case 5: return Genre::Comedy;
        case 6: return Genre::Crime;
        case 7: return Genre::Documentary;
        case 8: return Genre::Drama;
        case 9: return Genre::Fantasy;
        case 10: return Genre::Film_Noir;
        case 11: return Genre::Horror;
        case 12: return Genre::Musical;
        case 13: return Genre::Mystery;
        case 14: return Genre::Romance;
        case 15: return Genre::Sci_Fi;
        case 16: return Genre::Thriller;
        case 17: return Genre::War;
        case 18: return Genre::Western;
        default: return Genre::None;
    }
}

Genre stringToGenre(std::string genre) {
    if (genre == "Action") return Genre::Action;
    if (genre == "Adventure") return Genre::Adventure;
    if (genre == "Animation") return Genre::Animation;
    if (genre == "Children's") return Genre::Children_s;
    if (genre == "Comedy") return Genre::Comedy;
    if (genre == "Crime") return Genre::Crime;
    if (genre == "Documentary") return Genre::Documentary;
    if (genre == "Drama") return Genre::Drama;
    if (genre == "Fantasy") return Genre::Fantasy;
    if (genre == "Film-Noir") return Genre::Film_Noir;
    if (genre == "Horror") return Genre::Horror;
    if (genre == "Musical") return Genre::Musical;
    if (genre == "Mystery") return Genre::Mystery;
    if (genre == "Romance") return Genre::Romance;
    if (genre == "Sci-Fi") return Genre::Sci_Fi;
    if (genre == "Thriller") return Genre::Thriller;
    if (genre == "War") return Genre::War;
    if (genre == "Western") return Genre::Western;
    return Genre::None;
}

bool debugFindGenre(Genre a, const std::unordered_set<Genre> &genreSet)
{
    for(auto i : genreSet)
    {
        if(a == i) return true;
    }
    return false;
}
