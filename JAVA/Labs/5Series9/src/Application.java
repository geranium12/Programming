import exceptions.WrongInputException;
import series.ExponentialSeries;
import series.LinearSeries;
import series.Series;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

public class Application extends JFrame {

    Series series;

    private JButton buttonInput;
    private JPanel panel;
    private JPanel panelInput;
    private JPanel panelChoice;
    private JLabel labelFirst;
    private JTextField textFieldFirst;
    private JLabel labelCoefficient;
    private JTextField textFieldCoefficient;
    private JLabel labelN;
    private JTextField textFieldInputN;
    private JRadioButton radioButtonLinearSeries;
    private JRadioButton radioButtonExponentialSeries;
    private JTextField textFieldOutput;
    private JLabel labelFileName;
    private JLabel labelTypeOfSeries;
    private JButton buttonSave;
    private JLabel labelNPrint;
    private JTextField textFieldPrint;
    private JPanel panelPrint;
    private JTextField textFieldInputNPrint;
    private JButton buttonPrint;
    private JTextField textFieldSum;
    private JButton buttonSum;

    public Application() {

        ButtonGroup buttonGroup = new ButtonGroup();
        buttonGroup.add(radioButtonLinearSeries);
        buttonGroup.add(radioButtonExponentialSeries);

        buttonInput.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    String text = textFieldFirst.getText();
                    double first = Double.parseDouble(text);
                    text = textFieldCoefficient.getText();
                    double coeff = Double.parseDouble(text);
                    text = textFieldInputN.getText();
                    int n = Integer.parseInt(text);
                    if (n <= 0) {
                        throw new WrongInputException("Number of elements should be > 0!");
                    }
                    if (radioButtonLinearSeries.isSelected()) {
                        series = new LinearSeries(first, coeff, n);
                    } else {
                        series = new ExponentialSeries(first, coeff, n);
                    }
                    JOptionPane.showMessageDialog(null, "The data has been entered successfully!");
                } catch (NullPointerException ex) {
                    JOptionPane.showMessageDialog(null, "Enter all data!");
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(null, "Enter all right data! (only double to the first, " +
                            "coefficient fields and integer to the n field)");
                } catch (WrongInputException ex) {
                    JOptionPane.showMessageDialog(null, ex.getMessage());
                }
            }
        });

        buttonSave.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    series.saveToFile(textFieldOutput.getText());
                    JOptionPane.showMessageDialog(null, "The data has been written successfully!");
                } catch (NullPointerException ex) {
                    JOptionPane.showMessageDialog(null, "Series is not defined! " +
                            "(enter all data and press button Input)");
                } catch (IOException ex) {
                    JOptionPane.showMessageDialog(null, "File error!");
                }
            }
        });

        buttonPrint.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    if (series == null) {
                        throw new NullPointerException("Enter all need data and press button Input!");
                    }
                    int n = Integer.parseInt(textFieldInputNPrint.getText());
                    if (n <= 0) {
                        throw new WrongInputException("Number of printed elements should be > 0!");
                    }
                    StringBuilder str = new StringBuilder(series.getFirst() + " ");
                    for (int i = 2; i < n + 1; i++) {
                        str.append(series.calculateElement(i) + " ");
                    }
                    textFieldPrint.setText(str.toString());
                } catch (NullPointerException ex) {
                    JOptionPane.showMessageDialog(null, ex.getMessage());
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(null, "Enter number of elements to print!");
                } catch (WrongInputException ex) {
                    JOptionPane.showMessageDialog(null, ex.getMessage());
                }

            }
        });

        radioButtonLinearSeries.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    if (series != null) {
                        series = new LinearSeries(series.getFirst(), series.getCoeff(), series.getN());
                    } else throw new WrongInputException("Enter data in text fields and press button Input!");
                } catch (WrongInputException ex) {
                    JOptionPane.showMessageDialog(null, ex.getMessage());
                }
            }
        });

        radioButtonExponentialSeries.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    if (series != null) {
                        series = new ExponentialSeries(series.getFirst(), series.getCoeff(), series.getN());
                    } else throw new WrongInputException("Enter data in text fields and press button Input!");
                } catch (WrongInputException ex) {
                    JOptionPane.showMessageDialog(null, ex.getMessage());
                }
            }
        });
        buttonSum.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    textFieldSum.setText(Double.toString(series.sum()));
                } catch (NullPointerException ex) {
                    JOptionPane.showMessageDialog(null, "Series is not defined! " +
                            "(enter all data and press button Input)");
                }
            }
        });
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Series");
        frame.setContentPane(new Application().panel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        Dimension dimension = toolkit.getScreenSize();
        frame.setBounds(dimension.width / 5, dimension.height / 5, 645, 300);
        frame.setVisible(true);
    }

}
