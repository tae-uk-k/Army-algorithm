import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        int N;
        int ans =0;
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        if(N == 1 || N == 3) {
            System.out.println(-1);
            return;  
        }
        ans += N / 5;
        N = N % 5;
        if(N == 1 || N == 3) {
            ans--;
            N += 5;
        }
        ans += N / 2;

        System.out.println(ans);
    }
}
// 남은 수가  0,1,2,3,4 라고 해보자.
// 0은 무시하고 1,3은 2로 다 못 주니까 5를 더해야 한다.
//1은 6되고, 3은 8됨. 
//5로 나누고 나머지를 2로나누면 0이나 1임
// 0일때는 그대로 답이고 1일때는 5짜리 동전 하나 빼고 2짜리 동전 3개추가이니 답에다 +2 해주면 된다.

