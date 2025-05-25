// 77. Combinations

import java.util.ArrayList;
import java.util.List;

class Solution {

    public List<List<Integer>> combine(final int n, final int k) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> currentCombination = new ArrayList<>();
        backtrack(1, n, k, currentCombination, result);
        return result;
    }

    private void backtrack(final int currentNumber, final int upperLimit, final int targetSize,
                           final List<Integer> currentCombination, final List<List<Integer>> result) {
        final int currentSize = currentCombination.size();
        if (currentSize == targetSize) {
            final List<Integer> validCombination = new ArrayList<>(currentCombination);
            result.add(validCombination);
            return;
        }

        int i = currentNumber;
        while (i <= upperLimit) {
            currentCombination.add(Integer.valueOf(i));
            backtrack(i + 1, upperLimit, targetSize, currentCombination, result);

            int lastIndex = currentCombination.size() - 1;
            currentCombination.remove(lastIndex);

            i = i + 1;
        }
    }

    public static void main(final String[] args) {
        Solution solution = new Solution();
        List<List<Integer>> combinations = solution.combine(4, 2);
        System.out.println(combinations);
    }
}
