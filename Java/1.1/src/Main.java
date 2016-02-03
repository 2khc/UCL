import java.util.Scanner;

/**
 * Created by Kelv on 02/02/2016.
 */
public class Main {
    public static void main(String [] args)
    {
        // Input a sequency of String until "stop" is enterred
        new Main().inputString();
    }

    public void inputString()
    {
        Scanner sc = new Scanner(System.in);

        System.out.println("Input your string: ");
        String input = sc.nextLine();
        while (input.compareToIgnoreCase("stop") != 0)
        {
            input = sc.nextLine();
        }

        System.out.println("stopping");
    }

}