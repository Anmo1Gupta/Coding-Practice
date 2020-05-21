import java.util.Scanner;

public class DataAnalze2 {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        // Get sample size
        int sampleSize;

        // Tell the user to print out the sample size
        System.out.println("Please enter the sample size:");

        // in order to print out we need to print the input next statement
        sampleSize = input.nextInt();

        // final int numberTrials = 4;

        int[] sample1 = new int[sampleSize];
        int[] sample2 = new int[sampleSize];
        int[] sample3 = new int[sampleSize];
        int[] sample4 = new int[sampleSize];

        int i;
        System.out.println("\nEnter numbers for Trial 1");

        for (i = 0; i < sampleSize; ++i) {
            System.out.print("Enter sample #" + (i + 1) + ": ");
            sample1[i] = input.nextInt();

        }

        System.out.println("\nEnter numbers for Trial 2");

        for (i = 0; i < sampleSize; ++i) {
            System.out.print("Enter sample #" + (i + 1) + ": ");
            sample2[i] = input.nextInt();

        }

        System.out.println("\nEnter numbers for Trial 3");

        for (i = 0; i < sampleSize; ++i) {
            System.out.print("Enter sample #" + (i + 1) + ": ");
            sample3[i] = input.nextInt();

        }

        System.out.println("\nEnter numbers for Trial 4");

        for (i = 0; i < sampleSize; ++i) {
            System.out.print("Enter sample #" + (i + 1) + ": ");
            sample4[i] = input.nextInt();

        }

        System.out.println("\n\tSample #\t\tTrial 1\t\tTrial 2\t\tTrial 3\t\tTrial 4");
        for (i = 0; i < sampleSize; i++) {
            System.out.println("\t" + (i + 1) + "\t\t\t" + sample1[i] + "\t\t" + sample2[i] + "\t\t" + sample3[i]
                    + "\t\t" + sample4[i] + "\t\t");
        }

        System.out.println("\t-------------------------------------------------------------------------------");

        System.out.print("Averages:");
        // error, nothing that will run inside the machine
        // for loop

        double sumSample1 = 0;
        double avgSample1 = 0;
        double Min = 0;
        double Max = 0;
        for (i = 0; i < sampleSize; ++i) {
            sumSample1 += sample1[i];
        }
        avgSample1 = sumSample1 / sampleSize;
        System.out.print("\t\t\t" + avgSample1);
        input.close();
        // System.out.println("Min average: " Min);
        // System.out.println("Max averge: " Max);

        double sumSample2 = 0;
        double avgSample2 = 0;
        for (i = 0; i < sampleSize; ++i) {
            sumSample2 += sample2[i];
        }
        avgSample2 = sumSample2 / sampleSize;
        System.out.print("\t\t" + avgSample2);

        double sumSample3 = 0;
        double avgSample3 = 0;
        for (i = 0; i < sampleSize; ++i) {
            sumSample3 += sample3[i];
        }
        avgSample3 = sumSample3 / sampleSize;
        System.out.print("\t\t" + avgSample3);

        double sumSample4 = 0;
        double avgSample4 = 0;
        for (i = 0; i < sampleSize; ++i) {
            sumSample4 += sample4[i];
        }
        avgSample4 += sumSample4 / sampleSize;
        System.out.print("\t\t" + avgSample4);

        
        
        
        
        //Creating a new array of all the averages
        double[] avgSample = new double[4];
        avgSample[0] = avgSample1;
        avgSample[1] = avgSample2;
        avgSample[2] = avgSample3;
        avgSample[3] = avgSample4;

        //For calculating Maximum of All Averages
        Max = avgSample[0]; //Initializing variable 'Max' with the first value of array 'avgSample' or avgSample1
        for(i=0; i < avgSample.length; i++)
        {
            if(Max < avgSample[i]) //Comparing with subsequent avgSamples to find the maximum average
            {
                Max = avgSample[i];
            }
            else
            {
                continue;
            }
        }

        //For calculating Minimum of All Averages
        Min = avgSample[0]; //Initializing variable 'Min' with the first value of array 'avgSample' or avgSample1
        for(i=0; i < avgSample.length; i++)
        {
            if(Min > avgSample[i]) //Comparing with subsequent avgSamples to find the minimum average
            { 
                Min = avgSample[i];
            }
            else
            {
                continue;
            }
        }


        //Printing the minimum and maximum averages
        System.out.println("\n\nMin Average: " + Min);

        System.out.println("Max Average: " + Max);


        //Using If-else to find out how closely the trials match
        if( Max == Min ) 
        {
            System.out.println("\nThe trials match EXACTLY!");
        }
        else if( Max < (2*Min) ) //If the trials are less than 2 times the Minimum average (i.e. 2*Min)
        {
            System.out.println("\nThe trials concur with each other!");
        }
        else //Else if the difference between the Max and the Min Averages is too high
        {
            System.out.println("\nThe trials do not concur!");
        }

    }

}