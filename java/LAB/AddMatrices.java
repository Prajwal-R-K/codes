import java.util.Scanner;
public class AddMatrices {
    public static void main(String[] args)
    {
        int i,j;
        Scanner s=new Scanner(System.in);
        int n= Integer.parseInt(args[0]);
        int[][] a=new int[n][n];
        int[][] b=new int[n][n];
        int[][] c=new int[n][n];
        System.out.println("Enter the 1st Matrix");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                a[i][j]=s.nextInt();
            }
        }
        System.out.println("Enter the 2st Matrix");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                b[i][j]=s.nextInt();
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                c[i][j]=a[i][j]+b[i][j];
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
               System.out.print( c[i][j]+"\t");
               System.out.println( );
        }
           
    }
}
