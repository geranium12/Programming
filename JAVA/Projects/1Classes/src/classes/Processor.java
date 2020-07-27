package classes;

public class Processor {
    private String producer;
    private int cache;
    private int coresNumber;
    private int threadsNumber;
    private int clockRate;

    public Processor(String producer, int cache, int coresNumber, int threadsNumber, int clockRate) {
        this.producer = producer;
        this.cache = cache;
        this.coresNumber = coresNumber;
        this.threadsNumber = threadsNumber;
        this.clockRate = clockRate;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Processor processor = (Processor) o;
        return cache == processor.cache &&
                coresNumber == processor.coresNumber &&
                threadsNumber == processor.threadsNumber &&
                clockRate == processor.clockRate &&
                producer.equals(processor.producer);
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 31 * hash + producer.hashCode();
        hash = 31 * hash + cache;
        hash = 31 * hash + coresNumber;
        hash = 31 * hash + threadsNumber;
        hash = 31 * hash + clockRate;
        return hash;
    }

    @Override
    public String toString() {
        return "Processor{" +
                "producer='" + producer + '\'' +
                ", cache=" + cache +
                ", coresNumber=" + coresNumber +
                ", threadsNumber=" + threadsNumber +
                ", clockRate=" + clockRate +
                '}';
    }
}
