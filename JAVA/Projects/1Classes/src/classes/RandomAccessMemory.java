package classes;

import enums.RandomAccessMemoryType;

public class RandomAccessMemory {
    private RandomAccessMemoryType randomAccessMemoryType;
    private int capacity;
    private int speed;

    public RandomAccessMemory(RandomAccessMemoryType randomAccessMemoryType, int capacity, int speed) {
        this.randomAccessMemoryType = randomAccessMemoryType;
        this.capacity = capacity;
        this.speed = speed;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        RandomAccessMemory that = (RandomAccessMemory) o;
        return capacity == that.capacity &&
                speed == that.speed &&
                randomAccessMemoryType == that.randomAccessMemoryType;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 31 * hash + randomAccessMemoryType.ordinal();
        hash = 31 * hash + capacity;
        hash = 31 * hash + speed;
        return hash;
    }

    @Override
    public String toString() {
        return "RandomAccessMemory{" +
                "randomAccessMemoryType=" + randomAccessMemoryType +
                ", capacity=" + capacity +
                ", speed=" + speed +
                '}';
    }
}
