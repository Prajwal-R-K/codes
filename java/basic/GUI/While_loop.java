import javax.swing.JOptionPane;

public class While_loop {
    public static void main(String[] args) {
        int option=0;
        while(option==JOptionPane.YES_OPTION)
        {
            System.out.println("Contiue loop");
            option=JOptionPane.showConfirmDialog(null, "Continue?");
        }
    }
}
