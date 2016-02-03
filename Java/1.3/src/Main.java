import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by Kelv on 02/02/2016.
 */
public class Main {
    ArrayList<String> arrayList;

    public Main (ArrayList<String> arrayList)
    {
        this.arrayList = arrayList;
    }

    public void addString()
    {
        String input;
        Scanner sc = new Scanner(System.in);
        System.out.println("input 10 strings");
        while (arrayList.size() < 10)
        {
            input = sc.next();
            arrayList.add(input);
        }
        printReverse();
    }

    private void printReverse()
    {
        for (int i=arrayList.size()-1;i>=0;i--)
        {
            System.out.print(arrayList.get(i) + " ");
        }
    }

    public static void main (String[] args)
    {
        new Main(new ArrayList<>()).addString();
    }
}
