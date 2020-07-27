package equipment;

public enum FabricType {
    LEATHER(1.7), TEXTILES(1.2);

    public final double cost;
    FabricType(double cost) {
        this.cost = cost;
    }
}
