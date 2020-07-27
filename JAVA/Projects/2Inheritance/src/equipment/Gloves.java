package equipment;

public class Gloves extends Equipment {
    private FabricType fabricType;
    private SeasonType seasonType;
    private boolean isWaterproof;

    public Gloves(String brand, Gender gender, Size size, UseType useType, Color color, double weight,
                  FabricType fabricType, SeasonType seasonType, boolean isWaterproof) {
        super(brand, gender, size, useType, color, weight);
        this.fabricType = fabricType;
        this.seasonType = seasonType;
        this.isWaterproof = isWaterproof;
    }

    @Override
    public String toString() {
        return "Gloves{" + super.toString() +
                "fabricType=" + fabricType +
                ", seasonType=" + seasonType +
                ", isWaterproof=" + isWaterproof +
                '}';
    }

    @Override
    public int countCost() {
        return (int)(20 * fabricType.cost * seasonType.cost * (isWaterproof ? 1.4 : 1.0));
    }
}
