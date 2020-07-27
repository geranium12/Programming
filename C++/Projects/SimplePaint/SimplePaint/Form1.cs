/*
    Герасимчик Анна. 1 курс 7 группа
*/
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GraphicsWinForms
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            g = panel1.CreateGraphics();
            panel1.BackColor = Color.White;
        }
        bool startPaint = false;
        Graphics g;
    
        int? initX = null;
        int? initY = null;
        bool drawLine = true;
        bool drawSquare = false;
        bool drawRectangle = false;
        bool drawCircle = false;
        Color color = Color.Black;

        private void pnl_Draw_MouseMove(object sender, MouseEventArgs e)
        {
            if (startPaint)
            {
                int size = 10;
                string str = textBox1.Text;
                bool flag = false;
                if (str.Length != 0)
                    flag = true;

                for (int i = 0; i < str.Length; i++)
                    if ((str[i] - '0' > 9) || (str[i] - '0' < 0))
                    {
                        flag = false;
                        break;
                    }

                if (flag)
                    size = Convert.ToInt32(textBox1.Text);

                Pen p = new Pen(color, size);
                if (drawLine)
                {
                    g.DrawLine(p, new Point(initX ?? e.X, initY ?? e.Y), new Point(e.X, e.Y));
                }
                initX = e.X;
                initY = e.Y;
            }
        }

        private void pnl_Draw_MouseDown(object sender, MouseEventArgs e)
        {
            startPaint = true;
            if (drawSquare)
            {
     
                SolidBrush sb = new SolidBrush(color);
     
                g.FillRectangle(sb, e.X, e.Y, 50, 50);
                startPaint = false;
            }
            if (drawRectangle)
            {
                SolidBrush sb = new SolidBrush(color);

                g.FillRectangle(sb, e.X, e.Y, 100, 50);
                startPaint = false;
            }
            if (drawCircle)
            {
                SolidBrush sb = new SolidBrush(color);
                g.FillEllipse(sb, e.X, e.Y, 60, 60);
                startPaint = false;
            }
        }

        private void pnl_Draw_MouseUp(object sender, MouseEventArgs e)
        {
            startPaint = false;
            initX = null;
            initY = null;
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            g.Clear(panel1.BackColor);
            panel1.BackColor = Color.White;
            color = Color.Black;
            drawLine = true;
            drawSquare = false;
            drawRectangle = false;
            drawCircle = false;
            textBox1.Text = "5";
        }

        private void btn_PenColor_Click_1(object sender, EventArgs e)
        {
            ColorDialog c = new ColorDialog();
            if (c.ShowDialog() == DialogResult.OK)
            {
                color = c.Color;
            }
        }

        private void btn_Square_Click(object sender, EventArgs e)
        {
            drawSquare = true;
            drawRectangle = false;
            drawCircle = false;
        }

        private void btn_Rectangle_Click(object sender, EventArgs e)
        {
            drawSquare = false;
            drawRectangle = true;
            drawCircle = false;
        }

        private void btn_Circle_Click(object sender, EventArgs e)
        {
            drawSquare = false;
            drawRectangle = false;
            drawCircle = true;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            drawLine = true;
            drawSquare = false;
            drawRectangle = false;
            drawCircle = false;
        }
    }  
} 