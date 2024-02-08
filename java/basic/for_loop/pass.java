class A
{
    int a=10;
    int b=11;
    void pass(int i,int j)
    {
        i--;
        j--;
        
    }
}
public class pass {
    public static void main(String[] args) {
        int a =10,b=20;
        A t=new A();
       
        t.pass(a,b);
        System.out.println("after value"+a+"\t"+b);
    }
    
}
