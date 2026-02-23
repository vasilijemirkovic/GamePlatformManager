#ifndef SELECTION_H
#define SELECTION_H

#include "game.h"

class Selection {
    
private:
    std::string selectionName;
    std::vector<Game> games;
    Platform platform;

    //Private methods for validating a correctness of the input values
    void validateGames() const;
    bool containsDuplicates() const;
    bool allGamesSupportPlatform() const;

public:
    Selection(const std::string& selectionName, const std::vector<Game>& games,
              const Platform& platform = Platform::Nintendo);

    bool isReady() const;

    friend std::ostream& operator<<(std::ostream& os, const Selection& selection);

    const std::vector<Game>& getGames() const noexcept;
    
    Platform getPlatform() const noexcept;

    const std::string& getName() const noexcept;

    std::vector<std::string> compare(const std::vector<Selection>& others) const;
    
    void rearrange();
};

#endif // SELECTION_H