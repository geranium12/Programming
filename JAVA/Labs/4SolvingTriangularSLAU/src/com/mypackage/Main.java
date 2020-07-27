package com.mypackage;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

import static java.lang.Double.NEGATIVE_INFINITY;
import static java.lang.Double.POSITIVE_INFINITY;
import static java.lang.Math.abs;

class WrongInputData extends Exception {
    WrongInputData(String msg) {
        super(msg);
    }
}

class WrongDeterminant extends Exception {
    WrongDeterminant(String msg) {
        super(msg);
    }
}

class Matrix {
    private double[][] mat;
    private double[] f;

    public Matrix() {
        mat = new double[0][0];
        f = new double[0];
    }

    private void checkFile(File inputFile) throws WrongInputData, IOException {
        Scanner in = new Scanner(inputFile);
        if (!in.hasNextInt()) {
            throw new WrongInputData("The amount of rows and columns should be INTEGER!");
        }
        int n = in.nextInt();
        if (n <= 0) {
            throw new WrongInputData("Wrong number of input elements! (1st line)");
        }
        int i = 0;
        while (in.hasNextDouble()) {
            in.nextDouble();
            i++;
        }
        if (i < n * (n + 1)) {
            throw new WrongInputData("You need more input data!");
        }
        if (i > n * (n + 1)) {
            throw new WrongInputData("You need less input data!");
        }
        if (in.hasNext()) {
            throw new WrongInputData("Your file contains something else!");
        }

    }

    // Input data from file
    public void inputMatrix(File inputFile) throws IOException {
        try {
            checkFile(inputFile);
        } catch (WrongInputData ex) {
            System.out.println(ex.getMessage());
            return;
        }

        Scanner in = new Scanner(inputFile);
        int n;
        n = in.nextInt();
        mat = new double[n][n];
        int i = 0;
        while (i < n * n) {
            mat[i / n][i % n] = in.nextDouble();
            i++;
        }
        f = new double[n];
        i = 0;
        while (i < n) {
            f[i] = in.nextDouble();
            i++;
        }
    }

    // check if we can apply the method of Gauss
    private boolean isDetOkay() {
        int n = f.length;
        double eps = 10e-6;
        for (int i = 0; i < n; i++) {
            if (abs(mat[i][i]) < eps)
                return false;
        }
        return true;
    }

    // Gaussian Elimination
    double[] gaussianElimination() throws WrongDeterminant {
        int n = f.length;
        double[] res = new double[f.length];
        for (int j = 0; j < n; j++) {
            // search max index
            int maxIndex = j;
            for (int k = j + 1; k < mat.length; k++) {
                if (abs(mat[k][j]) > abs(mat[maxIndex][j])) {
                    maxIndex = k;
                }
            }

            // swap rows
            if (maxIndex != j) {
                double[] tempMat = mat[maxIndex];
                mat[maxIndex] = mat[j];
                mat[j] = tempMat;
                double temp = f[maxIndex];
                f[maxIndex] = f[j];
                f[j] = temp;
            }
        }
        if (!isDetOkay()) {
            throw new WrongDeterminant("The determinant of this matrix = 0!\nThe solution cannot be found!");
        }

        for (int i = n - 1; i >= 0; i--) {
            res[i] = f[i] / mat[i][i];
            for (int k = i - 1; k >= 0; k--) {
                f[k] -= mat[k][i] * res[i];
            }
            try {
                Double a = res[i];
                if (a.equals(Double.NaN) || res[i] == NEGATIVE_INFINITY || res[i] == POSITIVE_INFINITY)
                    throw new Exception("Gaussian elimination cannot be applied!");
            } catch (Exception ex) {
                System.out.println(ex.getMessage());
                return new double[0];
            }
        }
        return res;
    }
}

public class Main {

    public static void main(String[] args) {
        File inputFile = new File("input2.txt");
        Matrix mat = new Matrix();
        try {
            mat.inputMatrix(inputFile);
        } catch (IOException ex) {
            System.out.println(ex.getMessage());
            return;
        }
        try {
            double res[] = mat.gaussianElimination();
            if (res.length != 0) {
                System.out.println("RESULT X VECTOR:");
                for (int i = 0; i < res.length; i++) {
                    System.out.printf("%d\t%.2f\n", i, res[i]);
                }
            }
        } catch (WrongDeterminant ex) {
            System.out.println(ex.getMessage());
        }
    }
}