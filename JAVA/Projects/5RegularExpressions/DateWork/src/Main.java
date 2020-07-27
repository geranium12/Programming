import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.Scene;
import javafx.scene.control.ListView;
import javafx.scene.control.TextArea;
import javafx.scene.layout.FlowPane;
import javafx.stage.Stage;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import static java.lang.Math.max;

public class Main extends Application {
    private static final String TEXT = "dskfgj 03.05.1000 dfjgh lskdjgh skldjg slkdghlkdjhg kdjgh.,d fhgd lgjhkgjh " +
            "18.11.1994dk hgkld ghk ghlfjh lsg; 29.02.1969oeiu ndk j cn, b, nd vbenli01.12.1542dg dkg dkjg h01.01.999";
    private TextArea textArea;
    private ObservableList<String> observableArrayList;
    private ListView<String> listView;

    public static void main(String[] args) {
        Application.launch(args);
    }

    @Override
    public void start(Stage stage) {
        textArea = new TextArea();
        textArea.setWrapText(true);
        textArea.setPrefSize(450, 400);
        textArea.setText(TEXT);
        textArea.textProperty().addListener((observableValue, s, t1) -> {
            ArrayList<String> dates = checkDates(textArea);
            observableArrayList = FXCollections.observableArrayList(dates);
            listView.setItems(observableArrayList);
        });

        observableArrayList = FXCollections.observableArrayList(checkDates(textArea));
        listView = new ListView<>(observableArrayList);
        listView.setPrefSize(200, 400);

        FlowPane root = new FlowPane(textArea, listView);
        Scene scene = new Scene(root, textArea.getPrefWidth() + listView.getPrefWidth(),
                max(listView.getPrefHeight(), textArea.getPrefHeight()));

        stage.setScene(scene);
        stage.setResizable(false);
        stage.setTitle("DateList");
        stage.show();
    }

    public static ArrayList<String> checkDates(TextArea textArea) {
        ArrayList<String> dates = new ArrayList<>();
        String text = textArea.getText();
        Pattern pattern = Pattern.compile("(31[- /.](0[13578]|1[02])|30[- /.](0[1|3-9]|1[0-2])|(0\\d|[12]\\d)[- /.](0" +
                "[1-9]|1[012]))[- /.](2020|20[01]\\d|1\\d\\d\\d|0\\d\\d[1-9]|0\\d[1-9]\\d|0[1-9]\\d\\d)");
        Matcher matcher = pattern.matcher(text);
        while (matcher.find()) {
            int start = matcher.start();
            int end = matcher.end();
            String date = text.substring(start, end);
            dates.add(date);
        }
        return dates;
    }
}