#ifndef SELECTION_H
#define SELECTION_H

#include "game.h"

class Selection {
    
private:
    std::string selectionName;
    std::vector<Game> games;
    Platform platform;

public:
    Selection(const std::string& selectionName, const std::vector<Game>& games,
              const Platform& platform = Platform::Nintendo);

    bool isReady() const;

    friend std::ostream& operator<<(std::ostream& os, const Selection& selection);

    const std::vector<Game>& getGames() const noexcept;
    
    Platform getPlatform() const noexcept;

    const std::string& getName() const noexcept;
};

#endif // SELECTION_H