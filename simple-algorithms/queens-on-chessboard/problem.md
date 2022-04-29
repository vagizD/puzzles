### The problem

The task is the popular one - to find all the possible positions for N queens to be placed on NxN chessboard and not touching each other (for simplicity, N $\leq$ 10 is given).

### Algorithm

The approach is to represent a chessboard as NxN array and iterate over columns. Calling the recursive function, we can on each step go further if we can place a queen or step back if we cannot.

We need to store already filled diagonals and horizontal lines.
Algorithm starts from [0][0] and iteratively tries to put the next queen on the next column (on field[0][j+1]).
If all diagonals and rows are already filled, then it goes step back and puts the queen on field[i+1][j].

FindQueenPositions(n, row, column, &counter, &sum_of_verticals, back)

        * n - size of field
        * row - the row on which the last queen was placed on (if it was called after queen placement)
        * column - the column on which the last queen was placed on
        * counter - current number of found positions
        * back - boolean to indicate whether we go forward (need to find a place on new column, since iterate from first
              row) or moving back (we were on this column already and need to search for places from row where the last
              queen was placed +1
