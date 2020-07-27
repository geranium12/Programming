package com.Series;

public class Series {
    static class WrongCountException extends Exception {
        WrongCountException() { }
        WrongCountException(String msg) {
            super(msg);
        }
    }

    // (-1)^k * x^k / (k + 1) ^ 2
    static double countSum(double x, double eps) {
        double res = 0;
        int k = 1;
        double elem1 = -1. * x / ((k + 1) * (k + 1));
        k++;
        res += elem1;
        //System.out.printf("%.6f\n", elem1);
        if (Math.abs(res) < eps)
        {
            return res;
        }
        double elem2 = elem1 * (-1. * x * k * k) / ((k + 1) * (k + 1));
        res += elem2;
        k++;
        //System.out.printf("%.6f\n", elem2);
        while (Math.abs(elem1 - elem2) > eps)
        {
            elem1 = elem2;
            elem2 *= (-1. * x * k * k) / ((k + 1) * (k + 1));
            res += elem2;
            //System.out.printf("%.6f\n", elem2);
            k++;
        }
        res -= elem2;
        return res;
    }

    public static void main(String[] args) {
        /*
        Scanner in = new Scanner(System.in);
        double x = in.nextDouble();
        double eps = in.nextDouble();

        double d = countSum(x, eps);
        System.out.println(d);
        */
        try {
            if (args.length != 2) {
                throw new WrongCountException("The number of arguments should equal 2!");
            }
            if (Math.abs(Double.parseDouble(args[0])) > 1) {
                    throw new NumberFormatException("The Series does not converge!");
            }
                if (Double.parseDouble(args[1]) <= 0) {
                    throw new NumberFormatException("invalid eps - the second argument!");
            }
            System.out.printf("Sum = %.6f", countSum(Double.parseDouble(args[0]),
                    Double.parseDouble(args[1])));
        }
        catch (WrongCountException ex) {
            System.out.println(ex.getMessage());
        }
        catch (NumberFormatException ex) {
            System.out.println("Wrong format of input data - " + ex.getMessage());
        }
    }
}