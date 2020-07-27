package classes;

import java.util.Comparator;

public class SurnameComparator implements Comparator<Student> {
    public int compare(Student a, Student b) {
        return a.getSurname().compareTo(b.getSurname());
    }
}
