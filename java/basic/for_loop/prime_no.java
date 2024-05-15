public class prime_no {
    public static void main(String[] args)
    {
        System.out.println("The 40 Prime numberes are:");
        int count=0;
        int i,n=1;
        while(count<40 )
        {
            for( i=2;i<n;i++)
            {
                if(n%i==0)
                {
                    break;
                }
            }
            if(i==n)
            {
                System.out.print(n+"\t");
                count++;
                if(count%10==0)
                System.out.println();
            }
            n++;
        }
    }
    
}
