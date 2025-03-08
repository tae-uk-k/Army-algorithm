import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Integer[] arr = new Integer[3];
        
        for (int i = 0; i < 3; i++) {
            arr[i] = sc.nextInt(); 
        }

        Arrays.sort(arr);

        for (int i = 0; i < 3; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
