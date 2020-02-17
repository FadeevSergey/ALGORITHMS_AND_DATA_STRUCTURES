import java.io.*;
public class J {
    public static void main(String[] args)throws IOException {
        int n, m;
        try (BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("nice.in"), "UTF-8"))) {
            String[] s = in.readLine().split(" ");
            if (Integer.valueOf(s[0]) > Integer.valueOf(s[1])) {
                m = Integer.valueOf(s[0]);
                n = Integer.valueOf(s[1]);
            } else {
                n = Integer.valueOf(s[0]);
                m = Integer.valueOf(s[1]);
            }
        }
        int[][] dp = new int[1 << n + 1][1 << n + 1];
        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                int val = 0;
                for (int o = 0; o < n - 1; ++o) {
                    if ((i >> o) % 2 == (i >> (o + 1)) % 2 && (i >> o) % 2 == (j >> o) % 2 && (i >> (o + 1)) % 2 == (j >> (o + 1)) % 2) {
                        val++;
                        break;
                    }
                }
                if (val != 1) {
                    dp[i][j] = 1;
                }
            }
        }
        long[][] a = new long[m][1 << n];
        for (int i = 0; i < (1 << n); ++i) {
            a[0][i] = 1;
        }
        for (int o = 1; o < m; ++o) {
            for (int i = 0; i < (1 << n); ++i) {
                for (int j = 0; j < (1 << n); ++j) {
                    a[o][i] += a[o - 1][j] * dp[j][i];
                }
            }
        }
        long ans = 0;
        for (int i = 0; i < (1 << n); ++i) {
            ans += a[m - 1][i];
        }
        try (PrintWriter out = new PrintWriter("nice.out", "UTF-8")) {
            out.println(ans);
        }
    }
}