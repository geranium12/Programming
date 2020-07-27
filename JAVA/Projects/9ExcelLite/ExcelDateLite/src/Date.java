import java.text.SimpleDateFormat;
import java.util.GregorianCalendar;

public class Date extends GregorianCalendar{
    private String stringDate;
    private boolean isUnchanged;

    public Date() {
        isUnchanged = true;
    }

    public Date(int day, int month, int year) {
        super(year, month - 1, day);
        isUnchanged = false;
        stringDate = this.toString();
    }

    public String getStringDate() {
        return stringDate;
    }

    public void setStringDate(String stringDate) {
        this.stringDate = stringDate;
    }

    @Override
    public String toString() {
        if (isUnchanged){
            return "";
        }
        SimpleDateFormat fmt = new SimpleDateFormat("dd.MM.yyyy");
        fmt.setCalendar(this);
        return fmt.format(this.getTime());
    }

}
