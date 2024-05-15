
import java.util.Scanner;
class OOC extends Exception
{
    OOC(String msg)
    {
        super(msg);
    }
}
class CustomException 
{
    static void divide(double a,double b) throws OOC
    {
        if(b==0)
            throw new OOC("Division by zero is not possible");
        System.out.println(a/b);
    }


    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("Enter the values of x and y");
        double x=s.nextDouble();
        double y=s.nextDouble();
        try
        {
            divide(x,y);
        }
        catch(ArithmeticException o)
        {
            System.out.println(o);
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
        finally
        {
            System.out.println("Final");
        }
    }
}