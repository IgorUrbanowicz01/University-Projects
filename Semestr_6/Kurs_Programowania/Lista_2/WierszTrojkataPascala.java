import java.util.ArrayList;

public class WierszTrojkataPascala {
    private ArrayList<Integer> row;

    public WierszTrojkataPascala(int n) throws IllegalArgumentException {
        if (n < 0) {
            throw new IllegalArgumentException("Ujemny numer");
        }
        row = new ArrayList<>();
        row.add(1);
        for (int i = 1; i <= n; i++) {
            int prev = row.get(i - 1);
            int curr = prev * (n - i + 1) / i;
            row.add(curr);
        }
    }

    public int wspolczynnik(int m) throws IllegalArgumentException {
        if (m < 0 || m >= row.size()) {
            throw new IllegalArgumentException("liczba spoza zakresu");
        }
        return row.get(m);
    }
}