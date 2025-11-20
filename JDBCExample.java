import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.SQLException;

public class JDBCExample {
    public static void main(String[] args) {
        // Database URL, username, and password
        String jdbcUrl = "jdbc:mysql://localhost:3306/testdb"; // Adjust the port and database name if necessary
        String username = "root"; // Replace with your MySQL username
        String password = "password"; // Replace with your MySQL password

        Connection connection = null;
        Statement statement = null;
        ResultSet resultSet = null;

        try {
            // Step 1: Load the JDBC driver (optional for newer Java versions)
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Step 2: Establish the connection
            connection = DriverManager.getConnection(jdbcUrl, username, password);
            System.out.println("Connected to the database!");

            // Step 3: Create a statement
            statement = connection.createStatement();

            // Step 4: Execute a query
            String query = "SELECT * FROM users";
            resultSet = statement.executeQuery(query);

            // Step 5: Process the result set
            System.out.println("ID\tName\t\tEmail");
            System.out.println("--------------------------------");
            while (resultSet.next()) {
                int id = resultSet.getInt("id");
                String name = resultSet.getString("name");
                String email = resultSet.getString("email");
                System.out.println(id + "\t" + name + "\t" + email);
            }

        } catch (ClassNotFoundException e) {
            System.out.println("MySQL JDBC Driver not found.");
            e.printStackTrace();
        } catch (SQLException e) {
            System.out.println("Connection failed.");
            e.printStackTrace();
        } finally {
            // Step 6: Clean up and close resources
            try {
                if (resultSet != null) resultSet.close();
                if (statement != null) statement.close();
                if (connection != null) connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}
