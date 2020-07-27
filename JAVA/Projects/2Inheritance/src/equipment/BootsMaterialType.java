package equipment;

public enum BootsMaterialType {
    DRYSTAR(1.5), GORE_TEX(1.8), OTHER(2);

    public final double cost;
    BootsMaterialType(double cost) {
        this.cost = cost;
    }
}
