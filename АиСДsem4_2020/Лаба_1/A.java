import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;

public class A {
    private static int n, m;
    private static ArrayList<Boolean> used;
    private static ArrayList<Integer> parSoch;
    private static ArrayList<ArrayList<Integer>> edges;

    private static boolean kuhn(int v) {
        if (used.get(v)) {
            return false;
        }
        used.set(v, true);
        for (int i = 0; i < edges.get(v).size(); ++i) {
            int to = edges.get(v).get(i);
            if (parSoch.get(to) == -1 || kuhn(parSoch.get(to))) {
                parSoch.set(to, v);
                return true;
            }
        }
        return false;
    }

    private static void readEdges() throws IOException {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            String[] arrayWithArgs = reader.readLine().split(" ");
            edges = new ArrayList<>();
            n = Integer.valueOf(arrayWithArgs[0]);
            m = Integer.valueOf(arrayWithArgs[1]);

            for (int i = 0; i < n; i++) {
                edges.add(new ArrayList<>());
                arrayWithArgs = reader.readLine().split(" ");
                for (String str : arrayWithArgs) {
                    if (!str.equals("0")) {
                        edges.get(i).add(Integer.parseInt(str) - 1);
                    }
                }

            }
        }
        parSoch = new ArrayList<>(m);
        for (int i = 0; i < m; i++) {
            parSoch.add(-1);
        }
        used = new ArrayList<>(n);
    }

    private static int getSolution() {
        for (int v = 0; v < n; ++v) {
            used.clear();
            for (int i = 0; i < n; i++) {

                used.add(false);
            }
            kuhn(v);
        }
        int result = 0;
        for (int i = 0; i < m; ++i) {
            if (parSoch.get(i) != -1) {
                result++;
            }
        }
        return result;
    }

    private static void printSolution() {
        for (int i = 0; i < m; ++i) {
            if (parSoch.get(i) != -1) {
                System.out.println((parSoch.get(i) + 1) + " " + (i + 1));
            }
        }
    }


    public static void main(String[] args) throws IOException {
        readEdges();
        System.out.println(getSolution());
        printSolution();
    }
}

