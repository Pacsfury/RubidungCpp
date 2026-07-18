#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void clearScreen() {
    std::cout << "\033[2J\033[H" << std::flush;
}

class Level {
public:
    int levelNumber;
    const vector<vector<char>>& map;
    const vector<vector<char>>& getMap(int level) {
        switch(level) {
            case 1: {
                static const vector<vector<char>> map1 = {
                    {'#', '#', '#', '#', '#',' ',' '},
                    {'#', '.', '.', '.', '#',' ',' '},
                    {'#', '.', '.', '$', '#',' ',' '},
                    {'#', '#', '#', '.', '#',' ',' '},
                    {'#', '.', '.', '.', '#',' ',' '},
                    {'#', '.', '.', '.', '#',' ',' '},
                    {'#', '@', '#', '#', '#',' ',' '}
                };
                return map1;
            }

            case 2: {
                // Distinct layout from level 1 so progression is obvious.
                static const vector<vector<char>> map2 = {
                    {'#', '#', '#', '#', '#', '#', '#'},
                    {'#', '@', '.', '.', '.', '$', '#'},
                    {'#', '.', '#', '#', '#', '.', '#'},
                    {'#', '.', '.', '.', '#', '.', '#'},
                    {'#', '#', '#', '.', '.', '.', '#'},
                    {'#', '#', '#', '#', '#', '#', '#'}
                };
                return map2;
            }
        };
        static const vector<vector<char>> emptyMap;
        return emptyMap;
    }

    Level(int alevelNumber): levelNumber(alevelNumber), map(getMap(alevelNumber)) {}

};

class Player {

public:

    int x;
    int y;

    char getCurrentTile(const Level& level) {
        if (y < 0 || y >= (int)level.map.size() || x < 0 || x >= (int)level.map[0].size()) {
            return '#';
        }
        return level.map[y][x]; 
    }

    // Start beside the '@' marker for the given level map.
    explicit Player(const Level& level): x(1), y(1) {
        for (int i = 0; i < (int)level.map.size(); i++) {
            for (int j = 0; j < (int)level.map[i].size(); j++) {
                if (level.map[i][j] == '@') {
                    x = j;
                    y = i;
                    return;
                }
            }
        }
    }
};

bool playLevel(const Level& level) {
    bool win = false;
    Player player(level);

    cout << "Level " << level.levelNumber << endl;
    for (int i = 0; i < level.map.size(); i++) {
        for (int j = 0; j < level.map[i].size(); j++) {
            cout<<level.map[i][j] << " ";
        }

        cout<<endl;
    }

    for (int turn = 0; turn < 10; turn++) {
        string command;
        cin>>command;

        if (turn == 0) {
            clearScreen();
        }

        int oldX = player.x;
        int oldY = player.y;

        if (command == "w") {
            cout<<"Move up"<<endl;
            player.y -= 1;
        } else if (command == "a") {
            cout<<"Move left"<<endl;
            player.x -= 1;
        } else if (command == "s") {
            cout<<"Move down"<<endl;
            player.y += 1;
        } else if (command == "d") {
            cout<<"Move right"<<endl;
            player.x += 1;
        } else {
            cout<<"Invalid command"<<endl;
        }

        char currentTile = player.getCurrentTile(level);

        if (currentTile == '$') {
            cout<<"You won!"<<endl;
            win = true;
            break;
        } else if (currentTile == '#') {
            cout<<"You hit a spiky wall. Game over."<<endl;
            break;
        } else if (currentTile == 'O') {
            player.x = oldX;
            player.y = oldY;
        }
    
    }

    if (!win) {
        cout<<"Game over. Try again."<<endl;
    }

    return win;
}

int main() {
    const int TOTAL_LEVELS = 2;
    bool clearedAll = true;

    for (int level = 1; level <= TOTAL_LEVELS; level++) {
        Level actualLevel(level);
        if (!playLevel(actualLevel)) {
            clearedAll = false;
            break;
        }
    }

    clearScreen();

    if (clearedAll) {
        cout << "Congrats! You won!" << endl;
    }

    return 0;
}
