import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class Application extends JFrame {
    private static final int MIN_SPEED = 1;
    private static final int MAX_SPEED = 10;
    private static final int INITIAL_SPEED = 1;
    static final int SIZE = 450;

    private enum Direction {CLOCKWISE, ANTICLOCKWISE}

    private JSlider slider;
    private JComboBox comboBox;
    private boolean isClockwise = true;

    Application() {
        setLayout(new BorderLayout());

        JPanel panel = new JPanel();
        panel.setPreferredSize(new Dimension(SIZE, SIZE / 9));
        add(panel, BorderLayout.SOUTH);

        slider = new JSlider(JSlider.HORIZONTAL, MIN_SPEED, MAX_SPEED, INITIAL_SPEED);
        slider.setMajorTickSpacing(1);
        slider.setMinorTickSpacing(1);
        slider.setPaintTicks(true);
        slider.setPaintLabels(true);
        panel.add(slider);

        comboBox = new JComboBox(Direction.values());
        panel.add(comboBox);
        comboBox.addActionListener(e -> {
            Direction direction = (Direction) comboBox.getSelectedItem();
            switch (direction) {
                case CLOCKWISE:
                    isClockwise = true;
                    break;
                case ANTICLOCKWISE:
                    isClockwise = false;
            }
        });

        ImagePanel imagePanel = new ImagePanel(this);
        add(imagePanel, BorderLayout.CENTER);

        JButton openImage = new JButton("Open Image");
        panel.add(openImage);
        openImage.addActionListener(e -> {
            JFileChooser fileChooser = new JFileChooser();
            int result = fileChooser.showDialog(null, "Open file");
            if (result == JFileChooser.APPROVE_OPTION) {
                File file = fileChooser.getSelectedFile();
                try {
                    BufferedImage image = ImageIO.read(file);
                    imagePanel.setImage(image);
                } catch (IOException ex) {
                    System.out.println(ex.getMessage());
                }
            }
        });

        setVisible(true);
        pack();
        setMinimumSize(new Dimension(SIZE, SIZE));
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    public boolean isClockwise() {
        return isClockwise;
    }

    public int getSpeed() {
        return slider.getValue();
    }

    public static void main(String args[]) {
        Application app = new Application();
    }
}