import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class demo {
   // root@127.0.0.1:3306
    public static void main(String[] args) {
        String url = "jdbc:mysql://127.0.0.1:3306/?user=root";
        String username = "root";
        String password = "8660";

        try {
            // Load the MySQL JDBC driver
            Class.forName("com.mysql.jdbc.Driver");

            // Connect to the MySQL database
            Connection connection = DriverManager.getConnection(url, username, password);
            System.out.println("Connected to MySQL database!");

            // Your database operations using the connection object would go here

            connection.close(); // Close the connection after use
        } catch (ClassNotFoundException e) {
            System.out.println("Error: Could not find MySQL JDBC driver class");
            e.printStackTrace(); // Optional: Print stack trace for debugging
        } catch (SQLException e) {
            System.out.println("Error connecting to MySQL database: " + e.getMessage());
            e.printStackTrace(); // Optional: Print stack trace for debugging
        }
    }
}
