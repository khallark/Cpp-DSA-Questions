#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void shortest_distance(vector<vector<int>>&cost) {
	for(int i = 0; i < cost.size(); i++) {
        for(int j = 0; j < cost.size(); j++) {
            cost[i][j] = cost[i][j] == -1 ? 1e9 : cost[i][j];
        }
    }

    for(int via = 0; via < cost.size(); via++) {
        for(int i = 0; i < cost.size(); i++) {
            for(int j = 0; j < cost.size(); j++) {
                if(i != via && j != via) {
                    cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
                }
            }
        }
    }

    for(int i = 0; i < cost.size(); i++) {
        if(cost[i][i] < 0) {
            cout << "Negative Cycle Detected" << endl;
        }
    }
}
	int main() {
    vector<vector<int>> cost = {
        { 0,  2, -1, -1},
        { 1,  0,  3, -1},
        {-1, -1,  0, -1},
        { 3,  5,  4,  0}
    };
    shortest_distance(cost);

    cout << "      ";
    for(int i = 0; i < cost.size(); i++) {
        cout << i << "   ";
    }
    cout << endl << "    ";
    for(int i = 0; i < cost.size(); i++) {
        cout << "----";
    }
    cout << endl;
    for(int i = 0; i < cost.size(); i++) {
        cout << i << "  | ";
        for(int j = 0; j < cost.size(); j++) {
            cost[i][j] = cost[i][j] > 10000 ? -1 :cost[i][j];
            if(cost[i][j] >= 0) cout << " " << cost[i][j] << "  ";
            else cout << cost[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}