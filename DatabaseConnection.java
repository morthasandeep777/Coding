import java.sql.*;

public class DatabaseConnection {

    public static void main(String[] args) throws Exception {

        Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/student1", "root", "");
        if(con!=null){
            System.out.println("connection established");
        }
        
        else{
            System.out.println("connection failed");
        }
}
}