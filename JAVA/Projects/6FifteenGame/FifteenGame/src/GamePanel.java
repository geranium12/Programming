import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;
import java.util.Random;

import javax.swing.*;

public class GamePanel extends JPanel {
    private final static int SIZE = 2;
    private int nbTiles;
    private int[] tiles;
    private int tileSize;
    private int emptyCell;
    private boolean isGameOver;

    private BufferedImage[] icons;
    private BufferedImage bufferedImage;

    public GamePanel(BufferedImage buffIm) {
        setBackground(Color.WHITE);
        setForeground(Color.BLUE);
        setFont(new Font("Verdana", Font.BOLD, 80 / SIZE));

        bufferedImage = buffIm;

        nbTiles = SIZE * SIZE - 1;
        tiles = new int[SIZE * SIZE];
        tileSize = bufferedImage.getWidth() / SIZE;
        isGameOver = true;

        addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                if (isGameOver) {
                    start();
                } else {
                    int x = e.getX();
                    int y = e.getY();
                    int i1 = y / tileSize;
                    int j1 = x / tileSize;
                    int i2 = emptyCell / SIZE;
                    int j2 = emptyCell % SIZE;
                    int dir = 0;
                    if (j1 == j2 && Math.abs(i1 - i2) > 0) {
                        dir = (i1 - i2) > 0 ? SIZE : -SIZE;
                    } else if (i1 == i2 && Math.abs(j1 - j2) > 0) {
                        dir = (j1 - j2) > 0 ? 1 : -1;
                    }
                    if (dir != 0) {
                        do {
                            int newBlankPos = emptyCell + dir;
                            if (x < 0 || x > bufferedImage.getWidth() || y < 0 || y > bufferedImage.getWidth())
                                return;
                            tiles[emptyCell] = tiles[newBlankPos];
                            emptyCell = newBlankPos;
                        } while (emptyCell != i1 * SIZE + j1);
                        tiles[emptyCell] = 0;
                    }
                    isGameOver = isSolved();
                }
                repaint();
            }
        });

        start();
    }

    private void start() {
        do {
            restart();
            random();
        } while (!isSolvable());

        isGameOver = false;
    }

    private void restart() {
        icons = new BufferedImage[SIZE * SIZE];
        for (int i = 0; i < SIZE * SIZE; i++) {
            icons[i] = bufferedImage.getSubimage(
                    (i % SIZE) * tileSize, (i / SIZE) * tileSize, tileSize, tileSize);
        }
        for (int i = 0; i < tiles.length; i++) {
            tiles[i] = (i + 1) % tiles.length;
        }
        emptyCell = tiles.length - 1;
    }

    private void random() {
        int n = nbTiles;
        Random random = new Random();
        while (n > 1) {
            int r = random.nextInt(n--);
            int tmp = tiles[r];
            tiles[r] = tiles[n];
            tiles[n] = tmp;
        }
    }

    private boolean isSolvable() {
        int inversions = 0;
        for (int i = 0; i < nbTiles; i++) {
            for (int j = 0; j < i; j++) {
                if (tiles[j] > tiles[i])
                    inversions++;
            }
        }
        return inversions % 2 == 0;
    }

    private boolean isSolved() {
        if (tiles[tiles.length - 1] != 0)
            return false;
        for (int i = nbTiles - 1; i >= 0; i--) {
            if (tiles[i] != i + 1)
                return false;
        }
        return true;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        for (int i = 0; i < tiles.length; i++) {
            int x = (i % SIZE) * tileSize;
            int y = (i / SIZE) * tileSize;
            if (tiles[i] == 0) {
                if (isGameOver) {
                    g.setColor(Color.BLUE);
                    g.drawString("Done!", x + tileSize / 7, y + tileSize / 2);
                }
                continue;
            }
            g.drawImage(icons[tiles[i] - 1], x, y, null);
        }
    }
}