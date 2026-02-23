#include "selection.h"
#include <algorithm>
#include <stdexcept>

using namespace std;

Selection::Selection(const string& selectionName, const vector<Game>& games, const Platform& platform)
    : selectionName{ selectionName }, games{ games }, platform{ platform }
{
    validateGames();
}

const std::vector<Game>& Selection::getGames() const noexcept {
    return games;
}

Platform Selection::getPlatform() const noexcept {
    return platform;
}

const std::string& Selection::getName() const noexcept {
    return selectionName;
}


bool Selection::containsDuplicates() const {
    for (size_t i = 0; i < games.size(); ++i) {
        for (size_t j = i + 1; j < games.size(); ++j) {
            if (games[i].getName() == games[j].getName())
                return true;
        }
    }
    return false;
}

bool Selection::allGamesSupportPlatform() const {
    for (const auto& g : games) {
        if (!g.supportsPlatform(platform)) return false;
    }
    return true;
}

void Selection::validateGames() const {

    if (selectionName.empty()) throw std::runtime_error("Invalid selection name");

    if (containsDuplicates()) throw std::runtime_error("Duplicate games in selection");

    if (!allGamesSupportPlatform()) throw std::runtime_error("Game does not support selection platform");
}

bool Selection::isReady() const {
   return std::all_of(games.begin(), games.end(),
        [this](const Game& g)
        {
            const auto& platforms = g.getPlatforms();

            return std::all_of(platforms.begin(), platforms.end(),
                [this](Platform p)
                {
                    return p == platform;
                });
        }
    );
}

ostream& operator<<(ostream& os, const Selection& selection) {

    os << "[" << selection.selectionName << ", "
       << platformNames.at(static_cast<int>(selection.platform)) << ", {";

    for (size_t i = 0; i < selection.games.size(); i++) {
        os << selection.games[i];

        if (i + 1 < selection.games.size()) {
            os << ", ";
        }
    }

    return os << "}, " << (selection.isReady() ? "ready" : "not ready") << "]";
}