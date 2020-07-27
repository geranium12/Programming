package classes;

import enums.DimensionHardDiskDrive;
import enums.InterfaceHardDiskDrive;

public class HardDiskDrive {
    private InterfaceHardDiskDrive interfaceHardDiskDrive;
    private int capacity;
    private DimensionHardDiskDrive dimensionHardDiskDrive;
    private double randomAccessTime;

    public HardDiskDrive(InterfaceHardDiskDrive interfaceHardDiskDrive, int capacity, DimensionHardDiskDrive
            dimensionHardDiskDrive, double randomAccessTime) {
        this.interfaceHardDiskDrive = interfaceHardDiskDrive;
        this.capacity = capacity;
        this.dimensionHardDiskDrive = dimensionHardDiskDrive;
        this.randomAccessTime = randomAccessTime;
    }

    public int getCapacity() {
        return capacity;
    }

    public InterfaceHardDiskDrive getInterfaceHardDiskDrive() {
        return interfaceHardDiskDrive;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        HardDiskDrive that = (HardDiskDrive) o;
        return capacity == that.capacity &&
                Double.compare(that.randomAccessTime, randomAccessTime) == 0 &&
                interfaceHardDiskDrive == that.interfaceHardDiskDrive &&
                dimensionHardDiskDrive == that.dimensionHardDiskDrive;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 31 * hash + interfaceHardDiskDrive.ordinal();
        hash = 31 * hash + capacity;
        hash = 31 * hash + dimensionHardDiskDrive.ordinal();
        hash = 32 * hash + (int) (randomAccessTime * 1000);
        return hash;
    }

    @Override
    public String toString() {
        return "HardDiskDrive{" +
                "interfaceHardDiskDrive=" + interfaceHardDiskDrive +
                ", capacity=" + capacity +
                ", dimensionHardDiskDrive=" + dimensionHardDiskDrive +
                ", randomAccessTime=" + randomAccessTime +
                '}';
    }
}
