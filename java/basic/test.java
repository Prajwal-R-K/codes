/*import java.util.Scanner;
public class test{
    public static void main(String[] args)
{    Scanner s=new Scanner(System.in);
    char ch=s.next().charAt(0);
    System.out.println(ch);
}
}
*/

/*
class Counter
{
int count=0;//will get memory when instance is created

// static int count=0;//will get memory only once and retain its value
Counter()
{
count++;
System.out.println(count);
}
}

class test
{
public static void main(String args[])
{
Counter c1=new Counter();
Counter c2=new Counter();
Counter c3=new Counter();
 }
}*/


class test
{
    static int a = 3; 
     int b=8;
    static void meth(int x) { 
    System.out.println("x = " + x); 
    System.out.println("a = " + a); 
    System.out.println("b = " +a);
    }
    
 public static void main(String[] args)
 {

    meth(42);
    
}
static {
    System.out.println("Static block initialized."); 
    //b = a * 4;
    }
}