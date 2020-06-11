import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.io.File;

class ReadLines
{

    public static void main(String[] args) {
	
	if (args.length != 1) 
	{
	    System.out.println("You didn't provide an input file name.");
	} 
	else 
	{
	    List<String> list = new ArrayList<String>();

	    try 
	    {
		Scanner sc = new Scanner(new File(args[0]));
		while (sc.hasNextLine()) 
		{
		    String line = sc.nextLine();
		    list.add(line);
		}
	    } 
	    catch (Exception e) 
	    {
		System.out.println("Error: " + e.getMessage());
	    }

	}
    }
}
