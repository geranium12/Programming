package equipment;

public enum SeasonType {
    ALL_YEAR(2.2), SUMMER(1.6), WINTER(2.0);

    public final double cost;
    SeasonType(double cost) {
        this.cost = cost;
    }
}
