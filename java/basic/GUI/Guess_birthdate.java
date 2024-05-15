
import javax.swing.JOptionPane ;
public class Guess_birthdate 
{

    public static String set(int n)
    {
        String s="",s1;
        int column=0;
        for(int j=n;j<=31;)
            {
                for(int k=1;k<=n;k++)
                {
                    if(column%4==0)
                    {
                        s=s+"\n";
                    }
                    s1=Integer.toString(j);
                    s=s+s1+"  ";
                    j++;
                    column++;
                }
            j=j+n;
            }
        //System.out.println(s);
        return s;
    }

    public static void main(String[] args) 
    {
        int date=0,answer=JOptionPane.YES_OPTION;
        for(int i=1;i<=16;)
        {
            if(answer==JOptionPane.showConfirmDialog(null, "Is your birthdate in these numbers"+set(i)))
            {
                date=date+i;
            }
            i=i*2;
        }
        JOptionPane.showMessageDialog(null,"Your birthdate is "+date+"!");
    }
}
    

