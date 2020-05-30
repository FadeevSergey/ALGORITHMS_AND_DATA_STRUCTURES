import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class C {
    public static void main(String[] args) throws IOException {
        try(BufferedReader in = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(in.readLine().split(" ")[0]);

            for(int i = 0; i < n; i++) {
                BigInteger number = new BigInteger(in.readLine().split(" ")[0]);

                if(number.isProbablePrime(20)) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            }
        }
    }
}
