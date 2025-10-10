import java.util.*;

public class Main {
    public static void main(String[] arge){
        Scanner sc = new Scanner(System.in);
        int n= sc.nextInt();
        int sum=0;

        for(int N=1; N<=n; N++){
            sum++;
            ArrayList<Integer>term= new ArrayList<>();
            String NtoS = String.valueOf(N);

            for(char c : NtoS.toCharArray()){
                term.add(c-'0');
            }
            if(term.size() <= 2){
                continue;
            }
            int difference = term.get(0)-term.get(1);

            for(int i=0; i<term.size()-1; i++){
                if((term.get(i)-term.get(i+1))!=difference){
                    sum--;
                    break;
                }

            }
        }
        System.out.println(sum);
    }
}
