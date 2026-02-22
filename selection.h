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

    friend std::ostream& operator<<(std::ostream&, const Selection&);
};

#endif // SELECTION_H