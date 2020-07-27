import javax.swing.*;
import javax.swing.table.TableCellEditor;
import java.awt.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.GregorianCalendar;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.zip.DataFormatException;

public class CellEditor extends AbstractCellEditor implements TableCellEditor {
    private JTable table;
    private Date date;
    private int row, column;
    private JTextField text = new JTextField();
    private boolean trigger = true;
    private int flag = 0;

    final static Pattern DATE = Pattern.compile(
            "(((0[1-9]|[12]\\d|3[01])\\.(0[13578]|1[02])\\.((19|[2-9]\\d)\\d{2}))|" +
                    "((0[1-9]|[12]\\d|30)\\.(0[13456789]|1[012])\\.((19|[2-9]\\d)\\d{2}))|" +
                    "((0[1-9]|1\\d|2[0-8])\\.02\\.((19|[2-9]\\d)\\d{2}))|" +
                    "(29\\.02\\.((1[6-9]|[2-9]\\d)" +
                    "(0[48]|[2468][048]|[13579][26]))))");
    final static Pattern CELL = Pattern.compile("[A-Z][1-9]+[0-9]*");

    @Override
    public Component getTableCellEditorComponent(JTable table, Object value, boolean isSelected, int row, int column) {
        flag = 0;
        this.table = table;
        date = (Date) value;
        this.row = row;
        this.column = column;
        if (date != null) {
            text.setText(date.getStringDate());
        } else {
            text.setText("");
        }
        return text;
    }

    @Override
    public Object getCellEditorValue() {
        try {
            if (text.getText().equals("")) {
                return new Date();
            }
            date = parseFormula(text.getText());
            date.setStringDate(text.getText());
            table.getModel().setValueAt(date, row, column);
        } catch (SeriesFormatException | DataFormatException | MaxMinException e) {
            if (flag <= 1) {
                JOptionPane.showMessageDialog(null, e.getMessage());
            }
        }

        if (trigger && date != null){
            trigger = false;
            for (int i = 0; i < table.getRowCount(); i++) {
                for (int j = 1; j < table.getColumnCount(); j++) {
                    Date date = (Date) table.getValueAt(i, j);
                    if (date != null) {
                        table.editCellAt(i, j);
                    }
                }
            }
            for (int i = 0; i < table.getRowCount(); i++) {
                for (int j = 1; j < table.getColumnCount(); j++) {
                    Date date = (Date) table.getValueAt(i, j);
                    if (date != null) {
                        table.editCellAt(i, j);
                    }
                }
            }
            trigger = true;
        }
        return date;
    }

    Date parseFormula(String string) throws SeriesFormatException, DataFormatException, MaxMinException {
        Matcher matcher = DATE.matcher(string);
        if (matcher.matches()) {
            return parseDateFromStr(string);
        } else {
            if (string.charAt(0) == '=') {
                if (string.length() < 3) {
                    flag++;
                    throw new DataFormatException("Wrong data format (\"dd.mm.yyyy\")!");
                }
                if (string.charAt(1) == 'm') {
                    if ((string.substring(1, 5)).equals("min(")) {
                        return parseMaxMinFormula(string.substring(5, string.length() - 1), true);
                    }
                    if ((string.substring(1, 5)).equals("max(")) {
                        return parseMaxMinFormula(string.substring(5, string.length() - 1), false);
                    }
                } else {
                    return parseSeries(string.substring(1));
                }
            } else {
                flag++;
                throw new DataFormatException();
            }
        }
        return null;
    }

    Date parseDateFromStr(String string) {
        int day = Integer.parseInt(string.substring(0, 2));
        int month = Integer.parseInt(string.substring(3, 5));
        int year = Integer.parseInt(string.substring(6));
        return new Date(day, month, year);
    }

    Date parseSeries(String string) throws DataFormatException, SeriesFormatException {
        try {
            if (string.charAt(0) >= 'A' && string.charAt(0) <= 'Z') {
                Date date = parseFromCell(string.substring(0, 2));

                if (string.length() == 2) {
                    return date;
                }
                if (string.charAt(2) == '-') {
                    System.out.println(date);
                    date.add(GregorianCalendar.DAY_OF_MONTH, -1 * Integer.parseInt(string.substring(3)));
                    System.out.println(date);
                    return date;
                } else if (string.charAt(2) == '+') {
                    date.add(GregorianCalendar.DAY_OF_MONTH, Integer.parseInt(string.substring(3)));
                    return date;
                } else {
                    flag++;
                    throw new SeriesFormatException();
                }
            } else {
                if (string.length() < 10) {
                    flag++;
                    throw new SeriesFormatException();
                }
                Matcher matcher = DATE.matcher(string.substring(0, 10));
                if (matcher.matches()) {
                    Date newDate = parseDateFromStr(string.substring(0, 10));
                    if (string.length() == 10) {
                        return newDate;
                    }
                    if (string.charAt(10) == '-') {
                        newDate.add(GregorianCalendar.DAY_OF_MONTH, -1 * Integer.parseInt(string.substring(11)));
                        return newDate;
                    } else if (string.charAt(10) == '+') {
                        newDate.add(GregorianCalendar.DAY_OF_MONTH, Integer.parseInt(string.substring(11)));
                        return newDate;
                    } else {
                        flag++;
                        throw new SeriesFormatException();
                    }
                } else {
                    flag++;
                    throw new SeriesFormatException();
                }
            }
        } catch (NumberFormatException ex) {
            throw new SeriesFormatException();
        }
    }

    Date parseFromCell(String string) throws DataFormatException {
        int column = (int) (string.charAt(0)) - 64;
        int row = Integer.parseInt(string.substring(1)) - 1;

        if (column == this.column && row == this.row) {
            flag++;
            throw new DataFormatException("Wrong data format in cell: (" + (row + 1) + ", " + column + ")" + "!");
        }

        if (column >= table.getColumnCount() || row >= table.getRowCount()) {
            flag++;
            throw new DataFormatException("Out of bounds!");
        }

        Date newDate = (Date) table.getValueAt(row, column);
        if (newDate == null) {
            flag++;
            throw new DataFormatException("Wrong data format in cell: (" + (row + 1) + ", " + column + ")" + "!");
        }
        return parseDateFromStr(newDate.toString());
    }

    Date parseMaxMinFormula(String string, boolean flag) throws DataFormatException, MaxMinException {
        Matcher matcher = DATE.matcher(string);
        ArrayList<Date> list = new ArrayList<>();
        String s;
        while (matcher.find()) {
            s = matcher.group();
            list.add(parseDateFromStr(matcher.group()));
        }
        matcher = CELL.matcher(string);
        while (matcher.find()) {
            s = matcher.group();
            list.add(parseFromCell(s));
        }
        if (list.isEmpty()) {
            this.flag++;
            throw new MaxMinException();
        }
        if (flag) {
            return Collections.min(list);
        } else return Collections.max(list);
    }
}