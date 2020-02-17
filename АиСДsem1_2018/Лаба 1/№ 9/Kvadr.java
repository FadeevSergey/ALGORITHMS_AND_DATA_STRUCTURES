import java.util.Scanner;
public class Kvadr {
    public static void main(String[] args) {
        Scanner imput = new Scanner(System.in);
        double C = imput.nextDouble();
        double result;
        double left = 0.55;
        double right = 100000;
        double X = (left + right) / 2;
        result = X * X + Math.sqrt(X);
        while (Math.abs(X - C) > 0.000001) {
            if (result > C) {
                right = X;
            } else {
                left = X;
            }
            X = (left + right) / 2;
            result = X * X + Math.sqrt(X);
        }
        
        System.out.printf("%.6f", X);
    }
    
}
