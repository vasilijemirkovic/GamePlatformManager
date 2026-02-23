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
}

bool Selection::isReady() const {
    for (const auto& g : games)
        if (!g.supportsPlatform(platform))
            return false;

    return true;
}

vector<string> Selection::compare(const vector<Selection>& others) const
{
    if (others.empty())
        throw runtime_error("Nothing to compare");

    vector<string> result;

    for (const auto& other : others)
    {
        string line = selectionName + " vs " + other.selectionName + ": ";

        if (games.size() > other.games.size())
            line += "more games";
        else if (games.size() < other.games.size())
            line += "fewer games";
        else
            line += "same number of games";

        result.push_back(line);
    }

    return result;
}


void Selection::rearrange() {
    if (games.empty()) return;

    sort(games.begin(), games.end(),
        [](const Game& lhs, const Game& rhs)
        {
            if (lhs.getPlatforms().empty() || rhs.getPlatforms().empty())
                return lhs.getPlatforms().size() < rhs.getPlatforms().size();

            return lhs.getPlatforms().front() < rhs.getPlatforms().front();
        });
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