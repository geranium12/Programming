package equipment;

public class Jacket extends Equipment {
    private FabricType fabricType;
    private SeasonType seasonType;

    public Jacket(String brand, Gender gender, Size size, UseType useType, Color color, double weight,
                  FabricType fabricType, SeasonType seasonType) {
        super(brand, gender, size, useType, color, weight);
        this.fabricType = fabricType;
        this.seasonType = seasonType;
    }

    @Override
    public String toString() {
        return "Jacket{" + super.toString() +
                "fabricType=" + fabricType +
                ", seasonType=" + seasonType +
                '}';
    }

    @Override
    public int countCost() {
        return (int)(40 * seasonType.cost * fabricType.cost);
    }
}
