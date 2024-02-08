import java.util.Scanner;

public class employee {
    int ID;
    float salary;
    String name;
    Scanner s=new Scanner(System.in);
    void read()
    {
        System.out.println("Enter the ID , Name , Salary");
        ID=s.nextInt();
        
        name=s.nextLine();
        salary=s.nextFloat();
    }
    void display()
    {
        System.out.println("ID-"+ID+"\tNAME-"+name+"\tSALARY-"+salary);
    }
    void raiseSalary(int per)
    {
        salary=salary+salary*per/100;
    }
    public static void main(String[] args)
    {employee e=new employee();
        e.read();
        e.display();
        System.out.println("Enter the percenatge");
        int per=e.s.nextInt();
        e.raiseSalary(per);
        System.out.println("After Salary Hike");
        e.display();
    }
}
