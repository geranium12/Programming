package equipment;

public enum UseType {
    SPORT(2.1), TOURING(2.5), URBAN(1.4);

    public final double cost;
    UseType(double cost) {
        this.cost = cost;
    }
}
