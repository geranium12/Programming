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

namespace CalculatorWinForms
{
    public partial class Form1 : Form
    {
        static int flag = 0;
        static double temp;
        static double editValue;

        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int num = 2;
            if (flag == 0)
            {
                editValue = num;
                flag = 9;
            }
            else
            {
                if (flag == 1 || flag == 3 || flag == 5 || flag == 7)
                {
                    temp = editValue;
                    editValue = num;
                    flag++;
                }
                else
                {
                    if (flag == 2 || flag == 4 || flag == 6 || flag == 8 || flag == 9)
                    {
                        if (editValue < 10000000)
                        {
                            editValue = editValue * 10 + num;
                        }
                    }
                }
            }
            textBox1.Text = editValue.ToString();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            int num = 3;
            if (flag == 0)
            {
                editValue = num;
                flag = 9;
            }
            else
            {
                if (flag == 1 || flag == 3 || flag == 5 || flag == 7)
                {
                    temp = editValue;
                    editValue = num;
                    flag++;
                }
                else
                {
                    if (flag == 2 || flag == 4 || flag == 6 || flag == 8 || flag == 9)
                    {
                        if (editValue < 10000000)
                        {
                            editValue = editValue * 10 + num;
                        }
                    }
                }
            }
            textBox1.Text = editValue.ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int num = 1;
            if (flag == 0)
            {
                editValue = num;
                flag = 9;
            }
            else
            {
                if (flag == 1 || flag == 3 || flag == 5 || flag == 7)
                {
                    temp = editValue;
                    editValue = num;
                    flag++;
                }
                else
                {
                    if (flag == 2 || flag == 4 || flag == 6 || flag == 8 || flag == 9)
                    {
                        if (editValue < 10000000)
                        {
                            editValue = editValue * 10 + num;
                        }
                    }
                }
            }
            textBox1.Text = editValue.ToString();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            int num = 4;
            if (flag == 0)
            {
                editValue = num;
                flag = 9;
            }
            else
            {
                if (flag == 1 || flag == 3 || flag == 5 || flag == 7)
                {
                    temp = editValue;
                    editValue = num;
                    flag++;
                }
                else
                {
                    if (flag == 2 || flag == 4 || flag == 6 || flag == 8 || flag == 9)
                    {
                        if (editValue < 10000000)
                        {
                            editValue = editValue * 10 + num;
                        }
                    }
                }
            }
            textBox1.Text = editValue.ToString();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            int num = 5;
            if (flag == 0)
            {
                editValue = num;
                flag = 9;
            }
            else
            {
                if (flag == 1 || flag == 3 || flag == 5 || flag == 7)
                {
                    temp = editValue;
                    editValue = num;
                    flag++;
                }
                else
                {
                    if (flag == 2 || flag == 4 || flag == 6 || flag == 8 || flag == 9)
                    {
                        if (editValue < 10000000)
                        {
                            editValue = editValue * 10 + num;
                        }
                    }
                }
            }
            textBox1.Text = editValue.ToString();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            int num = 6;
            if (flag == 0)
            {
                editValue = num;
                flag = 9;
            }
            else
            {
                if (flag == 1 || flag == 3 || flag == 5 || flag == 7)
                {
                    temp = editValue;
                    editValue = num;
                    flag++;
                }
                else
                {
                    if (flag == 2 || flag == 4 || flag == 6 || flag == 8 || flag == 9)
                    {
                        if (editValue < 10000000)
                        {
                            editValue = editValue * 10 + num;
                        }
                    }
                }
            }
            textBox1.Text = editValue.ToString();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            int num = 7;
            if (flag == 0)
            {
                editValue = num;
                flag = 9;
            }
            else
            {
                if (flag == 1 || flag == 3 || flag == 5 || flag == 7)
                {
                    temp = editValue;
                    editValue = num;
                    flag++;
                }
                else
                {
                    if (flag == 2 || flag == 4 || flag == 6 || flag == 8 || flag == 9)
                    {
                        if (editValue < 10000000)
                        {
                            editValue = editValue * 10 + num;
                        }
                    }
                }
            }
            textBox1.Text = editValue.ToString();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            int num = 8;
            if (flag == 0)
            {
                editValue = num;
                flag = 9;
            }
            else
            {
                if (flag == 1 || flag == 3 || flag == 5 || flag == 7)
                {
                    temp = editValue;
                    editValue = num;
                    flag++;
                }
                else
                {
                    if (flag == 2 || flag == 4 || flag == 6 || flag == 8 || flag == 9)
                    {
                        if (editValue < 10000000)
                        {
                            editValue = editValue * 10 + num;
                        }
                    }
                }
            }
            textBox1.Text = editValue.ToString();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            int num = 9;
            if (flag == 0)
            {
                editValue = num;
                flag = 9;
            }
            else
            {
                if (flag == 1 || flag == 3 || flag == 5 || flag == 7)
                {
                    temp = editValue;
                    editValue = num;
                    flag++;
                }
                else
                {
                    if (flag == 2 || flag == 4 || flag == 6 || flag == 8 || flag == 9)
                    {
                        if (editValue < 10000000)
                        {
                            editValue = editValue * 10 + num;
                        }
                    }
                }
            }
            textBox1.Text = editValue.ToString();
        }

        private void button0_Click(object sender, EventArgs e)
        {
            int num = 0;
            if (flag == 0)
            {
                editValue = num;
                flag = 9;
            }
            else
            {
                if (flag == 1 || flag == 3 || flag == 5 || flag == 7)
                {
                    temp = editValue;
                    editValue = num;
                    flag++;
                }
                else
                {
                    if (flag == 2 || flag == 4 || flag == 6 || flag == 8 || flag == 9)
                    {
                        if (editValue < 10000000)
                        {
                            editValue = editValue * 10 + num;
                        }
                    }
                }
            }
            textBox1.Text = editValue.ToString();
        }

        private void buttonPlusMinus_Click(object sender, EventArgs e)
        {
            editValue *= -1;
            textBox1.Text = editValue.ToString();
        }

        private void buttonEqual_Click(object sender, EventArgs e)
        {
            if (flag == 1 || flag == 3 || flag == 5 || flag == 7)
            {
                flag = 9;
            }
            else if (flag == 2)
            {
                editValue = temp + editValue;
                flag = 0;
            }
            else if (flag == 4)
            {
                editValue = temp - editValue;
                flag = 0;
            }
            else if (flag == 6)
            {
                editValue = temp * editValue;
                flag = 0;
            }
            else if (flag == 8)
            {
                editValue = temp / editValue;
                flag = 0;
            }
            textBox1.Text = editValue.ToString();
        }

        private void buttonPlus_Click(object sender, EventArgs e)
        {
            if (flag == 2 || flag == 4 || flag == 6 || flag == 8)
                buttonEqual_Click(sender, e);
            flag = 1;
        }

        private void buttonMinus_Click(object sender, EventArgs e)
        {
            if (flag == 2 || flag == 4 || flag == 6 || flag == 8)
                buttonEqual_Click(sender, e);
            flag = 3;
        }

        private void buttonMul_Click(object sender, EventArgs e)
        {
            if (flag == 2 || flag == 4 || flag == 6 || flag == 8)
                buttonEqual_Click(sender, e);
            flag = 5;
        }

        private void buttonDiv_Click(object sender, EventArgs e)
        {
            if (flag == 2 || flag == 4 || flag == 6 || flag == 8)
                buttonEqual_Click(sender, e);
            flag = 7;
        }

        private void buttonDel_Click(object sender, EventArgs e)
        {
            editValue = (int)(editValue / 10);
            textBox1.Text = editValue.ToString();
        }

        private void buttonC_Click(object sender, EventArgs e)
        {
            editValue = 0;
            temp = 0;
            textBox1.Text = editValue.ToString();
        }

        private void buttonCE_Click(object sender, EventArgs e)
        {
            editValue = 0;
            textBox1.Text = editValue.ToString();
        }
    }
}
