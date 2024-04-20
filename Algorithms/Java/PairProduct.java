import java.util.HashMap;

class PairProduct {
    public static void main(final String[] args) {
        int[] arr = { 1, 2, 3, 4, 5 };
        int x = 10;
        int[] result = pairProduct(arr, x);
        if (result[0] == -1 && result[1] == -1) {
            System.out.println("No pair found");
        } else {
            System.out.println("Pair found at index " + result[0] + " and " + result[1]);
        }
    }

    static int[] pairProduct(final int[] arr, final int target) {
        final HashMap<Integer, Integer> map = new HashMap<>();
        final int[] result = { -1, -1 };

        for (int i = 0; i < arr.length; i++) {
            if (map.containsKey(target / arr[i])) {
                result[0] = map.get(target / arr[i]);
                result[1] = i;
                return result;
            }
            map.put(arr[i], i);
        }
        return result;
    }
}
