public class multiplicationTable{
    public static void main(String[] args)

{   int n=20;
    System.out.println("        MULTIPLICATION TABLE        ");
     System.out.print("     ");
     for(int i=1;i<=n;i++)
     {if(i<10)
       System.out.print("    "+i);
    else System.out.print("   "+i);
     }
     String output="";
     System.out.println("\n----------------------------------------------------------------------------------------------------------");
     for(int j=1;j<=n;j++)
     {  if(j>=100)
        output+="   "+j+"|";
        else if(j>=10)
        output+="  "+j+"|";
        else
        output+="   "+j+"|";
        for(int i=1;i<=n;i++)
        {
            if(i*j>=100)
                 output+="  "+i*j;
            else if(i*j>=10)
                 output+="   "+i*j;
            else
                 output+="    "+i*j;
        }
         output+="\n";
     }
     System.out.println(output);

}
}