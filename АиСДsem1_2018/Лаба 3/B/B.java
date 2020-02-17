import java.io.*;
public class B {
    public static void main(String[] args) throws IOException {
        int n;
        int m;
        int[][] array;
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"), "UTF-8"))) {
            String[] in = reader.readLine().split(" ");
            n = Integer.parseInt(in[0]);
            m = Integer.parseInt(in[1]);
            array = new int[n][m];
            for (int i = 0; i < n; ++i) {
                in = reader.readLine().split(" ");
                for (int k = 0; k < m; ++k) {
                    array[i][k] = Integer.parseInt(in[k]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < m; ++k) {   
                System.out.print(array[i][k] + " ");
            }
            System.out.println();
        }
        char[][] par = new char[n][m];
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < m; ++k) {
                if (i == 0 && k == 0) {
                    continue;
                }
                if (k != 0) {
                    if (i != 0) {
                        if (array[i - 1][k] < array[i][k - 1]) {
                            par[i][k] = 'R';
                            array[i][k] += array[i][k - 1];
                        } else {
                            par[i][k] = 'D';
                            array[i][k] += array[i - 1][k];
                        }
                    } else {
                        par[i][k] = 'R';
                        array[i][k] += array[i][k - 1];
                    }
                } else {
                    par[i][k] = 'D';
                    array[i][k] += array[i - 1][k];
                }
            }
        }
        char[] res = new char[n + m - 2];
        int f = n - 1;
        int s = m - 1;
        for (int i = n + m - 3; i >= 0; --i) {
            if (par[f][s] == 'R') {
                res[i] = 'R';
                s--;
            } else {
                res[i] = 'D';
                f--;
            }
        }
        try (PrintWriter out = new PrintWriter("output.txt", "UTF-8")) {
            out.println(array[n - 1][m - 1]);
            for (int i = 0; i < n + m - 2; ++i) {
                out.print(res[i]);
            }
        }
    }
}
