#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
using namespace std;

class Players {
private:

    vector<string> playerNames;
    vector<vector<string>> teams;

public:

    // Function to get the number of players and their names
    void setupPlayers() {
        int numPlayers;

        // Prompt for the number of players
        cout << "Enter the number of players: ";
        cin >> numPlayers;

        // Get player names
        for (int i = 0; i < numPlayers; ++i) {
            string name;
            cout << "Enter the name for player " << (i + 1) << ": ";
            cin >> name;
            playerNames.push_back(name);
        }

        // Group into teams if there are more than 6 players
        if (numPlayers > 6) {
            createTeams(numPlayers);
        }
    }

    // Function to create teams
    void createTeams(int numPlayers) {
        int numTeams = min(6, numPlayers);  // No more than 6 teams
        int baseTeamSize = numPlayers / numTeams;
        int extraPlayers = numPlayers % numTeams;

        // Initialize teams with the base team size
        teams.resize(numTeams);

        // Distribute players evenly across teams
        int playerIndex = 0;
        for (int i = 0; i < numTeams; ++i) {
            for (int j = 0; j < baseTeamSize; ++j) {
                teams[i].push_back(playerNames[playerIndex++]);
            }
        }

        // Randomly assign extra players to teams
        srand(time(0));
        for (int i = 0; i < extraPlayers; ++i) {
            int randomTeam = rand() % numTeams;
            teams[randomTeam].push_back(playerNames[playerIndex++]);
        }
    }

    // Function to display player names or teams
    void displayPlayers() const {
        if (playerNames.size() <= 6) {
            cout << "\nPlayers in the game:\n";
            for (const string& name : playerNames) {
                cout << name << endl;
                
            }
        }
        else {
            cout << "\nTeams in the game:\n";
            for (size_t i = 0; i < teams.size(); ++i) {
                cout << "Team " << (i + 1) << ": ";
                for (const string& name : teams[i]) {
                    cout << name << " ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    Players players;

    // Setup and display players or teams
    players.setupPlayers();
    players.displayPlayers();

    return 0;
}

