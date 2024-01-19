abstract class shape{
   abstract void calculateArea();
  
   abstract void calculatePerimeter();
   
}
class circle extends shape{
    int r;
    circle(int r){
        this.r=r;
    }
    void calculateArea()
        {
            System.out.println("Area ="+Math.PI*r*r);
        }
    void calculatePerimeter()
    {
        System.out.println("Perimeter ="+(2*Math.PI*r));
    }

}
class Triangle extends shape{
    int a1,a2,a3;
    Triangle(int a,int b,int c){
a1=a;
a2=b;
a3=c;
    }
    void calculateArea()
        {int s=(a1+a2+a3)/3;
            System.out.println("Area="+Math.sqrt(s*(s-a1)*(s-a2)*(s-a3)));
        }
    

    }
    void calculatePerimeter()
    {
        System.out.println("Perimeter ="+(a1+a2+a3));
}
}


public class Abstract {
    public static void main(String[] args){
        circle a=new circle(23);
        Triangle a1=new Triangle(23,34,31);
        System.out.println("CIRCLE");
        a.calculateArea();
        a.calculatePerimeter();
        System.out.println("TRAINGLE");
        a1.calculateArea();
        a1.calculatePerimeter();
    }
    
}
