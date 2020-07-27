package equipment;

public abstract class Equipment {
    private String brand;
    private Gender gender;
    private Size size;
    private UseType useType;
    private Color color;
    private double weight;

    public Equipment(String brand, Gender gender, Size size, UseType useType, Color color, double weight) {
        this.brand = brand;
        this.gender = gender;
        this.size = size;
        this.useType = useType;
        this.color = color;
        this.weight = weight;
    }

    public double getWeight() {
        return weight;
    }

    @Override
    public String toString() {
        return "Equipment{" +
                "brand='" + brand + '\'' +
                ", gender=" + gender +
                ", size=" + size +
                ", useType=" + useType +
                ", color=" + color +
                ", weight=" + weight +
                '}';
    }

    public abstract int countCost();
}
