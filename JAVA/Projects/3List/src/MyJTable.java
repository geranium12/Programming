import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.TableCellRenderer;
import java.awt.*;

public class MyJTable extends JTable {
    Border border;

    MyJTable() {
        setOpaque(true);
        border = BorderFactory.createLineBorder(Color.BLUE, 10);
        setBackground(Color.LIGHT_GRAY);
    }
}
