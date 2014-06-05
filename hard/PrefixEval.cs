using System;
using System.Collections.Generic;

namespace prefix
{
    class Prefix
    {
        static int Main(string[] args)
        {
            if (args.Length == 0)
            {
                System.Console.WriteLine("Please enter a numeric argument.");
                return 1;
            }

            System.IO.StreamReader file = new System.IO.StreamReader(args[0]);
            

            //System.IO.StreamReader file = new System.IO.StreamReader(@"C:\Users\sherman\Documents\Visual Studio 2013\Projects\prefix\prefix_examples.txt");
            
            String line;
            String [] elements;

            while ((line = file.ReadLine()) != null)
            {
                elements = line.Split(' ');
                decimal result = evaluateLine(elements);
                if (result == 0)
                    System.Console.WriteLine("0");
                else
                    System.Console.WriteLine(result.ToString("#"));
            }

            //System.Console.ReadLine();
            return 0;
        }

        static Decimal evaluateLine(String [] elements)
        {
            Stack<String> expression = new Stack<String>();

            foreach (String value in elements)
            {
                
                if (value.Equals(" ")) 
                {
                    continue;
                } 
                else if (isOperator(value)) 
                {
                    expression.Push(value);
                }
                else if (isOperand(value))
                {
                    handleOperand(expression, value);
                }
            }
            return Convert.ToDecimal(expression.Pop());
        }

        static Boolean isOperator(String value)
        {
            switch (value)
            {
                case ("+"):
                case ("-"):
                case ("*"):
                case ("/"):
                    return true;
                default:
                    return false;
            }
        }

        static Boolean isOperand(String value)
        {
            try
            {
                Convert.ToDecimal(value);
                return true;
            }
            catch (FormatException)
            {
                return false;
            }
        }

        static void handleOperand(Stack<String> expression, String right)
        {
            String left, op;
            /* right = pop
             * while right && Peek() are operands
             *    second = pop
             *    op = pop
             *    right = evaluate
             * push (right)
             */

            while (!isStackEmpty(expression) && isOperand(expression.Peek()) && isOperand(right))
            {
                left = expression.Pop();
                op = expression.Pop();
                right = applyOperator(Convert.ToDecimal(left), Convert.ToDecimal(right), op);
            }
            expression.Push(right);
        }

        static String applyOperator(decimal left, decimal right, string op)
        {
            switch (op)
            {
                case ("*"):
                    return (left * right).ToString();
                case ("/"):
                    return (left / right).ToString();
                case ("+"):
                    return (left + right).ToString();
                case ("-"):
                    return (left - right).ToString();
                default:
                    throw new ArgumentException("ERROR! Invalid operator: " + op);
            }
        }

        static bool isStackEmpty(Stack<String> s)
        {
            try
            {
                s.Peek();
                return false;
            }
            catch (InvalidOperationException)
            {
                return true;
            }
        }
    }
}
