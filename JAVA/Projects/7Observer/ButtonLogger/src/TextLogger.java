import javafx.scene.text.Text;

public class TextLogger extends Text implements Observer {
    @Override
    public void update(Object o) {
        if (getText().length() > 300) {
            setText("");
        }
        String string = "The user has pressed " + (String) o + ".\n";
        setText(getText() + string);
    }
}
