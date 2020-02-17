import java.io.*;
public class G {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in)); 
        String[] nm = input.readLine().split("\\p{javaWhitespace}+");
        int n = Integer.parseInt(nm[0]);
        int[] arr = new int[n + 1];
        int[][] arrGet = new int[3][n + 1];
        for (int i = 1; i <= n; ++i) {
            arrGet[0][i] = i;
            arrGet[1][i] = i;
            arrGet[2][i] = 1;
            arr[i] = -i;
        }

        String tempp;
        while((tempp = input.readLine()) != null) {
            String[] temp = tempp.split("\\p{javaWhitespace}+");
            if (temp[0].equals("union")) {
                int tempF = arr[Integer.parseInt(temp[1])];
                int tempS = arr[Integer.parseInt(temp[2])];
                int befF = tempF * -1;
                while (tempF > -1) {
                    int qwe = tempF;
                    befF = qwe;
                    tempF = arr[tempF];
                }
                tempF *= -1;
                int befS = tempS * -1;
                while (tempS > -1) {
                    int qwe = tempS;
                    befS = qwe;
                    tempS = arr[tempS];
                }
                tempS *= -1;
                if (tempF != tempS) {
                    if (arrGet[2][tempF] > arrGet[2][tempS]) {
                        arr[befS] = befF;
                        arrGet[2][tempF] += arrGet[2][tempS];
                        if (arrGet[0][tempF] > arrGet[0][tempS]) {
                            arrGet[0][tempF] = arrGet[0][tempS];
                        }
                        if (arrGet[1][tempF] < arrGet[1][tempS]) {
                            arrGet[1][tempF] = arrGet[1][tempS];
                        }
                    } else {
                        arr[befF] = befS;
                        arrGet[2][tempS] += arrGet[2][tempF];
                        if (arrGet[0][tempS] > arrGet[0][tempF]) {
                            arrGet[0][tempS] = arrGet[0][tempF];
                        }
                        if (arrGet[1][tempS] < arrGet[1][tempF]) {
                            arrGet[1][tempS] = arrGet[1][tempF];
                        }
                    }
                }
                continue;
            }
            if (temp[0].equals("get")) {
                int val = arr[Integer.parseInt(temp[1])];
                while (val > -1) {
                    val = arr[val];
                }
                val *= -1;
                System.out.print(arrGet[0][val] + " " + arrGet[1][val] + " " + arrGet[2][val] + "\n");
            } else {
                break;
            }
        }
        input.close();
    }
}