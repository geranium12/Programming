package equipment;

public class Helmet extends Equipment {
    private HelmetType helmetType;
    private HelmetMaterialType helmetMaterialType;

    public Helmet(String brand, Gender gender, Size size, UseType useType, Color color, double weight,
                  HelmetType helmetType, HelmetMaterialType helmetMaterialType) {
        super(brand, gender, size, useType, color, weight);
        this.helmetType = helmetType;
        this.helmetMaterialType = helmetMaterialType;
    }

    @Override
    public String toString() {
        return "Helmet{" + super.toString() +
                "helmetType=" + helmetType +
                ", helmetMaterialType=" + helmetMaterialType +
                '}';
    }

    @Override
    public int countCost() {
        return (int)(80 * helmetType.cost * helmetMaterialType.cost);
    }
}
