import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TextArea;
import javafx.scene.layout.FlowPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main extends Application {
    private final static String CHOICES[] = {"Natural number", "Integer", "Floating-point number", "Date", "Time",
            "E-mail"};
    final static Pattern NATURAL_NUMBER = Pattern.compile("[+]?[1-9]([0-9]*)");
    final static Pattern INTEGER = Pattern.compile("[+-]?(0|[1-9]([0-9]*))");
    final static Pattern FLOATING_POINT_NUMBER = Pattern.compile("[-+]?(([0-9]*[.]?[0-9]+)|([0-9]+[.]?[0-9]*))" +
            "([eE][-+]?[0-9]+)?");
    final static Pattern DATE = Pattern.compile("(31[- /.](0[13578]|1[02])|30[- /.](0[1|3-9]|1[0-2])|(0\\d|[12]\\d)" +
            "[- /.](0[1-9]|1[012]))[- /.](2020|20[01]\\d|1\\d\\d\\d|0\\d\\d[1-9]|0\\d[1-9]\\d|0[1-9]\\d\\d)");
    final static Pattern TIME = Pattern.compile("([0-1]\\d|2[0-3])(:[0-5]\\d){2}");
    final static Pattern EMAIL = Pattern.compile("^([-0-9a-z]+[.])*([-0-9a-z]{1,})@" +
            "([-a-z]{1,}\\.){1,2}[-a-z]{2,}", Pattern.CASE_INSENSITIVE);

    public static void main(String[] args) {
        Application.launch(args);
    }

    @Override
    public void start(Stage stage) {
        TextArea textArea = new TextArea();
        textArea.setPrefSize(150, 25);
        ObservableList<String> observableList = FXCollections.observableArrayList(CHOICES);
        ComboBox<String> comboBox = new ComboBox<>(observableList);
        comboBox.setValue(CHOICES[0]);

        Circle circle = new Circle(0, 0, 10);
        circle.setFill(Color.RED);

        comboBox.setOnAction(event -> {
            if (isComboBoxCurrentValue(comboBox.getValue(), textArea.getText())) {
                circle.setFill(Color.GREEN);
            } else {
                circle.setFill(Color.RED);
            }
        });

        FlowPane root = new FlowPane(textArea, comboBox, circle);
        textArea.textProperty().addListener((observable, oldValue, newValue) -> {
            if (isComboBoxCurrentValue(comboBox.getValue(), newValue)) {
                circle.setFill(Color.GREEN);
            } else {
                circle.setFill(Color.RED);
            }
        });

        Scene scene = new Scene(root, 400,40);
        stage.setScene(scene);
        stage.setResizable(false);
        stage.setTitle("TypeCheck");
        stage.show();
    }

    public static boolean isComboBoxCurrentValue(String comboBoxCurrentValue, String value) {
        Matcher m;
        switch (comboBoxCurrentValue) {
            case "Natural number":
                m = NATURAL_NUMBER.matcher(value);
                return m.matches();
            case "Integer":
                m = INTEGER.matcher(value);
                return m.matches();
            case "Floating-point number":
                m = FLOATING_POINT_NUMBER.matcher(value);
                return m.matches();
            case "Date":
                m = DATE.matcher(value);
                return m.matches();
            case "Time":
                m = TIME.matcher(value);
                return m.matches();
            case "E-mail":
                m = EMAIL.matcher(value);
                return m.matches();
        }
        return false;
    }
}