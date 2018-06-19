import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class InsertionSort {

    private List<Integer> validInput(){
        Scanner scan = new Scanner(System.in);

        System.out.println("How much numbers you want to sort?");
        int number = scan.nextInt();

        System.out.println("Enter the numbers...");
        List<Integer> inputList = new ArrayList<>();

        for(int i=0; i<number; i++) {
            int num = scan.nextInt();
            inputList.add(num);
        }

        return inputList;
    }

    private List<Integer> sort(List<Integer> l){
        for (int i=1; i<l.size(); i++) {
            int tempnum = l.get(i);
            int j=i-1;
            for (; j>=0; j--){
                if ( l.get(j) > tempnum ){
                    l.set(j+1, l.get(j));
                }
                else break;
            }
            l.set(j+1, tempnum);
        }
        return l;
    }

    public static void main(String[] args) {
        InsertionSort iS = new InsertionSort();

        List<Integer> list = iS.sort(iS.validInput());
        for (int i=0; i<list.size(); i++){
            System.out.println(list.get(i));
        }
    }
}