package equipment;

public enum HelmetType {
    FULL_FACE(1.9), MODULAR(2.6), OPEN_FACE(1.5);

    public final double cost;
    HelmetType(double cost) {
        this.cost = cost;
    }
}
