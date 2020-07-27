package app;

import classes.MyInteger;
import classes.Student;
import exceptions.WrongInputException;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.*;

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

    private ArrayList<Student> arrayList = new ArrayList<>();
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
                    TreeMap<Integer, Student> treeMap = findStudents(arrayList, courseFind, groupFind);
                    if (treeMap.isEmpty()) {
                        textAreaOutput.setText("There are no students such course and group in this list!");
                    } else {
                        outputFoundStudents(treeMap);
                    }
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(null, "Wrong input format!");
                } catch (Exception ex) {
                    textAreaOutput.setText(ex.getMessage());
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

    private TreeMap<Integer, Student> findStudents(ArrayList<Student> arrayList, int findCourse, int findGroup) {
        TreeMap<Integer, Student> treeMap = new TreeMap<>();
        Iterator itr = arrayList.iterator();
        while (itr.hasNext()) {
            Student value = (Student) itr.next();
            if (value.getCourse() == findCourse && value.getGroup() == findGroup) {
                treeMap.put(value.getRecordBook(), value);
            }
        }
        return treeMap;
    }

    private void outputFoundStudents(TreeMap<Integer, Student> treeMap) {
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
}
