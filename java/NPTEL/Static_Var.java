
class A{
    static int a=0;
   A()
    {
        a++;
    }
    A(int x)
    {
        a*=x;
    }
    A(float x)
    {
        a++;
    }
    void test()
    {
        a++;
    }
}
    public class Static_Var 
    {
      public static void main(String[] args) {
        System.out.println(A.a);
        A s1=new A();
        System.out.println(A.a);
        A s2=new A(2);
        System.out.println(A.a);
        A s3=new A(2.0f);
        System.out.println(A.a);
      
     //   System.out.println(s3.a);
        s1.test();
        System.out.println(s1.a);
    }
    
}

