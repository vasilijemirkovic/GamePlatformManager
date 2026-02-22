#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

enum class Platform { Nintendo, Sony, Microsoft, PC };
extern std::vector<std::string> platformNames;

class Game {
    
private:
    std::string name;
    int releaseYear;
    int score;
    std::vector<Platform> supportedPlatforms;

public:
    Game(const std::string& name, const int& releaseYear, const int& score, const std::vector<Platform>& platforms);

    bool supportsPlatform(Platform p) const;
    int addPlatforms(const std::vector<Platform>& morePlatforms);

    friend bool operator>(const Game&, const Game&);

    static std::vector<Game> filterByPlatform(const std::vector<Game>& games, Platform p);

    friend std::ostream& operator<<(std::ostream&, const Game&);

    std::vector<Platform> getPlatforms() const;
};

#endif // GAME_H