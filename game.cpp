#include "game.h"
#include <algorithm>
#include <stdexcept>
#include <fstream>
#include <sstream>

Platform stringToPlatform(const std::string& s);

using namespace std;

const vector<string> platformNames{ "Nintendo", "Sony", "Microsoft", "PC" };

Game::Game(const string& name, const int& releaseYear, const int& score, const vector<Platform>& platforms)
    : name{ name }, releaseYear{ releaseYear }, score{ score }, supportedPlatforms{ platforms }
{
    if (name.empty() || platforms.empty() || releaseYear < 1981 || releaseYear > 2026 || score < 0 || score > 10) {
        throw std::runtime_error("Invalid game data");
    }
}

const vector<Platform>& Game::getPlatforms() const noexcept {
    return supportedPlatforms;
}

bool Game::supportsPlatform(Platform p) const {
    return find(supportedPlatforms.begin(), supportedPlatforms.end(), p) != supportedPlatforms.end();
}

int Game::addPlatforms(const vector<Platform>& newPlatforms) {

    int added = 0;

    for(Platform p : newPlatforms){
        if(!supportsPlatform(p)){
            supportedPlatforms.push_back(p);
            added++;
        }
    }
    return added;
}

const std::string &Game::getName() const noexcept {
    return name;
}

bool operator>(const Game& lhs, const Game& rhs) {
    return (lhs.score >= rhs.score && lhs.releaseYear > rhs.releaseYear);
}

vector<Game> Game::filterByPlatform(const vector<Game>& games, Platform p) {

    vector<Game> result;

    for (const auto& g : games) {
        if (g.supportsPlatform(p)){
            result.push_back(g);
        }
    }
    return result;
}

ostream& operator<<(ostream& os, const Game& game) {

    os << "[" << game.name << ", " << game.releaseYear << ", " << game.score << ", {";

    for (size_t i = 0; i < game.supportedPlatforms.size(); i++) {
        os << platformNames.at(static_cast<int>(game.supportedPlatforms[i]));

        if (i + 1 < game.supportedPlatforms.size()){
            os << ", ";
        }
    }

    return os << "}]";
}


void Game::saveToFile(const std::vector<Game>& games, const std::string& filename) {

    ofstream file(filename);

    if (!file)
        throw runtime_error("Cannot open file for writing");

    for (const auto& g : games) {
        file << g.name << ";" << g.releaseYear << ";" << g.score << ";";

        for (size_t i = 0; i < g.getPlatforms().size(); ++i) {
            file << platformNames.at(static_cast<int>(g.getPlatforms()[i]));
            if (i + 1 < g.getPlatforms().size())
                file << ",";
        }

        file << "\n";
    }
}

vector<Game> Game::loadFromFile(const string& filename) {
    
    ifstream file(filename);

    if (!file)
        throw runtime_error("Cannot open file for reading");

    vector<Game> games;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);

        string name, yearStr, scoreStr, platformsStr;

        getline(ss, name, ';');
        getline(ss, yearStr, ';');
        getline(ss, scoreStr, ';');
        getline(ss, platformsStr, ';');

        int year = stoi(yearStr);
        int score = stoi(scoreStr);

        vector<Platform> platforms;
        stringstream ps(platformsStr);
        string p;

        while (getline(ps, p, ',')) {
            platforms.push_back(stringToPlatform(p));
        }

        games.emplace_back(name, year, score, platforms);
    }

    return games;
}

Platform stringToPlatform(const std::string& s) {
    for (size_t i = 0; i < platformNames.size(); ++i) {
        if (platformNames[i] == s)
            return static_cast<Platform>(i);
    }
    throw std::runtime_error("Unknown platform: " + s);
}