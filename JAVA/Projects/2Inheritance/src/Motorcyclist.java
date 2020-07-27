import equipment.*;

import java.util.ArrayList;
import java.util.Comparator;

public class Motorcyclist {
    private Helmet helmet;
    private Jacket jacket;
    private Gloves gloves;
    private Boots boots;
    private Pants pants;

    public Motorcyclist(Helmet helmet, Jacket jacket, Gloves gloves, Boots boots, Pants pants) {
        this.helmet = helmet;
        this.jacket = jacket;
        this.gloves = gloves;
        this.boots = boots;
        this.pants = pants;
    }

    public int countCost() {
        return helmet.countCost() + jacket.countCost() + gloves.countCost() + boots.countCost() + pants.countCost();
    }

    public void printEquipmentByWeight() {
        printArrayList(sortEquipmentByWeight(), false);
    }

    public void printEquipmentInPriceRange(int a, int b) {
        printArrayList(findEquipmentInPriceRange(a, b), true);
    }

    @Override
    public String toString() {
        return "Motorcyclist{" + "\n" +
                "helmet=" + helmet + "\n" +
                ", jacket=" + jacket + "\n" +
                ", gloves=" + gloves + "\n" +
                ", boots=" + boots + "\n" +
                ", pants=" + pants + "\n" +
                '}';
    }

    private ArrayList<Equipment> sortEquipmentByWeight() {
        ArrayList<Equipment> equipment = new ArrayList<>();
        equipment.add(helmet);
        equipment.add(jacket);
        equipment.add(gloves);
        equipment.add(boots);
        equipment.add(pants);
        equipment.sort(Comparator.comparingDouble(Equipment::getWeight));
        return equipment;
    }

    private ArrayList<Equipment> findEquipmentInPriceRange(int a, int b) {
        ArrayList<Equipment> equipment = new ArrayList<>();
        equipment.add(helmet);
        equipment.add(jacket);
        equipment.add(gloves);
        equipment.add(boots);
        equipment.add(pants);
        equipment.removeIf(equipment1 -> {
            if (equipment1.countCost() < a || equipment1.countCost() > b) {
                return true;
            } else {
                return false;
            }
        });
        return equipment;
    }

    private void printArrayList(ArrayList<Equipment> equipment, boolean f) {
        for (Equipment elem : equipment) {
            System.out.print(elem);
            if (f) {
                System.out.println(elem.countCost());
            } else {
                System.out.println();
            }
        }
    }
}
