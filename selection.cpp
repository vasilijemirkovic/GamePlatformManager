#include "selection.h"
#include <algorithm>
#include <stdexcept>

using namespace std;

Selection::Selection(const string& selectionName, const vector<Game>& games, const Platform& platform)
    : selectionName{ selectionName }, games{ games }, platform{ platform }
{
    if (selectionName.empty()) {
        throw std::runtime_error("Invalid selection name");
    }
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