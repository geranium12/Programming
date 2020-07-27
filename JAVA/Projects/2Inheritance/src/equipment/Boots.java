package equipment;

public class Boots extends Equipment {
    private SeasonType seasonType;
    private BootsMaterialType materialType;

    public Boots(String brand, Gender gender, Size size, UseType useType, Color color, double weight,
                 SeasonType seasonType, BootsMaterialType materialType) {
        super(brand, gender, size, useType, color, weight);
        this.seasonType = seasonType;
        this.materialType = materialType;
    }

    @Override
    public String toString() {
        return "Boots{" + super.toString() +
                "seasonType=" + seasonType +
                ", materialType=" + materialType +
                '}';
    }

    @Override
    public int countCost() {
        return (int)(100 * seasonType.cost * materialType.cost);
    }
}
