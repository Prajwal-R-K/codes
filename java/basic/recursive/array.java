
import java.util.Arrays;

class array {
    /*
    int values[];
    RecTest(int i) {
        values = new int[i];
        }
        // display array -- recursively
        void printArray(int i) {
        if(i==0) return;
        else printArray(i-1);
        System.out.println("[" + (i-1) + "] " + values[i-1]);
        }
        }
public class array {
    public static void main(String args[]) {
        RecTest ob = new RecTest(10);
        int i;
        for(i=0; i<10; i++) ob.values[i] = i;
        ob.printArray(10);
        }

        */



            public static void main(String[] args) {
                int[] arr = {1, 2, 3};
                System.out.println("Before: " + Arrays.toString(arr));
                
                // Calling a method with pass by reference
                modifyArray(arr);
                
                System.out.println("After: " + Arrays.toString(arr));
            }
        
            public static void modifyArray(int[] array) {
                for (int i = 0; i < array.length; i++) {
                    array[i] *= 2;
                }
                System.out.println("Inside method: " + Arrays.toString(array));
            }
        
        
    
}
        