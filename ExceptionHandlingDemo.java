public class ExceptionHandlingDemo {
    public static void main(String[] args) {
        int[] numbers = {10, 20, 30};
        int divisor = 0;

        try {
            System.out.println("Accessing element: " + numbers[3]);

            int result = numbers[2] / divisor;
            System.out.println("Division result: " + result);

        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: Tried to access an invalid index in the array.");
        } catch (ArithmeticException e) {
            System.out.println("Error: Division by zero is not allowed.");
        } finally {
            System.out.println("Finally block executed. Cleanup if necessary.");
        }

        try {
            checkAge(15); 
        } catch (InvalidAgeException e) {
            System.out.println("Caught the exception: " + e.getMessage());
        }
    }

    public static void checkAge(int age) throws InvalidAgeException {
        if (age < 18) {
            throw new InvalidAgeException("Age is less than 18. Access denied.");
        } else {
            System.out.println("Access granted. Age is valid.");
        }
    }
}

class InvalidAgeException extends Exception {
    public InvalidAgeException(String message) {
        super(message);
    }
}
