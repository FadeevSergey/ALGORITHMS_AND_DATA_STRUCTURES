import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
public class Heap {
    private static void swap(List<Integer> A, int a, int b) {
        int tmp = A.get(a);
        A.set(a, A.get(b));
        A.set(b, tmp);
    }
    public static void extract(List <Integer> A) {
        int k = 0;
        int tempMax = A.get(0);
        swap(A, 0, (A.size()-1));
        A.remove(A.size()-1);
        int siz = A.size();
        while(k * 2 + 1 < siz) {
            int left = k * 2 + 1;
            int right = left + 1;        
            int j = left;
            if (right < siz && A.get(right) > A.get(left)) {
                j = right;
            }
            if (A.get(k) <= A.get(j)) {
                break;
            }
               swap(A, k, j);
            k = j;
        }
        System.out.print(tempMax + "\n");    
    }
    public static void insert(List<Integer> A, int x) {
        int i = A.size() - 1;
        A.add(x);
        int parent = (A.size() - 1) / 2;
        while (i > 0 && parent < x) {
            swap(A, i, parent);
        }
    }
    public static void main(String[] args){
        List<Integer> A = new ArrayList<Integer>();
        Scanner imput = new Scanner(System.in);
        int size = imput.nextInt();
        int ch;
        for (int i = 0; i < size; ++i) {
            ch = imput.nextInt();
            if (ch == 0) {
                insert(A, imput.nextInt());
            }
            if (ch == 1) {
                extract(A);
            }
        }
    }
}