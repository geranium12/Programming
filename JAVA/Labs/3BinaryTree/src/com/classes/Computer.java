package com.classes;

public class Computer implements Comparable<Computer>{

    private String producer;
    private String processor;
    private double clockFrequency;
    private double price;
    private double displaySize;

    public Computer(String producer, String processor, double clockFrequency, double price, double displaySize) {
        this.producer = producer;
        this.processor = processor;
        this.clockFrequency = clockFrequency;
        this.price = price;
        this.displaySize = displaySize;
    }

    @Override
    public int compareTo(Computer o) {
        return Double.compare(clockFrequency, o.clockFrequency);
    }

    @Override
    public String toString() {
        return producer;
    }
}
