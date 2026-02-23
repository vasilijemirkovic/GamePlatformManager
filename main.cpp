#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "game.h"
#include "selection.h"

using namespace std;

int main() {

    // Test Game constructor
    cout << "Test Game\nConstructor\n";

    try {
        cout << Game{"Sims 12", 2020, 0, {Platform::Nintendo}} << '\n';
    } catch (runtime_error&) {
        cout << "Error1\n";
    }

    try {
        cout << Game{"Sims 0", 1, 1980, {Platform::Nintendo}} << '\n';
    } catch (runtime_error&) {
        cout << "Error2\n";
    }

    try {
        cout << Game{"Sims 1", 2, 1981, {Platform::Microsoft}} << '\n';
    } catch (runtime_error&) {
        cout << "Error3\n";
    }

    try {
        cout << Game{"Sims 5", 3, 2019, {Platform::Sony, Platform::PC}} << '\n';
    } catch (runtime_error&) {
        cout << "Error4\n";
    }

    try {
        cout << Game{"", 2019, 4, {Platform::Nintendo}} << '\n';
    } catch (runtime_error&) {
        cout << "Error5\n";
    }

    try {
        cout << Game{"Sims", 2019, 5, {}} << '\n';
    } catch (runtime_error&) {
        cout << "Error6\n";
    }

    try {
        cout << Game{"Sims", 2019, -1, {Platform::Nintendo}} << '\n';
    } catch (runtime_error&) {
        cout << "Error7\n";
    }

    try {
        cout << Game{"Sims", 2019, 0, {Platform::Nintendo}} << '\n';
    } catch (runtime_error&) {
        cout << "Error8\n";
    }

    try {
        cout << Game{"Sims", 2019, 10, {Platform::Nintendo}} << '\n';
    } catch (runtime_error&) {
        cout << "Error9\n";
    }

    try {
        cout << Game{"Sims", 2019, 11, {Platform::Nintendo}} << '\n';
    } catch (runtime_error&) {
        cout << "Error10\n";
    }

    const Game aa{"Ace Attorney", 1999, 7, {Platform::Nintendo}};
    const Game pok{"Pokemon", 1996, 6, {Platform::Nintendo}};
    const Game rl{"Rocket League", 2014, 9, {Platform::Nintendo, Platform::Sony, Platform::Microsoft, Platform::PC}};
    const Game gw{"God of War", 2010, 8, {Platform::Sony, Platform::Microsoft}};
    const Game dota{"DotA 2", 2011, 10, {Platform::PC}};
    const Game lp{"Little Big Planet", 2009, 10, {Platform::Sony}};
    const Game fifa{"Fifa 19", 2018, 5, {Platform::Nintendo, Platform::Microsoft, Platform::PC, Platform::Sony}};
    const Game uc{"Uncharted", 2008, 6, {Platform::Sony}};
    const Game halo{"Halo", 2007, 6, {Platform::Microsoft, Platform::PC}};
    const Game gwar{"Gears of War", 2007, 6, {Platform::Microsoft}};
    const Game diablo{"Diablo3", 2016, 8, {Platform::Nintendo, Platform::Microsoft, Platform::PC, Platform::Sony}};
    const Game ff{"Final Fantasy", 1985, 5, {Platform::Nintendo, Platform::Sony}};
    const Game mk{"Mario Kart", 1987, 7, {Platform::Nintendo, Platform::Nintendo}};
    const Game spyro{"Spyro", 1991, 7, {Platform::Microsoft, Platform::Sony}};
    const Game tomb{"Tomb Raider", 2006, 7, {Platform::PC, Platform::Microsoft, Platform::Sony}};
    const Game fout{"Fallout", 2000, 9, {Platform::Sony, Platform::PC}};

    // Test supportsPlatform
    cout << "\nTest supportsPlatform\n";

    cout << fifa.supportsPlatform(Platform::PC);
    cout << fifa.supportsPlatform(Platform::Sony);
    cout << fifa.supportsPlatform(Platform::Nintendo);
    cout << fifa.supportsPlatform(Platform::Microsoft);
    cout << '\n';

    cout << aa.supportsPlatform(Platform::PC);
    cout << aa.supportsPlatform(Platform::Sony);
    cout << aa.supportsPlatform(Platform::Nintendo);
    cout << aa.supportsPlatform(Platform::Microsoft);
    cout << '\n';

    // Test addPlatforms
    cout << "\nTest addPlatforms\n";
    vector<Platform> allPlatforms{Platform::Nintendo, Platform::Sony, Platform::Microsoft, Platform::PC};

    Game cp{uc};
    cout << cp.addPlatforms({}) << ' ';
    for (const auto& p : allPlatforms) cout << cp.supportsPlatform(p);
    cout << '\n';

    cout << cp.addPlatforms({Platform::Sony, Platform::PC, Platform::Microsoft, Platform::PC, Platform::Sony}) << ' ';
    for (const auto& p : allPlatforms) cout << cp.supportsPlatform(p);
    cout << '\n';

    cout << cp.addPlatforms({Platform::PC, Platform::Microsoft, Platform::Nintendo, Platform::Sony}) << ' ';
    for (const auto& p : allPlatforms) cout << cp.supportsPlatform(p);
    cout << '\n';

    cout << cp.addPlatforms({Platform::PC, Platform::Microsoft, Platform::Nintendo, Platform::Sony}) << ' ';
    for (const auto& p : allPlatforms) cout << cp.supportsPlatform(p);
    cout << '\n';

    // Test operator>
    cout << "\noperator>\n";

    cout << (halo > gwar) << (gwar > halo) << " ";
    cout << (aa > pok) << (pok > aa) << " ";
    cout << (halo > uc) << (uc > halo) << " ";
    cout << (dota > fifa) << (fifa > dota) << " ";
    cout << '\n';

    // Test filterByPlatform
    cout << "\nTest filter\n";

    cout << "Nintendo:\n";
    for (const auto& x : Game::filterByPlatform({aa,pok,rl,gw,dota,lp,fifa,uc,halo,gwar,diablo,ff,mk,spyro,tomb,fout}, Platform::Nintendo))
        cout << x << '\n';

    cout << "Sony:\n";
    for (const auto& x : Game::filterByPlatform({aa,pok,rl,gw,dota,lp,fifa,uc,halo,gwar,diablo,ff,mk,spyro,tomb,fout}, Platform::Sony))
        cout << x << '\n';

    cout << "Microsoft:\n";
    for (const auto& x : Game::filterByPlatform({halo,gwar,diablo,ff,mk,spyro,tomb,fout,aa,pok,rl,gw,dota,lp,fifa,uc}, Platform::Microsoft))
        cout << x << '\n';

    cout << "PC:\n";
    for (const auto& x : Game::filterByPlatform({aa,pok,rl,gw,dota,lp,fifa,uc,halo,pok,rl,gw,dota,gwar,diablo,ff,mk,spyro,tomb,fout}, Platform::PC))
        cout << x << '\n';

    // Test Selection
    cout << "\nSelection\nConstructor\n";

    const vector<Game> games{aa,pok,rl,gw,dota,lp,fifa,uc,halo,gwar,diablo,ff,mk,spyro,tomb,fout,aa};

    try {
        cout << Selection{"A", {}} << '\n';
    } catch (runtime_error&) {
        cout << "Error11\n";
    }

    try {
        cout << Selection{"", games} << '\n';
    } catch (runtime_error&) {
        cout << "Error12\n";
    }

    Selection nin{"N64", Game::filterByPlatform(games, Platform::Nintendo)};
    Selection son{"Sony", Game::filterByPlatform(games, Platform::Sony), Platform::Sony};
    Selection mic{"Xbox", Game::filterByPlatform(games, Platform::Microsoft), Platform::Microsoft};
    Selection ppc{"Gaming PC", Game::filterByPlatform(games, Platform::PC), Platform::PC};
    Selection mixed{"Mixed", games, Platform::Nintendo};
    const Selection cs{mic};

    // Test isReady
    cout << "\nTest isReady\n";
    Selection empty{"empty", {}};

    cout << nin.isReady()
         << son.isReady()
         << mic.isReady()
         << ppc.isReady()
         << mixed.isReady()
         << empty.isReady() << '\n';

    cout << nin << '\n';
    cout << son << '\n';
    cout << mic << '\n';
    cout << ppc << '\n';
    cout << empty << '\n';
    cout << mixed << '\n';
    cout << cs << '\n';


    cout << "\nTest compare\n";
    try {
        cout << "one\n";
        for (const auto& r : son.compare({nin,son,mic,empty,ppc,mixed}))
            cout << r << '\n';
        
        cout << "two\n";
        for (const auto& r : cs.compare({ nin,son,mic,empty,ppc,mixed }))
            cout << r << '\n';
            
        cout << "three\n";
        for (const auto& r : ppc.compare({ nin,son,mic,empty,ppc,mixed }))
            cout << r << '\n';
        
        cout << "four\n";
        for (const auto& r : empty.compare({nin,son,mic,empty,ppc,mixed}))
            cout << r << '\n';
        
        }catch (runtime_error& e) { 
            cout << "Error13\n";
        }
        
        cout << "\nTest rearrange\n";
        cout << "Original:\n" << mixed << '\n';
        mixed.rearrange();
        
        cout << "Gruppiert:\n" << mixed << '\n';
        cout << "Original:\n" << mic << '\n';
        
        mic.rearrange();
        
        cout << "Gruppiert:\n" << mic << '\n';
        empty.rearrange();
        
        cout << "Gruppiert:\n" << empty << '\n';

    return 0;
}