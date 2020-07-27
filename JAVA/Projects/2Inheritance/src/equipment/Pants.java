package equipment;

public class Pants extends Equipment {
    private FabricType fabricType;
    private SeasonType seasonType;
    private StyleType styleType;

    public Pants(String brand, Gender gender, Size size, UseType useType, Color color, double weight,
                 FabricType fabricType, SeasonType seasonType, StyleType styleType) {
        super(brand, gender, size, useType, color, weight);
        this.fabricType = fabricType;
        this.seasonType = seasonType;
        this.styleType = styleType;
    }

    @Override
    public String toString() {
        return "Pants{" + super.toString() +
                "fabricType=" + fabricType +
                ", seasonType=" + seasonType +
                ", styleType=" + styleType +
                '}';
    }

    @Override
    public int countCost() {
        return (int)(50 * fabricType.cost * seasonType.cost);
    }
}
