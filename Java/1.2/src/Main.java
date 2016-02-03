import java.util.ArrayList;
import java.util.Scanner;
/**
 * Created by Kelv on 02/02/2016.
 */
public class Main {
    public static void main (String[] args)
    {
        double num;

        Calculator calc = new Calculator(new ArrayList<>());
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter 10 numbers, pressing enter after each number");

        while (calc.getSize() < 10)
        {
            num = sc.nextInt();
            calc.addNumber(num);
        }

        calc.calcAverage();
    }
}
