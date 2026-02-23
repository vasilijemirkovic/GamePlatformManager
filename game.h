#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

enum class Platform { Nintendo, Sony, Microsoft, PC };
extern const std::vector<std::string> platformNames;

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

    const std::vector<Platform>& getPlatforms() const noexcept;

    static std::vector<Game> filterByPlatform(const std::vector<Game>& games, Platform p);

    friend bool operator>(const Game& lhs, const Game& rhs);

    friend std::ostream& operator<<(std::ostream& os, const Game& game);

};

#endif // GAME_H