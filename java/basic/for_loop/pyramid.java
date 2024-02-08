public class pyramid {
    public static void main(String[] args) {
        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9-i;j++)
            System.out.print("  ");
            for(int k=i;k>=1;k--)
            System.out.print(" "+k);
            for(int k=2;k<=i;k++)
            System.out.print(" "+k);
           System.out.println();
        }
       
    }
    
}
