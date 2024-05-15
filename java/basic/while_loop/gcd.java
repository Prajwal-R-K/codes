
import java.util.Scanner;

public class gcd {
    public static void main(String[] args)
    {
        int gcd=1,k=2;
        System.out.println("Enter the two numbers");
        Scanner s =new Scanner(System.in);
        int n1=s.nextInt();
        int n2=s.nextInt();
        while(k<=n1&&k<=n2)
        {
            if(n1%k==0&&n2%k==0)
            {
                gcd=k;
                
            }
            k++;
        }
        System.out.println("GCD of "+n1+" "+n2+" is "+gcd);
    }
    
}
