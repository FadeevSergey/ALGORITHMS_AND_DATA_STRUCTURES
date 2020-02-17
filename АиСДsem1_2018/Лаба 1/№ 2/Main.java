import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner imput = new Scanner(System.in);
        int[] arr = new int [101];
        while (imput.hasNextInt()) {
            arr[imput.nextInt()]++;    
        }
        for (int i = 0; i < 101; i++) {
            for (int k = 0; k < arr[i]; k++) {
                System.out.print(i + " ");
            }
        }
    }
}
