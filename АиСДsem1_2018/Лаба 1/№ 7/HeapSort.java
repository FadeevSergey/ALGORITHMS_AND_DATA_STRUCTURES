import java.util.Scanner;

public class HeapSort {
    
    public static void main(String[] args){
        Scanner imput = new Scanner(System.in);
        int n = imput.nextInt();
        int x = imput.nextInt();
        int y = imput.nextInt(); 
        int t = Math.min(x, y);
        int t1 = x * (n - 1);
        for (int k = 1; k < n; ++k) {
            if (Math.max(x * (n - 1 - k), y * k) < t1) {
                t1 = Math.max(x * (n - 1 - k), y * k);
            }
        }
        System.out.print((t1 + t));
    }
}