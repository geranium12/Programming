package app;

import classes.DomExample;
import classes.MyInteger;
import classes.Student;
import classes.SurnameComparator;
import org.xml.sax.SAXException;

import javax.swing.*;
import javax.xml.parsers.ParserConfigurationException;
import java.awt.event.*;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class InputDialog extends JDialog {
    private JPanel contentPane;
    private JButton buttonCancel;
    private JPanel panelInput;
    private JLabel labelRecordBook;
    private JLabel labelCourse;
    private JLabel labelSurname;
    private JLabel labelGroup;
    private JLabel labelInputFile;
    private JTextField textFieldInputFile;
    private JButton buttonAddData;
    private JButton buttonInputData;
    private JTextField textFieldRecordBook;
    private JTextField textFieldCourse;
    private JTextField textFieldSurname;
    private JTextField textFieldGroup;

    public InputDialog(ArrayList<Student> arrayList, MyInteger state) {
        setContentPane(contentPane);
        setModal(true);
        getRootPane().setDefaultButton(buttonCancel);

        buttonAddData.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                onAddData(arrayList, state);
            }
        });

        buttonInputData.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                onInputData(arrayList, state);
            }
        });

        buttonCancel.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                onCancel();
            }
        });

        // call onCancel() when cross is clicked
        setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                onCancel();
            }
        });
        // call onCancel() on ESCAPE
        contentPane.registerKeyboardAction(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                onCancel();
            }
        }, KeyStroke.getKeyStroke(KeyEvent.VK_ESCAPE, 0), JComponent.WHEN_ANCESTOR_OF_FOCUSED_COMPONENT);
    }

    private void onAddData(ArrayList<Student> arrayList, MyInteger state) {
        try {
            int recordBook = Integer.parseInt(textFieldRecordBook.getText());
            String surname = textFieldSurname.getText();
            int course = Integer.parseInt(textFieldCourse.getText());
            int group = Integer.parseInt(textFieldGroup.getText());
            arrayList.add(new Student(recordBook, surname, course, group));
            arrayList.sort(new SurnameComparator());
            state.setValue(1);
        } catch (NumberFormatException ex) {
            state.setValue(0);
            JOptionPane.showMessageDialog(null, "Wrong input format!");
        } catch (Exception ex) {
            state.setValue(0);
            JOptionPane.showMessageDialog(null, ex.getMessage());
        }
        dispose();
    }

    private void onInputData(ArrayList<Student> arrayList, MyInteger state) {
        File file = new File(textFieldInputFile.getText());
        if (file.getName().contains("xml")) {
            onInputDataXml(arrayList, state);
        } else {
            onInputDataTxt(arrayList, state);
        }
        dispose();
    }

    private void onInputDataXml(ArrayList<Student> arrayList, MyInteger state) {
        try {
            File file = new File(textFieldInputFile.getText());
            DomExample.readFromXmlFile(file, arrayList);
            arrayList.sort(new SurnameComparator());
            state.setValue(1);
        } catch (IOException | ParserConfigurationException | SAXException ex) {
            state.setValue(2);
            JOptionPane.showMessageDialog(null, ex.getMessage());
        }
        dispose();
    }

    private void onInputDataTxt(ArrayList<Student> arrayList, MyInteger state) {
        try {
            File file = new File(textFieldInputFile.getText());
            Student.readFromFile(file, arrayList);
            arrayList.sort(new SurnameComparator());
            state.setValue(1);
        } catch (Exception ex) {
            state.setValue(2);
            JOptionPane.showMessageDialog(null, ex.getMessage());
        }
        dispose();
    }

    private void onCancel() {
        dispose();
    }
}
