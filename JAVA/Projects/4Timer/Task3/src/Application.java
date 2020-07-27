import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.labels.PieSectionLabelGenerator;
import org.jfree.chart.labels.StandardPieSectionLabelGenerator;
import org.jfree.chart.plot.PiePlot;
import org.jfree.data.general.DefaultPieDataset;
import org.jfree.data.general.PieDataset;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import javax.swing.*;
import java.awt.*;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Application extends JFrame {

    Application() {
        ArrayList<MovieTypeData> arrayList = readJSON("src\\movie_types.json");

        DefaultPieDataset pieDataset = new DefaultPieDataset();
        for (MovieTypeData movie : arrayList) {
            pieDataset.setValue(movie.getMovieType(), movie.getValue());
        }

        JFreeChart pieChart = ChartFactory.createPieChart("MovieType Diagram",
                pieDataset, true, false, false);

        PiePlot piePlot = (PiePlot) pieChart.getPlot();
        piePlot.setSectionOutlinesVisible(false);
        piePlot.setLabelFont(new Font("SansSerif", Font.PLAIN, 11));
        piePlot.setNoDataMessage("No data available");
        piePlot.setLabelGap(0.02);

        PieSectionLabelGenerator labelGenerator = new StandardPieSectionLabelGenerator(
                "{0} - {2}");
        piePlot.setLabelGenerator(labelGenerator);
        
        JPanel panel = new JPanel(new BorderLayout());
        panel.add(new ChartPanel(pieChart), BorderLayout.CENTER);
        panel.validate();
        add(panel);

        setPreferredSize(new Dimension(640, 480));
        pack();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
    }

    @SuppressWarnings("unchecked")
    public static ArrayList<MovieTypeData> readJSON(String fileName) {

        ArrayList<MovieTypeData> resultList = new ArrayList<>();
        JSONParser jsonParser = new JSONParser();

        try (FileReader reader = new FileReader(fileName)) {
            Object obj = jsonParser.parse(reader);
            JSONArray movieTypesArray = (JSONArray) obj;

            movieTypesArray.forEach(o -> {
                JSONObject movie = (JSONObject) o;
                String movieType = (String) movie.get("movieType");
                Long value = (Long) movie.get("value");
                if (value < 0) {
                    try {
                        throw new WrongDataException("WrongDataException! Values should be >= 0!");
                    } catch (WrongDataException e) {
                        JOptionPane.showMessageDialog(null, e.getMessage());
                    }
                }
                resultList.add(new MovieTypeData(movieType, value));
            });

        } catch (IOException e) {
            JOptionPane.showMessageDialog(null, "IOException! " + e.getMessage());
        } catch (ParseException e) {
            JOptionPane.showMessageDialog(null, "ParseException! " + e.getMessage());
        }
        return resultList;
    }

    public static void main(String[] args) {
        Application app = new Application();
    }
}
