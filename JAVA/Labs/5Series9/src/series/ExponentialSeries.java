package series;

public class  ExponentialSeries extends Series{
    public ExponentialSeries(double first, double coeff, int n) {
        super(first, coeff, n);
    }

    @Override
    public double calculateElement(int j) {
        return first * Math.pow(coeff, j - 1);
    }
}
