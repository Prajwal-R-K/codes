package basic.method;

public class prime_nos {
    public static void main(String[] args) {
        System.out.println("The prime numbers between '20' and '50'");
        int a=20;
        int b=50;
        int count=0;
        while(a<=b)
        {
            
            if (isprime(a))
            {
                if(count%10==0) System.out.println();
                count++;
                System.out.print(a+"\t");
                a++;
            }
            a++;
        }
    }
    public static boolean isprime(int num){
        for(int i=2;i<num;i++)
        {
            if(num%i==0)
                return false;
        }
        return true;
    }
}
