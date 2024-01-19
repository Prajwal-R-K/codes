
import java.util.Scanner;
class staff1{
    String staffId,name,phone,salary;
    Scanner s=new Scanner(System.in);
    void read()
    {
        System.out.println("Enter StaffId ,name,phone,salary");
        staffId=s.next();
        name=s.next();
        phone=s.next();
        salary=s.next();

    }
    void display()
    {
        System.out.println(staffId +"\t"+name+"\t"+phone+"\t"+salary);
    }
}
class Teach extends staff1{
    String domain,publication;
    void read()
    {
        super.read();
        System.out.println("Enter the domain and publication");
        domain=s.next();
        publication=s.next();

    }
    void display()
    {   super.display();
        System.out.println("Domain - "+domain+"\t Publication-"+publication);

    }
}
class Tech extends staff1{
    String skils;
    void read()
    {
        super.read();
        System.out.println("Enter the Skills ");
        skils=s.next();

    }
    void display()
    {
        super.display();
        System.out.println("Skills - "+skils);
    }
}
class contract extends staff1{
    String period;
    void read()
    {
        super.read();
        System.out.println("Enter the period");
        period=s.next();
    }
    void display()
    {
        super.display();
        System.out.println("Period - "+period);
    }
}
public class staff{
public static void main(String[] args) {
    Teach a=new Teach();
    Tech b=new Tech();
    contract c=new contract();
    System.out.println("Enter the details");
    System.out.println("\nTeaching Staff".toUpperCase());
    a.read();
    System.out.println("\nTechnical Staff".toUpperCase());
      b.read();
      System.out.println("\nContract Staffto".toUpperCase());
      c.read();
      System.out.println();
    System.out.println("\nTeaching Staff".toUpperCase());
    a.display();
    System.out.println("\nTechnical Staff".toUpperCase());
    b.display();
      System.out.println("\nContract Staff".toUpperCase());
    c.display();
}
}



