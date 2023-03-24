
public class Test {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Nie podano zakresu liczb pierwszych.");
            return;
        }

        int n;
        try {
            n = Integer.parseInt(args[0]);
        } catch (NumberFormatException ex) {
            System.out.println("Nieprawidłowy zakres.");
            return;
        }

        PrimeNumbers primes = new PrimeNumbers(n);

        for (int i = 1; i < args.length; i++) {
            int m;
            try {
                m = Integer.parseInt(args[i]);
            } catch (NumberFormatException ex) {
                System.out.println(args[i] + " - nieprawidłowa dana.");
                continue;
            }

            int prime = primes.liczba(m);
            if (prime == -1) {
                System.out.println(m + " - liczba spoza zakresu.");
            } else {
                System.out.println(m + " - " + prime);
            }
        }
    }
}