import java.awt.Color;
import java.awt.Component;

import javax.swing.BorderFactory;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.ListCellRenderer;

import javax.swing.border.Border;

public class MyJLabel extends JLabel
        implements ListCellRenderer<Country> {
    private Border border;

    MyJLabel() {
        setIconTextGap(100);
        setOpaque(true);
        border = BorderFactory.createLineBorder(Color.BLUE, 3);
    }

    @Override
    public Component getListCellRendererComponent(JList<? extends Country> list,
                                                  Country value,
                                                  int index,
                                                  boolean isSelected,
                                                  boolean cellHasFocus) {
        setIcon(value.getFlag());
        setFont(list.getFont());
        setEnabled(list.isEnabled());
        setText(value.getName());

        if (isSelected) {
            setBackground(list.getSelectionBackground());
            setBorder(border);
        } else {
            setBackground(list.getBackground());
            setBorder(null);
        }

        return this;
    }
}