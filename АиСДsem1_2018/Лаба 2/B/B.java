import java.util.*;
import java.lang.*;
public class B {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<Integer>();
        Scanner input = new Scanner(System.in);
        int size = input.nextInt();
        for (int i = 0; i < size; ++i) {
           list.add(input.nextInt()); 
        }
        int k;
        int cur = 0;
        int temp;
        int kkkk = list.size() - 2;
        int curr;
        while(!list.isEmpty()) {
            k = 1;
                for (int i = 0; i < list.size() - 2; ++i) {
                    curr = 0;
                    if(Objects.equals(list.get(i), list.get(i + 1)) && Objects.equals(list.get(i + 1), list.get(i + 2))) {
                        if (i + 3 < list.size()) {
                            temp = list.get(i);
                            size = list.size();
                            for (int j = i + 3; j < size; ++j) {
                                if (list.get(j) == temp)
                                    curr++;
                                else
                                    break;
                            }
                        }
                        int tempp = curr + 3;
                        for (int g = 0; g < tempp; ++g) {
                           cur++;
                           list.remove(i);
                        }
                        k = 0;
                        break;
                    }
                }
                kkkk = list.size() - 2;
                if (k != 0) {
                    System.out.print(cur);
                    return;
                }
        }
        System.out.print(cur);
    }
}