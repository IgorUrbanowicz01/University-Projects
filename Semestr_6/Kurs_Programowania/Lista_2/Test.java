public class Test {
    public static void main(String[] args) {
        try {
            int n = Integer.parseInt(args[0]);
            WierszTrojkataPascala row = new WierszTrojkataPascala(n);
            for (int i = 1; i < args.length; i++) {
                try {
                    int m = Integer.parseInt(args[i]);
                    int wsp = row.wspolczynnik(m);
                    System.out.println(m + " - " + wsp);
                } catch (NumberFormatException e) {
                    System.out.println(args[i] + " - nieprawidłowa dana");
                } catch (IllegalArgumentException e) {
                    System.out.println(args[i] + " - " + e.getMessage());
                }
            }
        } catch (NumberFormatException e) {
            System.out.println(args[0] + " - liczba spoza zakresu");
        } catch (IllegalArgumentException e) {
            System.out.println(args[0] + " - " + e.getMessage());
        }
    }
}