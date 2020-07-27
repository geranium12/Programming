package series;

import java.io.FileWriter;
import java.io.IOException;

public abstract class Series {

    protected double first;
    protected double coeff;
    protected int n;

    public Series(double first, double coeff, int n) {
        this.first = first;
        this.coeff = coeff;
        this.n = n;
    }

    public double getFirst() {
        return first;
    }

    public double getCoeff() {
        return coeff;
    }

    public int getN() {
        return n;
    }

    public abstract double calculateElement(int j);

    public double sum() {
        double sum = first;
        for (int i = 2; i < n + 1; i++) {
            sum += calculateElement(i);
        }
        return sum;
    }

    @Override
    public String toString() {
        String res = new String(Double.toString(first));
        for (int i = 2; i < n + 1; i++) {
            res += " " + calculateElement(i);
        }
        return res;
    }

    public void saveToFile(String fileName) throws IOException {
        FileWriter output = new FileWriter(fileName);
        output.append(first + " ");
        for (int i = 2; i < n + 1; i++) {
            output.append(calculateElement(i) +  " ");
        }
        output.close();
    }
}
