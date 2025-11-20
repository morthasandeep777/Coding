public class ExceptionHandlingExample2 {

    public static void main(String[] args) {
        try {
            // Code that might throw an exception
            int result = 10 / 0; 
        } catch (ArithmeticException e) {
            // Code to handle the exception
            System.out.println("An arithmetic exception occurred: " + e.getMessage());
        } finally {
            // Code that always executes, regardless of an exception
            System.out.println("This block always executes.");
        }
    }
}