package exceptions;

public class EmptyFileException extends Exception {
    public EmptyFileException(String str) {
        super(str);
    }
}