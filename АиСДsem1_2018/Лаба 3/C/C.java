import java.util.*;
public class C {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] arrey = new int[n];
        for (int i = 0; i < n; ++i) {
            arrey[i] = in.nextInt();
        }
        int[] d = new int[n];
        int[] p = new int[n];
        for (int i = 0; i < n; ++i) {
            d[i] = 1;
            p[i] = -1;
            for (int j = 0; j < i; ++j) {
                if (arrey[j] < arrey[i]) {
                    if (1 + d[j] > d[i]) {
                        d[i] = 1 + d[j];
                        p[i] = j;
                    }
                }
            }
        }
        
        int ans = d[0];
        int pos = 0;
        for (int i = 0; i < n; ++i) {
            if (d[i] > ans) {
                ans = d[i];
                pos = i;
            }
        }
        System.out.println(ans);
        List<Integer> list = new ArrayList<>();
        while (pos != -1) {
            list.add(arrey[pos]);
            pos = p[pos];
        }
        for (int i = list.size() - 1; i>= 0; --i) {
            System.out.print(list.get(i) + " ");
        }
    }
}