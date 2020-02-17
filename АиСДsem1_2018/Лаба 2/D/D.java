import java.io.*;
import java.util.LinkedList;
public class D {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in)); 
        int num = Integer.parseInt(input.readLine());
        LinkedList<String> arrF = new LinkedList<>();
        LinkedList<String> arrS = new LinkedList<>();
        ///////////////////////////////////////////
        for (int i = 0; i < num; ++i) {
            String[] temp = input.readLine().split("\\p{javaWhitespace}+");
            if (arrF.size() > arrS.size()) {
                    arrS.add(arrF.remove(0));
                }
            if (temp[0].equals("+")) {
                arrF.add(temp[1]);
                continue;
            }
            if (temp[0].equals("-")) {
                System.out.print(arrS.remove(0) + "\n");
                continue;
            }
            if (temp[0].equals("*")) {
                if (arrS.size() == arrF.size() || arrS.size() > arrF.size()) {   
                    arrF.add(0, temp[1]);
                    continue;
                }
                if (arrS.size() < arrF.size()) {
                    arrS.add(arrF.get(0));
                    arrF.set(0, temp[1]);
                }
            }
        }
        input.close();
    }
}