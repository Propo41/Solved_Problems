import java.util.*;

public class Main {

    public static void main(String[] args) {
        int tsc, n,k;
        Scanner sc = new Scanner(System.in);

        tsc = sc.nextInt();

        for (int i = 1; i <= tsc; i++) {

            int[] temp = new int[5];
            int[] arr = new int[10];

            n = sc.nextInt();

            for (int l = 1; l <= n; l++) {
                int t = l;
                 k = 0;
                while (t > 0) {
                    temp[k] = t % 10;
                    t = t / 10;
                    k++;
                }

                for (int j = 0; j < k; j++) {
                   
                    arr[temp[j]]++;
                    
                }

            }

            for (int m = 0; m < arr.length; m++) {

                System.out.print(arr[m]);
                if(m==arr.length-1)
                     System.out.println();
                else
                    System.out.print(" ");
            }

        }


    }
}

