import java.util.*;

public class Main{
    public static void main(String[] args){
            Scanner sc = new Scanner(System.in);
            String n = sc.next();

            int[] count = new int[10];
            int sum = 0;

            for(char c : n.toCharArray()){
                    int digit = c-'0';
                    count[digit]++;
                    sum+=digit;
            }

            if(count[0]==0 || sum%3!=0){
                System.out.println(-1);
                return;
            }

            StringBuilder sb = new StringBuilder();
            for(int i=9; i>=0; i--){
                for(int j= count[i]; j>0; j--){
                    sb.append(i);
                }
            }
            System.out.println(sb);
    }
}
