package basic.GUI;  // Give (run java) not (run code)
import javax.swing.JOptionPane;

public class sum_of_values {
    public static void main(String[] args) {
        int sum=0,option=0;
        while(option==JOptionPane.YES_OPTION)
        {
            String data=JOptionPane.showInputDialog("Enter the integer value:");
            int num=Integer.parseInt(data);
            sum+=num;
            option=JOptionPane.showConfirmDialog(null, "CONTINUE");
        }
        JOptionPane.showMessageDialog(null,"The Sum of entered numbers is:"+sum);
    }
}
