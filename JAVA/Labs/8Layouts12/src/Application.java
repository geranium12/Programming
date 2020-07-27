import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Application extends JFrame {

    private static final int NUMBER_OF_ROWS = 5;
    private static final int NUMBER_OF_COLUMNS = 3;
    private static final int NUMBER_OF_ICONS = 4;

    private JTabbedPane tabbedPane = new JTabbedPane();

    private JPanel panel1 = new JPanel();
    private JPanel panel1Center = new JPanel();
    private JList listLeft = new JList();
    private JList listRight = new JList();
    private DefaultListModel listModelLeft = new DefaultListModel();
    private DefaultListModel listModelRight = new DefaultListModel();
    private JButton buttonNorth = new JButton();
    private JButton buttonSouth = new JButton();

    private JPanel panel2 = new JPanel();
    private MouseListener mouseListener2;

    private JPanel panel3 = new JPanel();
    private Color initialColor = Color.GREEN;
    private Color changeColor = Color.YELLOW;

    private JRadioButton[] radioButtons = new JRadioButton[NUMBER_OF_ICONS];
    private ButtonGroup buttonGroup = new ButtonGroup();

    public Application() {
        this.setTitle("App");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);

        tabbedPane.setVisible(true);

        initialisePanel1();

        initialisePanel2();

        initialisePanel3();

        // ADD ALL COMPONENTS
        panel1.add(panel1Center, BorderLayout.CENTER);
        tabbedPane.add(panel1, "1");
        tabbedPane.add(panel2, "2");
        tabbedPane.add(panel3, "3");
        this.setContentPane(tabbedPane);
    }

    // PANEL 1
    void initialisePanel1() {
        panel1.setLayout(new BorderLayout());
        panel1.setSize(getWidth(), getHeight());
        panel1.setVisible(true);

        setData1();

        listLeft.setModel(listModelLeft);
        listRight.setModel(listModelRight);

        listLeft.setPreferredSize(new Dimension(200, getHeight()));
        listRight.setPreferredSize(new Dimension(200, getHeight()));
        panel1.add(listLeft, BorderLayout.WEST);
        panel1.add(listRight, BorderLayout.EAST);

        panel1Center.setLayout(new BorderLayout());
        panel1Center.setVisible(true);
        buttonNorth.setPreferredSize(new Dimension(300, 70));
        buttonNorth.setText(">");
        buttonNorth.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                move(listLeft.getSelectedIndices(), listModelLeft, listModelRight);
            }
        });

        buttonSouth.setPreferredSize(new Dimension(300, 70));
        buttonSouth.setText("<");
        buttonSouth.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                move(listRight.getSelectedIndices(), listModelRight, listModelLeft);
            }
        });
        panel1Center.add(buttonNorth, BorderLayout.NORTH);
        panel1Center.add(buttonSouth, BorderLayout.SOUTH);

    }

    // DATA
    void setData1() {
        listModelLeft.addElement("Vows are spoken");
        listModelLeft.addElement("To be broken");
        listModelLeft.addElement("Feelings are intense");
        listModelLeft.addElement("Words are trivial");
        listModelLeft.addElement("Pleasures remain");
        listModelLeft.addElement("So does the pain");
        listModelLeft.addElement("Words are meaningless");
        listModelLeft.addElement("And forgettable");

        listModelRight.addElement("All I ever wanted");
        listModelRight.addElement("All I ever needed");
        listModelRight.addElement("Is here in my arms");
        listModelRight.addElement("Words are very unnecessary");
        listModelRight.addElement("They can only do harm");
    }

    void move(int[] indices, DefaultListModel list1, DefaultListModel list2) {
        int k = 0;
        for (int index : indices) {
            list2.addElement(list1.remove(index - k++));
        }
    }

    // PANEL 2
    void initialisePanel2() {
        mouseListener2 = new MouseAdapter() {
            String str;

            @Override
            public void mousePressed(MouseEvent e) {
                JButton jButton = (JButton) e.getSource();
                str = jButton.getText();
                jButton.setText("Clicked!");
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                JButton jButton = (JButton) e.getSource();
                jButton.setText(str);
            }

            @Override
            public void mouseEntered(MouseEvent e) {
                JButton jButton = (JButton) e.getSource();
                jButton.setBackground(changeColor);
            }

            @Override
            public void mouseExited(MouseEvent e) {
                JButton jButton = (JButton) e.getSource();
                jButton.setBackground(initialColor);
            }
        };

        panel2.setLayout(new GridLayout(NUMBER_OF_ROWS, NUMBER_OF_COLUMNS));
        panel2.setVisible(true);

        for (int i = 0; i < NUMBER_OF_ROWS; i++) {
            for (int j = 0; j < NUMBER_OF_COLUMNS; j++) {
                JButton button = new JButton();
                button.setVisible(true);
                String indexStr = Integer.toString(i * NUMBER_OF_COLUMNS + j + 1);
                button.setText(indexStr);
                button.setBackground(Color.GREEN);
                button.addMouseListener(mouseListener2);
                panel2.add(button);
            }
        }
    }

    // PANEL 3
    void initialisePanel3() {
        panel3.setVisible(true);

        radioButtons[0] = new JRadioButton("1");
        radioButtons[1] = new JRadioButton("2");
        radioButtons[2] = new JRadioButton("3");
        radioButtons[3] = new JRadioButton("4");

        ImageIcon imageIconOrange = new ImageIcon("src\\data\\orange.png");
        ImageIcon imageIconPineapple = new ImageIcon("src\\data\\pineapple.png");
        ImageIcon imageIconPear = new ImageIcon("src\\data\\pear.png");
        ImageIcon imageIconWatermelon = new ImageIcon("src\\data\\watermelon.png");

        for (int i = 0; i < NUMBER_OF_ICONS; i++) {
            radioButtons[i].setIcon(imageIconOrange);
            radioButtons[i].setSelectedIcon(imageIconPear);
            radioButtons[i].setRolloverIcon(imageIconPineapple);
            radioButtons[i].setPressedIcon(imageIconWatermelon);
            //radioButtons[i].setPreferredSize(new Dimension(100, 100));
            buttonGroup.add(radioButtons[i]);
            panel3.add(radioButtons[i]);
        }
    }

    public static void main(String[] args) {
        Application app = new Application();
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        Dimension dimension = toolkit.getScreenSize();
        app.setBounds(dimension.width / 2 - 320, dimension.height / 2 - 240, 640, 480);
    }
}
