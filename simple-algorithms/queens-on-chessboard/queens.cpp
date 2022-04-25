#include <iostream>
#include <vector>
#include <tuple>

using namespace std;


int diagonals1[2*10 - 2];  // lines of type y=x
int diagonals2[2*10 - 2];  // lines of type y=c-x, c from 0 to 2n-1
int horizontal[10];
vector<tuple<int,int>> queens;  // to store all queen positions


int FindQueenPositions(int &n, int row, int column, int &counter, bool &back) {
    if (queens.size() == 0 && row == n-1) return counter;
    int j = (back)? column: column+1;
    for (int i = (back)? row+1: 0; i < n; i++) {  // need to go from first row
        if (horizontal[i] == 0 && diagonals1[i+j] == 0 && diagonals2[(n-1) - i + j] == 0) {
            if (j == n-1) {  // if the field is full and all queens are placed
                counter++;
                // when the field is filled, we need to step back and eliminate the previous queen's effect
                back = true;
                tuple<int, int> last_position = queens.back();  // get coordinates of the last queen placed
                int last_row = get<0>(last_position), last_column = get<1>(last_position);
                horizontal[last_row] = 0;
                diagonals1[last_row+last_column] = 0;
                diagonals2[(n-1) - last_row + last_column] = 0;
                queens.pop_back();
                return FindQueenPositions(n, last_row, last_column, counter, back);
            }
            horizontal[i] = 1;
            diagonals1[i+j] = 1;
            diagonals2[(n-1) - i + j] = 1;
            back = false;  // new queen means going forward -> back = false;
            queens.emplace_back(tuple<int,int> {i,j});
            return FindQueenPositions(n, i, j, counter, back);
            // when queen is placed,
            // we turn correspondent arrays' elements to ones and make recursive call with columns+1
        }
    // when the column could not be filled, we need to step back and eliminate the previous queen's effect
    back = true;
    tuple<int, int> last_position = queens.back();  // get coordinates of the last queen placed
    int last_row = get<0>(last_position), last_column = get<1>(last_position);
    horizontal[last_row] = 0;
    diagonals1[last_row+last_column] = 0;
    diagonals2[(n-1) - last_row + last_column] = 0;
    queens.pop_back();
    return FindQueenPositions(n, last_row, last_column, counter, back);
    }
    return counter;
}


int main() {
    int n;
    cin >> n;
    int row = 0, column = -1, counter = 0;
    bool back = false;  // to indicate that we search from 0 or from i+1 (going forward or stepping back)
    for (int i = 0; i < 10; i++) {
        horizontal[i] = 0;
    }
    for (int i = 0; i < 2*10 - 2;i++) {
        diagonals1[i] = 0;
        diagonals2[i] = 0;
    }
    if (n == 0) {
        cout << 0;
    }
    else if (n == 1) {
        cout << 1;
    }
    else {
        cout << FindQueenPositions(n, row, column, counter, back);
    }
    return 0;
}