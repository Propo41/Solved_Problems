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
                    switch (temp[j]) {
                        case 0:
                            arr[0]++;
                            break;
                        case 1:
                            arr[1]++;
                            break;
                        case 2:
                            arr[2]++;
                            break;

                        case 3:
                            arr[3]++;
                            break;

                        case 4:
                            arr[4]++;
                            break;

                        case 5:
                            arr[5]++;
                            break;

                        case 6:
                            arr[6]++;
                            break;

                        case 7:
                            arr[7]++;
                            break;

                        case 8:
                            arr[8]++;
                            break;

                        case 9:
                            arr[9]++;
                            break;

                    }
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

