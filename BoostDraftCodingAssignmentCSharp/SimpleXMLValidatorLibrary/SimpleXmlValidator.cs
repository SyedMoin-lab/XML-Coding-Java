using System;
using System.Collections.Generic;

namespace SimpleXMLValidatorLibrary
{
    public class SimpleXmlValidator
    {
        public static bool DetermineXml(string xml)
        {
            Stack<string> stack = new Stack<string>();
            int i = 0;

            while (i < xml.Length)
            {
                if (xml[i] == '<')
                {
                    int j = i + 1;

                    // Find the end of the tag
                    while (j < xml.Length && xml[j] != '>')
                    {
                        j++;
                    }

                    if (j == xml.Length)
                    {
                        return false; // Tag not closed properly
                    }

                    string tagContent = xml.Substring(i + 1, j - i - 1).Trim();

                    if (tagContent.StartsWith("/"))
                    {
                        // Closing tag
                        string tagName = tagContent.Substring(1).Trim();

                        if (stack.Count == 0 || stack.Peek() != tagName)
                        {
                            return false; // No matching opening tag
                        }

                        stack.Pop();
                    }
                    else
                    {
                        // Opening tag
                        string tagName = tagContent.Split(' ')[0].Trim();
                        stack.Push(tagName);
                    }

                    i = j;
                }

                i++;
            }

            return stack.Count == 0;
        }
    }
}
