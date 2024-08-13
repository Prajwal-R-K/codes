import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

public class BankDBMS extends JFrame implements ActionListener {
    private JTextField id, name, accountNo, balance;
    private JTextArea display;
    private Connection conn;
    private JButton create, retrieve, update, delete;

    public BankDBMS() {
        setTitle("Bank DBMS");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Initialize database connection (replace with your database details)
        try {
            conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/bankdb", "root", "your password");
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Database connection failed!", "Error", JOptionPane.ERROR_MESSAGE);
            System.exit(1);
        }

        // Create input fields using BoxLayout
        Box inputBox = Box.createVerticalBox();
        inputBox.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        id = new JTextField(10);
        name = new JTextField(20);
        accountNo = new JTextField(20);
        balance = new JTextField(10);

        inputBox.add(createInputField("ID:", id));
        inputBox.add(createInputField("Name:", name));
        inputBox.add(createInputField("Account No:", accountNo));
        inputBox.add(createInputField("Balance:", balance));

        // Create buttons using FlowLayout
        JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.CENTER));

        create = new JButton("Create");
        create.addActionListener(this);
        buttonPanel.add(create);

        retrieve = new JButton("Retrieve");
        retrieve.addActionListener(this);
        buttonPanel.add(retrieve);

        update = new JButton("Update");
        update.addActionListener(this);
        buttonPanel.add(update);

        delete = new JButton("Delete");
        delete.addActionListener(this);
        buttonPanel.add(delete);

        // Display area
        display = new JTextArea(15, 50);
        display.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(display);

        // Main content pane with BorderLayout
        getContentPane().setLayout(new BorderLayout());
        getContentPane().add(inputBox, BorderLayout.NORTH);
        getContentPane().add(buttonPanel, BorderLayout.CENTER);
        getContentPane().add(scrollPane, BorderLayout.SOUTH);

        setLocationRelativeTo(null); // Center the frame on screen
        setVisible(true);
    }

    // Method to create a labeled input field
    private JPanel createInputField(String label, JTextField textField) {
        JPanel panel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        panel.add(new JLabel(label));
        panel.add(textField);
        return panel;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == create) {
            create();
        } else if (e.getSource() == retrieve) {
            retrieve();
        } else if (e.getSource() == update) {
            update();
        } else if (e.getSource() == delete) {
            delete();
        }
    }

    private void create() {
        try {
            String sql = "INSERT INTO customers (id, name, account_no, balance) VALUES (?, ?, ?, ?)";
            PreparedStatement statement = conn.prepareStatement(sql);
            statement.setInt(1, Integer.parseInt(id.getText()));
            statement.setString(2, name.getText());
            statement.setString(3, accountNo.getText());
            statement.setInt(4, Integer.parseInt(balance.getText()));
            statement.executeUpdate();
            JOptionPane.showMessageDialog(this, "Customer created successfully!");
            clear();
        } catch (SQLException ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(this, "Failed to create customer.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void retrieve() {
        try {
            // Prepare the base query
            StringBuilder sqlBuilder = new StringBuilder("SELECT * FROM customers WHERE ");

            // Check each field and add conditions to the query
            boolean isFirst = true;

            // Add ID condition if ID field is filled
            if (!id.getText().trim().isEmpty()) {
                if (!isFirst) {
                    sqlBuilder.append(" AND ");
                }
                sqlBuilder.append("id = ").append(Integer.parseInt(id.getText().trim()));
                isFirst = false;
            }

            // Add Name condition if Name field is filled
            if (!name.getText().trim().isEmpty()) {
                if (!isFirst) {
                    sqlBuilder.append(" AND ");
                }
                sqlBuilder.append("name = '").append(name.getText().trim()).append("'");
                isFirst = false;
            }

            // Add Account No condition if Account No field is filled
            if (!accountNo.getText().trim().isEmpty()) {
                if (!isFirst) {
                    sqlBuilder.append(" AND ");
                }
                sqlBuilder.append("account_no = '").append(accountNo.getText().trim()).append("'");
                isFirst = false;
            }
            if (!balance.getText().trim().isEmpty()) {
                if (!isFirst) {
                    sqlBuilder.append(" AND ");
                }
                sqlBuilder.append("balance = '").append(balance.getText().trim()).append("'");
                isFirst = false;
            }

            // Execute the constructed query
            Statement statement = conn.createStatement();
            ResultSet resultSet = statement.executeQuery(sqlBuilder.toString());
            display.setText("");

            // Process the result set
            while (resultSet.next()) {
                display.append("ID: " + resultSet.getInt("id") + ", ");
                display.append("Name: " + resultSet.getString("name") + ", ");
                display.append("Account No: " + resultSet.getString("account_no") + ", ");
                display.append("Balance: " + resultSet.getInt("balance") + "\n");
            }

            // Close resources
            statement.close();
            resultSet.close();
        } catch (SQLException ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(this, "Failed to retrieve customers.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }
    private void update() {
        try {
            String sql = "UPDATE customers SET name = ?, account_no = ?, balance = ? WHERE id = ?";
            PreparedStatement statement = conn.prepareStatement(sql);
            statement.setString(1, name.getText());
            statement.setString(2, accountNo.getText());
            statement.setInt(3, Integer.parseInt(balance.getText()));
            statement.setInt(4, Integer.parseInt(id.getText()));
            statement.executeUpdate();
            JOptionPane.showMessageDialog(this, "Customer updated successfully!");
            clear();
        } catch (SQLException ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(this, "Failed to update customer.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void delete() {
        try {
            String sql = "DELETE FROM customers WHERE id = ?";
            PreparedStatement statement = conn.prepareStatement(sql);
            statement.setInt(1, Integer.parseInt(id.getText()));
            statement.executeUpdate();
            JOptionPane.showMessageDialog(this, "Customer deleted successfully!");
            clear();
        } catch (SQLException ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(this, "Failed to delete customer.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void clear() {
        id.setText("");
        name.setText("");
        accountNo.setText("");
        balance.setText("");
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new BankDBMS();
        });
    }
}