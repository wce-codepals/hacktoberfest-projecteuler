import java.io.*;
import java.util.*;

public class scores {
    public static void main() throws FileNotFoundException {
        File f = new File("p022_names.txt");
        Scanner scan = new Scanner(f).useDelimiter(","); // delimiter takes every name splitting at every comma
        
        ArrayList<String> list = new ArrayList<String>();
        
        // reads in names and strips them of "
        while (scan.hasNext()) {
            list.add(scan.next().replace("\"", "").toLowerCase());
        }
        
        System.out.println(getNameScore(list));
    }
    
    public static int getNameScore(ArrayList<String> list) {
        // alphabetical order
        Collections.sort(list);
        
        // for alphabetical value
        String[] ref = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
        
        int count = 0;
        
        for (int i = 0; i < list.size(); i++) { // every word
            int wordCount = 0;
            for (int j = 0; j < list.get(i).length(); j++) { // every letter
                for (int k = 0; k < ref.length; k++) { // compares letter against every string in ref[]
                    if (list.get(i).substring(j,j+1).equals(ref[k])) {
                        wordCount += k+1; // because arrays start at 0
                    }
                }
            }
            
            count += wordCount * (i+1); // because arrays start at 0
        }
        
        return count;
    }
}
