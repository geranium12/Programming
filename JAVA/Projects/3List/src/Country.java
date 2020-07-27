import javax.swing.*;
import java.nio.file.Path;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Country implements Comparable<Country>{
    private String name;
    private String capital;
    private ImageIcon flag;

    Country(String name) {
        this.name = name;
        this.flag = getImage();
    }

    Country(String name, String capital) {
        this.name = name;
        this.capital = capital;
        this.flag = getImage();
    }

    private ImageIcon getImage() {
        String str = this.name;
        str = str.toLowerCase();
        str = str.replace(" ", "");
        ImageIcon icon = new ImageIcon("src\\plain\\flag_" + str + ".png");
        return icon;
    }

    public String getName() {
        return name;
    }

    public String getCapital() {
        return capital;
    }

    public ImageIcon getFlag() {
        return flag;
    }

    @Override
    public int compareTo(Country o) {
        return this.name.compareTo(o.name);
    }
}
