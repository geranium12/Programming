package equipment;

public enum HelmetMaterialType {
    FIBRE(1.3), THERMOPLASTIC_RESIN(1.8);

    public final double cost;
    HelmetMaterialType(double cost) {
        this.cost = cost;
    }
}
