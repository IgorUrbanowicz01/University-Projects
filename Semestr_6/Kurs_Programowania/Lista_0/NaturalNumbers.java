public class NaturalNumbers {
    public static void main(String[] args) {
        for (int i = 0; i < args.length; i++) {
            try {
                int n = Integer.parseInt(args[i]);
                System.out.println(n + " " + div(n));
            } catch (NumberFormatException ex) {
                System.out.println(args[i] + " nie jest liczba calkowita");
            }
        }
    }

    public static int div(int n) {
        int i;
        for (i = n - 1; i > 1; i--) {
            if (n % i == 0) {
                break;
            }
        }
        return i;
    }
}