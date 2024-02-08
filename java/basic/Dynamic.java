
class figure 
{
    int d1,d2;
    protected figure(int i,int j)
    {
        d1=i;
        d2=j;
    }
    void area()
    {
        System.out.println("no area");
    }
}
class tri extends figure
{
    tri(int a,int b)
    {
        super(a,b);
    }
    void area()
    {
        System.out.println("area of triangel is   "+d1*d2*0.5);
    }
}
class rec extends figure
{
    rec(int a,int b)
    {
        super(a,b);
    }
    void area()
    {
        System.out.println("area of rectangle   "+d1*d2);
    }
}
public class Dynamic {
    public static void main(String[] args) {
        figure f1=new tri(10,20);
        f1.area();
        figure f2=new rec(5,6);
        f2.area();
    }
}
