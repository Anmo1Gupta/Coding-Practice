import java.util.ArrayList;
import java.io.*;
import java.util.Scanner;;

class Aquarium {
    private int size; // the board is size x size
    private ArrayList<Integer> columnTotals; // the totals at the top of the columns, left to right
    private ArrayList<Integer> rowTotals; // the totals at the left of the rows, top to bottom
    private File file; // the file of aquarium information

    public Aquarium(String filename) throws FileNotFoundException{

        file = new File(filename);
        try {
            Scanner s = new Scanner(file); //Using Scanner to take input from the file

            String line = s.nextLine(); //Reading First Line of the file which contains the column nos.

            //Splitting the first line of the file using .split(" ") function and one-by-one adding it to the Arraylist columnTotals
            for(String val : line.split(" ")){
                columnTotals.add(Integer.parseInt(val));
            }
            line = s.nextLine(); //Using the same method to read the second line of the file into the same variable
            //Again splitting the line using.split(" ") function and one-by-one adding it to the Arraylist rowTotals
            for(String val : line.split(" ")){
                rowTotals.add(Integer.parseInt(val));
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

    }
}