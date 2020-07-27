package classes;

import exceptions.EmptyFileException;
import exceptions.WrongInputException;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Student {
    int recordBook;
    String surname;
    int course;
    int group;

    public int getRecordBook() {
        return recordBook;
    }

    public void setRecordBook(int recordBook) {
        this.recordBook = recordBook;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public int getCourse() {
        return course;
    }

    public void setCourse(int course) {
        this.course = course;
    }

    public int getGroup() {
        return group;
    }

    public void setGroup(int group) {
        this.group = group;
    }

    public Student(int recordBook, String surname, int course, int group) {
        this.recordBook = recordBook;
        this.surname = surname;
        this.course = course;
        this.group = group;
    }

    @Override
    public String toString() {
        return "Student{" +
                "recordBook=" + recordBook +
                ", surname='" + surname + '\'' +
                ", course=" + course +
                ", group=" + group +
                '}';
    }

    public String toStringXML() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("<student recordBook = \"" + this.recordBook + "\">");
        stringBuilder.append('\n');
        stringBuilder.append("<surname>" + this.getSurname() + "</surname>");
        stringBuilder.append('\n');
        stringBuilder.append("<course>" + this.getCourse() + "</course>");
        stringBuilder.append('\n');
        stringBuilder.append("<group>" + this.getGroup() + "</group>");
        stringBuilder.append('\n');
        stringBuilder.append("</student>");
        return stringBuilder.toString();
    }

    public static void readFromFile(File file, ArrayList<Student> arrayList) throws WrongInputException,
            EmptyFileException, FileNotFoundException {
        arrayList.clear();
        Scanner scanner = new Scanner(file);
        int recordBook;
        String surname;
        int course;
        int group;
        if (!scanner.hasNext()) {
            throw new EmptyFileException("File " + file.getName() + " is empty!");
        }
        while (scanner.hasNext()) {
            recordBook = scanner.nextInt();
            surname = scanner.next();
            course = scanner.nextInt();
            group = scanner.nextInt();
            arrayList.add(new Student(recordBook, surname, course, group));
        }
    }
}
