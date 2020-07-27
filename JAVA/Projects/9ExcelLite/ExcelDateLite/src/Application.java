import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.util.Vector;

public class Application extends JFrame {
    private final static int INITIAL_ROWS_NUMBER = 50;
    private final static int INITIAL_WINDOW_WIDTH = 640;
    private final static int INITIAL_WINDOW_HEIGHT = 480;

    Application() {
        DefaultTableModel tableModel = new DefaultTableModel() {
            public Class getColumnClass(int column) {
                return Date.class;
            }
            public boolean isCellEditable(int row, int column) {
                if (column == 0)
                    return false;
                else
                    return super.isCellEditable(row, column);
            }
        };
        JTable table = new JTable(tableModel);
        table.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
        JScrollPane scrollPane = new JScrollPane(table);

        Vector<Integer> rowNumbers = new Vector<>(INITIAL_ROWS_NUMBER);
        for (int i = 0; i < rowNumbers.capacity(); i++) {
            rowNumbers.add(i + 1);
        }

        tableModel.addColumn("", rowNumbers);

        table.setRowHeight(30);
        for (int i = 65; i < 91; i++) {
            tableModel.addColumn((char) i);
            table.getColumnModel().getColumn(i - 65).setPreferredWidth(100);
        }

        table.setDefaultEditor(Date.class, new CellEditor());

        table.setValueAt(new Date(03, 05, 2001), 0, 4);
        table.setValueAt(new Date(01, 12, 2000), 1, 2);
        table.setValueAt(new Date(03, 07, 1972), 3, 4);
        table.setValueAt(new Date(16, 01, 1971), 2, 4);
        table.setValueAt(new Date(17, 01, 1943), 1, 4);
        table.setValueAt(new Date(24, 01, 1939), 1, 1);
        table.setValueAt(new Date(24, 04, 2001), 1, 3);
        table.setValueAt(new Date(31, 01, 1989), 0, 1);
        table.setValueAt(new Date(28, 02, 1994), 0, 2);
        table.setValueAt(new Date(03, 05, 2020), 0, 3);

        setContentPane(scrollPane);
        scrollPane.setPreferredSize(new Dimension(INITIAL_WINDOW_WIDTH, INITIAL_WINDOW_HEIGHT));
        setPreferredSize(new Dimension(INITIAL_WINDOW_WIDTH, INITIAL_WINDOW_HEIGHT));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
        pack();
        setExtendedState(MAXIMIZED_BOTH);
    }

    public static void main(String[] args) {
        new Application();
    }
}
