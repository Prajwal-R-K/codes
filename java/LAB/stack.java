import java.util.Scanner;
class stack1{
    Scanner s=new Scanner(System.in);
    
        int max=10,top=-1;
        int stack[]=new int[max];
        void push()
        {
            if(top==max-1) System.out.println("STACK OVERFLOW");
            else {System.out.println("Enter the element");stack[++top]=s.nextInt();}
        }
        void pop()
        {
            if(top==-1){System.out.println("STACK UNDERFLOW");}
            else{System.out.println("The deleted element is "+stack[top--]);}
        }
        void display()
        {
            if(top==-1){System.out.println("STACK IS EMPTY");}
            else{for(int i=top;i>=0;i--)System.out.print(stack[i] +"\t");System.out.println();}
        }
}
public class stack{
        public static void main(String srgs[])
        { //  Scanner s=new Scanner(System.in);
            stack1 obj=new stack1();

            while(true)
            {
            System.out.println("1-push\t2-pop\t3-display\t4-exit");
            int n=obj.s.nextInt();
            switch (n) {
                case 1:obj.push();
                    
                    break;
                case 2:obj.pop();
                    
                    break;
                case 3:obj.display();
                    
                    break;
                case 4:System.exit(0);
                default:System.out.println("Invalid choice");
                    break;
            }
        }
    }
}
