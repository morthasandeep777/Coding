import java.util.Arrays;

public class ArraysExample {
    public static void main(String[] args) {
        int[] numbers = {3, 5, 1, 4};
        Arrays.sort(numbers); // Sorts array
        System.out.println(Arrays.toString(numbers)); // [1, 3, 4, 5]
        int index = Arrays.binarySearch(numbers, 4); // Finds index of 4
        System.out.println("Index of 4: " + index); // Output: Index of 4: 2
    }
}
