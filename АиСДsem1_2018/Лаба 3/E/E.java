import java.util.*;
public class E {
    public static void main(String[] args) {
        String f = "0";
        String s = "0";
        try (Scanner input = new Scanner(System.in)) {
            f += input.nextLine();
            s += input.nextLine();
        }
        int n = Math.max(f.length() - 1, s.length() - 1);
        int[][] d = new int[n + 4][n + 4];
        d[0][0] = 0;
        for (int i = 1; i < s.length(); ++i) {
            d[0][i] = d[0][i - 1] + 1;
        }
        for (int i = 1; i < f.length(); ++i) {
            d[i][0] = d[i - 1][0] + 1;
            for (int j = 1; j < s.length(); ++j) {
                if (f.charAt(i) != s.charAt(j)) {
                    d[i][j] = Math.min(d[i - 1][j] + 1, d[i][j - 1] + 1);
                    d[i][j] = Math.min(d[i][j], d[i - 1][j - 1] + 1);
                } else {
                    d[i][j] = d[i - 1][j - 1];
                }
            }
        }
        System.out.print(d[f.length() - 1][s.length() - 1]);
    }
}