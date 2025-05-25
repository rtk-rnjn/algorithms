// 6. Zigzag Conversion

class Solution {
    public String convert(final String s, final int numRows) {
        if (numRows == 1) {
            return s;
        }

        int totalRows = Math.min(numRows, s.length());
        StringBuilder[] rows = new StringBuilder[totalRows];
        for (int index = 0; index < totalRows; index = index + 1) {
            rows[index] = new StringBuilder();
        }

        int currentRow = 0;
        boolean movingDown = false;

        char[] characters = s.toCharArray();
        for (int index = 0; index < characters.length; index = index + 1) {
            char currentChar = characters[index];
            rows[currentRow].append(currentChar);

            if (currentRow == 0 || currentRow == numRows - 1) {
                movingDown = !movingDown;
            }

            if (movingDown) {
                currentRow = currentRow + 1;
            } else {
                currentRow = currentRow - 1;
            }
        }

        StringBuilder finalResult = new StringBuilder();
        for (int index = 0; index < totalRows; index = index + 1) {
            finalResult.append(rows[index]);
        }

        return finalResult.toString();
    }

    public static void main(final String[] args) {
        Solution solution = new Solution();
        String output = solution.convert("PAYPALISHIRING", 3);
        System.out.println(output); // Output: PAHNAPLSIIGYIR
    }
}
