#include "selection.h"

using namespace std;

Selection::Selection(const string& selectionName, const vector<Game>& games, const Platform& platform)
    : selectionName{ selectionName }, games{ games }, platform{ platform }
{
    if (selectionName.empty()) {
        throw runtime_error("Error!");
    }
}

bool Selection::isReady() const {
    for (size_t i = 0; i < games.size(); i++) {
        for (size_t j = 0; j < games.at(i).getPlatforms().size(); j++) {
            if (games.at(i).getPlatforms().at(j) != platform) {
                return false;
            }
        }
    }
    return true;
}

ostream& operator<<(ostream& os, const Selection& selection) {

    os << "[" << selection.selectionName << ", "
       << platformNames.at(static_cast<int>(selection.platform)) << ", {";

    for (size_t i = 0; i < selection.games.size(); i++) {
        os << selection.games.at(i);

        if (i != selection.games.size() - 1) {
            os << ", ";
        }
    }

    os << "}, ";

    if (selection.isReady()) os << "ready";
    else os << "not ready";

    return os << "]";
}