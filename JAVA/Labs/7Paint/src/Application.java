import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.CompoundBorder;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.plaf.metal.MetalScrollBarUI;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.File;
import java.io.IOException;

public class Application extends JFrame {

    private JPanel panel = new JPanel();
    private JPanel panelButtons = new JPanel();
    private PanelPaint panelPaint = new PanelPaint();
    private JFileChooser fileChooser = new JFileChooser();
    private JColorChooser colorChooser = new JColorChooser();
    private JDialog dialog;
    private JScrollPane scrollPane = new JScrollPane(panelPaint, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
    private JButton buttonOpen = new JButton("Open image");
    private JButton buttonSave = new JButton("Save image");
    private JButton buttonChooseColor = new JButton("Choose color");
    private JButton buttonClear = new JButton("Clear field");
    private Color color = Color.red;
    private int xPrev, yPrev, xCur, yCur;
    private Toolkit toolkit = Toolkit.getDefaultToolkit();
    private Dimension dimension = toolkit.getScreenSize();
    private FileNameExtensionFilter filter = new FileNameExtensionFilter(
            "JPG & JPEG & PNG & GIF Images", "jpg", "jpeg", "png", "gif");

    private Font defaultFont = new Font("Gill Sans MT",Font.BOLD,14);
    private Color textColor = Color.decode("#000000");
    private Color backgroundColor = Color.decode("#ccffff");
    private Border line, margin, compound;



    Application() {

        // FRAME
        this.setTitle("Paint");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);

        //PANEL
        panel.setLayout(new BorderLayout());
        panel.setVisible(true);

        // PANEL PAINT
        panelPaint.setPreferredSize(dimension);
        panelPaint.setVisible(true);
        panelPaint.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
                xPrev = e.getX();
                yPrev = e.getY();
            }
        });
        panelPaint.addMouseMotionListener(new MouseAdapter() {
            @Override
            public void mouseDragged(MouseEvent e) {
                int xCur = e.getX();
                int yCur = e.getY();

                Graphics g = panelPaint.getGraphics();
                Graphics bufferedImage = panelPaint.getBufferedImage().getGraphics();

                g.setColor(color);
                bufferedImage.setColor(color);

                g.drawLine(xPrev, yPrev, xCur, yCur);
                bufferedImage.drawLine(xPrev, yPrev, xCur, yCur);

                xPrev = xCur;
                yPrev = yCur;
            }
        });

        // PANEL BUTTONS
        panelButtons.setLayout(new GridLayout(1, 4));
        panelButtons.setVisible(true);

        // BUTTON OPEN
        buttonOpen.setBounds(new Rectangle(200, 50));
        buttonOpen.setVisible(true);
        fileChooser.setFileFilter(filter);
        buttonOpen.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                int returnVal = fileChooser.showOpenDialog(null);

                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File file = fileChooser.getSelectedFile();
                    try {
                        panelPaint.setBufferedImage(ImageIO.read(file));
                        dimension = new Dimension(panelPaint.getBufferedImage().getWidth(),
                                panelPaint.getBufferedImage().getHeight());
                        panelPaint.setPreferredSize(dimension);
                        dimension = toolkit.getScreenSize();
                        scrollPane.setViewportView(panelPaint);
                        panel.repaint();
                    } catch (IOException ex) {
                        JOptionPane.showMessageDialog(null, "Can't read this file!", "IOException", 0);
                    }
                }
            }
        });

        // BUTTON SAVE
        buttonSave.setBounds(new Rectangle(200, 100));
        buttonSave.setVisible(true);
        buttonSave.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                int returnVal = fileChooser.showSaveDialog(null);

                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    File file = fileChooser.getSelectedFile();
                    try {
                        ImageIO.write(panelPaint.getBufferedImage(), "png", file);
                    } catch (IOException ex) {
                        JOptionPane.showMessageDialog(null, "Can't write this file!", "IOException", 0);
                    }
                }
            }
        });

        //BUTTON CHOOSE COLOR
        buttonChooseColor.setBounds(new Rectangle(200, 100));
        buttonChooseColor.setVisible(true);
        ActionListener cancelListener = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                color = Color.red;
            }
        };
        ActionListener okListener = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                color = colorChooser.getColor();
            }
        };
        dialog = JColorChooser.createDialog(null, "Choose color", true, colorChooser, okListener, cancelListener);
        buttonChooseColor.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                dialog.setVisible(true);
            }
        });

        // BUTTON CLEAR
        buttonClear.setBounds(new Rectangle(200, 100));
        buttonClear.setVisible(true);
        buttonClear.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                panelPaint.clear();
                panelPaint.setPreferredSize(dimension);
                scrollPane.setViewportView(panelPaint);
                panel.repaint();
            }
        });

        // DESIGN COMPONENTS
        scrollPane.getVerticalScrollBar().setUI( new MetalScrollBarUI() {
            @Override
            protected void paintThumb( Graphics g, JComponent c, Rectangle tb ) {
                backgroundColor = Color.decode("#8884FF");
                g.setColor(backgroundColor);
                if ( scrollbar.getOrientation() == JScrollBar.VERTICAL ) {
                    g.fillRect( tb.x, tb.y, tb.width, tb.height );
                } else {
                    g.fillRect( tb.x, tb.y, tb.width, tb.height );
                }
            }

            @Override
            protected void paintTrack(Graphics g, JComponent c, Rectangle tb) {
                backgroundColor = Color.decode("#DAD8FF");
                g.setColor(backgroundColor);
                g.fillRect(tb.x, tb.y, tb.width, tb.height);
            }
        });
        scrollPane.getHorizontalScrollBar().setUI( new MetalScrollBarUI() {
            @Override
            protected void paintThumb( Graphics g, JComponent c, Rectangle tb ) {
                backgroundColor = Color.decode("#8884FF");
                g.setColor(backgroundColor);
                if ( scrollbar.getOrientation() == JScrollBar.VERTICAL ) {
                    g.fillRect( tb.x, tb.y, tb.width, tb.height );
                } else {
                    g.fillRect( tb.x, tb.y, tb.width, tb.height );
                }
            }

            @Override
            protected void paintTrack(Graphics g, JComponent c, Rectangle tb) {
                backgroundColor = Color.decode("#DAD8FF");
                g.setColor(backgroundColor);
                g.fillRect(tb.x, tb.y, tb.width, tb.height);
            }
        });

        backgroundColor = Color.decode("#D7BCE8");
        buttonOpen.setFocusPainted(false);
        buttonOpen.setBorder(null);
        buttonOpen.setForeground(textColor);
        buttonOpen.setBackground(backgroundColor);
        line = new LineBorder(Color.BLACK, 1);
        margin = new EmptyBorder(5, 15, 5, 15);
        compound = new CompoundBorder(line, margin);
        buttonOpen.setBorder(compound);
        buttonOpen.setFont(defaultFont);
        buttonOpen.setOpaque(true);

        backgroundColor = Color.decode("#E8CEE4");
        buttonSave.setFocusPainted(false);
        buttonSave.setBorder(null);
        buttonSave.setForeground(textColor);
        buttonSave.setBackground(backgroundColor);
        line = new LineBorder(Color.BLACK, 1);
        margin = new EmptyBorder(5, 15, 5, 15);
        compound = new CompoundBorder(line, margin);
        buttonSave.setBorder(compound);
        buttonSave.setFont(defaultFont);
        buttonSave.setOpaque(true);

        backgroundColor = Color.decode("#FDE2FF");
        buttonChooseColor.setFocusPainted(false);
        buttonChooseColor.setBorder(null);
        buttonChooseColor.setForeground(textColor);
        buttonChooseColor.setBackground(backgroundColor);
        line = new LineBorder(Color.BLACK, 1);
        margin = new EmptyBorder(5, 15, 5, 15);
        compound = new CompoundBorder(line, margin);
        buttonChooseColor.setBorder(compound);
        buttonChooseColor.setFont(defaultFont);
        buttonChooseColor.setOpaque(true);

        backgroundColor = Color.decode("#fef0ff");
        buttonClear.setFocusPainted(false);
        buttonClear.setBorder(null);
        buttonClear.setForeground(textColor);
        buttonClear.setBackground(backgroundColor);
        line = new LineBorder(Color.BLACK, 1);
        margin = new EmptyBorder(5, 15, 5, 15);
        compound = new CompoundBorder(line, margin);
        buttonClear.setBorder(compound);
        buttonClear.setFont(defaultFont);
        buttonClear.setOpaque(true);


        // ADD COMPONENTS
        panelButtons.add(buttonOpen);
        panelButtons.add(buttonSave);
        panelButtons.add(buttonChooseColor);
        panelButtons.add(buttonClear);
        panel.add(panelButtons, BorderLayout.SOUTH);
        panel.add(scrollPane, BorderLayout.CENTER);
        this.getContentPane().add(panel);
    }

    public static void main(String[] args) {
        Application app = new Application();
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        Dimension dimension = toolkit.getScreenSize();
        app.setBounds(dimension.width / 2 - 320, dimension.height / 2 - 240, 640, 480);
    }
}
