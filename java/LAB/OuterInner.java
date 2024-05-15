class Outer
{
    void display()
    {
        System.out.println("Outer Class");
        Inner in=new Inner();
        in.display(); 
    }
    class Inner
    {
        void display()
        {
            System.out.println("Inner Class");
        }
    }
}

public class OuterInner {
    public static void main(String[] args) {
        Outer o=new Outer();
        Outer.Inner i=o.new Inner();
        o.display();
        i.display();
    }
}
