import java.util.Scanner;

/**
 * Created by Kelv on 02/02/2016.
 */
public class Main {
    double numOne;
    double numTwo;

    public Main() {
        // constructor
    }


    public void inputNumber() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a number: ");
        this.numOne = scanner.nextDouble();
        System.out.println("Enter another number: ");
        this.numTwo = scanner.nextDouble();
    }

    public double calc() {
        return Math.sqrt(this.numOne + this.numTwo);
    }

    public static void main(String[] args) {
        Main main = new Main();
        main.inputNumber();
        System.out.println("Result is: " + main.calc());
    }
}
