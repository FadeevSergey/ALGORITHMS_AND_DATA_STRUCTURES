import java.util.Scanner;
import java.util.LinkedList;
public class C {
    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        int temp;
        int size = -1;
        for (int i = 0; i < num; ++i) {
            temp = input.nextInt();
            if (temp == 1) {
                list.add(input.nextInt());
                size++;
                continue;
            }
            if (temp == 2) {
                list.remove(0);
                size--;
                continue;
            }
            if (temp == 3) {
                list.remove(size);
                size--;
                continue;
            }
            if (temp == 4) {
                int q = input.nextInt();
                for (int k = 0; k <= size; ++k) {
                    if (list.get(k) == q) {
                        System.out.print(k + "\n");
                        break;
                    }
                }
                continue;
            }
            if (temp == 5) {
                System.out.print(list.get(0) + "\n");
            }
        }
    }
}