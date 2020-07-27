import com.classes.Computer;
import com.tree.Tree;

public class Main {
    public static void main(String[] args) {

        System.out.println("TREE OF INTEGERS");
        Tree<Integer> tree = new Tree();
        try {
            tree.add(42);
            tree.add(17);
            tree.add(65);
            tree.add(39);
            tree.add(24);
            tree.add(52);
            tree.add(90);
            tree.add(103);
            tree.add(84);
            tree.add(88);
            tree.add(86);
            tree.add(87);
            tree.add(2);
            tree.add(3);
            tree.add(-5);
            tree.add(-28);
            tree.add(89);

            tree.preoderTraversal();

            tree.delete(65);
            tree.delete(-5);
            tree.delete(24);

            tree.preoderTraversal();

        } catch (NullPointerException ex) {
            System.out.println(ex.getMessage());
        }

        System.out.println("TREE OF COMPUTERS");
        Computer pc1 = new Computer("HP", "Core i5", 3.2, 800, 14);
        Computer pc2 = new Computer("Lenovo", "Core i3", 3.6, 1200, 24);
        Computer pc3 = new Computer("ASUS", "Core i5", 2.8, 900, 19);
        Computer pc4 = new Computer("Acer", "Core i7", 4.4, 1500, 17.3);
        Computer pc5 = new Computer("Apple", "Core i7", 3.8, 2200, 17.3);
        Tree<Computer> tree2 = new Tree();
        try {
            tree2.add(pc1);
            tree2.add(pc2);
            tree2.add(pc3);
            tree2.add(pc4);
            tree2.add(pc5);

            System.out.println("Search(pc5) " + tree2.search(pc5));
            System.out.println("NumberOfNodes " + tree2.numberOfNodes());
            tree2.inorderTraversal();
            tree2.preoderTraversal();
            tree2.postorderTraversal();

            tree2.delete(pc1);
            tree2.delete(pc2);
            tree2.delete(pc3);
            tree2.delete(pc4);
            tree2.delete(pc5);
        } catch (NullPointerException ex) {
            System.out.println(ex.getMessage());
        }
    }
}
