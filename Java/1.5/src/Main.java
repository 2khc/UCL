import java.util.Scanner;

/**
 * Created by Kelv on 02/02/2016.
 */
public class Main {

    public Main()
    {
        //. constructor
    }

    public double inputDouble()
    {
        double num;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Input a number: ");
        num = scanner.nextDouble();
        return num;
    }

    public double calc(double numOne, double numTwo)
    {
        return Math.sqrt(numOne+numTwo);
    }


    public static void main (String[] args)
    {
        Main main = new Main();
        double numOne = main.inputDouble();
        double numTwo = main.inputDouble();
        System.out.println("Final value is: " + main.calc(numOne, numTwo));
    }
}
