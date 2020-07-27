package classes;

import exceptions.EmptyFileException;
import exceptions.WrongInputException;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Student{
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

    public Student(int recordBook, String surname, int course, int group) throws WrongInputException {
        if (recordBook <= 0) {
            throw new WrongInputException("The entered number of record book is not correct!");
        }
        if (course <= 0) {
            throw new WrongInputException("The entered course is not correct!");
        }
        if (group <= 0) {
            throw new WrongInputException("The entered group is not correct!");
        }
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

    public static void readFromFile(File file, ArrayList<Student> arrayList) throws WrongInputException,
            EmptyFileException, FileNotFoundException {
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
