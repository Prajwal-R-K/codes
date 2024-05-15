class NewThread implements Runnable
{
    Thread t;
    NewThread()
    {
        t=new Thread(this,"Demo Thread");
        System.out.println("Child Thread:"+t);
        t.start();
    }
    public void run()
    {
        try
        {
        for(int i=0;i<=5;i++)
        {
        System.out.println("Child Thread:"+i);
        Thread.sleep(500);
        }
        }
        catch(InterruptedException o)
        {
            System.out.println("Child Interrputed:"+o);
        }
        System.out.println("Exit Child Thread");
    }
}

public class runnable {
    public static void main(String[] args) {
        NewThread newThread =new NewThread();
        //Main thread interrupts the child thread
       // newThread.t.interrupt();
        
        try
        {
        for(int i=0;i<=5;i++)
        {
            
        System.out.println("Main Thread:"+i);
        
        Thread.sleep(1000);
        
        }
        }
        catch(InterruptedException o)
        {
            System.out.println("Main Interrputed"+o);
        }
        System.out.println("Exit Main Thread");
        
    }
}

