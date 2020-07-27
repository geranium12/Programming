package series;

public class LinearSeries extends Series {
    public LinearSeries(double first, double coeff, int n) {
        super(first, coeff, n);
    }

    @Override
    public double calculateElement(int j) {
        return first + coeff * (j - 1);
    }
}
