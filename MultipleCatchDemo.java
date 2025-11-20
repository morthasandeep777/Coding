public class MultipleCatchDemo {
    public static void main(String[] args) {
        try {
            int[] numbers = {10, 20, 30};

            int result = numbers[1] / 0; 
            System.out.println("Result: " + result);

            System.out.println("Accessing element: " + numbers[5]);

        } catch (ArithmeticException e) {
            System.out.println("Error: Division by zero is not allowed.");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: Tried to access an invalid index in the array.");
        } catch (Exception e) {
            System.out.println("Error: An unexpected exception occurred.");
        }

        System.out.println("Program continues after exception handling.");
    }
}
