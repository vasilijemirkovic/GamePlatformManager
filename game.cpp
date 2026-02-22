#include "game.h"

using namespace std;

vector<string> platformNames{ "Nintendo", "Sony", "Microsoft", "PC" };

Game::Game(const string& name, const int& releaseYear, const int& score, const vector<Platform>& platforms)
    : name{ name }, releaseYear{ releaseYear }, score{ score }, supportedPlatforms{ platforms }
{
    if (name.empty() || platforms.empty() || releaseYear < 1981 || releaseYear > 2019 || score < 0 || score > 10) {
        throw runtime_error("Error!");
    }
}

vector<Platform> Game::getPlatforms() const {
    return supportedPlatforms;
}

bool Game::supportsPlatform(Platform p) const {
    for (size_t i = 0; i < supportedPlatforms.size(); i++) {
        if (p == supportedPlatforms.at(i)) return true;
    }
    return false;
}

int Game::addPlatforms(const vector<Platform>& morePlatforms) {

    int addedCount = 0;
    
    vector<Platform> toAdd;
    
    bool found = false;

    for (int i = 0; i < static_cast<int>(morePlatforms.size()); i++){

        found = false;

        for (int j = 0; j < static_cast<int>(supportedPlatforms.size()); j++) {
            if (morePlatforms.at(i) == supportedPlatforms.at(j)) found = true;
        }

        if (!found) {
            toAdd.push_back(morePlatforms.at(i));
            addedCount++;
        }
    }

    for (const auto& platform : toAdd){
        supportedPlatforms.push_back(platform);
    }

    return addedCount;
}

bool operator>(const Game& left, const Game& right) {
    return (left.score >= right.score && left.releaseYear > right.releaseYear);
}

vector<Game> Game::filterByPlatform(const vector<Game>& games, Platform p) {

    vector<Game> result;

    for (size_t i = 0; i < games.size(); i++) {
        if (games.at(i).supportsPlatform(p)){
            result.push_back(games.at(i));
        }
    }

    return result;
}

ostream& operator<<(ostream& os, const Game& game) {

    os << "[" << game.name << ", " << game.releaseYear << ", " << game.score << ", {";

    for (size_t i = 0; i < game.supportedPlatforms.size(); i++) {
        os << platformNames.at(static_cast<int>(game.supportedPlatforms.at(i)));

        if (i != game.supportedPlatforms.size() - 1){
            os << ", ";
        }
    }

    return os << "}]";
}