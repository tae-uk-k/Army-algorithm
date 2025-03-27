import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double[] scores = new double[n];
        double max = 0, sum = 0;

        for (int i = 0; i < n; i++) {
            scores[i] = sc.nextInt();
            if (scores[i] > max) max = scores[i];
        }

        for (int i = 0; i < n; i++) {
            sum += (scores[i] / max) * 100;
        }

        System.out.println(sum / n);
    }
}
