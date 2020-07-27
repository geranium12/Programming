package classes;

public class OpticalDiskDrive {
    private int readSpeed;
    private int writeSpeed;
    private boolean hasDVD;

    public OpticalDiskDrive(int readSpeed, int writeSpeed, boolean hasDVD) {
        this.readSpeed = readSpeed;
        this.writeSpeed = writeSpeed;
        this.hasDVD = hasDVD;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        OpticalDiskDrive that = (OpticalDiskDrive) o;
        return readSpeed == that.readSpeed &&
                writeSpeed == that.writeSpeed &&
                hasDVD == that.hasDVD;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 31 * hash + readSpeed;
        hash = 31 * hash + writeSpeed;
        hash = 31 * hash + (hasDVD ? 1 : 0);
        return hash;
    }

    @Override
    public String toString() {
        return "OpticalDiskDrive{" +
                "readSpeed=" + readSpeed +
                ", writeSpeed=" + writeSpeed +
                ", hasDVD=" + hasDVD +
                '}';
    }
}
