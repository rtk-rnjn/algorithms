// 36. Valid Sudoku

import java.util.HashSet;

class Solution {

    public boolean isValidSudoku(final char[][] board) {
        for (int rowIndex = 0; rowIndex < 9; rowIndex = rowIndex + 1) {
            HashSet<Character> rowSet = new HashSet<>();
            HashSet<Character> columnSet = new HashSet<>();
            HashSet<Character> boxSet = new HashSet<>();

            for (int columnIndex = 0; columnIndex < 9; columnIndex = columnIndex + 1) {
                char rowValue = board[rowIndex][columnIndex];
                char columnValue = board[columnIndex][rowIndex];

                // Validate row
                if (rowValue != '.') {
                    if (rowSet.contains(rowValue)) {
                        return false;
                    } else {
                        rowSet.add(rowValue);
                    }
                }

                // Validate column
                if (columnValue != '.') {
                    if (columnSet.contains(columnValue)) {
                        return false;
                    } else {
                        columnSet.add(columnValue);
                    }
                }

                // Validate 3x3 box
                int boxRowStart = 3 * (rowIndex / 3);
                int boxColStart = 3 * (rowIndex % 3);
                int currentBoxRow = boxRowStart + (columnIndex / 3);
                int currentBoxCol = boxColStart + (columnIndex % 3);
                char boxValue = board[currentBoxRow][currentBoxCol];

                if (boxValue != '.') {
                    if (boxSet.contains(boxValue)) {
                        return false;
                    } else {
                        boxSet.add(boxValue);
                    }
                }
            }
        }
        return true;
    }

    public static void main(final String[] args) {
        Solution solution = new Solution();
        char[][] board = {
            { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
            { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
            { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
            { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
            { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
            { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
            { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
            { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
            { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
        };
        boolean isValid = solution.isValidSudoku(board);
        System.out.println(isValid); // true
    }
}
