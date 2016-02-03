import java.util.ArrayList;

/**
 * Created by Kelv on 02/02/2016.
 */
public class Calculator {
    ArrayList<Double> numList;

    public Calculator(ArrayList<Double> list)
    {
        // constructor
        numList = list;
    }

    public boolean addNumber(Double num)
    {
        if(numList.size() <10)
        {
            numList.add(num);
            return true;
        }
        else
        {
            return false;
        }
    }

    public int getSize()
    {
        return numList.size();
    }

    public void calcAverage()
    {
        double sum = 0;
        for(int i = 0; i< numList.size(); i++)
        {
            sum += numList.get(i);
        }
        sum = sum / numList.size();
        System.out.println(sum);
    }

}
