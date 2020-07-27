import org.xml.sax.SAXException;

import javax.xml.parsers.ParserConfigurationException;
import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Motorcyclist motorcyclist = null;
        Scanner scanner = new Scanner(System.in);
        boolean f = false;
        int i = 1;
        while (i != 0) {
            System.out.println("Enter:" + "\n" +
                    "1. Read from file." + "\n" +
                    "2. Print equipments cost." + "\n" +
                    "3. Print equipments by weight." + "\n" +
                    "4. Print equipment in price range." +"\n" +
                    "0. Exit.");
            i = scanner.nextInt();
            switch(i) {
                case (1) : {
                    try {
                        motorcyclist = Dom.readFromXmlFile(new File("input.xml"));
                        f = true;
                    } catch(ParserConfigurationException | SAXException | IOException ex) {
                        System.out.println(ex.getMessage());
                    }
                    break;
                }
                case (2) : {
                    if (f) {
                        System.out.println(motorcyclist.countCost());
                    } else {
                        System.out.println("Read from file!");
                    }
                    break;
                }
                case (3) : {
                    if (f) {
                        motorcyclist.printEquipmentByWeight();
                    } else {
                        System.out.println("Read from file!");
                    }
                    break;
                }
                case (4) : {
                    if (f) {
                        System.out.println("Enter price range:");
                        int a = scanner.nextInt();
                        int b = scanner.nextInt();
                        motorcyclist.printEquipmentInPriceRange(a, b);
                    } else {
                        System.out.println("Read from file!");
                    }
                }
            }
        }
    }
}
