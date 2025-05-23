// Generating random number using java.util.Random;
import java.util.Random;

public class sample{
    
    public static void main(String[] args) {
        
        // Creating the instance of Random class
        Random r= new Random();

        // Generate random integers in range 0 to 999
        int r1 = r.nextInt(1000);
        int r2 = r.nextInt(1000);

        // Printing random integers
        System.out.println("Random Integers: " + r1);
        System.out.println("Random Integers: " + r2);

        // Generate random doubles
        double rd1 = r.nextDouble();
        double rd2 = r.nextDouble();

        // Printing random doubles
        System.out.println("Random Doubles: " + rd1);
        System.out.println("Random Doubles: " + rd2);
    }
}
