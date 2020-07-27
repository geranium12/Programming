import java.util.StringTokenizer;

public class Main {
    static class WrongCountException extends Exception {
        WrongCountException() {}
        WrongCountException(String msg) {
            super(msg);
        }
    }

    static class WrongInputException extends Exception {
        WrongInputException() {}
        WrongInputException(String msg) {
            super(msg);
        }
    }

    static int countExpression(int x, StringBuilder str) {
        StringTokenizer strtok;
        String tok = null;
        int res = 0;
        if (((str.charAt(0) == '+') || (str.charAt(0) == '-')) &&
                (Character.isDigit(str.charAt(1)) ||
                        (str.charAt(1) == 'x'))) {
            strtok = new StringTokenizer(str.toString(), "+-x", true);
            tok = strtok.nextToken();
            String s = strtok.nextToken();
            if (tok.equals("+")) {
                if (s.equals("x")) {
                    res += x;
                } else {
                    res += Integer.parseInt(s);
                }
            } else {
                if (s.equals("x")) {
                    res -= x;
                } else {
                    res -= Integer.parseInt(s);
                }
            }
            if (strtok.hasMoreTokens()) {
                tok = strtok.nextToken();
                if (tok.equals("x")) {
                    res *= x;
                }
            }
        } else {
            str.insert(0, "+");
            strtok = new StringTokenizer(str.toString(), "+-", true);
        }

        while (strtok.hasMoreTokens()) {
            if (tok == null || tok.equals("x")) {
                tok = strtok.nextToken();
            }
            StringBuilder s = new StringBuilder(strtok.nextToken());
            int temp;
            if (s.charAt(s.length() - 1) == 'x') {
                if (s.length() == 1) {
                    temp = 1;
                } else {
                    s.deleteCharAt(s.length() - 1);
                    temp = Integer.parseInt(s.toString());
                }
                temp *= x;
            } else {
                temp = Integer.parseInt(s.toString());
            }
            if (tok.equals("+")) {
                if (strtok.hasMoreTokens()) {
                    tok = strtok.nextToken();
                    if (tok.equals("x")) {
                        temp *= x;
                    }
                }
                res += temp;
            } else {
                if (strtok.hasMoreTokens()) {
                    tok = strtok.nextToken();
                    if (tok.equals("x")) {
                        temp *= x;
                    }
                }
                res -= temp;
            }
        }
        return res;
    }

    static boolean isGoodStr(String str) {
        int i = 0;
        int prev = 0;
        // 0 - number
        // 1 - + / -
        // 2 - x
        if (str.charAt(0) == '+' || str.charAt(0) == '-') {
            if (str.length() == 1) {
                return false;
            }
            prev = 1;
            i = 1;
        }
        if (!(Character.isDigit(str.charAt(str.length() - 1))) ||
                (str.charAt(str.length() - 1) == 'x')) {
            return false;
        }
        while (i < str.length()) {
            char c = str.charAt(i);
            if (Character.isDigit(c)) {
                if (prev == 2) {
                    return false;
                }
                prev = 0;
            } else if (c == 'x') {
                if (prev == 2) {
                    return false;
                }
                prev = 2;
            } else if ((c == '+' || c == '-')) {
                if (prev == 1) {
                    return false;
                }
                prev = 1;
            } else {
                return false;
            }
            i++;
        }
        return true;
    }

    public static void main(String[] args) {

        for (int i = 0; i < args.length; i++) {

            System.out.println("N" + i + "   " + args[i]);
        }
        try {
            if (args.length != 2) {
                throw new WrongCountException("The number of arguments should equal 2!");
            }
            int x = Integer.parseInt(args[0]);
            String s = args[1];
            StringBuilder str = new StringBuilder(s);
            if (!isGoodStr(s)) {
                throw new WrongInputException("WRONG INPUT STRING " + s);
            } else System.out.println("SUM = " + countExpression(x, str));
        } catch (WrongCountException ex) {
            System.out.println(ex.getMessage());
        } catch (NumberFormatException ex) {
            System.out.println("WRONG NUMBER " + ex.getMessage());
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
        }
    }
}