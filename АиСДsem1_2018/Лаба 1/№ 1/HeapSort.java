import java.util.Scanner;

public class HeapSort {

    private static int n;

    private static void swap(int[] A, int a, int b) {
        int tmp = A[a];
        A[a] = A[b];
        A[b] = tmp;
    }

    private static void insert(int[] A, int i) {
        int left = i * 2;
        int right = left + 1;
        int max = i;
        if (left <= n && A[left] > A[i]){ 
            max = left;
        }
        if (right <= n && A[right] > A[max]) {
            max = right;
        }
        if (max != i) {
            swap(A, i, max);
            insert(A, max);
        }
    }

    public static void HeapSort(int[] A) {
        n = A.length - 1;

        for (int i = n / 2; i >= 0; i--)
            insert(A, i);

        for (int i = n; i > 0; i--) {
            swap(A, 0, i);
            n--;
            insert(A, 0);
        }
    }

    public static void main(String[] args) {
        Scanner imput = new Scanner(System.in);
        int size = imput.nextInt();
        int[] A = new int[size];
        for (int q = 0; q < size; ++q) {
            A[q] = imput.nextInt();
        }
        HeapSort(A);
        for (int i = 0; i < size; ++i) {
            System.out.print(A[i] + " ");
        }
    }
}