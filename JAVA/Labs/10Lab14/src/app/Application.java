package app;

import classes.MyInteger;
import classes.Student;
import exceptions.WrongInputException;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Map;
import java.util.TreeMap;

public class Application extends JFrame {
    private JPanel panel;
    private JPanel panelOutput;
    private JPanel panelFind;
    private JButton buttonInput;
    private JLabel labelCourseFind;
    private JLabel labelGroupFind;
    private JPanel panelInput;
    private JTextField textFieldCourseFind;
    private JTextField textFieldGroupFind;
    private JTextArea textAreaOutput;
    private JButton buttonFind;
    private JTextArea textAreaAllOutput;
    private JLabel labelOutput;
    private JTextField textFieldOutput;
    private JButton buttonOutput;

    private ArrayList<Student> arrayList = new ArrayList<>();
    private TreeMap<Integer, Student> treeMap = new TreeMap<>();
    public MyInteger state = new MyInteger(0);

    public Application() {
        this.setContentPane(panel);
        this.setTitle("App");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);

        buttonInput.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                state.setValue(0);
                InputDialog inputDialog = new InputDialog(arrayList, state);
                inputDialog.pack();
                inputDialog.setVisible(true);
                if (state.getValue() == 1) {
                    toEnable();
                    outputAllStudents();
                } else if (state.getValue() == 2) {
                    textAreaAllOutput.setText("");
                    toDisable();
                    toDisable2();
                }
            }
        });

        buttonFind.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    int courseFind = Integer.parseInt(textFieldCourseFind.getText());
                    if (courseFind <= 0) {
                        throw new WrongInputException("The entered course number is not correct!");
                    }
                    int groupFind = Integer.parseInt(textFieldGroupFind.getText());
                    if (groupFind <= 0) {
                        throw new WrongInputException("The entered group number is not correct!");
                    }
                    treeMap = findStudents(arrayList, courseFind, groupFind);
                    if (treeMap.isEmpty()) {
                        textAreaOutput.setText("There are no students such course and group in this list!");
                        toDisable2();
                    } else {
                        outputFoundStudents();
                        toEnable2();
                    }
                } catch (NumberFormatException ex) {
                    toDisable2();
                    JOptionPane.showMessageDialog(null, "Wrong input format!");
                } catch (Exception ex) {
                    textAreaOutput.setText(ex.getMessage());
                }
            }
        });

        buttonOutput.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    File file = new File(textFieldOutput.getText());
                    writeToXmlFile(file);
                    JOptionPane.showMessageDialog(null, "The data has been written successfully!");
                    //DomExample.writeToXmlFile(file, treeMap);
                } /*catch (ParserConfigurationException ex) {
                    toDisable();
                    toDisable2();
                    JOptionPane.showMessageDialog(null, ex.getMessage());
                }*/catch (IOException ex) {
                    JOptionPane.showMessageDialog(null, ex.getMessage());
                }
            }
        });
    }

    private void toEnable() {
        panelOutput.setEnabled(true);
        panelFind.setEnabled(true);
        labelCourseFind.setEnabled(true);
        labelGroupFind.setEnabled(true);
        textFieldCourseFind.setEnabled(true);
        textFieldGroupFind.setEnabled(true);
        textAreaOutput.setEnabled(true);
        textAreaAllOutput.setEnabled(true);
        buttonFind.setEnabled(true);
    }

    private void toDisable() {
        panelOutput.setEnabled(false);
        panelFind.setEnabled(false);
        labelCourseFind.setEnabled(false);
        labelGroupFind.setEnabled(false);
        textFieldCourseFind.setEnabled(false);
        textFieldGroupFind.setEnabled(false);
        textAreaOutput.setEnabled(false);
        textAreaAllOutput.setEnabled(false);
        buttonFind.setEnabled(false);
    }

    private void toEnable2() {
        labelOutput.setEnabled(true);
        textFieldOutput.setEnabled(true);
        buttonOutput.setEnabled(true);
    }

    private void toDisable2() {
        labelOutput.setEnabled(false);
        textFieldOutput.setEnabled(false);
        buttonOutput.setEnabled(false);
    }

    private TreeMap<Integer, Student> findStudents(ArrayList<Student> arrayList, int findCourse, int findGroup) {
        treeMap.clear();
        Iterator itr = arrayList.iterator();
        while (itr.hasNext()) {
            Student value = (Student) itr.next();
            if (value.getCourse() == findCourse && value.getGroup() == findGroup) {
                treeMap.put(value.getRecordBook(), value);
            }
        }
        return treeMap;
    }

    private void outputFoundStudents() {
        StringBuilder stringBuilder = new StringBuilder();
        Iterator itr = treeMap.entrySet().iterator();
        while (itr.hasNext()) {
            Map.Entry<Integer, Student> entry = (Map.Entry<Integer, Student>) itr.next();
            int key = entry.getKey();
            Student value = entry.getValue();
            stringBuilder.append(value);
            stringBuilder.append('\n');
        }
        textAreaOutput.setText(stringBuilder.toString());
    }

    private void outputAllStudents() {
        StringBuilder stringBuilder = new StringBuilder();
        Iterator itr = arrayList.iterator();
        while (itr.hasNext()) {
            Student value = (Student) itr.next();
            stringBuilder.append(value);
            stringBuilder.append('\n');
        }
        textAreaAllOutput.setText(stringBuilder.toString());
    }

    private String getXml() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("<students>");
        stringBuilder.append('\n');
        Iterator itr = treeMap.entrySet().iterator();
        while (itr.hasNext()) {
            Map.Entry<Integer, Student> entry = (Map.Entry<Integer, Student>) itr.next();
            Student value = entry.getValue();
            stringBuilder.append(value.toStringXML());
            stringBuilder.append('\n');
        }
        stringBuilder.append("</students>");
        return stringBuilder.toString();
    }

    private void writeToXmlFile(File file) throws IOException {
        FileWriter fileWriter = new FileWriter(file.getName());
        fileWriter.write(getXml());
        fileWriter.flush();
    }
}
