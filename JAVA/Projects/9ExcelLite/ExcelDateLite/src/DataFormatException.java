public class DataFormatException extends Exception {
    public DataFormatException() {
        super("Wrong data format (\"dd.mm.yyyy\")!");
    }

    public DataFormatException(String string) {
        super(string);
    }
}
