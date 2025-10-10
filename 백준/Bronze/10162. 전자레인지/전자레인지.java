import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int A = 0, B = 0, C = 0;

        while (N >= 300) {
            N -= 300;
            A++;
        }
        while (N >= 60) {
            N -= 60;
            B++;
        }
        while (N >= 10) {
            N -= 10;
            C++;
        }
        if (N != 0) {
            System.out.println(-1);
        } else {
            System.out.println(A + " " + B + " " + C);
        }
    }
}