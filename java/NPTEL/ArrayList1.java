import java.util.*;
public class ArrayList1 {
    public static void main(String[] args)
     {
        System.out.println("Java".equals("Java"));
        int sum=0;
        int average=0;
        System.out.println("Enter the number:");
        Scanner sc=new Scanner(System.in);
        ArrayList <Integer> l=new ArrayList<Integer>();
        
        while(sc.hasNextInt())
        {
            System.out.println("Entr");
            l.add(sc.nextInt());
        }
        for(int i=0;i<l.size();i++)
        {
            System.out.println(l.get(i));
            sum+=l.get(i);

        }
        average=sum/l.size();
        System.out.println(sum+" " +average);
    }
    
}
