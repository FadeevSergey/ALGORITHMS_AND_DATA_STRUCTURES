import java.io.*;
import java.util.*;
public class A {
    public static void main(String[] args) throws IOException {
        String[] in;
        int n;
        int k;
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"), "UTF-8"))) {
            in = reader.readLine().split(" ");
            n = Integer.parseInt(in[0]);
            k = Integer.parseInt(in[1]);
            in = (reader.readLine()).split(" ");
        }
        int[] array = new int[n];
        int[] par = new int[n];
        for (int i = 1; i < n - 1; ++i) {
            array[i] = Integer.parseInt(in[i - 1]);
        }
        for (int i = 1; i < n; ++i) {
            int pos = -1;
            int tMax = Integer.MIN_VALUE;
            for (int j = i - 1; (j >= i - k) && (j >= 0);  --j) {
                if (array[j] >= tMax) {
                    pos = j;
                    tMax = array[j];
                }  
            }
            array[i] += array[pos];
            par[i] = pos;
        }
        int i = n - 1;
        List<Integer> list = new ArrayList<>();
        list.add(n);
        while (i != 0) {
            list.add(par[i] + 1);
            i = par[i];
        }
        try (PrintWriter out = new PrintWriter("output.txt", "UTF-8")) {
            out.println(array[n - 1]);
            out.println(list.size() - 1);
            for (i = list.size() - 1; i >= 0; --i) {
                out.print(list.get(i) + " ");
            }
        }
    }
}
