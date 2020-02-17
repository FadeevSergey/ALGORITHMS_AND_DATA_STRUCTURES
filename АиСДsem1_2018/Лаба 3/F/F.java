import java.util.*;
public class F {
    public static Scanner in = new Scanner(System.in);
    public static int n;
    public static int[] p;
    public static int result = Integer.MAX_VALUE;
    public static int numK = 0;
    public static int[][] dp;
    public static List<Integer> list = new ArrayList<>();
    
    public static void maid() {
        n = in.nextInt();
        p = new int[n];
        dp = new int[n + 1][n + 2];
    }
    
    public static void forIn() {
        for (int i = 0; i < n; ++i) {
            p[i] = in.nextInt();
        }
    }
    public static void forDin() {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                    dp[i][j] = 1000000;
            }
        }
        dp[0][0] = 0;
    }
    
    public static void din() {
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (p[i - 1] > 100) {
                    if (j != 0 && j < n) {
                        dp[i][j] = Integer.min(dp[i - 1][j - 1] + p[i - 1], dp[i - 1][j + 1]);
                        continue;
                    }
                    if (j != n) {
                        dp[i][j] = dp[i - 1][j + 1];
                        continue;
                    }
                    if (j == 0 || j == n) {
                        dp[i][j] = dp[i - 1][j - 1] + p[i - 1];
                    }
                } else {
                    if (j < n) {
                        dp[i][j] = Integer.min(dp[i - 1][j] + p[i - 1], dp[i - 1][j + 1]);
                        continue;
                    }
                    if (j == n) {
                        dp[i][j] = dp[i - 1][j] + p[i - 1];
                    }
                }
            }
        }
    }
    
    public static void for2() {
        for (int j = 0; j < n + 1; ++j) {
            if (dp[n][j] <= result) {
                result = dp[n][j];
                numK = j;
            }
        }
    }
    
    public static void forList() {
           while (n != 0) {
            if (dp[n][numK] == dp[n - 1][numK + 1]) {
                list.add(n);
                n--;
                numK++;
            } else { 
                if (p[n - 1] > 100) {
                n--;
                numK--;
                } else {
                    n--;
                }
            }
        }
    }
    
    public static void forFirstOut() {
        System.out.println(result);
        System.out.print(numK + " ");
    }
    
    public static void forOut() {
        System.out.println(list.size());
        for (int i = list.size() - 1; i >= 0; --i) {
            System.out.println(list.get(i));
        }
    }
    
    public static void main(String[] args){
        maid();
        forIn();
        forDin();
        din();
        for2();
        forFirstOut();
        forList();
        forOut();
    }
}