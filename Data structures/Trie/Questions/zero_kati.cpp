#include <iostream>
#include <vector>
using namespace std;
void grid(vector<vector<char>> v) {
    cout << "  " << v[0][0] << "  |  " << v[0][1] << "  |  " << v[0][2] << endl;
    cout << "-----------------" << endl;
    cout << "  " << v[1][0] << "  |  " << v[1][1] << "  |  " << v[1][2] << endl;
    cout << "-----------------" << endl;
    cout << "  " << v[2][0] << "  |  " << v[2][1] << "  |  " << v[2][2] << endl << endl;
}

bool checkWinner(vector<vector<char>> v, char c) {
    for(int i = 0; i < 3; i++) {
        if(v[i][0] == v[i][1] && v[i][1] == v[i][2] && v[i][0] == c) {
            return true;
        }
        if(v[0][i] == v[1][i] && v[1][i] == v[2][i] && v[0][i] == c) {
            return true;
        }
    }
    if(v[0][0] == v[1][1] && v[1][1] == v[2][2] && v[0][0] == c) {
        return true;
    }
    if(v[0][2] == v[1][1] && v[1][1] == v[2][0] && v[0][2] == c) {
        return true;
    }
    return false;
}

void tic_tac_toe() {
    vector<vector<char>> v(3, vector<char>(3, ' '));
    vector<char> ops(2);
    cout << "Opponent 1's symbol = ";
    cin >> ops[0];
    cout << "Opponent 2's symbol = ";
    cin >> ops[1];
    int size = 0;
    bool switcher = false;
    grid(v);
    while(size < 9) {
        int row, col;

        if(switcher == 0) 
            cout << "OPPONENT-1's position of input (x, y): ";
        else
            cout << "OPPONENT-2's position of input (x, y): ";

        cin >> row >> col;
        if(v[row - 1][col - 1] == ' ') {
            v[row - 1][col - 1] = ops[switcher];
            size++;
        }
        else {
            cout << "Place already filled, please try again." << endl;
            continue;
        }
        grid(v);
        if(checkWinner(v, ops[switcher])) {
            if(switcher == 0) {
                cout << "Opponent 1 wins!" << endl;
            }
            else {
                cout << "Opponent 2 wins!" << endl;
            }
            return;
        }
        switcher = !switcher;
    }
    cout << "Match Draws" << endl;
}
int main() {
    tic_tac_toe();
    return 0;
}