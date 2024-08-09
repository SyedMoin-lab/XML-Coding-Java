package xmlvalidatorlibrary;

import java.util.Stack;

public class SimpleXmlValidator {

    public static boolean determineXml(String xml) {
        Stack<String> stack = new Stack<>();

        int i = 0;
        while (i < xml.length()) {
            if (xml.charAt(i) == '<') {
                int end = xml.indexOf('>', i);
                if (end == -1) {
                    return false; // Invalid XML if there is no closing '>'
                }

                String tag = xml.substring(i + 1, end);

                if (tag.startsWith("/")) {
                    // Closing tag
                    if (stack.isEmpty() || !stack.pop().equals(tag.substring(1))) {
                        return false; // Tags don't match
                    }
                } else {
                    // Opening tag
                    if (tag.contains(" ") || tag.contains("=")) {
                        return false; // Invalid if tag contains attributes or spaces
                    }
                    stack.push(tag);
                }

                i = end + 1;
            } else {
                i++;
            }
        }

        return stack.isEmpty(); // All tags should be properly closed
    }
}
