import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Application extends JFrame {
    private JList<Country> list;
    private JScrollPane scrollPane;
    private JTabbedPane tabbedPane;

    private JPanel panel1;
    private JPanel panel2;

    private JTable table;
    private JTextField country, price, description;
    private JButton  addTrip;
    private boolean flag;

    private final static int WIDTH = 800;
    private final static int HEIGHT = 400;

    private final static Object[][] TOUR_PACKAGES = {
            {new Country("Montenegro").getFlag(), "Don’t say it too loudly, but Montenegro might just be the most " +
                    "beautiful of all the Balkan countries.", 500, false},
            {new Country("Georgia").getFlag(), "Georgia is a treasure trove of Orthodox architecture!", 1000, false},
            {new Country("France").getFlag(), "France is the most popular tourist destination in the world. " +
                    "There are many reasons why so many people enjoy visiting the diverse country, including the " +
                    "natural beauty, the amazing climate, outdoor recreational activities such as golf courses, " +
                    "art museums and galleries and so much more.", 999, false},
            {new Country("Germany").getFlag(),
                    "Germany is a country rich in natural beauty. Between the North Sea and Baltic coasts in the " +
                            "north and the peaks of the Alps in the south lie extremely diverse landscapes, with " +
                            "everything from wide expanses of river and lakeland scenery, hilly uplands and densely " +
                            "wooded regions to agricultural plains and industrial conurbations.", 5000, false}
    };
    private final static Object[] NAMES_OF_COLUMNS = {"Country", "Description", "Price", "Activate trip"};
    private final static Object[] SUM_ROW = {"", "Total price:", 0, false};

    Application() {

        // 1 JLIST
        Map<String, Country> countries = new TreeMap<>();

        try (Scanner scanner = new Scanner(new File("src\\countries.txt"))) {
            while (scanner.hasNext()) {
                String line = scanner.nextLine();
                String[] str = line.split("—");
                Country country = new Country(str[0], str[1]);
                countries.put(country.getName(), country);
            }

        } catch (FileNotFoundException ex) {
            System.out.println(ex.getMessage());
            return;
        }

        tabbedPane = new JTabbedPane();
        DefaultListModel<Country> countryDefaultListModel = new DefaultListModel<>();
        countryDefaultListModel.addAll(countries.values());
        list = new JList<>();
        MyJLabel label = new MyJLabel();
        list.addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                Country country = list.getSelectedValue();
                label.setText(country.getName() + " - " + country.getCapital());
                label.setIcon(country.getFlag());
            }
        });
        list.setModel(countryDefaultListModel);
        list.setCellRenderer(new MyJLabel());

        scrollPane = new JScrollPane(list);
        scrollPane.setVisible(true);
        scrollPane.setPreferredSize(new Dimension(WIDTH, HEIGHT));

        panel1 = new JPanel();
        panel1.setPreferredSize(new Dimension(WIDTH, HEIGHT));
        panel1.add(label);
        panel1.add(scrollPane);

        tabbedPane.add(panel1, "Countries List");

        // 2 JTABLE

        flag = false;

        panel2 = new JPanel();
        panel2.setPreferredSize(new Dimension(WIDTH, HEIGHT));
        table = new MyJTable();
        country = new JTextField();
        price = new JTextField();
        description = new JTextField();
        addTrip = new JButton("Add trip");

        JPanel panelForTextFields = new JPanel(new GridLayout(3, 4));

        panelForTextFields.add(new JLabel("Country:"));
        panelForTextFields.add(new JLabel("Description:"));
        panelForTextFields.add(new JLabel("Price:"));

        panelForTextFields.add(country);
        panelForTextFields.add(description);
        panelForTextFields.add(price);
        panelForTextFields.add(addTrip);


        JScrollPane scrollPane = new JScrollPane(table);
        scrollPane.setVisible(true);
        scrollPane.setPreferredSize(new Dimension(WIDTH, HEIGHT - HEIGHT / 4));
        panel2.add(scrollPane);
        panel2.add(panelForTextFields);
        tabbedPane.add(panel2, "Tour packages");

        DefaultTableModel tableModel = new DefaultTableModel(TOUR_PACKAGES, NAMES_OF_COLUMNS) {
            // FOR RENDERING IMAGES AND CHECKBOXES
            @Override
            public Class<?> getColumnClass(int column) {
                return getValueAt(0, column).getClass();
            }

            @Override
            public boolean isCellEditable(int row, int column) {
                if (column != 0 && row != getRowCount() - 1) {
                    return true;
                } else {
                    return false;
                }
            }
        };

        tableModel.addRow(SUM_ROW);
        table.setRowHeight(HEIGHT / 4);
        table.setModel(tableModel);

        // GET DESCRIPTION
        table.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                JTable target = (JTable) e.getSource();
                int row = target.getSelectedRow();
                int column = target.getSelectedColumn();
                if (column == 1) {
                    JOptionPane.showMessageDialog(null, TOUR_PACKAGES[row][column]);
                }
            }
        });

        addTrip.addActionListener(e -> {
            try {
                int priceField = Integer.parseInt(price.getText());
                Country country = new Country(Application.this.country.getText());
                Object[] obj = new Object[]{country.getFlag(), description.getText(), priceField, false};
                tableModel.insertRow(tableModel.getRowCount() - 1, obj);
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(null, ex.getMessage() + "\n Number " +
                        "Format Exception!");
            }
        });

        // COUNT TOTAL SUM
        tableModel.addTableModelListener(e -> {
            if (!flag) {
                int sum = 0;
                for (int i = 0; i < tableModel.getRowCount() - 1; i++) {
                    if ((Boolean) tableModel.getValueAt(i, 3)) {
                        sum += (int) tableModel.getValueAt(i, 2);
                    }
                }
                flag = true;
                tableModel.setValueAt(sum, tableModel.getRowCount() - 1, 2);
                flag = false;
            }
        });

        setResizable(false);
        setContentPane(tabbedPane);
        setVisible(true);
        pack();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public static void main(String[] args) {
        Application app = new Application();
    }
}

