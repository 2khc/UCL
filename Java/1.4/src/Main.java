import java.util.Random;

/**
 * Created by Kelv on 02/02/2016.
 */
public class Main {
    double lowest;
    double sum;
    double highest;

    public Main(double lowest, double sum, double highest)
    {
        this.lowest = lowest;
        this.sum = sum;
        this.highest = highest;
    }

    public void generate()
    {
        double num;
        Random rand = new Random();
        for (int i=0;i<10000; i++)
        {
            if (rand.nextBoolean() == true)
            {
                num = -rand.nextDouble();
            }
            else
            {
                num = rand.nextDouble();
            }
            if (num < this.lowest)
            {
                this.lowest = num;
            }
            else if (num > this.highest)
            {
                this.highest = num;
            }
            this.sum += num;
        }
        System.out.println("Highest: " + this.highest);
        System.out.println("Lowest: " + this.lowest);
        System.out.println("Average: " + this.sum/10000);
    }

    public static void main (String[] args)
    {
        new Main(0,0,0).generate();
    }
}
